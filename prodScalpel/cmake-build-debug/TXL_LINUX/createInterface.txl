include "cOriginal.grm"


define addGraft
	__ADDGRAFTHERE__JUSTHERE [NL]
end define


define interfaceFunction
	__INTERFACE_FUNCTION [NL]
end define

define declaration_or_statement_markers
	[declaration_or_statement] 
	| [stringlit] [NL]
end define

redefine declaration_or_statement
	[declaration] 
    |	[statement] 
    |	[addGraft]
    |	[interfaceFunction]
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
	|	[interfaceFunction]

#ifdef PREPROCESSOR
    |	[preprocessor]
#endif
    |	[compound_statement] [NL]	% sometimes, function headers are ifdefed out
#ifdef GNU
    |	[macro_declaration_or_statement]
#endif
    |	[unknown_declaration_or_statement]
end redefine


define decl_specifiers_and_declarator
	[decl_specifiers] [declarator]
end define









function main
	match [program]
			P[program]
			
	import TXLargs [repeat stringlit]
	deconstruct  TXLargs
		GraftProgramPath [stringlit]
		GraftFunctionName [stringlit] InterfaceName [stringlit] VariableInHostName [stringlit] ArgumentsFilePath [stringlit] 
		OutputFilePath [stringlit] InterfaceHeaderName [stringlit] JustInterfaceName [stringlit] HostTransplantSourceFile [stringlit]
		ifDefsPath [stringlit]	
		
	construct programNoIfDefs [program]
		_ [removeIFDefs GraftProgramPath ifDefsPath]	
			
	construct newP[program]
		programNoIfDefs[identifyFunctionThatContainsTheGraft P] 
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



function identifyFunctionThatContainsTheGraft P [program]
	match * [function_definition]
		myF [function_definition]
	import TXLargs [repeat stringlit]
	deconstruct  TXLargs
		GraftProgramPath [stringlit]
		GraftFunctionName [stringlit] InterfaceName [stringlit] VariableInHostName [stringlit] ArgumentsFilePath [stringlit] 
		OutputFilePath [stringlit] InterfaceHeaderName [stringlit] JustInterfaceName [stringlit] HostTransplantSourceFile [stringlit]
		ifDefsPath [stringlit]
		
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
       	
       	
       			
		%extract includes from host file	
		construct hostP [program]
			_ [read HostTransplantSourceFile]
		
		deconstruct * [repeat function_definition_or_declaration] hostP
			fctDeclFromHost [repeat function_definition_or_declaration]
		
		construct justIncludeLybrariesFromHost [repeat function_definition_or_declaration]
			_ [extractIncludeLibraries fctDeclFromHost]
		%END extract includes from host file
       	
       	
       	construct newInterfaceID [id]
       		_ [unquote InterfaceName]
		construct FunctionsSymbols [repeat decl_specifiers_and_declarator]
			_ [determineReturnValues myF newInterfaceID] 
		deconstruct * [decl_specifiers_and_declarator] FunctionsSymbols
			CalledFunctionRet [decl_specifiers_and_declarator]	
		deconstruct CalledFunctionRet
			interfaceDeclSpec [decl_specifiers] interfaceDeclarator [declarator] 
		construct interfaceArgsList [list argument_declaration] 
			_ [read ArgumentsFilePath]
		construct interfaceDeclExtTest[function_declarator_extension]
			'( interfaceArgsList ')		
		construct interfaceDeclExt[function_declarator_extension]
			'( ')	
		construct interfaceFunctionHeaderTest [function_header]
			interfaceDeclSpec interfaceDeclarator interfaceDeclExtTest
		construct interfaceFunctionHeader [function_header]
			interfaceDeclSpec interfaceDeclarator interfaceDeclExt
			
			
			
			
		construct interfaceMark [interfaceFunction]
			__INTERFACE_FUNCTION	
		construct interfaceDecl [declaration_or_statement]
			interfaceMark	
		construct interfaceCompStatementBody [compound_statement_body]
			interfaceDecl
		construct interfaceCompoundStatement [compound_statement]
			'{  interfaceCompStatementBody '}
		construct interfaceCompleteFunctionDefinition [function_definition]
			interfaceFunctionHeaderTest interfaceCompoundStatement
		construct interfaceCompleteFunctionDefinitionTest [function_definition]
			interfaceFunctionHeaderTest interfaceCompoundStatement
			
			
			
			
			
		construct callToTheInterface [repeat function_definition]
			_ [headerToFunctionCall interfaceFunctionHeaderTest interfaceArgsList interfaceCompleteFunctionDefinition VariableInHostName] 
       	
       	
       	
       	
       	
       	deconstruct * [function_definition] callToTheInterface
       		firstCallToTheInterface [function_definition]
       	
       	
       	construct headerMarkIncl [stringlit]
       		"#include"
       	
       	%HeaderName
       	construct interfaceHeader [stringlit]
       		headerMarkIncl [+ " \""] [+ JustInterfaceName] [+ "\""]
			%"#include \"TransplantCode/InterfaceHeader.h\""
		construct preprocLineTransplantHeader [preprocessor_line]
		_ [unquote interfaceHeader]
       	
       	
       	
       	construct headerFctDefOrDecl [function_definition_or_declaration]	
       		preprocLineTransplantHeader
       	
       	construct interfaceCompleteFctDefOrDecl [function_definition_or_declaration]
       		interfaceCompleteFunctionDefinition
       		
       	construct callToTheInterfaceFctDeforDecl [function_definition_or_declaration]
       		firstCallToTheInterface
       	
       	
       	
       	
       	%construct header File
       	construct functionHeaderStringlitTest [stringlit]
      		_ [quote interfaceFunctionHeaderTest]
       	construct functionHeaderStringlit [stringlit]
      		_ [quote interfaceFunctionHeader]
      	 construct functionHeaderDeclarationTest [stringlit]	
       		functionHeaderStringlitTest [+ ";"] 
       	construct functionHeaderDeclaration [stringlit]	
       		functionHeaderStringlit [+ ";"] 

       	construct interfaceHeaderIDDeclTest [id]
       		_ [unquote functionHeaderDeclarationTest]	
       	construct interfaceHeaderIDDecl [id]
       		_ [unquote functionHeaderDeclaration]	
	
	
       		
       	construct printHeaderFileInterface [repeat function_definition_or_declaration]
       		justIncludeLybrariesFromHost [fput InterfaceHeaderName]
       		
       			
       	construct printfctHeaderDeclStmGraftInt [id]
       			interfaceHeaderIDDeclTest [fput InterfaceHeaderName]
       	

       	
       	
       	
       	construct finalFunctionsForInterface [repeat function_definition_or_declaration]
       		_ [. headerFctDefOrDecl] [. interfaceCompleteFctDefOrDecl] [. callToTheInterfaceFctDeforDecl]		
       	construct writeToFile [repeat function_definition_or_declaration]
       		finalFunctionsForInterface [write OutputFilePath]
