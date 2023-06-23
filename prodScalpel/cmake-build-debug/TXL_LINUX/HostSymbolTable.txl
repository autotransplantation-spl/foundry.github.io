include "cOriginal.grm"


define addGraft
	__ADDGRAFTHERE__JUSTHERE
end define


redefine declaration_or_statement
	[declaration] 
    |	[statement] 
    |	[addGraft]
#ifdef PREPROCESSOR
    |	[preprocessor]
#endif
#ifdef GNU
    |	[function_definition]  
#endif
#ifdef MACROS
    |	[macro_declaration_or_statement]
#endif
    |	[unknown_declaration_or_statement]
end redefine

redefine function_definition_or_declaration
	[function_definition]  
    |	[declaration] 
	
	|	[addGraft]

#ifdef PREPROCESSOR
    |	[preprocessor]
#endif
    |	[compound_statement] [NL]	% sometimes, function headers are ifdefed out
#ifdef GNU
    |	[macro_declaration_or_statement]
#endif
    |	[unknown_declaration_or_statement]
end redefine

 

function main
	match [program]
			P[program]
	construct newP[program]
		P[outputSymbolTable] 
end function

function outputSymbolTable
	match [program]
		p [program]
	import TXLargs [repeat stringlit]
	deconstruct * [stringlit] TXLargs
		something [stringlit]
	where not
		p [identifyFunctionThatContainsTheGraft p]
 	%construct globalSymbolTable [repeat declaration]
     	%_[symbolTableGlobalVars p] [write something]
end function


rule identifyFunctionThatContainsTheGraft P [program]
	match [function_definition]
		myF [function_definition]
    deconstruct myF
    	header [function_header] paramDecls [opt KR_parameter_decls] statementComp [compound_statement]
   	deconstruct * [compound_statement_body] statementComp
        body [compound_statement_body] 
    deconstruct * [declaration_or_statement] body
        myGraft [addGraft]   
    deconstruct body
     	bodyDeclAndSt [repeat declaration_or_statement]
	construct NewBodyDeclState [repeat declaration_or_statement]
		_ [constructBodyUntilGraftPlace bodyDeclAndSt] 	
	construct newBody [compound_statement_body]
		NewBodyDeclState
	construct newCompStatement [compound_statement]
		{ newBody  }
	import TXLargs [repeat stringlit]
	deconstruct * [stringlit] TXLargs
		something [stringlit]
    construct fuctUntilGraft [function_definition]
        header paramDecls newCompStatement
        
    deconstruct * [repeat function_definition_or_declaration] P
    	ListOfProgrFctDecl [repeat function_definition_or_declaration]
        
    construct localAndGlobalSymbolTable [repeat declaration]
     	_ [constructLocalSymbolTable fuctUntilGraft] [write something]
     	%_ [symbolTableGlobalVars ListOfProgrFctDecl] [constructLocalSymbolTable fuctUntilGraft] [write something]
end rule




function constructBodyUntilGraftPlace V1 [repeat declaration_or_statement]
	replace [repeat declaration_or_statement]
        returnValue [repeat declaration_or_statement]
	deconstruct V1
        First1 [declaration_or_statement] Rest1 [repeat declaration_or_statement]         
	where not
		First1 [containsAGraft]
    by
      returnValue [. First1]
	  [constructBodyUntilGraftPlace Rest1]
end function


function containsAGraft
    match [declaration_or_statement]
        AS [addGraft]
end function
	












	
%construct symbol table for globally defined variables
function symbolTableGlobalVars 	P [repeat function_definition_or_declaration]
    replace [repeat declaration]
        decl [repeat declaration]                 				
    deconstruct P
        First1 [function_definition_or_declaration] Rest1 [repeat function_definition_or_declaration] 
    %construct NewProg [program]
    	%Rest1
	construct newDeclList [repeat declaration]
		decl[constructdeclarationsFromDeclaration First1] 
    by
      newDeclList
	  [symbolTableGlobalVars Rest1]
end function	


function constructdeclarationsFromDeclaration fctOrDecl [function_definition_or_declaration]
	replace [repeat declaration]
		listVar [repeat declaration]
	deconstruct fctOrDecl
		currentDecl [declaration]
	deconstruct currentDecl 
		DeclSpec [decl_specifiers] initDecl [list init_declarator] SemiColoumn [semi]
		
		
	construct currentVarDecl [ declaration]	
		DeclSpec initDecl SemiColoumn
		
	construct testAdd [repeat declaration]
		_ [addNextDecl currentVarDecl]  
		
	construct newDeclList [repeat declaration]
		listVar[addNextDecl currentVarDecl]
	by
		newDeclList
