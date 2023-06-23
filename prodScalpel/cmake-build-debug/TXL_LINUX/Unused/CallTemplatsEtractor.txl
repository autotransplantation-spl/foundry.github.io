include "c.grm"


define FunctionOutput
	BEGIN [function_definition] END[NL]
end define

%ideea: not calling templates, but data dependency contexts for all different calling templates
%keep the minimum data dependency context
%abstract just according to the contexts elements used at that point

function main
	match [program]
			P[program] 
	construct programFctDefs [repeat function_definition]
		_ [^ P] 
	construct graftFunction [repeat function_definition]
		_ [getGraftFunction programFctDefs] 
	deconstruct * [function_definition] graftFunction
		MyGraft [function_definition] 
	
	construct listOfCallers [repeat FunctionOutput]
		_ [extractCallPlaces MyGraft]  [write "AllGraftCallers.out"]
		
end function

function getGraftFunction ListOfFct [repeat function_definition]	
	replace [repeat function_definition]
		current [repeat function_definition]
	deconstruct ListOfFct
		first [function_definition] rest [repeat function_definition]
	construct JustGraft [repeat function_definition]
		_ [addJustIfGraft first]
	by
		JustGraft 
		[getGraftFunction rest]
end function



function addJustIfGraft CurrentFct [function_definition]
	replace  [repeat function_definition]
		graftFct [repeat function_definition]
    where 
       	CurrentFct [containsAGraft]
	by
		CurrentFct
end function


function containsAGraft
    match * [declaration_or_statement]
        AS [addGraft]

end function




%extractions

function extractCallPlaces GraftFct [function_definition]
	replace [repeat FunctionOutput]
		current [repeat FunctionOutput]
	deconstruct * [declarator] GraftFct
		fctID [declarator]	
	construct stringFctName [stringlit]
		_ [quote fctID]
		
	construct CallCommand [id]
    	_ [system "./SourceContent input stringLength.c"]
	construct ListOfExistingSourceFiles [repeat stringlit]
		_ [read "SourceFiles.out"] [print]
	
	construct allCallers [repeat FunctionOutput]
		_ [constructAllCallers stringFctName ListOfExistingSourceFiles]
	

	
	by
		allCallers
end function



function constructAllCallers	GraftName [stringlit]
								ListOfSourceFiles [repeat stringlit]
	replace [repeat FunctionOutput]
		currentList [repeat FunctionOutput]
	deconstruct ListOfSourceFiles
		first [stringlit] rest [repeat stringlit]
	construct P [program]
		_ [read first] 
	construct fctFromCurrentP [repeat function_definition]
		_ [^ P]	
	construct GraftCallers [repeat FunctionOutput]
		_ [constructGraftCallers GraftName fctFromCurrentP]
	
	by
		currentList [. GraftCallers]
		[constructAllCallers GraftName rest]
end function

function constructGraftCallers	GraftName [stringlit]
								ListOfFct [repeat function_definition]
	replace [repeat FunctionOutput]
		currentList [repeat FunctionOutput]
	deconstruct ListOfFct 
		first [function_definition] rest [repeat function_definition]
	construct graftCaller [repeat FunctionOutput]
		_ [addFctIfCallsGraft GraftName first]
	by
		currentList [.graftCaller]
		[constructGraftCallers GraftName rest]
end function



function addFctIfCallsGraft	GrftName [stringlit]
							CurrFct [function_definition]
	replace [repeat FunctionOutput]
		_ [repeat FunctionOutput]
	where
		CurrFct [matchGraftCall GrftName]
		construct CurrentSymbolTable [repeat variableDeclaration]
			_ [ constructLocalSymbolTable CurrFct] 
			
				construct listOfDecl [repeat decl_specifiers]
			_ [^ CurrentSymbolTable] 
		construct namesFromDecl [repeat stringlit]
			_ [extractNamesFromDecl listOfDecl] 
		
		construct listOfNames [repeat base_declarator]
			_ [^ CurrentSymbolTable]
		construct namesAsString [repeat stringlit]
			_ [namesToString listOfNames] 
		construct listOfAllNames [repeat stringlit]
			namesFromDecl [. namesAsString]
		construct newFct [function_definition]
			CurrFct [normalize listOfAllNames]
	by
		BEGIN newFct END
