include "CGraft.grm"


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
 	construct globalSymbolTable [repeat variableDeclaration]
     	_[symbolTableGlobalVars p] [write something]
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
    construct localAndGlobalSymbolTable [repeat variableDeclaration]
     	_[symbolTableGlobalVars P] [constructLocalSymbolTable fuctUntilGraft] [write something]
    construct Message [id]
        _ [message localAndGlobalSymbolTable] 
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
	  returnValue [constructBodyUntilGraftPlace Rest1]
end function


function containsAGraft
    match [declaration_or_statement]
        AS [addGraft]
end function
	
	
%construct symbol table for globally defined variables
function symbolTableGlobalVars 	P [program]
    replace [repeat variableDeclaration]
        decl [repeat variableDeclaration]                 				
    deconstruct P
        First1 [function_definition_or_declaration] Rest1 [repeat function_definition_or_declaration] 
    construct NewProg [program]
    	Rest1
	construct newDeclList [repeat variableDeclaration]
		decl[constructVariableDeclarationsFromDeclaration First1]
    by
      newDeclList
	  [symbolTableGlobalVars NewProg]
end function	


function constructVariableDeclarationsFromDeclaration fctOrDecl [function_definition_or_declaration]
	replace [repeat variableDeclaration]
		listVar [repeat variableDeclaration]
	deconstruct fctOrDecl
		currentDecl [declaration]
	deconstruct currentDecl 
		currentVarDecl [ variableDeclaration]
		
	construct newDeclList [repeat variableDeclaration]
		listVar[addNextDecl currentVarDecl]
	by
		newDeclList
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