end function



function extractIncludeLibraries	ProgramCode [repeat function_definition_or_declaration]
	replace [repeat function_definition_or_declaration]
		current [repeat function_definition_or_declaration]
	
	deconstruct ProgramCode 
		first [function_definition_or_declaration] rest [repeat function_definition_or_declaration]
	
	construct addPreproc [repeat function_definition_or_declaration]
		_ [addJustLibrary first]
		
	by
		current [. addPreproc]
		[extractIncludeLibraries rest]
end function

function addJustLibrary	FctOrDecl [function_definition_or_declaration]
	replace [repeat function_definition_or_declaration]
		_ [repeat function_definition_or_declaration]
		
	deconstruct * [preprocessor] FctOrDecl
		preprocStm [preprocessor]
		
	construct stringPreproc [stringlit]
		_ [quote preprocStm]
		
	where
		stringPreproc [grep "include <"]
		
	by
		_ [. FctOrDecl]
end function















function containsAGraft
    match * [declaration_or_statement]
        AS [addGraft]
end function


function headerToFunctionCall	FunctionHeader [function_header]
								ListOfSymbols [list argument_declaration]
								InterfaceDefinition [function_definition]
								NewVarInHostName [stringlit]
	replace [repeat function_definition]
		current [repeat function_definition]
	deconstruct * [base_declarator] FunctionHeader
		FunctionNameBaseDecl [base_declarator]	
	construct FunctionName [stringlit]
		_ [quote FunctionNameBaseDecl]% [+ " ( "]	
	construct testArgToDecl [repeat declaration]
		_ [argumentDeclToVariableDeclRemoveHostAnnotations ListOfSymbols]
	construct baseDeclFromArgs [repeat base_declarator]
		_ [^ testArgToDecl] 
	construct ListOfBaseDecl [list base_declarator]
        _ [, each baseDeclFromArgs][print]	
	construct ListOfArguments [stringlit]
		_ [quote ListOfBaseDecl]
	construct FunctionCall [stringlit]
		FunctionName [+ " ( "] [+ ListOfArguments] [+ " )"] 
	construct fctCallID [id]
		_ [unquote FunctionCall]
	construct MacroCall [macro_name]	
		fctCallID	
	construct voidSpecifier [decl_qualifier_or_type_specifier]
		void
	construct declSpecifier [decl_specifiers]
		voidSpecifier
	construct functionCallDecl [declarator]
		main	
	construct functionHeader [function_header]
		declSpecifier functionCallDecl '( ')	
	construct graftMark [addGraft]
		__ADDGRAFTHERE__JUSTHERE	
	construct graftDecl [declaration_or_statement]
		graftMark	
	construct hostID [id]
		_ [unquote NewVarInHostName]
	construct NewVarTypes [repeat decl_specifiers_and_declarator]
		_ [determineReturnValues InterfaceDefinition hostID]
	deconstruct * [decl_specifiers_and_declarator] NewVarTypes
		ElForDeclarations [decl_specifiers_and_declarator]
	deconstruct ElForDeclarations
		declSpec [decl_specifiers] newDecl [declarator]	
	construct NewDeclaration [declaration]
		declSpec newDecl ';
	construct newDeclOrStm [declaration_or_statement]
		NewDeclaration
	construct attributionStm [stringlit]
		NewVarInHostName [+ " = "] [+ FunctionCall]
	construct functionToken [token]
		_ [unquote attributionStm]% ';	
	construct functionUnknownItem [unknown_item]
		functionToken
	construct functionCallUnknownDecl [unknown_declaration_or_statement]	
		functionUnknownItem ';	
	construct functionCallDeclStatement [declaration_or_statement]
		functionCallUnknownDecl			
	construct graftDeclRepeat [repeat declaration_or_statement]
		_ [. graftDecl]	[.newDeclOrStm] [. functionCallDeclStatement] 				
	construct compoundBody [compound_statement_body]
		graftDeclRepeat	
	construct compoundStatement [compound_statement]
		'{ compoundBody  '}	
	construct functionCallCompleteFunction [function_definition]
			functionHeader compoundStatement	
	by
		_ [. functionCallCompleteFunction]		