end function


function extractNamesFromDecl	ListOfDecl [repeat decl_specifiers]
	replace [repeat stringlit]
		current [repeat stringlit]
	deconstruct ListOfDecl 
		first [decl_specifiers]	rest[repeat decl_specifiers]
	construct names [repeat stringlit]
		_ [extractNames first]
	by
		current [. names]
		[extractNamesFromDecl rest]		
end function

function extractNames	Decl [decl_specifiers]
	replace [repeat stringlit]
		_ [repeat stringlit]
	deconstruct * [repeat decl_qualifier_or_type_specifier] Decl
		listDecl [repeat decl_qualifier_or_type_specifier]
	deconstruct listDecl
		first [decl_qualifier_or_type_specifier] sec [decl_qualifier_or_type_specifier]
	construct stringFromDecl [stringlit]
		_[quote sec]
		
	by
		stringFromDecl
end function



function namesToString DeclList [repeat base_declarator]
	replace [repeat stringlit]
			current [repeat stringlit]
	deconstruct DeclList
		first [base_declarator] rest [repeat base_declarator]
	construct firstString [stringlit]
		_[quote first]
	by
		current [. firstString]
		[namesToString rest]
end function


function matchGraftCall	GrftName [stringlit]
	match * [id]
		currentId [id]
	construct stringID [stringlit]
		_ [quote currentId]
	where
		stringID [= GrftName]
end function



%just normalize all ids to x
rule normalize	ListOfNames [repeat stringlit]
	replace $ [id]
		Id[id]
	where
		ListOfNames [containsID Id]
	by
		'x
 end rule
 
 
 function containsID	Current [id]
 	match * [stringlit]
 		name [stringlit]
 	construct currentString [stringlit]
 		_ [quote Current]
 	where
 		name [= currentString]
 end function
 
 
 
 
 
 
 
 
 
 
 
 
 %construct symbol table for variables that are defined locally, in the body or the 
%head of the function that contains the target place
function constructLocalSymbolTable P [function_definition]
	replace [repeat variableDeclaration]
		P2 [repeat variableDeclaration]
	construct AllIdsInit [repeat variableDeclaration]
		_ [^ P] 
	construct AllIds [repeat variableDeclaration]
		_ [constructSeparatedDeclarationForEveyVar AllIdsInit]
	construct allIdsFunctionDeclaration [repeat argument_declaration]
		_ [^ P] 
	construct justTest [repeat variableDeclaration]
		AllIds [argumentDeclToVariableDecl allIdsFunctionDeclaration]
	by
		P2 [. justTest]
end function


function constructSeparatedDeclarationForEveyVar listOfVar [repeat variableDeclaration]
	replace [repeat variableDeclaration]
		finalLstOfVar [repeat variableDeclaration]
	deconstruct listOfVar
        First1 [variableDeclaration] Rest1 [repeat variableDeclaration]
         
    construct newFinalLstOfVar [repeat variableDeclaration]
		finalLstOfVar[addNextDecl First1]
	by
		newFinalLstOfVar
	 	[constructSeparatedDeclarationForEveyVar Rest1]
end function


function addNextDecl currentVarDecl [variableDeclaration]
	replace [repeat variableDeclaration]
		decl [repeat variableDeclaration]
	deconstruct   currentVarDecl
		specT [decl_specifiers] declT [list init_declarator] ';
    construct initialVars [repeat variableDeclaration]
    	_ [addVarIfJustDeclaration currentVarDecl] 	
    deconstruct specT
		repeatFromDecl [repeat decl_qualifier_or_type_specifier]
	construct testT [repeat decl_qualifier_or_type_specifier]
		_ [removeTypeSpecifiers repeatFromDecl]
	construct newVarDeclSpecifiers [decl_specifiers]
		testT
	construct allVars [repeat variableDeclaration]
		initialVars [allVariableDeclarationSeparedList newVarDeclSpecifiers declT ]
	by
		decl [. allVars]
