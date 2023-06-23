include "cOriginal.grm"

redefine upper_macro_name
   [upperlowerid] 
end redefine


redefine program
	...
	|	[repeat stringlit]
end redefine


define function_definition_output
	[id] [stringlit] [NL]
end define


function main
	match * [program]
		P [program]
		
	import TXLargs [repeat stringlit]
	deconstruct TXLargs
		outputFile [stringlit] fixIfDefProg [stringlit]
		
	deconstruct P
		listOfFiles [repeat stringlit]
	
	construct listOfFunctionNames [repeat function_definition_output]
		_ [extractFunctionNames listOfFiles fixIfDefProg]
		
	construct printList [repeat function_definition_output]
		listOfFunctionNames [write outputFile]
end function


function extractFunctionNames	ListOfFiles [repeat stringlit]
								FixIfDefProg [stringlit]
	replace [repeat function_definition_output]
		current [repeat function_definition_output]
	deconstruct ListOfFiles
		first [stringlit] rest [repeat stringlit]
	construct nonIfDefsOutput [stringlit]
		first [+ "NONExt"]
	construct commandForNonIf [stringlit]
		_ [+ FixIfDefProg] [+ " "] [+ first] [+ " "] [+ first]  [+ " "]  [+ nonIfDefsOutput]
	construct CallCommand2 [id]
    	_ [system commandForNonIf]
	construct ProgramSource [repeat program]
		_ [read nonIfDefsOutput] 
	
	construct functionHeadersList [repeat function_header]
		_ [^ ProgramSource]
		
	construct newDefinedFunctions [repeat function_definition_output]
		_ [extractFunctionsFromAListOfHeaders functionHeadersList first]
	
	by
		current	[. newDefinedFunctions]
		[extractFunctionNames rest FixIfDefProg]
end function


function extractFunctionsFromAListOfHeaders	FunctionHeaders [repeat function_header]
											FunctionSourceFileName [stringlit]
	replace [repeat function_definition_output]
		current [repeat function_definition_output]
	deconstruct FunctionHeaders 
		first [function_header] rest [repeat function_header]
	deconstruct * [base_declarator] first
		currentBaseDecl [base_declarator]
	construct baseDeclID [id]
		_ [reparse currentBaseDecl]
	construct newFctDefinitionOutput [function_definition_output]
		baseDeclID FunctionSourceFileName
	by
		current [. newFctDefinitionOutput]
		[extractFunctionsFromAListOfHeaders rest FunctionSourceFileName]
end function