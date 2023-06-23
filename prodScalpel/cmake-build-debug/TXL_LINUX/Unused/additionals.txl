%construct all source code of the program, for later usage
function constructAllSourceCode SourceCodeFiles [repeat stringlit]
	replace [repeat function_definition_or_declaration]
		ListOfSourceCode [repeat function_definition_or_declaration]
	deconstruct SourceCodeFiles 
		first [stringlit] rest [repeat stringlit]
	construct currentProgram [repeat function_definition_or_declaration]
		_[read first]
	by
		ListOfSourceCode [. currentProgram]
		[constructAllSourceCode rest]
		
end function


function identifyFunctionsNameFromList	V1 [repeat function_definition_or_declaration] SourceCode [repeat stringlit]
										AllIdList [repeat id]
	replace [repeat id]
		currentIdList [repeat id]		
	construct currendAndAllIdsList [repeat id]
		AllIdList [.currentIdList]	
	deconstruct V1
		first [function_definition_or_declaration] rest [repeat function_definition_or_declaration]
	construct newIdList [repeat id]
		currentIdList [addNextFctIfCase currendAndAllIdsList first SourceCode]
 
	by 
		newIdList
		[identifyFunctionsNameFromList rest SourceCode AllIdList]
end function

function addNextFctIfCase	ListOfAllIds [repeat id] NextFct [function_definition_or_declaration] SourceCode [repeat stringlit]
	replace [repeat id]
		currIdList [repeat id]
	deconstruct * [declarator] NextFct
		HeaderOfF [declarator]
	deconstruct * [id] HeaderOfF
		idOfFct [id]
	where not
		ListOfAllIds [fctNameInIDsList idOfFct]
	by
		currIdList [. idOfFct]
		
end function










define simple_type_name
	'char
    |   'int
    |   'void
    |   'float
    |   'double
   % |   [type_id]
end define

function constructListOfCalledFromFunction FunctionID [id] SourceCode [repeat stringlit]
	replace [repeat id]
		current [repeat id]
	construct repeatIDs [repeat id]
		FunctionID
	construct testing [repeat function_definition_or_declaration]
		_ [addIDFromFiles SourceCode repeatIDs]
	by
		current
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



function addNextDeclLocal currentVarDecl [variableDeclaration]
	replace [repeat variableDeclaration]
		decl [repeat variableDeclaration]

	deconstruct  currentVarDecl
		specT [decl_specifiers] declT [list init_declarator] ';
	construct allVariableDeclarationSeparedList [repeat variableDeclaration]
		_ [allVariableDeclarationSeparedList specT declT]
	by
		decl [. allVariableDeclarationSeparedList]
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



function addDeclOrStatement decl [declaration_or_statement]
	replace [repeat declaration_or_statement]
		listDeclStatement [repeat declaration_or_statement]
	where not
		decl [containsAGraft]
	by
		listDeclStatement [.decl]
end function





rule findGraftPosition
	replace [addGraft]
		gg [addGraft]
		
	construct something [stringlit]
		"/Users/margineanalexandru/Documents/workspace/Transplants/input/stringLength.c"

    construct P2 [program]
               _[read something]
               
    deconstruct P2
        fct_body [function_definition]
        
    deconstruct fct_body
        headerG [function_header] paramDeclsG [opt KR_parameter_decls] statementCompG [compound_statement]
	by
		compund_statement
		
end rule


function replaceInFunctionDeclaration 	V1 [program] 
                   					
    deconstruct V1
        First1 [function_definition_or_declaration] Rest1 [repeat function_definition_or_declaration]
    construct Message [id]
        _ [message First1]
        
    construct NewProg [program]
    	Rest1
        
     construct Message2 [id]
        _ [message "-------------------------"]
           
        
    replace [program]
        prog [program]
   % where 
    %	Rest1 [>First1]
    by
      NewProg
	  [replaceInFunctionDeclaration NewProg]
end function


function compareProgs FileName [stringlit]
					  OriginalProg [program]	
	construct something [stringlit]
		"/Users/margineanalexandru/Documents/workspace/Transplants/input/stringLength.c"
	construct testPP [program]
		OriginalProg
    construct P2 [program]
               _[read something]
               
    
    deconstruct P2
        elements2 [repeat function_definition_or_declaration]
    deconstruct testPP
    	el33 [function_definition_or_declaration] elements1 [repeat function_definition_or_declaration]
    
    	
     %deconstruct testPP
      %  elements1 [repeat function_definition_or_declaration]   %addGG [addGraft] el3 [repeat function_definition_or_declaration]
    	
    	
    %deconstruct * [function_definition_or_declaration]testPP
     %   elements1 [id]   
        
	% elements1 [function_definition_or_declaration]
	%replace  [repeat program]
	%	P [repeat program]
	%by
	%	P2 [. testPP]
		construct Message [id]
               _ [message elements1]
	replace [program]
		P [program]	
	by
        testPP
		

end function

% Simple normalization rule -
% just make all identifiers the same 
rule normalize
	replace [id] 
		Id [id]
	% don't go on forever! 
	deconstruct not Id
		'x
	by
		'x
end rule



rule replaceVarName
    replace [id]
    	AddGraftHere
    by
		testResultString
end rule