end function
	
	
function addVarIfJustDeclaration	var [variableDeclaration]
	replace [repeat variableDeclaration]
		varDecl [repeat variableDeclaration]
		deconstruct   var
		specT [decl_specifiers] declT [list init_declarator] ';
		
		
		deconstruct specT
			repeatFromDecl [repeat decl_qualifier_or_type_specifier]
		
		construct testT [repeat decl_qualifier_or_type_specifier]
			_ [removeTypeSpecifiers repeatFromDecl]
		
		construct newVarDeclSpecifiers [decl_specifiers]
			testT
			
		construct newVar [variableDeclaration]
			newVarDeclSpecifiers ';
			
	where not
		declT [hasDecl]
	by
		varDecl [.newVar]	
end function	




function removeTypeSpecifiers	v1 [repeat decl_qualifier_or_type_specifier]
	replace [repeat decl_qualifier_or_type_specifier]
		varSpec [repeat decl_qualifier_or_type_specifier]
	deconstruct v1
		first [decl_qualifier_or_type_specifier] rest [repeat decl_qualifier_or_type_specifier] 

	construct finalDeclOrSpec [decl_qualifier_or_type_specifier]
		_ [addJustIfTypeSpec first]
	by
		varSpec [.finalDeclOrSpec]
		[removeTypeSpecifiers rest]
		
end function

function addJustIfTypeSpec	V1 [decl_qualifier_or_type_specifier]
	replace [decl_qualifier_or_type_specifier]
		declOrType [decl_qualifier_or_type_specifier]
	deconstruct  V1
		typeSpec [type_specifier]
	by
		V1
end function

function hasDecl
	match * [list init_declarator]
		AS [init_declarator]
end function

	
function allVariableDeclarationSeparedList	specifier [decl_specifiers]
											declList [list init_declarator]
	replace [repeat variableDeclaration]
		variableDeclList [repeat variableDeclaration]
	deconstruct * [init_declarator] declList
		First [init_declarator] 
	construct Rest [list init_declarator]
		declList [tail 2]	
	
	deconstruct * [declarator] First
		currentDeclarator [declarator]

	construct newVarDecl [variableDeclaration]
		specifier currentDeclarator ';
	by
		variableDeclList [. newVarDecl]
		[allVariableDeclarationSeparedList specifier Rest]
end function
	
	
	
	
	

function isDeclaration
	match [function_definition_or_declaration]
		AS [variableDeclaration]
end function
	

%functions for adding variables from function header into variableDeclaration List	
function argumentDeclToVariableDecl argDecl [repeat argument_declaration]
	replace [repeat variableDeclaration]
		varDecl [repeat variableDeclaration]
	deconstruct argDecl
		first [argument_declaration] rest [repeat argument_declaration]	
	deconstruct first	
		declSpec [decl_specifiers] argDeclarator [opt argument_declarator]     	
	construct declar [variableDeclaration]
		declSpec   ';			
	construct FinalDeclar [variableDeclaration]
		declar [variableFromArgWithOpt first]		
	by
		varDecl [. FinalDeclar]
		[argumentDeclToVariableDecl rest]
end function
	
	
function variableFromArgWithOpt Arg [argument_declaration]
	replace [variableDeclaration]
		var [variableDeclaration]
	deconstruct Arg	
		declSpec [decl_specifiers] argDeclarator [opt argument_declarator]
	deconstruct declSpec
		repeatFromDecl [repeat decl_qualifier_or_type_specifier]
		
	construct testT [repeat decl_qualifier_or_type_specifier]
		_ [removeTypeSpecifiers repeatFromDecl]
		
	construct newVarDeclSpecifiers [decl_specifiers]
		testT
	deconstruct *[declarator] argDeclarator
		declForArg [declarator]
	construct initDeclForLst [init_declarator]
		declForArg
	construct declar [variableDeclaration]
		newVarDeclSpecifiers declForArg  ';
	by
		declar
end function





rule normalize2
	replace [id]
		Id[id]
	deconstruct not Id
		'x
	by
		'x
 end rule
