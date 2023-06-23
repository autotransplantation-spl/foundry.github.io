include "cOriginal.grm"

tokens
	%idd "\u\i*"
	end_source_files_mark "______________________________"
	end_call_graph_marker "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"
	current_function "^^\i+^^"
	
		%source_file_element3 "\i+/.\i+"
	
	
	source_file_element "@@\i*.\i*@@"
	source_file_token "source_file:"

end tokens

%redefine program
%	[reverse_call_graph]
%end redefine


redefine program
    [compilation_unit]
    |	[list argument_declaration]
    |	[reverse_call_graph]
end redefine

define reverse_call_graph
	[source_files] [NL][current_function] [NL] [repeat graph]
end define

define source_files
	[repeat source_file_element] [NL] [end_source_files_mark] [NL] [NL]
end define

define graph
	[repeat graph_entry] [end_call_graph_marker] [NL]
end define

define graph_entry
	[id] [source_file_token] [source_file_element] [NL]
end define


tokens
	endMarker ">>>>>>>>>"
end tokens


define declaration_or_statement_markers
	[declaration_or_statement] 
	| [stringlit] [NL]
end define

define ids_with_line_break
	[id] [NL]
end define


define function_for_transplant
	[opt function_for_transplant_name] [NL] [repeat ids_with_line_break]  [end_call_graph_marker] [NL]
end define

define function_for_transplant_name
	[id]
end define



define return_structure
	[function_name_return] [return_type] [return_variable]
end define

define function_name_return
	[stringlit]
end define

define return_type
	[stringlit]
end define

define return_variable
	[stringlit]
end define



%symbol table grammar definitions

%(
define symbol_table
	[function_name] [repeat argument_symbol] [repeat variable_symbol]
end define

define function_name
	[stringlit]
end define

define argument_symbol
	
end define
)%



















function main
	match [program]
		P [program]
		

	import TXLargs [repeat stringlit]
	deconstruct TXLargs
		first [stringlit] rest [repeat stringlit]
	export LineNumber [number]
		1
	
	
	construct theCallGraph [program]
		_ [read first] 
		
	deconstruct * [reverse_call_graph] theCallGraph
		 CallGraph [reverse_call_graph]
		
	construct newP [reverse_call_graph]
		CallGraph [constructNewGPFunctions]
end function