end function


%functions for adding variables from function header into declaration List	
function argumentDeclToVariableDeclRemoveHostAnnotations argDecl [list argument_declaration]
	replace [repeat declaration]
		varDecl [repeat declaration]
	deconstruct argDecl
		first [argument_declaration] , rest [list argument_declaration]	
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
		% Remove the host label, so the first 7 characters
		%construct varStringNoHostLabel [stringlit]
		%	varStringlit [: 8 999]
		
		construct varIdAsID [id]
			_ [unquote varStringlit]
		construct varDeclsss [declarator]
			varIdAsID
			
		% Remove the host label, so the first 7 characters	
		construct declaratorRemovedHostLabel [declarator]	
			varDeclsss [removeHostLabelFromDeclaration]
			
		construct varInitDeclarator [init_declarator]
			declaratorRemovedHostLabel
		construct varListInitDecl [list init_declarator]
			_ [, varInitDeclarator]
		construct varDeclaration [declaration]
			typesModifiersDeclSpec varListInitDecl '; 	
	construct FinalDeclar [declaration]
		varDeclaration [variableFromArgWithOpt first]		
	by
		varDecl [. FinalDeclar]
		[argumentDeclToVariableDeclRemoveHostAnnotations rest]
end function
	
	
function variableFromArgWithOpt Arg [argument_declaration]
	replace [declaration]
		var [declaration]
	deconstruct Arg	
		declSpec [decl_specifiers] argDeclarator [opt argument_declarator]
	deconstruct declSpec
		repeatFromDecl [repeat decl_qualifier_or_type_specifier]
		
	construct testT [repeat decl_qualifier_or_type_specifier]
		repeatFromDecl % _ [removeTypeSpecifiers repeatFromDecl]
		
	construct newVarDeclSpecifiers [decl_specifiers]
		testT
	deconstruct *[declarator] argDeclarator
		declForArg [declarator]
		
	% Remove host labels
	construct declForArgNoHostLabel [declarator]
		declForArg [removeHostLabelFromDeclaration]
	
	construct initDeclForLst [init_declarator]
		declForArgNoHostLabel
	construct declar [declaration]
		newVarDeclSpecifiers declForArgNoHostLabel  ';
	by
		declar
end function

rule removeHostLabelFromDeclaration
	replace $ [reference_id]
		current [reference_id]
	deconstruct * [id] current
		currentId [id]
	construct currentStringlit [stringlit]
		_ [quote currentId]
		
	where
		currentStringlit [grep "$_host_"]	
		
	construct currentStringNoLabel [stringlit]
		currentStringlit [: 8 999]
	construct currentIdNoLabel [id]
		_ [unquote currentStringNoLabel]
	construct currentRefIdNoLabel [reference_id]
		currentIdNoLabel
		
	by
		currentRefIdNoLabel
end rule


%retrieve return values:
function determineReturnValues	GraftFunctionDefinition [function_definition]
								InterfaceID [id]
	replace [repeat decl_specifiers_and_declarator ]
		current [repeat decl_specifiers_and_declarator]
	deconstruct * [function_header] GraftFunctionDefinition
		fctHead [function_header]
	deconstruct * [function_declarator_extension] fctHead
		fctDeclExtention [function_declarator_extension]		
	deconstruct * [declarator] fctHead
		currentDeclarator [declarator]
	deconstruct * [decl_specifiers] fctHead
		currentSpecifiers [decl_specifiers]	
  	deconstruct currentDeclarator
     	ptrOperator [repeat ptr_operator] oldBaseDeclarator [base_declarator] declExtentsion [repeat declarator_extension] 
     construct newReferenceID [reference_id]
     	InterfaceID	
 	construct newBaseDeclarator [base_declarator]
 		newReferenceID
	construct newFunctionDeclarator [declarator]
		ptrOperator newBaseDeclarator
	construct declSpecAndDeclarator [decl_specifiers_and_declarator]	
		currentSpecifiers newFunctionDeclarator
	by
		current [. declSpecAndDeclarator]
end function