end function		
	
	
%construct symbol table for variables that are defined locally, in the body or the 
%head of the function that contains the target place
function constructLocalSymbolTable P [function_definition]
	replace [repeat declaration]
		P2 [repeat declaration]
	%deconstruct * [function_definition] Ps
	%	justFunctionP [function_definition]
	
	%FIX FOR NOT ADDING DECLARATIONS FROM BLOCKS THAT DO NOT REACH THE TARGET PLACE!!!
	
	
	construct AllIdsInit [repeat declaration]
		_ [^ P] 
	construct AllIds [repeat declaration]
		_ [constructSeparatedDeclarationForEveyVar AllIdsInit]
	construct allIdsFunctionDeclaration [repeat argument_declaration]
		_ [^ P] 
	%add function headers declarations!!!!
	construct justTest [repeat declaration]
		AllIds [argumentDeclToVariableDecl allIdsFunctionDeclaration]
	by
		P2 [. justTest]
end function



%(
function removeUserDefinedTypes	DeclarationList [repeat declaration]
	replace [repeat declaration]
		current [repeat declaration]
		
	deconstruct DeclarationList 
		first [declaration] rest [repeat declaration]
		
	construct justSympleTypes [repeat declaration]
		_ [addJustIfSimpleType first] 
		
	by
		current [. justSympleTypes]
		[removeUserDefinedTypes rest] 
end function


function addJustIfSimpleType	Decl [declaration]
	replace [repeat declaration]
		_ [repeat declaration]
		
		
	by
		_ [. Decl]
end function
)%






function constructSeparatedDeclarationForEveyVar listOfVar [repeat declaration]
	replace [repeat declaration]
		finalLstOfVar [repeat declaration]
	deconstruct listOfVar
        First1 [declaration] Rest1 [repeat declaration]
         
    construct newFinalLstOfVar [repeat declaration]
		finalLstOfVar [addNextDecl First1]
	by
		newFinalLstOfVar
	 	[constructSeparatedDeclarationForEveyVar Rest1]
end function






function hasMacroSpec
	match * [macro_specifier]
		currentMacro [macro_specifier]
end function



%PROBLEM!!!
function addNextDecl currentVarDecl [declaration]
	replace [repeat declaration]
		decl [repeat declaration]
	deconstruct   currentVarDecl
		specT [decl_specifiers] declT [list init_declarator] ';
	where not
		currentVarDecl [hasMacroSpec]
    construct initialVars [repeat declaration]
    	_  [addVarIfJustDeclaration currentVarDecl] 	
    deconstruct specT
		repeatFromDecl [repeat decl_qualifier_or_type_specifier]
	construct removedQualifiers [repeat decl_qualifier_or_type_specifier]
		_ [removeTypeSpecifiers repeatFromDecl] 
	%construct 
	construct newVarDeclSpecifiers [decl_specifiers]
		removedQualifiers 
	%fix here for adding qualifiers also and in the next function!!!
	construct allVars [repeat declaration]
		initialVars [alldeclarationSeparedList newVarDeclSpecifiers declT ] 
	by
		decl [. allVars]
end function
	
	
function addVarIfJustDeclaration	var [declaration]
	replace [repeat declaration]
		varDecl [repeat declaration]
		deconstruct   var
		specT [decl_specifiers] declT [list init_declarator] ';
		deconstruct specT
			repeatFromDeclWithQualifiers [repeat decl_qualifier_or_type_specifier] 
			
			construct repeatFromDecl [repeat decl_qualifier_or_type_specifier]
		_ [removeTypeSpecifiers repeatFromDeclWithQualifiers] 
		%fix here for adding qualifiers also
		
		construct lengthOfRepeat [number]
			_ [length repeatFromDecl]
		construct lengthOfModifiers [number]
			lengthOfRepeat [- 1]
		construct varID [repeat decl_qualifier_or_type_specifier]
			repeatFromDecl [tail lengthOfRepeat]
		construct typesModifiers [repeat decl_qualifier_or_type_specifier]
			repeatFromDecl [head lengthOfModifiers]
		construct typesModifiersDeclSpec [decl_specifiers]
			typesModifiers
		deconstruct * [decl_qualifier_or_type_specifier] varID
			varIdEl [decl_qualifier_or_type_specifier]
		construct varStringlit [stringlit]
			_ [quote varIdEl]
		construct varIdAsID [id]
			_ [unquote varStringlit]
		construct varDeclsss [declarator]
			varIdAsID
		construct varInitDeclarator [init_declarator]
			varDeclsss
		construct varListInitDecl [list init_declarator]
			_ [, varInitDeclarator]
		construct varDeclaration [declaration]
			typesModifiersDeclSpec varListInitDecl '; 
		%needed for checking if not macro specifier in initial variable; otherwise it will be seen as declarator
		construct testT [repeat decl_qualifier_or_type_specifier]
			_ [removeTypeSpecifiers repeatFromDecl]
		construct newVarDeclSpecifiers [decl_specifiers]
			testT	
		construct newVar [declaration]
			newVarDeclSpecifiers ';
	where not
		declT [hasDecl]
	where not
		newVar [checkForMacroSpecifier]
	by
		varDecl [.varDeclaration]	
