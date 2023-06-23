include "cOriginal.grm"

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%This program will extract all the symbol table from the graft function definition					 %	
%it receives as a parameter the graft function name and file										 %
%and will return all the variables in the graft function header declaration							 %
%that should be tried for mappings																	 %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%GRAMMAR DEFINITIONS

define functionLocalAndGlobalSymbolTable
	[function_name] ': [NL] [repeat declaration]
end define

define function_name 
	[id]
end define

%END GRAMMAR DEFINITIONS
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%



%transformation rules

function main
	match [program]
			P[program]
			
	import TXLargs [repeat stringlit]
	deconstruct TXLargs
		graftFunctionName [stringlit]  outputFile [stringlit] fixIfDefProg [stringlit] ProgramPath [stringlit]
	
	
	construct PNoIfDefs [program]
		_ [removeIFDefs ProgramPath fixIfDefProg]
	

			
	construct newP[program]
		PNoIfDefs[identifyFunctionThatContainsTheGraft graftFunctionName outputFile] 
end function



function removeIFDefs	ProgramPath [stringlit]
						fixIfDefProg [stringlit]
	replace [program]
		P [program]
	construct nonIfDefsOutput [stringlit]
		ProgramPath [+ "NON"]					
	construct commandForNonIf [stringlit]
		_ [+ fixIfDefProg] [+ " "] [+ ProgramPath] [+ " "] [+ ProgramPath]  [+ " "]  [+ nonIfDefsOutput]
	construct CallCommand2 [id]
    	_ [system commandForNonIf]
	construct outputFileCompleteName [stringlit]
		_ [+ nonIfDefsOutput]
	construct ProgramSource [program]
		_ [read outputFileCompleteName]
	by
		ProgramSource
end function



function identifyFunctionThatContainsTheGraft	GraftFunctionName [stringlit]
												OutputFile [stringlit]
	match * [function_definition]
		myF [function_definition]
		
		
	deconstruct * [function_header] myF
		currentFunctionHeader [function_header]	
	deconstruct * [base_declarator] currentFunctionHeader
		currentBaseDecl [base_declarator]
	construct baseDeclID [id]
		_ [reparse currentBaseDecl]
	construct baseDeclStringLit [stringlit]
		_ [quote baseDeclID]
    where
       	baseDeclStringLit [= GraftFunctionName]
       	
       	construct graftFinalSymbolTable [repeat declaration]
     		_ [constructGraftSymbolTable myF] 
     	construct writeSymbolTable [repeat declaration]
     		graftFinalSymbolTable [write OutputFile]
end function


function constructGraftSymbolTable P [function_definition]
	replace [repeat declaration]
		P2 [repeat declaration]
	construct allIdsFunctionDeclaration [repeat argument_declaration]
		_ [^ P] 
	construct justTest [repeat declaration]
		_ [argumentDeclToVariableDecl allIdsFunctionDeclaration]
	by
		P2 [. justTest]
end function

function argumentDeclToVariableDecl argDecl [repeat argument_declaration]
	replace [repeat declaration]
		varDecl [repeat declaration]
	deconstruct argDecl
		first [argument_declaration] rest [repeat argument_declaration]	
	deconstruct first	
		declSpec [decl_specifiers] argDeclarator [opt argument_declarator]     	
	construct declar [declaration]
		declSpec   ';			
	construct FinalDeclar [declaration]
		declar [variableFromArgWithOpt first]		
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
	deconstruct  V1
		typeSpec [type_specifier]
	by
		declOrType [. V1]
end function