function constructNewGPFunctions
	replace [reverse_call_graph]
		P [reverse_call_graph]
		
		
	
	deconstruct * [reverse_call_graph] P
		CallGraphOfProgram [reverse_call_graph]
	
	deconstruct * [repeat graph] CallGraphOfProgram
		listOfCallGraphs [repeat graph]
	
	deconstruct listOfCallGraphs
		first [graph] rest [repeat graph]
		
	deconstruct * [repeat graph_entry] first
		ListOfGraphEntries [repeat graph_entry]
		
		
		
	%construct current function as a graph entry	
	deconstruct * [current_function] CallGraphOfProgram
		currentFunctionToken [current_function]
		
	construct currentFunctionTokenString [stringlit]
		_ [quote currentFunctionToken]
	construct lengthCFT [number]
		_ [# currentFunctionTokenString] [- 2]
	
	construct currentFunctionString [stringlit]
		currentFunctionTokenString [: 3 lengthCFT] 
	construct currentFunctionID [id]
		_ [unquote currentFunctionString]
	construct SourceFileTok	[source_file_token] 
		'source_file:
	construct SourceFileElTok [source_file_element]	
		'@@dct.c@@
	construct currentFctGraphEntry [graph_entry]
		currentFunctionID SourceFileTok SourceFileElTok 
		
		
		
		
	deconstruct ListOfGraphEntries
		firstEntry [graph_entry] calledEntries [repeat graph_entry]
	construct ListOfCalledEntries [repeat graph_entry]
		calledEntries [. currentFctGraphEntry]
				construct msmsss [repeat graph_entry]
			ListOfCalledEntries 
		
		
		
		
		
		
		
		
		
		
	%write the functions for GP
	construct Candidate [repeat function_for_transplant]
		_ [writeACandidate ListOfGraphEntries ListOfCalledEntries] [print] [write "outputFCTLOCS!!!.out"]
	by
		P
		
end function





function writeACandidate	ListOfGraphEntries [repeat graph_entry]
							ListOfCalledEntries [repeat graph_entry]
	replace [repeat function_for_transplant]
		current [repeat function_for_transplant]
	deconstruct ListOfGraphEntries
		first [graph_entry] rest [repeat graph_entry]
		
		
		
	%current called for marking in the formatted function
	deconstruct ListOfCalledEntries
		currentCalled [graph_entry] restCalled [repeat graph_entry]
	deconstruct * [id] currentCalled
		currentCalledID [id]
	construct currentCalledString [stringlit]
		_ [quote currentCalledID]
	deconstruct first
		fctName [id] srcToken [source_file_token] SourceFileName [source_file_element] 
	construct inputFileName [stringlit]
		_ [quote SourceFileName]
	construct path [stringlit]
		"input/"	
	construct lengthOfFileName [number]
		_ [# inputFileName] [- 2]
	construct inputFilNameNoMarks [stringlit]
		inputFileName [: 3 lengthOfFileName]
	construct CompleteFileName [stringlit]
		path [+ inputFilNameNoMarks] 
	construct nonIfDefsOutput [stringlit]
		CompleteFileName [+ "NON"]
	construct commandForNonIf [stringlit]
		_ [+"./ifdef.x "] [+ CompleteFileName] [+ " "] [+ CompleteFileName]  [+ " "] [+ "/home/alex/workspace/Transplants/"] [+ nonIfDefsOutput]
	construct CallCommand2 [id]
    	_ [system commandForNonIf]
	construct outputFileCompleteName [stringlit]
		_ [+ "/home/alex/workspace/Transplants/"] [+ nonIfDefsOutput]
	construct ProgramSource [repeat program]
		_ [read outputFileCompleteName] 
	deconstruct * [repeat function_definition_or_declaration] ProgramSource
		ProgramFunctions [repeat function_definition_or_declaration]
	construct StringFctName [stringlit]
		_ [quote fctName] 
	construct NeededFunction [repeat function_definition_or_declaration]
		ProgramFunctions [extractNeededFunction StringFctName]
	import FunctionDefinitionHost [function_definition_or_declaration]
	
	
	
	
	%construct symbol table and abstract the function definition
	construct functionName [stringlit]
		StringFctName 
    construct localAndGlobalSymbolTable [repeat declaration]
     	_ [constructLocalSymbolTable FunctionDefinitionHost] 
	construct listOfBaseDeclarators [repeat base_declarator]
		_ [^ localAndGlobalSymbolTable] 
	construct listOfBaseDeclaratorsAsIDs[repeat id]
		_ [^ listOfBaseDeclarators] 
	construct newFunctionDefinition [function_definition_or_declaration]
		FunctionDefinitionHost [abstractAllId listOfBaseDeclaratorsAsIDs StringFctName]
	
	
	
	
	
	%construct symbol table and abstract the called function for the return value maybe???
	
	
	
	construct CalledFctName [stringlit]
		currentCalledString[fput "TESTARGSSYMBOL.out"]
	construct ArgsSymbolTable [repeat declaration]
		_ [symbolTableArgs currentCalled] [fput "TESTARGSSYMBOL.out"]
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	%determine the return value of the next function
	construct FunctionsSymbols [repeat return_structure]
		_ [determineReturnValues currentCalled] 
	
	deconstruct * [return_structure] FunctionsSymbols
		CalledFunctionRet [return_structure]
	
	
	
	%first replace return statements with just return
	
	construct finalFunctionDefinition [function_definition_or_declaration]
		newFunctionDefinition [removeReturnStatements] %[fput "TESTREMRETURN.out"]
	
	
	%place for grammarRewrite
	construct LOCsFromFct [repeat ids_with_line_break]
		_ [rewriteAsLocs finalFunctionDefinition currentCalledString CalledFunctionRet ArgsSymbolTable] 
	deconstruct * [function_header] FunctionDefinitionHost
		CurrentFunctionHeader [function_header]
	construct FctHeaderStringlit [stringlit]
		_ [quote CurrentFunctionHeader]
	construct functionNameAsID [id]
		_ [unquote StringFctName]
	construct FunctionName [function_for_transplant_name]
		functionNameAsID
	construct FunctionEndMarker [end_call_graph_marker]
		'@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
	construct completeFunction [function_for_transplant]
		FunctionName LOCsFromFct FunctionEndMarker
	construct messs [id]
		_ [message FunctionDefinitionHost]
	by
		current [. completeFunction]
		[writeACandidate rest restCalled]
end function




rule removeReturnStatements
	replace  $ [jump_statement]
		current [jump_statement]
	
	construct currentString [stringlit]
		_ [quote current] [fput "TESTREMRETURN2.out"]
		
	
	construct gotoLabel [label_id]
		LABEL_ABST	
		
	
	construct returnReplacement [jump_statement]
		'goto gotoLabel
		
		
	where
		currentString [grep "return"]
	by
		returnReplacement
		
end rule




function symbolTableArgs	first [graph_entry]
	replace [repeat declaration]
		current [repeat declaration]


	deconstruct first
		fctName [id] srcToken [source_file_token] SourceFileName [source_file_element] 
	construct inputFileName [stringlit]
		_ [quote SourceFileName]
	construct path [stringlit]
		"input/"	
	construct lengthOfFileName [number]
		_ [# inputFileName] [- 2]
	construct inputFilNameNoMarks [stringlit]
		inputFileName [: 3 lengthOfFileName]
	construct CompleteFileName [stringlit]
		path [+ inputFilNameNoMarks] 
	construct nonIfDefsOutput [stringlit]
		CompleteFileName [+ "NON"]
	construct commandForNonIf [stringlit]
		_ [+"./ifdef.x "] [+ CompleteFileName] [+ " "] [+ CompleteFileName]  [+ " "] [+ "/home/alex/workspace/Transplants/"] [+ nonIfDefsOutput]
	construct CallCommand2 [id]
    	_ [system commandForNonIf]
	construct outputFileCompleteName [stringlit]
		_ [+ "/home/alex/workspace/Transplants/"] [+ nonIfDefsOutput]
	construct ProgramSource [repeat program]
		_ [read outputFileCompleteName] 
	deconstruct * [repeat function_definition_or_declaration] ProgramSource
		ProgramFunctions [repeat function_definition_or_declaration]
	construct StringFctName [stringlit]
		_ [quote fctName] 
	construct NeededFunction [repeat function_definition_or_declaration]
		ProgramFunctions [extractNeededFunction StringFctName]
	import FunctionDefinitionHost [function_definition_or_declaration]
	
	

		%construct symbol table and abstract the function definition
	construct functionName [stringlit]
		StringFctName 
    construct localAndGlobalSymbolTable [repeat declaration]
     	_ [constructLocalSymbolTable FunctionDefinitionHost] 
     	
     	
	construct listOfBaseDeclarators [repeat base_declarator]
		_ [^ localAndGlobalSymbolTable] 
	construct listOfBaseDeclaratorsAsIDs[repeat id]
		_ [^ listOfBaseDeclarators] 
		
		
	construct newFunctionDefinition [function_definition_or_declaration]
		FunctionDefinitionHost [abstractAllId listOfBaseDeclaratorsAsIDs StringFctName]




	%construct the abstract symbol table

	construct localAndGlobalSymbolTableAbstract [repeat declaration]
     	_ [constructLocalSymbolTable newFunctionDefinition] 



	deconstruct * [function_header] newFunctionDefinition
		FunctionHeader [function_header]
		
	construct ListOfArguments [repeat argument_declaration]
		_ [^ FunctionHeader]
		
	construct ArgsSymbolTable [repeat declaration]
		_ [argumentDeclToVariableDecl ListOfArguments]


	by
		ArgsSymbolTable
end function




























function extractNeededFunction	FctName [stringlit]
	match * [function_definition_or_declaration]
		current [function_definition_or_declaration]
	
	
	
	construct currentFct [id]
		_ [deconstructFunctionDefinition current] 
		
	construct currentFctString [stringlit]
		_ [quote currentFct]
	where
		currentFct [= FctName]
		export FunctionDefinitionHost [function_definition_or_declaration]
			current
end function



function deconstructFunctionDefinition currentFctDef [function_definition_or_declaration]
	replace [id]
		_ [id]
	deconstruct * [function_definition] currentFctDef
			justFunct [function_definition]
		deconstruct * [function_header] justFunct
			fctHeader [function_header]
		deconstruct * [opt KR_parameter_decls] justFunct
			fctKR [opt KR_parameter_decls]	
				deconstruct * [compound_statement] justFunct
			fctStatement [compound_statement]
		deconstruct * [compound_statement_body] fctStatement
			fctStatementBody [compound_statement_body]
		construct fctStatementWithoutPreprocessor [compound_statement]
			{ fctStatementBody }
		construct functionWithoutPreprocessor [function_definition]
			fctHeader fctKR fctStatementWithoutPreprocessor 
		deconstruct fctHeader
			spec [opt decl_specifiers] decl [declarator] ext[function_declarator_extension] 
		construct stringFromDecl [stringlit]
			_ [quote decl]
		construct IDFromDecl [id]
			_ [unquote stringFromDecl]
	by
		IDFromDecl
end function































%grammar rewrite
function rewriteAsLocs	FctDef [function_definition_or_declaration]
						CurrentCalledFunction [stringlit]
						CalledFctReturn [return_structure]
						ArgsSymbolTable [repeat declaration]
	replace [repeat ids_with_line_break]
		current [repeat ids_with_line_break]
	
	deconstruct * [compound_statement_body] FctDef
		currentFctBody [compound_statement_body]
	
	deconstruct * [repeat declaration_or_statement] currentFctBody
		FctDecl [repeat declaration_or_statement]
		
		
	construct FctDeclMarkers [repeat declaration_or_statement_markers]	
		_ [ToDeclStmMarkers FctDecl] 
		
		
		
	%deconstruct * [declaration_or_statement_markers] currentFctBody
		%testingJ [declaration_or_statement_markers]
		
		
		
		
		
	construct DeclAsStrings [repeat declaration_or_statement_markers]
		_ [declToStringlit FctDeclMarkers CurrentCalledFunction CalledFctReturn ArgsSymbolTable] 
		
		
		
	construct DeclAsIds [repeat ids_with_line_break]
		_ [stringlitToId DeclAsStrings]	% [write "BLANAAAAAA.out"]
		
	construct message [id]
		_ [message DeclAsIds]	
	
		
	by
		DeclAsIds
		
end function


function stringlitToId 	ListOfStrings [repeat declaration_or_statement_markers]
	replace [repeat ids_with_line_break]
		current [repeat ids_with_line_break]
	deconstruct ListOfStrings 
		first [declaration_or_statement_markers] rest [repeat declaration_or_statement_markers]
	
	construct firstString [stringlit]
		_ [quote first]
		
	construct finalFirstStrng [stringlit]
		firstString [replaceIfItIsString first]
	
	construct firstId [id]
		_ [unquote finalFirstStrng]
	
	
	
	construct idWithLB [ids_with_line_break]
		firstId
	by
		current [. idWithLB]
		[stringlitToId rest]
end function



function replaceIfItIsString	Current [declaration_or_statement_markers]
	replace [stringlit]
		_ [stringlit]
	deconstruct * [stringlit] Current
		currentString [stringlit]
	by
		currentString
		
end function


function ToDeclStmMarkers	Initial [repeat declaration_or_statement]
	replace [repeat declaration_or_statement_markers]
		current [repeat declaration_or_statement_markers]
	deconstruct Initial
		first [declaration_or_statement] rest [repeat declaration_or_statement]
	construct CurrDecl [declaration_or_statement_markers]
		first
		
	by
		current [. CurrDecl]
		[ToDeclStmMarkers rest]
end function





function declToStringlit	Decl [repeat declaration_or_statement_markers]
							CurrentCalledFunction [stringlit]
							CurrentCalledRet [return_structure]
							ArgsSymbolTable [repeat declaration]
	replace [repeat declaration_or_statement_markers]
		current [repeat declaration_or_statement_markers]
	deconstruct Decl 
		first [declaration_or_statement_markers] rest [repeat declaration_or_statement_markers]
	%construct stringFromDecl [stringlit]
		%_ [quote first]

		%solve called functions
		
		
	%add the function mark also at the beggining
	

	
	export AdditionalFunctionCall [repeat declaration_or_statement_markers]
		_
	
	export LabelMarker [repeat declaration_or_statement_markers]
		_
	
	construct firstSolvedCallFunctions [declaration_or_statement_markers]
		first  [solveCalledFunction first CurrentCalledFunction CurrentCalledRet ArgsSymbolTable]
	
	
	
	
	
	
	%fix order for compund statemend; it should be first
	
	construct firstWithLineStatements [declaration_or_statement_markers]
		firstSolvedCallFunctions [addNumberAtStatements]
		
	construct firstWithLine [declaration_or_statement_markers]
		firstWithLineStatements [addNumberAtMacros]
	
	construct finalString [declaration_or_statement_markers]
		firstWithLine [solveCompundStatement first CurrentCalledFunction CurrentCalledRet ArgsSymbolTable]
		

	construct finalRest [repeat declaration_or_statement_markers]
		rest [AddFromCompund first]
		
	import AdditionalFunctionCall [repeat declaration_or_statement_markers]
		
	import LabelMarker [repeat declaration_or_statement_markers]	
	
	construct finalStringAddedFunctionCall [repeat declaration_or_statement_markers]
		AdditionalFunctionCall [. finalString] [. LabelMarker]
	by
		current [. finalStringAddedFunctionCall]
		[declToStringlit finalRest CurrentCalledFunction CurrentCalledRet ArgsSymbolTable]
end function




%add callings to functions; if value is used solve this; solve in compund statements; solve pointers!!!
function solveCalledFunction	OriginalStm [declaration_or_statement_markers]
								CurrentCalledFunction [stringlit]
								CurrentCalledRet [return_structure]
								ArgsSymbolTable [repeat declaration]
	replace [declaration_or_statement_markers]
		current [declaration_or_statement_markers]
	deconstruct * [declaration_or_statement] OriginalStm
		currStatement [declaration_or_statement]
		
		
	%test for macro I think:-??	
	%construct mssss [declaration_or_statement]
	%	currStatement %[fput "HELLOO.out"]	
	%construct testing [declaration_or_statement]
	%	currStatement [CheckAllTYPES CurrentCalledFunction]
	
	
	export ReplacedToken [repeat declaration_or_statement_markers]
		_
	
	construct replacedArgs [declaration_or_statement]
		currStatement [replaceNeededFunctionCallArgs CurrentCalledFunction CurrentCalledRet ArgsSymbolTable] 
	construct replacedUnaryExpr [declaration_or_statement]
		replacedArgs [replaceNeededFunctionCallUnaryExpr CurrentCalledFunction CurrentCalledRet ArgsSymbolTable]
	
	
	
	
	
	%in the case of replaced macro specifier, the function calling is direct, so no need to add it again in the global variable
	construct replacedMacroSpecifier [declaration_or_statement]
		replacedUnaryExpr [replaceNeededFunctionCallMacroSpecifier CurrentCalledFunction CurrentCalledRet ArgsSymbolTable]





	construct exportFunction [declaration_or_statement]
		currStatement [exportFunctionNameIfCalled replacedMacroSpecifier CurrentCalledFunction]


		
	construct currentString [stringlit]
		_ [quote replacedMacroSpecifier]  [fput "TESTLABEL.out"]

	by
		replacedMacroSpecifier
		
end function


function exportFunctionNameIfCalled	NewDeclStatement [declaration_or_statement]
									FctName [stringlit]
	match [declaration_or_statement]
		current [declaration_or_statement]
	construct Old [stringlit]
		_ [quote current]
	construct New [stringlit]
		_ [quote NewDeclStatement]

	where not
		Old [= New]
		import AdditionalFunctionCall [repeat declaration_or_statement_markers]
		
		import ReplacedToken [repeat declaration_or_statement_markers]

		%(construct FctCallMarker [stringlit]
			"//call the function: "
		construct finalFctCall [stringlit]
			FctCallMarker [+ FctName] %[+ Old]
		construct declStmMarkerNewFct [declaration_or_statement_markers]
			finalFctCall
		)%
		export AdditionalFunctionCall 
			_ [. ReplacedToken] 
end function




rule replaceNeededFunctionCallMacroSpecifier	FunctionName [stringlit]
												CurrentCalledRet [return_structure]
												ArgsSymbolTable [repeat declaration]
	replace  $ [macro_specifier]
		express [macro_specifier]
		
		
		
		
		
	construct exprAsString [stringlit]
		_ [quote express]
	construct retName [stringlit]
		"//call_the_function: "
		
		
		
		
	deconstruct  express
		CurrentMacroName [macro_name] '(  CurrentMacroArgs [macro_arguments] ')
	construct macroAsString [stringlit]
		_ [quote CurrentMacroName]
		
	construct variableName [stringlit]
		retName [+ macroAsString]
	construct variableID [id]
		_ [unquote variableName]
		
		

		
		
	construct MacroN [macro_name]
		variableID
	construct MacroC [macro_call]
		MacroN '(  ')
	construct FTT [macro_specifier]
		MacroC
		
	%assure not replacing an already replaced one	
	construct indexOfFunction [number]
		_ [index exprAsString FunctionName] [- 1]
	construct initialPosition [number]
		indexOfFunction [- 15]
		
	construct messss [unary_expression]
		exprAsString 
		
	construct replacedSign [stringlit]
		exprAsString [: initialPosition indexOfFunction] 	
		
		
		
		
	where 
		exprAsString [grep FunctionName]
		
	where not
		replacedSign [= "@ABSTRETVAL_ret_"]






			construct mes3333sss [macro_specifier]
		express [fput "CREATEVARMAP.out"]
				
	construct mes33sss [macro_arguments]
		CurrentMacroArgs %[fput "CREATEVARMAP.out"]
		
		
		
		
		
		
		deconstruct CurrentMacroArgs
			ListOfArgs [repeat macro_argument] 
			
		construct MacroArgsStringlit [stringlit]
			_ [quote CurrentMacroArgs][fput "CREATEVARMAP.out"]
			
		construct LengthOfMacroArgs [number]
			_ [# MacroArgsStringlit]
			
		construct MacroArgsNoBrackets [stringlit]
			MacroArgsStringlit [: 1 LengthOfMacroArgs]
			
			
		construct macroAsRepeatStrings [repeat stringlit]
			_ [deconstructArgumentsIntoListOfStringlit MacroArgsNoBrackets]	[fput "CREATEVARMAP.out"]
			
			
			
		%construct listMaybe [list stringlit]
		%	_ [unquote MacroArgsStringlit]
		

		%construct ArgsStringlit [repeat stringlit]
			%_ [macroArgsToStringlit ListOfArgs]% [fput "CREATEVARMAP.out"]
			
			
		%construct listOfIDSfromArgs [repeat stringlit]
			%_ [^ CurrentMacroArgs] [fput "CREATEVARMAP.out"]
			
			
		
		construct ListOfDeclarations [repeat declaration_or_statement_markers]
			_ [declarationArgsToStringlit ArgsSymbolTable macroAsRepeatStrings] [fput "testDecl.out"]






		import AdditionalFunctionCall [repeat declaration_or_statement_markers]
		export AdditionalFunctionCall
			_
			
			
		
		%construct the label
		
		construct LabelName [id]
			LABEL
		construct labelID [id]
			LabelName [!]
		construct labelString [stringlit]
			_ [quote labelID]
		construct finalLabelString [stringlit]
			labelString [+ ":"]
		construct labelDeclOrStmMarker [declaration_or_statement_markers]
			finalLabelString
		construct repeatLabel [repeat declaration_or_statement_markers]
			_ [. labelDeclOrStmMarker]
		
		
		
		
		import LabelMarker [repeat declaration_or_statement_markers]
		
		export LabelMarker [repeat declaration_or_statement_markers]
			_ [. repeatLabel]
		
		
		%mapping table
		import ReplacedToken [repeat declaration_or_statement_markers]
		construct mappingTableMarker [stringlit]
			"//Mappings for function: "
		construct finalMappings [stringlit]
			mappingTableMarker [+ exprAsString]
		construct exprAsDeclStmMarker [declaration_or_statement_markers]
			finalMappings
		export ReplacedToken
			_ [. ListOfDeclarations] [. exprAsDeclStmMarker] 
		
	by
		FTT
end rule




function deconstructArgumentsIntoListOfStringlit	Arguments [stringlit]
	replace [repeat stringlit]
		current [repeat stringlit]
	
	construct IndexOfComa [number]
		_ [index Arguments ","] 
	
	construct EndOfCurrentArg [number]
		IndexOfComa [-1]
	
	construct startOfNextArg [number]
		IndexOfComa [+ 2]
		
	construct firstArgument [stringlit]
		Arguments [: 1 EndOfCurrentArg]
	
	construct nextArgument [stringlit]
		Arguments [: startOfNextArg 999]
		
	
	construct RepeatFirstArg [repeat stringlit]
		_ [. firstArgument]
		
	construct AddedLastArg [repeat stringlit]
		RepeatFirstArg [addLastArgWhenNoBracket nextArgument]
	
	where not
		IndexOfComa [= 0]
	by
		current [. AddedLastArg]
		[deconstructArgumentsIntoListOfStringlit nextArgument]
end function


function addLastArgWhenNoBracket Argument [stringlit]
	replace [repeat stringlit]
		current [repeat stringlit]
	construct IndexOfComa [number]
		_ [index Argument ","] 
	where
		IndexOfComa [= 0]
	by
		current	[. Argument]
end function




function declarationArgsToStringlit	Declarations[repeat declaration]
									NewValues [repeat stringlit]
	replace [repeat declaration_or_statement_markers]
		current [repeat declaration_or_statement_markers]
		
	deconstruct Declarations
		first [declaration] rest [repeat declaration]
	
	deconstruct NewValues 
		firstVal [stringlit] restVal [repeat stringlit]
		
	deconstruct first 
		declSpec [decl_specifiers] initDecl [list init_declarator] semiMark[semi]
		
	deconstruct * [init_declarator] initDecl	
		varName [init_declarator]
	construct varString [stringlit]
		_ [quote varName]
	construct varId [id]
		_ [unquote varString]
	construct varUniqueID [id]
		varId [!]
		
	construct varUniqueInitDecl [init_declarator]
		varUniqueID
	construct varUniqueListDecl [list init_declarator]
		_ [, varUniqueInitDecl]
	construct newDeclarator [declaration]
		declSpec varUniqueListDecl semiMark
		
	construct varUniqueDeclString [stringlit]
		_ [quote varUniqueListDecl]
		
	construct firstAsStringlit [stringlit]
		_ [quote declSpec] [+ " "][+ varUniqueDeclString ] [+ " = "] [+ firstVal ][+ " ;"]
	construct firstMarker [declaration_or_statement_markers]
		firstAsStringlit
	
	by
		current [. firstMarker]
		[declarationArgsToStringlit rest restVal]
end function

































rule replaceNeededFunctionCallArgs	FunctionName [stringlit]
									CurrentCalledRet [return_structure]
									ArgsSymbolTable [repeat declaration]
	replace  $ [argument_expression]
		express [argument_expression]
	construct exprAsString [stringlit]
		_ [quote express]
	construct retName [stringlit]
		"@ABSTRETVAL_ret_"
	construct variableName [stringlit]
		retName [+ FunctionName]
	construct variableID [id]
		_ [unquote variableName]
	construct FTT [argument_expression]
		variableID
		
		
		
		
		
	%assure not replacing an already replaced one	
	construct indexOfFunction [number]
		_ [index exprAsString FunctionName] [- 1]
	construct initialPosition [number]
		indexOfFunction [- 15]
		
	construct messss [unary_expression]
		exprAsString 
		
	construct replacedSign [stringlit]
		exprAsString [: initialPosition indexOfFunction] 
		
		
		
		
	where 
		exprAsString [grep FunctionName]
	
	where not
		replacedSign [= "@ABSTRETVAL_ret_"]
		
		%mapping table
		import ReplacedToken [repeat declaration_or_statement_markers]
		construct mappingTableMarker [stringlit]
			"//Mappings for function: "
			
		construct callFunctionMarker [stringlit]
			"//call_the_function: "
		construct finalMappings [stringlit]
			mappingTableMarker [+ exprAsString]
		construct finalCallFunction [stringlit]
			callFunctionMarker [+ FunctionName] [+ " ();"]
		construct exprAsDeclStmMarker [declaration_or_statement_markers]
			finalMappings
		construct callFctAsDeclStmMarker [declaration_or_statement_markers]
			finalCallFunction
			
		%construct the variable declaration that will replace the function call	
		deconstruct CurrentCalledRet 
			RetName [function_name_return] RetType [return_type] RetVar[return_variable]	
		construct ReplacementName [stringlit]
			_ [quote FTT]
		deconstruct * [stringlit] RetName
			RetNameStringlit [stringlit]
		deconstruct * [stringlit] RetType
			RetTypeStringlit [stringlit]
		deconstruct * [stringlit] RetVar 
			RetVarStringlit [stringlit]
		construct AbstractRetVar [stringlit]
			_ [+ "@ABST_"] [+ FunctionName] [+ "_"]  [+ RetVarStringlit]
		construct testtt [stringlit]
			RetTypeStringlit [+ ReplacementName] [+ " = "] [+ AbstractRetVar]
		construct testDeclMarker [declaration_or_statement_markers]
			testtt
			
			
			
			
			
				deconstruct * [assignment_expression] express
			AssignExpr [assignment_expression]
		
		construct exprAsStringlit [stringlit]
			_ [quote AssignExpr] 
			
			
		construct LengthOfArgs [number]
			_ [# exprAsStringlit] [- 1]
			
		construct ArgsNoBrackets [stringlit]
			exprAsStringlit [: 2 LengthOfArgs] 
			
			
		construct ArgsAsRepeatStrings [repeat stringlit]
			_ [deconstructArgumentsIntoListOfStringlit ArgsNoBrackets]	

			
		construct ListOfDeclarations [repeat declaration_or_statement_markers]
			_ [declarationArgsToStringlit ArgsSymbolTable ArgsAsRepeatStrings] [fput "testDecl.out"]
			
			
			
			
		%construct the label
		
		construct LabelName [id]
			LABEL
		construct labelID [id]
			LabelName [!]
		construct labelString [stringlit]
			_ [quote labelID]
		construct finalLabelString [stringlit]
			labelString [+ ":"]
		construct labelDeclOrStmMarker [declaration_or_statement_markers]
			finalLabelString

			
			
		export ReplacedToken
			_ [. ListOfDeclarations] [. callFctAsDeclStmMarker] [. exprAsDeclStmMarker]  [. labelDeclOrStmMarker] [.testDeclMarker]
			
			
			
			
		
	by
		FTT
end rule


rule replaceNeededFunctionCallUnaryExpr	FunctionName [stringlit]
										CurrentCalledRet [return_structure]
										ArgsSymbolTable [repeat declaration]
	replace  $ [unary_expression]
		express [unary_expression]
	construct exprAsString [stringlit]
		_ [quote express]
	construct retName [stringlit]
		"@ABSTRETVAL_ret_"
	construct variableName [stringlit]
		retName [+ FunctionName]
	construct variableID [id]
		_ [unquote variableName]
	construct FTT [unary_expression]
		variableID
		
		
		
	%assure not replacing an already replaced one	
	construct indexOfFunction [number]
		_ [index exprAsString FunctionName] [- 1]
	construct initialPosition [number]
		indexOfFunction [- 15]
		
	construct messss [unary_expression]
		exprAsString 
		
	construct replacedSign [stringlit]
		exprAsString [: initialPosition indexOfFunction] 
	

		
		
	where 
		exprAsString [grep FunctionName]
	where not
		replacedSign [= "@ABSTRETVAL_ret_"]
		%mapping table
		import ReplacedToken [repeat declaration_or_statement_markers]
		construct mappingTableMarker [stringlit]
			"//Mappings for function: "
			
		construct callFunctionMarker [stringlit]
			"//call_the_function: "
		construct finalMappings [stringlit]
			mappingTableMarker [+ exprAsString]
		construct finalCallFunction [stringlit]
			callFunctionMarker [+ FunctionName] [+ " ();"]
		construct exprAsDeclStmMarker [declaration_or_statement_markers]
			finalMappings
		construct callFctAsDeclStmMarker [declaration_or_statement_markers]
			finalCallFunction
		

		%construct the variable declaration that will replace the function call	
		deconstruct CurrentCalledRet 
			RetName [function_name_return] RetType [return_type] RetVar[return_variable]	
		construct ReplacementName [stringlit]
			_ [quote FTT]
		deconstruct * [stringlit] RetName
			RetNameStringlit [stringlit]
		deconstruct * [stringlit] RetType
			RetTypeStringlit [stringlit]
		deconstruct * [stringlit] RetVar 
			RetVarStringlit [stringlit]
		construct AbstractRetVar [stringlit]
			_ [+ "@ABST_"] [+ FunctionName] [+ "_"]  [+ RetVarStringlit]
		construct testtt [stringlit]
			RetTypeStringlit [+ ReplacementName] [+ " = "] [+ AbstractRetVar]%_ [quote FTT] [+ "= PULA"]
		construct testDeclMarker [declaration_or_statement_markers]
			testtt
			
			





			
		deconstruct * [postfix_extension] express
			PostFixExt [postfix_extension]
		
		construct extAsStringlit [stringlit]
			_ [quote PostFixExt] 
			
			
		construct LengthOfArgs [number]
			_ [# extAsStringlit] [- 1]
			
		construct ArgsNoBrackets [stringlit]
			extAsStringlit [: 3 LengthOfArgs] 
			
			
		construct ArgsAsRepeatStrings [repeat stringlit]
			_ [deconstructArgumentsIntoListOfStringlit ArgsNoBrackets]		
			



		%construct checkExp [unary_expression]
			%express [CheckAllTYPES]	
			
			
			
			
		construct ListOfDeclarations [repeat declaration_or_statement_markers]
			_ [declarationArgsToStringlit ArgsSymbolTable ArgsAsRepeatStrings] 
			
			
		
		%construct the label
		
		construct LabelName [id]
			LABEL
		construct labelID [id]
			LabelName [!]
		construct labelString [stringlit]
			_ [quote labelID]
		construct finalLabelString [stringlit]
			labelString [+ ":"]
		construct labelDeclOrStmMarker [declaration_or_statement_markers]
			finalLabelString	
		
			
		export ReplacedToken
			_ [.ListOfDeclarations] [.callFctAsDeclStmMarker]  [. exprAsDeclStmMarker] [. labelDeclOrStmMarker] [.testDeclMarker]
			
	by
		FTT
end rule



%VERY USEFULL!!!!
rule CheckAllTYPES	
	replace  $ [any]
		express [any]


		construct eString [stringlit]
		_ [quote express]
	construct typeT [id]
		_ [typeof express]
	construct stringType [stringlit]
		_ [quote typeT] [+ "  "]
	construct finalMessage [stringlit]
		stringType [+ eString] [fput "CHECKTYPES.out"]








	%construct msssss [any]
		%express [fput "CHECKTYPES.out"]
	

	by
		express
end rule


function addNumberAtMacros
	replace [declaration_or_statement_markers]
		current [declaration_or_statement_markers]
	deconstruct * [macro_specifier] current
		currentState444ment [macro_specifier] 
	construct TTTT [macro_specifier]
		currentState444ment 
		
	construct CurrentAsString [stringlit]
		_ [quote current]
	
	construct FirstTwoChars [stringlit]
		CurrentAsString [: 1 2]
	construct commentMark [stringlit]
		"//"	
	where not
		commentMark [= FirstTwoChars]	
		
	import LineNumber [number]
	construct LineString [stringlit]
		_ [quote LineNumber]
		
	%comment the line numbers	
	construct commentStartMarker [stringlit]
		"/* "
	construct commentEndMarker [stringlit]
		" */  "
	construct FinalLineString [stringlit]
		commentStartMarker [+ LineString] [+ commentEndMarker]	
		
		
		
	construct currentStatementString [stringlit]
		FinalLineString [quote current]
	construct currentStmLine [declaration_or_statement_markers]
		currentStatementString
	export LineNumber
		LineNumber [+ 1]
	by
		currentStmLine
end function



function addNumberAtStatements
	replace [declaration_or_statement_markers]
		current [declaration_or_statement_markers]
	deconstruct * [statement] current
		currentState444ment [statement] 
	import LineNumber [number]
	construct LineString [stringlit]
		_ [quote LineNumber] %[+ " "]
		
	%comment the line numbers	
	construct commentStartMarker [stringlit]
		"/* "
	construct commentEndMarker [stringlit]
		" */  "
	construct FinalLineString [stringlit]
		commentStartMarker [+ LineString] [+ commentEndMarker]
		
		
	construct currentStatementString [stringlit]
		FinalLineString [quote current]
	construct currentStmLine [declaration_or_statement_markers]
		currentStatementString
	export LineNumber
		LineNumber [+ 1]
	by
		currentStmLine
end function


function AddFromCompund CurrentStatement [declaration_or_statement_markers]
	replace [repeat declaration_or_statement_markers]
		currentList [repeat declaration_or_statement_markers]
	deconstruct * [compound_statement_body] CurrentStatement
		currentCompund [compound_statement_body]	
	deconstruct * [structured_statement] CurrentStatement
		currentCompund2 [structured_statement]
	construct compundNoBody [declaration_or_statement_markers]
		currentCompund2 [removeBodyFromCompund]
	construct compundString [stringlit]
		_ [quote compundNoBody] 
	construct lengthOfHeader [number]
		_ [# compundString] [- 2]
	construct removedEndOfBlock [stringlit]
		compundString [: 1 lengthOfHeader]
	deconstruct * [repeat declaration_or_statement] currentCompund
		declsFromCompund [repeat declaration_or_statement]
	construct declsMarkersFromCompund [repeat declaration_or_statement_markers]	
		_ [ToDeclStmMarkers declsFromCompund] 	
	construct finalMarker [stringlit]
		"} "
	construct finalEndOfCompund [stringlit]
		finalMarker [+ "//"] [+ removedEndOfBlock] 
	construct addFinalMarker [declaration_or_statement_markers]
		finalEndOfCompund
	by
		declsMarkersFromCompund [.addFinalMarker] [. currentList]
end function


function solveCompundStatement	CurrentStatement [declaration_or_statement_markers]
								FunctionName [stringlit]
								CurrentCalledRet [return_structure]
								ArgsSymbolTable [repeat declaration]
	
	replace [declaration_or_statement_markers]
		current [declaration_or_statement_markers]
	deconstruct * [structured_statement] CurrentStatement
		currentCompund [structured_statement]		
	deconstruct * [compound_statement_body] CurrentStatement
		justIfItHasBody [compound_statement_body]	
	construct compundNoBody [declaration_or_statement_markers]
		currentCompund [removeBodyFromCompund] 
		
		
		%%!!!!!!!!!!!!!!!!!!1!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	construct firstSolvedCallFunctions [declaration_or_statement_markers]
		compundNoBody [solveCalledFunction compundNoBody FunctionName CurrentCalledRet ArgsSymbolTable]

	construct compundString [stringlit]
		_ [quote firstSolvedCallFunctions] 
	construct lengthOfHeader [number]
		_ [# compundString] [- 1]
	construct removedEndOfBlock [stringlit]
		compundString [: 1 lengthOfHeader] 
	import LineNumber [number]
	export LineNumber 
		LineNumber [- 1]	
	by
		removedEndOfBlock
end function



rule removeBodyFromCompund
	replace $ [compound_statement_body]
		_ [compound_statement_body] 
	by
		_
		
end rule




rule ObtainNeededFunctions	FctList [repeat stringlit]%P [repeat function_definition_or_declaration]
	replace $ [function_definition]
		current [function_definition]
		
	deconstruct * [declarator] current
		CurrentFctHeader [declarator] 
	
	
	construct FctName [stringlit]
		_ [quote CurrentFctHeader]
	
	where 
		FctList [CheckIfInFctList FctName]
		
	construct messagggg [id]
		_ [message CurrentFctHeader]
	
	export NeededFunction [function_definition_or_declaration]
		current
	
	by
		current
		
end rule


function CheckIfInFctList CurrentFct [stringlit]
	match * [stringlit]
		FctInList [stringlit]
	
	where 
		FctInList [= CurrentFct]
end function





%symbol table rules & functions

rule abstractAllId	ListOfIDs [repeat id]
					FctName [stringlit]
	replace $ [id]
		current [id]
	construct AbstractMarker [id]
		_ [unquote "@ABST"]
	construct FctNameId [id]
		_ [unquote FctName]
	construct finalIdReplacement [id]
		AbstractMarker [_ FctNameId] [_ current]
	where
		ListOfIDs [idInList current]
	by	
		finalIdReplacement
		
end rule


function idInList	CurrentId [id]
	match * [id]
		idFromList [id]
	where
		CurrentId [= idFromList]
end function







%construct symbol table for variables that are defined locally, in the body or the 
%head of the function that contains the target place
function constructLocalSymbolTable P [function_definition_or_declaration]
	replace [repeat declaration]
		P2 [repeat declaration]
	deconstruct * [function_definition] P
		justFunctionP [function_definition]
	construct AllIdsInit [repeat declaration]
		_ [^ justFunctionP] 
	construct AllIds [repeat declaration]
		_ [constructSeparatedDeclarationForEveyVar AllIdsInit]
	construct allIdsFunctionDeclaration [repeat argument_declaration]
		_ [^ justFunctionP] 
	%add function headers declarations!!!!
	construct justTest [repeat declaration]
		AllIds [argumentDeclToVariableDecl allIdsFunctionDeclaration]
	by
		P2 [. justTest]
end function


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


function addNextDecl currentVarDecl [declaration]
	replace [repeat declaration]
		decl [repeat declaration]
	deconstruct   currentVarDecl
		specT [decl_specifiers] declT [list init_declarator] ';
    construct initialVars [repeat declaration]
    	_  [addVarIfJustDeclaration currentVarDecl] 	
    deconstruct specT
		repeatFromDecl [repeat decl_qualifier_or_type_specifier]
	construct testT [repeat decl_qualifier_or_type_specifier]
		 repeatFromDecl %_ [removeTypeSpecifiers repeatFromDecl]
	construct newVarDeclSpecifiers [decl_specifiers]
		testT
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
		construct varDeclOut [stringlit]
			_ [quote varDeclaration] 
		%needed for checking if not macro specifier in initial variable; otherwise it will be seen as declarator
		construct testT [repeat decl_qualifier_or_type_specifier]
			repeatFromDecl %_ [removeTypeSpecifiers repeatFromDecl]
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
		repeatFromDecl % _ [removeTypeSpecifiers repeatFromDecl]
		
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





%retrieve return values:

function determineReturnValues	ListOfGraphEntries [graph_entry]
	replace [repeat return_structure ]
		current [repeat return_structure]
	deconstruct ListOfGraphEntries
		first [graph_entry]
	deconstruct first
		fctName [id] srcToken [source_file_token] SourceFileName [source_file_element] 
	construct inputFileName [stringlit]
		_ [quote SourceFileName]
	construct path [stringlit]
		"input/"	
	construct lengthOfFileName [number]
		_ [# inputFileName] [- 2]
	construct inputFilNameNoMarks [stringlit]
		inputFileName [: 3 lengthOfFileName]
	construct CompleteFileName [stringlit]
		path [+ inputFilNameNoMarks] 
	construct nonIfDefsOutput [stringlit]
		CompleteFileName [+ "NON"]
	construct commandForNonIf [stringlit]
		_ [+"./ifdef.x "] [+ CompleteFileName] [+ " "] [+ CompleteFileName]  [+ " "] [+ "/home/alex/workspace/Transplants/"] [+ nonIfDefsOutput]
	construct CallCommand2 [id]
    	_ [system commandForNonIf]
	construct outputFileCompleteName [stringlit]
		_ [+ "/home/alex/workspace/Transplants/"] [+ nonIfDefsOutput]
	construct ProgramSource [repeat program]
		_ [read outputFileCompleteName] 
	deconstruct * [repeat function_definition_or_declaration] ProgramSource
		ProgramFunctions [repeat function_definition_or_declaration]
	construct StringFctName [stringlit]
		_ [quote fctName] 
	construct NeededFunction [repeat function_definition_or_declaration]
		ProgramFunctions [extractNeededFunction StringFctName]
	import FunctionDefinitionHost [function_definition_or_declaration]
	
	export ReturnStatementValue [stringlit]
		"NO RETURN"
	construct returnStatement [function_definition_or_declaration]
		FunctionDefinitionHost [determineReturnInstruction]
	import ReturnStatementValue [stringlit]
	
	
	
	
	
	deconstruct * [function_header] FunctionDefinitionHost
		fctHead [function_header]
	
	deconstruct * [type_specifier] fctHead
		fctDecl [type_specifier]
	construct declString [stringlit]
		_ [quote fctDecl] [+ " "]
	
	construct functionName [stringlit]
		StringFctName [+ "   "]
	construct msss [stringlit]
		functionName [+ declString] [+ ReturnStatementValue] 
	
	%[function_name_return] [return_type] [return_variable]
	
	construct FunctionNameRet [function_name_return]
		functionName
	
	construct FunctionRetType [return_type]
		declString
		
	construct FunctionReturnValue [return_variable]
		ReturnStatementValue
		
	construct ReturnStatement [return_structure]
		FunctionNameRet FunctionRetType FunctionReturnValue
	
	by
		current [. ReturnStatement]
		%[determineReturnValues rest]
end function


function determineReturnInstruction
	match * [jump_statement]
		current [jump_statement]
	
	construct currentString [stringlit]
		_ [quote current]
		
	where
		currentString [grep "return"]
		import ReturnStatementValue [stringlit]
		export ReturnStatementValue
			currentString [: 8 100]
end function