end function	


	

rule checkForMacroSpecifier
	match [any]
		macroSpec [any]
	deconstruct * [macro_specifier]	macroSpec
		MSpec [macro_specifier]
end rule


function hasDecl
	match * [list init_declarator]
		AS [init_declarator]
end function
 
	


function alldeclarationSeparedList	specifier [decl_specifiers]
											declList [list init_declarator]
	replace [repeat declaration]
		variableDeclList [repeat declaration]
		
	
	deconstruct * [init_declarator] declList
		First [init_declarator] 
	construct Rest [list init_declarator]
		declList [tail 2]	
	
	deconstruct * [declarator] First
		currentDeclarator [declarator]

	construct newVarDecl [declaration]
		specifier currentDeclarator ';
	by
		variableDeclList [. newVarDecl]
		[alldeclarationSeparedList specifier Rest]
end function
	
	

%functions for adding variables from function header into declaration List	
function argumentDeclToVariableDecl argDecl [repeat argument_declaration]
	replace [repeat declaration]
		varDecl [repeat declaration]
	deconstruct argDecl
		first [argument_declaration] rest [repeat argument_declaration]	
	deconstruct first	
		declSpec [decl_specifiers] argDeclarator [opt argument_declarator]     	
	%construct declar [declaration]
		%declSpec   ';			
	%again, make this too [decl_specifiers] [list init_declarator] [semi], for easier extraction
		deconstruct declSpec
			repeatFromDecl [repeat decl_qualifier_or_type_specifier] 
		construct lengthOfRepeat [number]
			_ [length repeatFromDecl]
		construct lengthOfModifiers [number]
			lengthOfRepeat [- 1]
		construct varID [repeat decl_qualifier_or_type_specifier]
			repeatFromDecl [tail lengthOfRepeat]
		construct typesModifiers [repeat decl_qualifier_or_type_specifier]
			repeatFromDecl [head lengthOfModifiers]
		construct typesModifiersDeclSpec [decl_specifiers]
			typesModifiers
		deconstruct * [decl_qualifier_or_type_specifier] varID
			varIdEl [decl_qualifier_or_type_specifier]
		construct varStringlit [stringlit]
			_ [quote varIdEl]
		construct varIdAsID [id]
			_ [unquote varStringlit]
		construct varDeclsss [declarator]
			varIdAsID
		construct varInitDeclarator [init_declarator]
			varDeclsss
		construct varListInitDecl [list init_declarator]
			_ [, varInitDeclarator]
		construct varDeclaration [declaration]
			typesModifiersDeclSpec varListInitDecl '; 	
	construct FinalDeclar [declaration]
		varDeclaration [variableFromArgWithOpt first]		
	by
		varDecl [. FinalDeclar]
		[argumentDeclToVariableDecl rest]
end function
	
	
function variableFromArgWithOpt Arg [argument_declaration]
	replace [declaration]
		var [declaration]
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
	construct declar [declaration]
		newVarDeclSpecifiers declForArg  ';
	by
		declar
end function


%remove qualifiers as const, static, etc
function removeTypeSpecifiers	v1 [repeat decl_qualifier_or_type_specifier]
	replace [repeat decl_qualifier_or_type_specifier]
		varSpec [repeat decl_qualifier_or_type_specifier]
	deconstruct v1
		first [decl_qualifier_or_type_specifier] rest [repeat decl_qualifier_or_type_specifier] 
	construct finalDeclOrSpec [repeat decl_qualifier_or_type_specifier]
		_ [addJustIfTypeSpec first]
	by
		varSpec [.finalDeclOrSpec]
		[removeTypeSpecifiers rest]
end function


function addJustIfTypeSpec	V1 [decl_qualifier_or_type_specifier]
	replace [repeat decl_qualifier_or_type_specifier]
		declOrType [repeat decl_qualifier_or_type_specifier]
		
	deconstruct not * [cv_qualifier] V1
		notCV [cv_qualifier]
	deconstruct not * [sc_specifier] V1
		notSC [sc_specifier]
	%deconstruct not * [struct_or_union_specifier] V1
		%notStructUnion [struct_or_union_specifier]
	by
		declOrType [. V1]
end function





