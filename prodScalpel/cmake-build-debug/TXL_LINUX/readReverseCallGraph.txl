include "cOriginal.grm"

%redefine upper_macro_name
%   [upperlowerid] 
%end redefine

tokens
	end_source_files_mark "______________________________"
	end_call_graph_marker "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"
	current_function "^^\i+^^"
	source_file_element "@@[/\i]*.\i*@@"
	source_file_token "source_file:"

end tokens

redefine label
	[EX] [label_id] ': [IN] 
    |   [EX][SP][SP] 'case [constant_expression] ': [IN] 
    |   [EX][SP][SP] 'default ': [IN] 
#ifdef GNU
    |   [EX][SP][SP] 'case [constant_expression] [SP] '... [SP] [constant_expression] ': [IN]    
#endif
end redefine

redefine program
    [compilation_unit]
    |	[list argument_declaration]
    |	[reverse_call_graph]
end redefine

define reverse_call_graph
	[source_files] [NL][current_function_entry] [repeat graph]
end define


define current_function_entry
	[current_function] [source_file_element]
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


redefine declaration_or_statement
	...
	| [stringlit] [NL]
	| [id] [NL]
end redefine

define ids_with_line_break
	[id] [NL]
end define


define function_for_transplant
	[opt function_for_transplant_name]  [function_definition_or_declaration]   [end_call_graph_marker] [NL]
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



define function_instante_mappings
	[function_name] [NL] [repeat symbol_mapping]  [end_call_graph_marker] [NL]
end define



define symbol_table
	[repeat symbol_table_entry]
end define

define symbol_table_entry
	[function_name] -> [argument_symbol] : [repeat variable_symbol] [NL]
	|	[declaration]
end define


define function_name
	[id]
end define

define argument_symbol
	[id]
end define


define variable_symbol
	[id]
end define





define symbol_mapping
	[abstract] [mapping] [NL]
end define

define abstract 
	[id]
end define

define mapping
	[id]
end define




define function_definition_or_declaration_with_name
	[function_name] [NL] [function_definition_or_declaration]
end define



redefine function_definition
    [NL] [function_header]
#ifdef PREPROCESSOR
    [repeat preprocessor_function_header]
#endif
    [opt KR_parameter_decls]
    [compound_statement] 
end redefine


define abstract_entry_point_symbol_table
	[repeat symbol_table_entry] '@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ [NL] [repeat symbol_table_entry]
end define



function main
	match [program]
		P [program]
	deconstruct * [reverse_call_graph] P
		 CallGraph [reverse_call_graph]
		
	export FixedEntryPoint [number]
		0
	export CompoundNumberMarker [number]
		0
	
	export listOfAlreadyWrittenFunctions [repeat stringlit]
		_
		
	% Construct the list of all added labels
	% We will need this later for adding the ones after the call of the core function
	
	export ListOfAddedLabels [repeat declaration_or_statement]
		_
		
	construct newP [reverse_call_graph]
		CallGraph [constructNewGPFunctions]
		

end function




function constructNewGPFunctions
	replace [reverse_call_graph]
		P [reverse_call_graph]
		
		
	
	import TXLargs [repeat stringlit]
	
	deconstruct TXLargs
		donorSourceFiles [stringlit] modifiedFunctionLOCsOutput [stringlit] 
		SkeletonInstantiateMappings [stringlit] HostSymbolTableFile [stringlit] 
		CurrentExistingMappings [stringlit] fixIfDefProg [stringlit] calledFunctionsFile [stringlit]
		outputLabelsFile [stringlit]
		
		
	export allReplacedFunctions [repeat stringlit]
		_
		
	export fixIfDefProg
	export donorSourceFiles
		
		
		
	% NEW: ALL LIST OF CALLED FUNCTIONS	
	construct allCalledFunctionsProg [program]
		_ [read calledFunctionsFile]
		
	deconstruct * [reverse_call_graph] allCalledFunctionsProg
		 allCalledFunctionsCallGraph [reverse_call_graph]
		 
		deconstruct * [repeat graph] allCalledFunctionsProg
			allCalledFunctionsRepeatGraph [repeat graph]
			
			deconstruct allCalledFunctionsRepeatGraph
				firstEntryCalled [graph] restEntriesCalled [repeat graph]
		
			deconstruct * [repeat graph_entry] firstEntryCalled
		ListOfCalledFunctions [repeat graph_entry]
		
		
		
		
		
		
		
		
	deconstruct * [reverse_call_graph] P
		CallGraphOfProgram [reverse_call_graph]
		
	deconstruct * [repeat graph] CallGraphOfProgram
		listOfCallGraphs [repeat graph]
	
	deconstruct listOfCallGraphs
		first [graph] rest [repeat graph]
		
	deconstruct * [repeat graph_entry] first
		ListOfGraphEntriesOriginal [repeat graph_entry]
		
		
	%add all this in the list of graph entries!!! - TEST - 
	
	construct ListOfGraphEntries [repeat graph_entry]
		ListOfGraphEntriesOriginal [addToListOfGraphEntriyIfUnique ListOfCalledFunctions]
		

		
	%construct current function as a graph entry	
	deconstruct * [current_function_entry] CallGraphOfProgram
		currentFunctionEntry [current_function_entry]
		
		
	deconstruct currentFunctionEntry
		currentFunctionToken [current_function] SourceFileElTok [source_file_element]
	
		
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
	
	construct currentFctGraphEntry [graph_entry]
		currentFunctionID SourceFileTok SourceFileElTok 
		
		
		
		
	deconstruct ListOfGraphEntries
		firstEntry [graph_entry] calledEntries [repeat graph_entry]
	construct ListOfCalledEntries [repeat graph_entry]
		calledEntries [. currentFctGraphEntry]
				construct msmsss [repeat graph_entry]
			ListOfCalledEntries 
		
		
		
		
		
	export MappingsForFunctionInstantiation [repeat function_instante_mappings]
		_
		
	export HostSymbolTable [repeat symbol_table_entry]
		_
	
	export CurrentMappingList [repeat function_instante_mappings]	
		_
	
	export EntryPointSymbolTable [repeat symbol_table_entry]
		_
		
	
	%write the functions for GP
	construct Candidate [repeat function_for_transplant]
		_ [writeACandidate ListOfGraphEntries ListOfCalledEntries currentFunctionID ListOfCalledFunctions] [write modifiedFunctionLOCsOutput]
	

	
	
	import MappingsForFunctionInstantiation [repeat function_instante_mappings]
	import HostSymbolTable [repeat symbol_table_entry]
	import CurrentMappingList [repeat symbol_mapping]	
	
	construct msss [repeat function_instante_mappings]
		MappingsForFunctionInstantiation [write SkeletonInstantiateMappings]
		
		
	import EntryPointSymbolTable [repeat symbol_table_entry]
	
	
	construct finalSymbolTable [abstract_entry_point_symbol_table]
		HostSymbolTable '@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ EntryPointSymbolTable
	
	
	construct ms2 [abstract_entry_point_symbol_table]
		finalSymbolTable [write HostSymbolTableFile]
		
	construct ms3 [repeat function_instante_mappings]
		CurrentMappingList [write CurrentExistingMappings]
		
	
	import allReplacedFunctions 
		
	construct mdsk [repeat stringlit]
		allReplacedFunctions 
		
	%construct lengthReplacedFct [number]
	%	_ [length allReplacedFunctions]
	
	
	
	import ListOfAddedLabels [repeat declaration_or_statement]
	construct outputAddedLabels [repeat declaration_or_statement]
		ListOfAddedLabels [fput outputLabelsFile]
	
	
	
	by
		P
		
end function




function addToListOfGraphEntriyIfUnique	NewFunctions [repeat graph_entry]
	replace [repeat graph_entry]
		current [repeat graph_entry]
	deconstruct NewFunctions
		first [graph_entry] rest [repeat graph_entry]
	
	construct justUnique [repeat graph_entry]
		_ [addJustUnique current first]
	
	
	by
		current [. justUnique]
		[addToListOfGraphEntriyIfUnique rest]
end function


function addJustUnique	ListOfCurrentEntries [repeat graph_entry]
						NewEntry [graph_entry]
	replace [repeat graph_entry]
		current [repeat graph_entry]
		
	where not 
		ListOfCurrentEntries [searchGraphEntryInRepeatGraphEntry NewEntry]
		
	by
		current [. NewEntry]
end function


rule searchGraphEntryInRepeatGraphEntry	searchedGraphEntry [graph_entry]
	match [graph_entry]
		current [graph_entry]
		
	deconstruct * [id] current
		currentID [id]
	
	deconstruct * [id] searchedGraphEntry
		searchedID [id]
	
	where
		searchedID [= currentID]
	
end rule


function writeACandidate	ListOfGraphEntries [repeat graph_entry]
							ListOfCalledEntries [repeat graph_entry]
							CoreFunction [id]
							ListOfCalledFunctions [repeat graph_entry]
	replace [repeat function_for_transplant]
		current [repeat function_for_transplant]
	deconstruct ListOfGraphEntries
		first [graph_entry] rest [repeat graph_entry]
		
		

		
	import donorSourceFiles [stringlit] %with /!!!
		
		
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
		donorSourceFiles	
	construct lengthOfFileName [number]
		_ [# inputFileName] [- 2]
	construct inputFilNameNoMarks [stringlit]
		inputFileName [: 3 lengthOfFileName]
	construct CompleteFileName [stringlit]
		path [+ inputFilNameNoMarks] 
	construct nonIfDefsOutput [stringlit]
		CompleteFileName [+ "NON"]

	import fixIfDefProg [stringlit]

	construct commandForNonIf [stringlit]
		_ [+ fixIfDefProg] [+ " "] [+ CompleteFileName] [+ " "] [+ CompleteFileName]  [+ " "]  [+ nonIfDefsOutput]
	construct CallCommand2 [id]
    	_ [system commandForNonIf]
	construct outputFileCompleteName [stringlit]
		_ [+ nonIfDefsOutput]
	construct ProgramSource [repeat program]
		_ [read outputFileCompleteName] 
		
	construct ProgramSourceFixedComp [repeat program]
		ProgramSource [compoundStmAddBracketsAtOnlyOneStm]
	
	
	
	deconstruct * [repeat function_definition_or_declaration] ProgramSourceFixedComp
		ProgramFunctions [repeat function_definition_or_declaration]
	construct StringFctName [stringlit]
		_ [quote fctName] 
	construct NeededFunction [repeat function_definition_or_declaration]
		ProgramFunctions [extractNeededFunction StringFctName]
	
	
	
	
	import FunctionDefinitionHost [function_definition_or_declaration]
	
	
	deconstruct FunctionDefinitionHost
		headerFct [function_header] repPreproc [repeat preprocessor_function_header] bodyFct [compound_statement]
		
	construct newBodyWithArgs [compound_statement]
		bodyFct [addAdditionalVariables StringFctName]
	
	construct FunctionDefinitionHostArgs [function_definition_or_declaration]
		headerFct repPreproc newBodyWithArgs
	

	
	
	%construct symbol table and abstract the function definition
	construct functionName [stringlit]
		StringFctName 
    construct localAndGlobalSymbolTable [repeat declaration]
     	_ [constructLocalSymbolTable FunctionDefinitionHostArgs] 
     	
 	
     	
	construct listOfBaseDeclarators [repeat base_declarator]
		_ [^ localAndGlobalSymbolTable] 
	construct listOfBaseDeclaratorsAsIDs[repeat id]
		_ [^ listOfBaseDeclarators] 
	construct newFunctionDefinition [function_definition_or_declaration]
		FunctionDefinitionHostArgs [abstractAllId listOfBaseDeclaratorsAsIDs StringFctName]
	
		
		
	construct newFunctionDefinitionFixedInitialization [function_definition_or_declaration]
		newFunctionDefinition [separateInitializationForEveryBlock]
	
	
	%construct symbol table and abstract the called function for the return value maybe???
	
	
	
	construct CalledFctName [stringlit]
		currentCalledString
	construct ArgsSymbolTable [repeat declaration]
		_ [symbolTableArgs currentCalled]
		

	%JUST if it is the entry point, add its arguments as abstract values
	
	construct addTheParamsForEntryPoint [repeat declaration]
		_ [exportEntryPointParams first]

	
	%determine the return value of the next function
	construct FunctionsSymbols [repeat return_structure]
		_ [determineReturnValues currentCalled] 
	
	deconstruct * [return_structure] FunctionsSymbols
		CalledFunctionRet [return_structure]
	
	
	
	%NEW: DETERMINE RETUEN STRUCT FOR ALL CALELD FUNCTIONS!
	
	
	construct calledFunctionsReturnedStructure [repeat return_structure]
		_ [determineReturnValuesListOfEntries ListOfCalledFunctions]
	
	construct mdsmkdsa [repeat return_structure]
		calledFunctionsReturnedStructure 
		
		
	construct allCalledRepeatString [repeat stringlit]
		_ [repeatGraphEntryToStringlit ListOfCalledFunctions]
	
	
	
	%first replace return statements with just return
	
	construct finalFunctionDefinition [function_definition_or_declaration]
		newFunctionDefinitionFixedInitialization % [removeReturnStatements functionName]
	
	
	%add new declarations for argc, argv if it is the main function
	
	

	
	
	%place for grammarRewrite
	construct resultAsRepeat [repeat function_definition_or_declaration]
		_ [rewriteAsLocs finalFunctionDefinition currentCalledString CalledFunctionRet ArgsSymbolTable CoreFunction ListOfCalledFunctions calledFunctionsReturnedStructure functionName] 
		
		

		
	deconstruct resultAsRepeat	
		LOCsFromFct	[function_definition_or_declaration] restNull [repeat function_definition_or_declaration]
		
	deconstruct * [function_header] FunctionDefinitionHostArgs
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
	by
		current [. completeFunction]
		[writeACandidate rest restCalled CoreFunction ListOfCalledFunctions]
end function


function addAdditionalVariables	FctName [stringlit]
	replace * [compound_statement_body]
		current [compound_statement_body]
	
	deconstruct * [repeat declaration_or_statement] current
		currentBlock [repeat declaration_or_statement]
	
	deconstruct currentBlock
		first [declaration_or_statement] rest [repeat declaration_or_statement]
	
	construct newDeclaration [stringlit]
		"int argc;"
		
	construct newDeclID [id]
		_ [unquote newDeclaration]
	construct newDeclarationStm [declaration_or_statement]
		first [parse newDeclID]
		
		
	construct newDeclarationV [stringlit]
		"char ** argv;"
		
	construct newDeclIDV [id]
		_ [unquote newDeclarationV]
	construct newDeclarationStmV [declaration_or_statement]
		first [parse newDeclIDV]
	construct newRepeat [repeat declaration_or_statement]
		_ [.newDeclarationStm] [. newDeclarationStmV] [. currentBlock]
		
	construct newComBody [compound_statement_body]
		newRepeat
	where
		FctName [= "main"]
	
	
	by
		newComBody
		
end function








function repeatGraphEntryToStringlit	ListOfGraphEntry [repeat graph_entry]
	replace [repeat stringlit]
		current [repeat stringlit]
		
	deconstruct ListOfGraphEntry 
		first [graph_entry] rest [repeat graph_entry]
		
	deconstruct * [id] first
		currentCalledID [id]
	construct currentCalledString [stringlit]
		_ [quote currentCalledID]	
	
	by
		current [. currentCalledString]
		[repeatGraphEntryToStringlit rest]
end function



function exportEntryPointParams	CurrentFunction [graph_entry]
	replace [repeat declaration]
		_ [repeat declaration]
	
	import FixedEntryPoint [number]
	
	where 
		FixedEntryPoint [= 0]
		
		export FixedEntryPoint
			1
		
		construct abstractFromEntryFunctionParams [repeat declaration]
			_ [symbolTableArgs CurrentFunction]
	 
	 	construct symbolsEntries [repeat symbol_table_entry]
	 		_ [reparse abstractFromEntryFunctionParams]
	 	import EntryPointSymbolTable [repeat symbol_table_entry]
	 	export EntryPointSymbolTable
	 		EntryPointSymbolTable [. symbolsEntries]

		
	by
		_
end function





rule compoundStmAddBracketsAtOnlyOneStm
	replace $ [sub_statement]
		stn [statement]
	construct newCompoundStmBody [compound_statement_body]
		stn
	construct newCompoundStm [compound_statement]
		{ newCompoundStmBody }
	construct newCompSubStm [sub_statement]
		newCompoundStm
	by
		newCompSubStm
end rule



rule separateInitializationForEveryBlock
	replace $ [compound_statement_body]
		currentBody [compound_statement_body]
	
		
	deconstruct currentBody
		declFromBody [repeat declaration_or_statement]
		
	construct newBlockDeclStm [repeat declaration_or_statement]
		_ [extendInitializationInBlock declFromBody]

	construct newBlock [compound_statement_body]
		newBlockDeclStm

	by
		newBlock
end rule

function extendInitializationInBlock	InitialBlock [repeat declaration_or_statement]
	replace [repeat declaration_or_statement]
		finalBlock [repeat declaration_or_statement]
	deconstruct InitialBlock
		first [declaration_or_statement] rest [repeat declaration_or_statement]
	
	construct firstRepeat [repeat declaration_or_statement]
		_ [.first]
		
	construct firstExtended [repeat declaration_or_statement]
		firstRepeat [extendInitializationInDeclaration first]
	
	by
		finalBlock [. firstExtended]
		[extendInitializationInBlock rest]
		
end function

function extendInitializationInDeclaration	CurrentDeclaration [declaration_or_statement]
	replace [repeat declaration_or_statement]
		_ [repeat declaration_or_statement]
		
	deconstruct CurrentDeclaration
		Decl [declaration]
		
	%it should have this list
	deconstruct * [list init_declarator] Decl
		hasListInitDecl [list init_declarator]	
		
	%only this declarations for the moment
	deconstruct Decl
		DeclSpec [decl_specifiers] initializationFromDecl [list init_declarator] semiMark [semi]
		

		
		

	%first construct the new declaration, without init declarator
	%before this all declaration where extended, so only one variable is declared at a declaration
	
	deconstruct initializationFromDecl
		firstInit [init_declarator] , restInit [list init_declarator]
		
	%we are interested just in declarations with initialization
		
	deconstruct firstInit
		theDeclarator [declarator] neededInitialization [initialization]
	
	construct initDeclNoInit [init_declarator]
		theDeclarator
		
	construct newRepeatInitDecl [repeat init_declarator]
		_ [. initDeclNoInit]
	
	construct newListInitDecl [list init_declarator]
		_ [, each newRepeatInitDecl]
	
	construct newVarDecl [declaration]
		DeclSpec newListInitDecl semiMark
		
		
	%next construct the statement, from the base declarator and the initializer
	
	deconstruct * [base_declarator] theDeclarator
		justBaseDecl [base_declarator]	
		
		
	construct initializationStringlit [stringlit]
		_ [quote neededInitialization]
	construct baseDeclStringlit [stringlit]
		_ [quote justBaseDecl]	
	
	construct newStatementStringlit [stringlit]
		baseDeclStringlit [+ " "] [+ initializationStringlit] [+ ";"]
		
		
	%now transform these to declaration_or_statement, and replace in the original	
	construct newStatement [repeat declaration_or_statement]
		_ [parse newStatementStringlit]
	
	construct newDeclOrStm [declaration_or_statement]
		newVarDecl
	
	by
		_ [. newDeclOrStm] [.newStatement]
end function








function solveReturnStatements	DeclStm [declaration_or_statement]
								FunctionName [stringlit]
								FctVoidOrNon [stringlit]
	replace [declaration_or_statement]
		currentDecl [declaration_or_statement]
		
	
	skipping [compound_statement]	
	deconstruct * [jump_statement] currentDecl
		current [jump_statement]
		
	import additionalDeclForReturn [repeat declaration_or_statement]
	construct currentString [stringlit]
		_ [quote current] 
		
	
	construct gotoLabelString [stringlit]
		_ [+ "LABEL_"] [+ FunctionName]
	
	

	
	construct gotoLabel [id]
		_ [unquote gotoLabelString]
		
	
	construct returnReplacement [jump_statement]
		'goto gotoLabel
		
		

		
	where
		currentString [grep "return"]
		
		
		construct returnedValue [stringlit]
			currentString [: 8 100]
			
		
		
		construct emptyDeclStm [repeat declaration_or_statement]
			_
		construct newDeclStmNonVoid [repeat declaration_or_statement]
			emptyDeclStm [constructDeclarationForNonVoid FctVoidOrNon FunctionName returnedValue]
			
		construct newDeclStm [repeat declaration_or_statement]
			newDeclStmNonVoid [constructDeclarationForVoid FctVoidOrNon FunctionName returnedValue]
		
		
		
		export additionalDeclForReturn
			additionalDeclForReturn [. newDeclStm]
			

		construct emptyLabel [repeat label]
			_			
		construct returnReplacementStm [statement]
			emptyLabel returnReplacement ';
		
		construct returnReplacementDeclStm [declaration_or_statement]
			returnReplacementStm
			
						
						construct mdskadmks [stringlit]
		gotoLabelString 
			
	by
		returnReplacementDeclStm
end function


function constructDeclarationForNonVoid	FctVoidOrNon[stringlit]
										FunctionName [stringlit]	
										returnedValue [stringlit]
	replace [repeat declaration_or_statement]
		_ [repeat declaration_or_statement]
		
	construct returnMarkerAbst [stringlit]
			"/*@STM*/ $ABSTRETVAL_ret_"
		
		
	construct newDeclarationStatement [stringlit]
		returnMarkerAbst [+ FunctionName] [+ " = "] [+ returnedValue] [+ ";"]
		
	construct newDeclStmId [id]
		_ [unquote newDeclarationStatement]
		
	construct newDeclStm [declaration_or_statement]
		newDeclarationStatement
	
	where
		FctVoidOrNon [= "non_void"]
		
	by
		_ [. newDeclStm]
end function

function constructDeclarationForVoid	FctVoidOrNon[stringlit]
										FunctionName [stringlit]	
										returnedValue [stringlit]
	replace [repeat declaration_or_statement]
		_ [repeat declaration_or_statement]
		
	construct returnMarkerAbst [stringlit]
			"/*@STM*/ $ABSTRETVAL_ret_"
		
	construct newDeclStm [declaration_or_statement]
		returnedValue  [+ ";"]
		
	construct lengthOfReturnedVal [number]
		_ [# returnedValue]
	
	where 
		FctVoidOrNon [= "void"]
	where
		lengthOfReturnedVal [> 0]
	by
		_ [. newDeclStm]
end function


rule removeReturnStatements	FunctionName [stringlit]
	replace  $ [jump_statement]
		current [jump_statement]
	
	construct currentString [stringlit]
		_ [quote current] 
		
	
	construct gotoLabelString [stringlit]
		_ [+ "LABEL_"] [+ FunctionName]
	
	
	construct gotoLabel [id]
		_ [unquote gotoLabelString]
		
	
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

	import donorSourceFiles [stringlit] %with /!!!
	deconstruct first
		fctName [id] srcToken [source_file_token] SourceFileName [source_file_element] 
	construct inputFileName [stringlit]
		_ [quote SourceFileName]
	construct path [stringlit]
		donorSourceFiles	
	construct lengthOfFileName [number]
		_ [# inputFileName] [- 2]
	construct inputFilNameNoMarks [stringlit]
		inputFileName [: 3 lengthOfFileName]
	construct CompleteFileName [stringlit]
		path [+ inputFilNameNoMarks] 
	construct nonIfDefsOutput [stringlit]
		CompleteFileName [+ "NON"]

	import fixIfDefProg [stringlit]

	construct commandForNonIf [stringlit]
		_ [+ fixIfDefProg] [+ " "] [+ CompleteFileName] [+ " "] [+ CompleteFileName]  [+ " "]  [+ nonIfDefsOutput]
	construct CallCommand2 [id]
    	_ [system commandForNonIf]
	construct outputFileCompleteName [stringlit]
		_ [+ nonIfDefsOutput]
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
		


	%separate initialization from declaration
	construct newFunctionDefinitionFixedInitialization [function_definition_or_declaration]
		newFunctionDefinition [separateInitializationForEveryBlock]
		
		


	%construct the abstract symbol table

	construct localAndGlobalSymbolTableAbstract [repeat declaration]
     	_ [constructLocalSymbolTable newFunctionDefinitionFixedInitialization] 



	deconstruct * [function_header] newFunctionDefinitionFixedInitialization
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
		
		%first extend declarations!
		%and remove static/constant from declarations, for avoiding compilation errors related to this
		
		construct currentExtended [function_definition_or_declaration]
			current [extendAllDeclarations]
		
		
		export FunctionDefinitionHost [function_definition_or_declaration]
			currentExtended
end function



function deconstructFunctionDefinition currentFctDef [function_definition_or_declaration]
	replace [id]
		_ [id]
	deconstruct * [function_definition] currentFctDef
		justFunct [function_definition]
	deconstruct * [function_header] justFunct
		fctHeader [function_header]

	deconstruct fctHeader
		spec [opt decl_specifiers] decl [declarator] ext[function_declarator_extension] 
	deconstruct * [base_declarator] decl
		justTheBaseDecl [base_declarator]
	construct stringFromDecl [stringlit]
		_ [quote justTheBaseDecl]
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
						CoreFunction [id]
						ListOfCalledFunctions [repeat graph_entry]
						AllCalledReturnStruct [repeat return_structure]
						CurrentExistingFunction [stringlit]
	replace [repeat function_definition_or_declaration]
		current [repeat function_definition_or_declaration]
		
		
	deconstruct * [compound_statement_body] FctDef
		currentFctBody [compound_statement_body]
	
	deconstruct * [repeat declaration_or_statement] currentFctBody
		FctDecl [repeat declaration_or_statement]
	
	deconstruct * [function_header] FctDef
		currentFctHeader [function_header]
	
	
	construct functionNonVoid [stringlit]
		"non_void"
	construct functionVoidOrNon [stringlit]
		functionNonVoid [checkIfVoid currentFctHeader]
	
		
	construct FctDeclMarkers [repeat declaration_or_statement]	
		_ [ToDeclStmMarkers FctDecl] 
		
		
	export ReachedCall [stringlit]
		"NO"
		
		
		
	construct newFunctionFixed [function_definition_or_declaration]
		FctDef [fixEveryBlock FctDeclMarkers CurrentCalledFunction CalledFctReturn ArgsSymbolTable CoreFunction ListOfCalledFunctions AllCalledReturnStruct CurrentExistingFunction functionVoidOrNon]
		
	
		
	construct completeFctNoStringlit [function_definition_or_declaration]
		newFunctionFixed [everyBlockToIDs] 
		
	
		
	by
		_ [. completeFctNoStringlit]
		
end function

function checkIfVoid	FctHeader [function_header]
	replace [stringlit]
		current [stringlit]
	
	deconstruct FctHeader
		declSpec [ decl_specifiers] declaratorF [declarator] fctExt [function_declarator_extension] 
		
	deconstruct declaratorF
		repPtr [repeat ptr_operator] baseDecl [base_declarator] declExt [repeat declarator_extension]
		
	construct ptrOpString [stringlit]
		_ [quote repPtr]
		
	export ExtensionIfRequired [stringlit]
		_ [quote declExt]
			
	construct declSpecString [stringlit]
		_ [quote declSpec]
	construct declaratorFString [stringlit]
		_ [quote declaratorF]
	construct declString [stringlit]
		_ [+ declSpecString]  [+ ptrOpString] 		
		
	where
		declString [= void]
	
	by
		"void"
end function



rule everyBlockToIDs
	replace $ [compound_statement]
		currentBlock [compound_statement]
		deconstruct * [compound_statement_body] currentBlock
			currentBlockBody [compound_statement_body]
		construct blockReplacedDeclStm [compound_statement_body]
			currentBlockBody [replaceDeclStmNoBodyStringlit]
		construct replacedBlock [compound_statement]
			'{ blockReplacedDeclStm '}	
	by
		replacedBlock
end rule


rule replaceDeclStmNoBodyStringlit
	skipping [compound_statement]
	replace $ [declaration_or_statement]
		current [declaration_or_statement]
		
	deconstruct current
		currentStringlit [stringlit]	
	construct newDeclID [id]
		_ [unquote currentStringlit]
		
		
		
		construct mdskds [id]
		newDeclID 
		
		
	construct declAsStringlit [stringlit]
		_ [quote current]
		


	construct finalReplacement [stringlit]
		declAsStringlit
	construct replacementAsDeclStatement [declaration_or_statement]
		finalReplacement
	deconstruct not * [compound_statement_body] current
		currentCompund [compound_statement_body]

	by
		newDeclID
end rule


%do it at blocks level!!!!
rule fixEveryBlock	Decl [repeat declaration_or_statement]
					CurrentCalledFunction [stringlit]
					CurrentCalledRet [return_structure]
					ArgsSymbolTable [repeat declaration]
					CoreFunction [id]
					ListOfCalledFunctions [repeat graph_entry]
					AllCalledReturnStruct [repeat return_structure]
					CurrentExistingFunction [stringlit]
					FctVoidOrNon [stringlit]
	replace $ [compound_statement]
		currentBlock [compound_statement]
		
	


	

	
	deconstruct * [compound_statement_body] currentBlock
		currentBlockBody [compound_statement_body]
	deconstruct currentBlockBody
		currentBlockDeclStm [repeat declaration_or_statement]
	construct DeclAsStrings [repeat declaration_or_statement]
		_ [declToStringlit currentBlockDeclStm CurrentCalledFunction CurrentCalledRet ArgsSymbolTable CoreFunction ListOfCalledFunctions AllCalledReturnStruct CurrentExistingFunction FctVoidOrNon] 
	%construct blockReplacedDeclStm [compound_statement_body]
		%currentBlockBody [replaceDeclStmNoBody]
	construct newBlockBody [compound_statement_body]
		DeclAsStrings
	construct replacedBlock [compound_statement]
		'{ newBlockBody '}	
		
	by
		replacedBlock
end rule



function stringlitToId 	ListOfStrings [repeat declaration_or_statement]
	replace [repeat ids_with_line_break]
		current [repeat ids_with_line_break]
	deconstruct ListOfStrings 
		first [declaration_or_statement] rest [repeat declaration_or_statement]
	
	
	
	construct firstString [stringlit]
		_ [quote first]
		
	construct intermediateFirstStrng [stringlit]
		firstString [replaceIfItIsString first]
		
		construct finalFirstStrng [stringlit]
		intermediateFirstStrng [replaceIfItIsString first]
	
	construct firstId [id]
		_ [unquote finalFirstStrng]
	
	
	
	construct idWithLB [ids_with_line_break]
		firstId
		
		
	construct mdskds [ids_with_line_break]
		idWithLB 
		
	by
		current [. idWithLB]
		[stringlitToId rest]
end function




function declOrStatementToStringlit	CurrentDecl [declaration_or_statement]
	replace [declaration_or_statement]
		current [stringlit]
	deconstruct not CurrentDecl
		CurrentDeclStringlit [stringlit]	
		
		
	construct currentDeclStringlit [stringlit]
		_ [quote CurrentDecl]
		
	construct newDeclFromStringlit [declaration_or_statement]
		currentDeclStringlit
	by
		newDeclFromStringlit
end function






function replaceIfItIsString	Current [declaration_or_statement]
	replace [stringlit]
		_ [stringlit]
	deconstruct * [stringlit] Current
		currentString [stringlit]
	by
		currentString
		
end function


function ToDeclStmMarkers	Initial [repeat declaration_or_statement]
	replace [repeat declaration_or_statement]
		current [repeat declaration_or_statement]
	deconstruct Initial
		first [declaration_or_statement] rest [repeat declaration_or_statement]
	construct CurrDecl [declaration_or_statement]
		first
		
	by
		current [. CurrDecl]
		[ToDeclStmMarkers rest]
end function





function declToStringlit	Decl [repeat declaration_or_statement]
							CurrentCalledFunction [stringlit]
							CurrentCalledRet [return_structure]
							ArgsSymbolTable [repeat declaration]
							CoreFunction [id]
							ListOfCalledFunctions [repeat graph_entry]
							AllCalledReturnStruct [repeat return_structure]
							CurrentExistingFunctionName [stringlit]
							FctVoidOrNon [stringlit]
	replace [repeat declaration_or_statement]
		current [repeat declaration_or_statement]
	deconstruct Decl 
		first [declaration_or_statement] rest [repeat declaration_or_statement]
		
		
	export BeginCompoundMarker [repeat declaration_or_statement]
		_
	export EndCompoundMarker [repeat declaration_or_statement]
		_
	%add the function mark also at the beggining
	export AdditionalFunctionCall [repeat declaration_or_statement]
		_
	export LabelMarker [repeat declaration_or_statement]
		_	
		
		
	%first handle the return statement
	export additionalDeclForReturn [repeat declaration_or_statement]
		_ 
	construct firstSolvedReturns [declaration_or_statement]
		first [solveReturnStatements first CurrentExistingFunctionName FctVoidOrNon]
		
		
	construct firstSolvedCallFunctions [declaration_or_statement]
		firstSolvedReturns  [solveCalledFunctionNoCompund firstSolvedReturns CurrentCalledFunction CurrentCalledRet ArgsSymbolTable CoreFunction ListOfCalledFunctions AllCalledReturnStruct]
	%fix order for compund statemend; it should be first
	
	
	%add markers at declarations!!!	
	construct firstSolvedStatement [declaration_or_statement]
		firstSolvedCallFunctions [addMarkerAtDeclarations]
	
	
	
	construct firstWithLineStatements [declaration_or_statement]
		firstSolvedStatement [addNumberAtStatements]	
		
		
	construct firstWithLineSolvedOneParamFctCall [declaration_or_statement]
		firstWithLineStatements [addNumberAtStmFunctCallWithOneParameter firstSolvedCallFunctions]
		
	construct firstWithLine [declaration_or_statement]
		firstWithLineSolvedOneParamFctCall [addNumberAtMacros firstSolvedCallFunctions] 
		
		

	export ElseStatement [repeat declaration_or_statement]
		_	
		
	construct finalStringNoElse [declaration_or_statement]
		firstWithLine [solveCompundStatement firstSolvedReturns CurrentCalledFunction CurrentCalledRet ArgsSymbolTable CoreFunction ListOfCalledFunctions AllCalledReturnStruct]
	%construct finalRest [repeat declaration_or_statement]
		%rest [AddFromCompund first]
		
	
	construct finalString [declaration_or_statement]
		finalStringNoElse [solveElseCompounds firstSolvedReturns CurrentCalledFunction CurrentCalledRet ArgsSymbolTable CoreFunction ListOfCalledFunctions AllCalledReturnStruct]
	
	import additionalDeclForReturn
	import ElseStatement 
	import BeginCompoundMarker [repeat declaration_or_statement]
	import EndCompoundMarker [repeat declaration_or_statement]
	import AdditionalFunctionCall [repeat declaration_or_statement]
	import LabelMarker [repeat declaration_or_statement]	
	construct finalStringAddedFunctionCall [repeat declaration_or_statement]
		AdditionalFunctionCall [.BeginCompoundMarker] [. finalString] [. LabelMarker]

	construct newRest [repeat declaration_or_statement]
		_ [. ElseStatement] [. rest]% [. ElseStatement]
		
	construct reallyFinalNewStm [repeat declaration_or_statement]
		finalStringAddedFunctionCall %[revertToOriginalIfCompound first]
	
	by
		_ [. current] [.additionalDeclForReturn] [. reallyFinalNewStm]  [. EndCompoundMarker]
		[declToStringlit newRest CurrentCalledFunction CurrentCalledRet ArgsSymbolTable CoreFunction ListOfCalledFunctions AllCalledReturnStruct CurrentExistingFunctionName FctVoidOrNon]
end function










function addMarkerAtDeclarations
	replace [declaration_or_statement]
		current [declaration_or_statement]
	deconstruct not * [statement] current
		currentNotStatement [statement] 
	deconstruct not * [macro_specifier] current
		currentNotMacro [macro_specifier] 
	construct LineString [stringlit]
		"@DECL"
	%comment the line numbers	
	construct commentStartMarker [stringlit]
		"/*"
	construct commentEndMarker [stringlit]
		"*/ "
	construct FinalLineString [stringlit]
		commentStartMarker [+ LineString] [+ commentEndMarker]
	construct currentStatementString [stringlit]
		FinalLineString [quote current]
	construct currentStmLine [declaration_or_statement]
		currentStatementString
	by
		currentStmLine
end function























function revertToOriginalIfCompound	DeclOrStm [declaration_or_statement]
	replace [repeat declaration_or_statement]
		current [repeat declaration_or_statement]
	deconstruct * [compound_statement_body] DeclOrStm
		compStmBody [compound_statement_body]
	
	by
		_ [. DeclOrStm]
		
end function





function hasCompundBody
	match [declaration_or_statement]
		current [declaration_or_statement]
	
	deconstruct * [compound_statement_body] current
		currentCompund [compound_statement_body]
end function



function solveCalledFunctionNoCompund	OriginalStm [declaration_or_statement]
										CurrentCalledFunction [stringlit]
										CurrentCalledRet [return_structure]
										ArgsSymbolTable [repeat declaration]
										CoreFunction [id]
										ListOfCalledFunctions [repeat graph_entry]
										AllCalledReturnStruct [repeat return_structure]
	replace [declaration_or_statement]
		current [declaration_or_statement]
		
	deconstruct * [declaration_or_statement] OriginalStm
		declStmOriginal [declaration_or_statement]
		
	where not
		declStmOriginal [hasCompundBody]		
		
		construct msssss [declaration_or_statement]
			OriginalStm 
		
		construct newCurrent [declaration_or_statement]	
			current [solveCalledFunction OriginalStm CurrentCalledFunction CurrentCalledRet ArgsSymbolTable CoreFunction ListOfCalledFunctions AllCalledReturnStruct]
		
	by
		newCurrent
end function
									

%add callings to functions; if value is used solve this; solve in compund statements; solve pointers!!!
function solveCalledFunction	OriginalStm [declaration_or_statement]
								CurrentCalledFunction [stringlit]
								CurrentCalledRet [return_structure]
								ArgsSymbolTable [repeat declaration]
								CoreFunction [id]
								ListOfCalledFunctions [repeat graph_entry]
								AllCalledReturnStruct [repeat return_structure]
								
				
	
	replace [declaration_or_statement]
		current [declaration_or_statement]
		
		
		
	%do not look at the else clauses here; they will be solved later	
	%construct OriginalStmNoElseClause [declaration_or_statement]
		%OriginalStm [removeElseClause]
		
	deconstruct  [declaration_or_statement] OriginalStm
		currStatement [declaration_or_statement]

	
	export ReplacedToken [repeat declaration_or_statement]
		_
	
	construct replacedArgs [declaration_or_statement]
		currStatement [replaceNeededFunctionCallArgs CurrentCalledFunction CurrentCalledRet ArgsSymbolTable CoreFunction ListOfCalledFunctions AllCalledReturnStruct] 
	construct replacedUnaryExpr [declaration_or_statement]
		replacedArgs [replaceNeededFunctionCallUnaryExpr CurrentCalledFunction CurrentCalledRet ArgsSymbolTable CoreFunction ListOfCalledFunctions AllCalledReturnStruct]
	
	
	
	
	
	%in the case of replaced macro specifier, the function calling is direct, so no need to add it again in the global variable
	construct replacedMacroSpecifier [declaration_or_statement]
		replacedUnaryExpr [replaceNeededFunctionCallMacroSpecifier CurrentCalledFunction CurrentCalledRet ArgsSymbolTable CoreFunction ListOfCalledFunctions AllCalledReturnStruct]

	construct exportFunction [declaration_or_statement]
		currStatement [exportFunctionNameIfCalled replacedMacroSpecifier]

	by
		replacedMacroSpecifier
		
end function


function exportFunctionNameIfCalled	NewDeclStatement [declaration_or_statement]
	match [declaration_or_statement]
		current [declaration_or_statement]
	construct Old [stringlit]
		_ [quote current]
	construct New [stringlit]
		_ [quote NewDeclStatement]

	where not
		Old [= New]
		
		import ReachedCall [stringlit]
		
		export ReachedCall [stringlit]
			"YES"
		
		
		import AdditionalFunctionCall [repeat declaration_or_statement]
		
		import ReplacedToken [repeat declaration_or_statement]

		%(construct FctCallMarker [stringlit]
			"//call the function: "
		construct finalFctCall [stringlit]
			FctCallMarker [+ FctName] %[+ Old]
		construct declStmMarkerNewFct [declaration_or_statement]
			finalFctCall
		)%
		export AdditionalFunctionCall 
			_ [. ReplacedToken] 
end function




rule replaceNeededFunctionCallMacroSpecifier	FunctionNameNON [stringlit]
												CurrentCalledRetNOT_USED [return_structure]
												ArgsSymbolTableNOT_USED [repeat declaration]
												CoreFunction [id]
												ListOfCalledFunctions [repeat graph_entry]
												AllCalledReturnStruct [repeat return_structure]
	skipping [compound_statement]
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
	%construct unique fct identifier
	construct fctID [id]
		_ [unquote macroAsString]
	construct uniqueFctID [id]
		fctID [!]
	construct uniqueFctStringlit [stringlit]
		_ [quote uniqueFctID]
	construct variableName [stringlit]
		retName [+ macroAsString] [+ " "] [+ uniqueFctStringlit]
	construct variableID [id]
		_ [unquote variableName]
	construct MacroN [macro_name]
		variableID
	construct MacroC [macro_call]
		MacroN '(  ')
	construct FTT [macro_specifier]
		MacroC
		
		
		
	construct emptyMacroString [stringlit]
		"//REMOVE_THIS"
	construct emptyMacroStringID [id]
		_ [unquote emptyMacroString]
	construct emptyMacroN [macro_name]
		emptyMacroStringID
	construct emptyMacroC [macro_call]
		emptyMacroN '( ')
	construct emptyMacroSpec [macro_specifier]
		emptyMacroC
		
		
		
	construct macroCallString [stringlit]
		_ [quote FTT]	
	construct declStmMacroSpec [declaration_or_statement]
		macroCallString
		
	%assure not replacing an already replaced one	
	%construct indexOfFunction [number]
	%	_ [index exprAsString FunctionName] [- 1]
	%construct initialPosition [number]
	%	indexOfFunction [- 15]
	%construct replacedSign [stringlit]
	%	exprAsString [: initialPosition indexOfFunction] 
	
			export FunctionName [stringlit]
		""
			export ArgsSymbolTable [repeat declaration]
		_
		export returnStructureOfCalled [repeat return_structure]
			_
			
	where 
		%express [matchCoreFunctionCall FunctionName]
		express [matchCoreFunctionCall ListOfCalledFunctions exprAsString]
		import FunctionName
		import ArgsSymbolTable
		import returnStructureOfCalled
		deconstruct * [return_structure] returnStructureOfCalled
			CurrentCalledRet [return_structure]
			

			
		
		
	%where not
	%	replacedSign [= "$ABSTRETVAL_ret_"]
		deconstruct CurrentMacroArgs
			ListOfArgs [repeat macro_argument] 
		construct MacroArgsStringlit [stringlit]
			_ [quote CurrentMacroArgs]
		construct LengthOfMacroArgs [number]
			_ [# MacroArgsStringlit]
		construct MacroArgsNoBrackets [stringlit]
			MacroArgsStringlit [: 1 LengthOfMacroArgs]
		construct macroAsRepeatStrings [repeat stringlit]
			_ [deconstructArgumentsIntoListOfStringlit MacroArgsNoBrackets]
		construct FinalArgsAsRepeatStrings [repeat stringlit]
			macroAsRepeatStrings [addArgumentsIntoListOfStringlitWhenJustOne MacroArgsNoBrackets]		
		deconstruct * [function_name_return] CurrentCalledRet
			calledFctName [function_name_return]
		export CurrentFunctionMappings [repeat symbol_mapping]
			_
		export ListOfArgumentsForReturn [list id]
			_
		export AbstractionFctMappings [repeat symbol_mapping]
			_
		construct ListOfDeclarations [repeat declaration_or_statement]
			_ [declarationArgsToStringlit ArgsSymbolTable FinalArgsAsRepeatStrings calledFctName uniqueFctStringlit] 

		import ListOfArgumentsForReturn [list id]
		import CurrentFunctionMappings [repeat symbol_mapping]
		import AbstractionFctMappings [repeat symbol_mapping]
		construct uniqueFctNameAsID [id]
			_ [unquote uniqueFctStringlit]
		construct newFctInstMapping [function_instante_mappings]
			uniqueFctNameAsID CurrentFunctionMappings '@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
		construct newAbstractMappings [function_instante_mappings]
			uniqueFctNameAsID AbstractionFctMappings '@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
		import MappingsForFunctionInstantiation [repeat function_instante_mappings]
		export MappingsForFunctionInstantiation [repeat function_instante_mappings]
			MappingsForFunctionInstantiation [. newFctInstMapping]
		import CurrentMappingList [repeat function_instante_mappings]	
		export CurrentMappingList [repeat function_instante_mappings]	
			CurrentMappingList [. newAbstractMappings]
		import AdditionalFunctionCall [repeat declaration_or_statement]
		export AdditionalFunctionCall
			_

		%mapping table
		import ReplacedToken [repeat declaration_or_statement]
		construct mappingTableMarker [stringlit]
			"//Mappings for function: "
		construct finalMappings [stringlit]
			mappingTableMarker [+ exprAsString] [+ ";"]
		construct exprAsDeclStmMarker [declaration_or_statement]
			finalMappings
		construct currentCalledFunctionNameID [id]
			_ [unquote FunctionName]
			
			
			
		%construct the label
		construct labelMarkerS [stringlit]
			"LABEL_"
		construct labelNameString [stringlit]
			labelMarkerS [+ FunctionName] 
		construct LabelName [id]
			_ [unquote labelNameString]
		construct labelID [id]
			LabelName [!]
		construct labelString [stringlit]
			_ [quote labelID]
		construct finalLabelString [stringlit]
			labelString [+ " :"]
		construct noOpStmString [stringlit]
			"if(0){}"
		construct noOpDStm [declaration_or_statement]
			noOpStmString
		construct noOpDStmMarker [repeat declaration_or_statement]
			_ [. noOpDStm]
		construct fls [declaration_or_statement]
			finalLabelString	
		construct labelDeclOrStmMarker [repeat declaration_or_statement]
			_ [. fls]
	
		import ListOfAddedLabels [repeat declaration_or_statement]
		export ListOfAddedLabels
			ListOfAddedLabels [. fls]	
			
			
			
			
			
			
			
			
			
			
			
			
			
	construct retNameVAR [stringlit]
		"$ABSTRETVAL_ret_"
		
			%add here the array marker if case!!
	import ExtensionIfRequired [stringlit]
			
	construct initialVariableNameVAR [stringlit]
		retNameVAR [+ FunctionName]
	construct initialVariableNameIDVAR [id]
		_ [unquote initialVariableNameVAR]

	construct initialVariableNameIDUniqueVAR [id]
		initialVariableNameIDVAR [!]
		
	construct initialStringVarNameUniqueVAR [stringlit]
		_ [quote initialVariableNameIDUniqueVAR]
		
		
	construct variableNameVAR [stringlit]
		initialStringVarNameUniqueVAR [+ ExtensionIfRequired]
		
	construct variableIDVAR [id]
		_ [unquote variableNameVAR]
	construct FTTVAR [argument_expression]
		variableIDVAR

			
			
			
			
			
			
			
		%construct the variable declaration that will replace the function call	
		deconstruct CurrentCalledRet 
			RetName [function_name_return] RetType [return_type] RetVar[return_variable]	
		construct ReplacementName [stringlit]
			_ [quote FTTVAR]
		deconstruct * [stringlit] RetName
			RetNameStringlit [stringlit]
		deconstruct * [stringlit] RetType
			RetTypeStringlit [stringlit]
		deconstruct * [stringlit] RetVar 
			RetVarStringlit [stringlit]
			
		
		construct AbstractRetVar [stringlit]
			_ [+ "$ABST_"] [+ FunctionName] [+ "_"]  [+ RetVarStringlit] 
			
		%add declaration marker
		construct LineString [stringlit]
			"@DECL"
		%comment the line numbers	
		construct commentStartMarker [stringlit]
			"/*"
		construct commentEndMarker [stringlit]
			"*/ "

		construct testtt [stringlit]
			commentStartMarker [+ LineString] [+ commentEndMarker] [+ RetTypeStringlit] [+ ReplacementName] [+ ";"]
		construct testDeclMarker [declaration_or_statement]
			testtt 
			
			
			
			
			
			
			
			
			
		%macroAsString here!!!	
		construct returnIfCase [repeat declaration_or_statement]
			_ [addReturnToLastFunction CoreFunction currentCalledFunctionNameID ListOfArgumentsForReturn]
		export ReplacedToken
			_ [. ListOfDeclarations] [.testDeclMarker] [.returnIfCase] [. exprAsDeclStmMarker] [.declStmMacroSpec] [. labelDeclOrStmMarker] [. noOpDStmMarker]
	by
		emptyMacroSpec
end rule



rule matchCoreFunctionCall	CalledFunctionsList [repeat graph_entry]
							ExpressionAsString [stringlit]
	match [id]
		current [id]
	construct currentString [stringlit]
		_ [quote current]
	where
		CalledFunctionsList [stringInRepeatStringlit currentString ExpressionAsString]
end rule

rule stringInRepeatStringlit	searchedString [stringlit]
								ExpressionAsString [stringlit]
	match [graph_entry]
		currentGraphEntry [graph_entry]
		
		
	deconstruct * [id] currentGraphEntry
		currentID [id]
	
	construct current [stringlit]
		_ [quote currentID]
		
	%assure not replacing an already replaced one	
	construct indexOfFunction [number]
		_ [index ExpressionAsString current] [- 1]
	construct initialPosition [number]
		indexOfFunction [- 15]
	construct replacedSign [stringlit]
		ExpressionAsString [: initialPosition indexOfFunction] 
	where 
		current [= searchedString]
	where not
		replacedSign [= "$ABSTRETVAL_ret_"]
		%we need the source code for all replaced functions	
		import allReplacedFunctions [repeat stringlit]
		construct newCalledFunction [repeat stringlit]
			_ [exportCalledFctIfCase searchedString allReplacedFunctions] 
		export allReplacedFunctions
			allReplacedFunctions [. newCalledFunction]
			
		import FunctionName [stringlit]
		export FunctionName
			current
			
			
		import ArgsSymbolTable [repeat declaration]
			
		export ArgsSymbolTable
			_ [symbolTableArgs currentGraphEntry]
		
		
			%determine the return value of the next function
		construct FunctionsSymbols [repeat return_structure]
		_ [determineReturnValues currentGraphEntry] 
		
		construct msdasd [stringlit]
			FunctionName 
					construct msdsdasd [repeat return_structure]
			FunctionsSymbols 
	
		
	
	
		deconstruct * [return_structure] FunctionsSymbols
			CalledFunctionRet [return_structure]
		
		import returnStructureOfCalled [repeat return_structure]
		
		export returnStructureOfCalled
			FunctionsSymbols
		
		
			
		
	
		
end rule


function returnCalledFunction	CalledFunctionName [stringlit]
	match * [graph_entry]
		current [graph_entry]
	
	
end function



function exportCalledFctIfCase	CalledFctName [stringlit]
								ListOfCalledFunctions [repeat stringlit]			

	replace [repeat stringlit]
		current [repeat stringlit]
		
	where not
		ListOfCalledFunctions [simpleStringInRepeatStringlit CalledFctName]
	
	by
		current [. CalledFctName]
end function


rule simpleStringInRepeatStringlit	searchedString[stringlit]
	match [stringlit]
		current [stringlit]
	where
		current [= searchedString]
end rule






function addArgumentsIntoListOfStringlitWhenJustOne	Arguments [stringlit]
	replace [repeat stringlit]
		current [repeat stringlit]
		
	construct IndexOfComa [number]
		_ [index Arguments ","] 	
		
	where 
		IndexOfComa [= 0]
	by
		Arguments
end function



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
									CalledFunctionName [function_name_return]
									UniqueFunctionID [stringlit]
	replace [repeat declaration_or_statement]
		current [repeat declaration_or_statement]
	deconstruct Declarations
		first [declaration] rest [repeat declaration]
	deconstruct NewValues 
		firstVal [stringlit] restVal [repeat stringlit]	
	deconstruct first 
		declSpec [decl_specifiers] initDecl [list init_declarator] semiMark[semi]
	deconstruct * [init_declarator] initDecl	
		varName [init_declarator]
	deconstruct varName 
		ptrOp [repeat ptr_operator] BaseDecl [base_declarator]  Ext [repeat declarator_extension] 	
	construct varString [stringlit]
		_ [quote BaseDecl]		
	construct varId [id]
		_ [unquote varString]
	construct varUniqueID [id]
		varId [!]
	construct varUniqueIDStringlit [stringlit]
		_ [quote varUniqueID]
	construct varUniqueInitDecl [init_declarator]
		ptrOp varUniqueID Ext	
	construct varCompleteDeclStringlit [stringlit]
		_ [quote varUniqueInitDecl]	
	construct varUniqueListDecl [list init_declarator]
		_ [, varUniqueInitDecl]
	construct newDeclarator [declaration]
		declSpec varUniqueListDecl semiMark
	construct varUniqueDeclString [stringlit]
		_ [quote varUniqueListDecl]
	%maybe write this different!!!
	construct AbstractValueMarker [stringlit]
		UniqueFunctionID [+ "_"] [+ "$ABSTRACT_ID_"]
	construct AbstractValueID [id]
		_ [unquote AbstractValueMarker]
	construct AbstractValue [id]
		AbstractValueID [!] 
	construct AbstractValueString [stringlit]
		_ [quote AbstractValue]
	construct firstAsStringlit [stringlit]
		_ [quote declSpec] [+ " "][+ varUniqueDeclString ] [+ " = "] [+ AbstractValueString ][+ " ;"]
	
	
	construct LineString [stringlit]
		"@DECL"
		
	%comment the line numbers	
	construct commentStartMarker [stringlit]
		"/*"
	construct commentEndMarker [stringlit]
		"*/ "
	construct FinalLineString [stringlit]
		commentStartMarker [+ LineString] [+ commentEndMarker] [+ firstAsStringlit]
	construct firstMarker [declaration_or_statement]
		FinalLineString
		
		
		
		
		
	construct varStringAsID [id]
		_ [unquote varString]
	construct varUniqueIDStringlitasID [id]
		_ [unquote varUniqueIDStringlit]
	construct firstValID [id]
		_ [unquote firstVal]
	construct AbstractValueStringID [id]
		_[ unquote AbstractValueString]
	%mappings from the current function and the next function
	deconstruct * [base_declarator] varName
		varBaseDecl [base_declarator]
	construct varBaseDeclString [stringlit]
		_ [quote varBaseDecl]
	construct varUniqueIdString [stringlit]
		_ [quote varUniqueID]
	construct newMapping [symbol_mapping]
		 AbstractValueStringID firstValID
	construct outputNewMapping [symbol_mapping]
		newMapping   
	%host symbol table	
	import HostSymbolTable [repeat symbol_table_entry]
	
	
	
	
	
	construct declarationReplacedBaseDecl [declaration]
		first [replaceBaseDecl varId AbstractValue]
	
	construct fixedVariableDeclaration [repeat declaration]
		_ [addNextDecl declarationReplacedBaseDecl]
		
		
	%it should be just one, but to be checked!!!!	
	deconstruct * [declaration] fixedVariableDeclaration
		JustTheDecl [declaration]
		
		
	
	
		
		
	construct listOfSymbolTableEntry [symbol_table_entry]
        JustTheDecl
	
	
	
	
	%TEST
	
	
	
	construct declarationAsStringlit [stringlit]
		_ [quote fixedVariableDeclaration]
		
		
		
		
	construct declSpecString [stringlit]
		_ [quote declSpec]
		
	construct typeNameString [stringlit]
		declSpecString [declSpecStringType declSpec]	
		
		
		
		
	
	
	%deconstruct * [type_specifier] declSpec
	%	typeName [type_specifier]
	%construct typeNameString [stringlit]
	%	_ [quote typeName]
		
		
		
		
	deconstruct CalledFunctionName
		calledName [stringlit]
	construct calledNameID [id]
		_ [unquote calledName]
	construct typeNameID [id]
		_ [unquote typeNameString]
	construct varCompleteID [id]
		_ [unquote declarationAsStringlit]	
	construct newHostTableEntry [ symbol_table_entry]
		calledNameID -> typeNameID :  varCompleteID 
	export HostSymbolTable
		HostSymbolTable [. listOfSymbolTableEntry]
	%mappings for instantiation for current function
	import CurrentFunctionMappings [repeat symbol_mapping]
	construct newFunctionInstantiateMapping [symbol_mapping]
		 varStringAsID  varUniqueIDStringlitasID
	export CurrentFunctionMappings
		CurrentFunctionMappings [. newFunctionInstantiateMapping]
		
		
		
	import AbstractionFctMappings [repeat symbol_mapping]
	
	export AbstractionFctMappings [repeat symbol_mapping]
		AbstractionFctMappings [. newMapping] 
		
		
	import ListOfArgumentsForReturn [list id]
	export ListOfArgumentsForReturn 
		ListOfArgumentsForReturn [, varUniqueID]
		
	by
		current [. firstMarker]
		[declarationArgsToStringlit rest restVal CalledFunctionName UniqueFunctionID]
end function


function declSpecStringType	Current [decl_specifiers]
	replace [stringlit]
		_ [stringlit]
		
			
	deconstruct * [type_specifier] Current
		typeName [type_specifier]
		
	construct typeNameString [stringlit]
		_ [quote typeName]
		
	by
		typeNameString
end function




function replaceBaseDecl	IdInFunction [id]
							AbstractID [id]
	replace * [base_declarator]
		current [base_declarator]
	
	construct currentAsString [stringlit]
		_ [quote current]
	construct currentAsId [id]
		_ [unquote currentAsString]	
	
	where
		currentAsId [= IdInFunction]
		construct baseDeclAbstract [base_declarator]
			AbstractID
	by
		baseDeclAbstract
end function



rule replaceNeededFunctionCallArgs	FunctionNameNON [stringlit]
									CurrentCalledRetNOT_USED [return_structure]
									ArgsSymbolTableNOT_USED [repeat declaration]
									CoreFunction [id]
									ListOfCalledFunctions [repeat graph_entry] 
									AllCalledReturnStruct [repeat return_structure]
	skipping [compound_statement]
	replace  $ [argument_expression]
		express [argument_expression]
	construct exprAsString [stringlit]
		_ [quote express]
	construct retName [stringlit]
		"$ABSTRETVAL_ret_"
	
	%assure not replacing an already replaced one	
	%construct indexOfFunction [number]
	%	_ [index exprAsString FunctionName] [- 1]
	%construct initialPosition [number]
	%	indexOfFunction [- 15]
	%construct messss [unary_expression]
	%	exprAsString 
	%construct replacedSign [stringlit]
	%	exprAsString [: initialPosition indexOfFunction] 	
		
		
	%construct FunctionNameCalled [stringlit]
		%_ [+ " "] [+ FunctionName] [+ " ("]		
		
		
	export FunctionName [stringlit]
		""
	export ArgsSymbolTable [repeat declaration]
		_
	export returnStructureOfCalled [repeat return_structure]
		_

		
	where 
		express [matchCoreFunctionCall ListOfCalledFunctions exprAsString]
		
		import FunctionName
		import ArgsSymbolTable
				import returnStructureOfCalled
		deconstruct * [return_structure] returnStructureOfCalled
			CurrentCalledRet [return_structure]

			
		
		import ExtensionIfRequired [stringlit]
		
	construct initialVariableName [stringlit]
		retName [+ FunctionName]
	construct initialVariableNameID [id]
		_ [unquote initialVariableName]

	construct initialVariableNameIDUnique [id]
		initialVariableNameID [!]
		
	construct initialStringVarNameUnique [stringlit]
		_ [quote initialVariableNameIDUnique]
		
		
	construct variableName [stringlit]
		initialStringVarNameUnique [+ ExtensionIfRequired]
		
	construct variableID [id]
		_ [unquote variableName]
	construct FTT [argument_expression]
		variableID
	deconstruct * [function_name_return] CurrentCalledRet
		calledFctName [function_name_return]
		
	%where not
	%	replacedSign [= "$ABSTRETVAL_ret_"]
		%mapping table
		import ReplacedToken [repeat declaration_or_statement]
		construct mappingTableMarker [stringlit]
			"//Mappings for function: "
		construct callFunctionMarker [stringlit]
			"//call_the_function: "
		construct finalMappings [stringlit]
			mappingTableMarker [+ exprAsString] [+ ";"]
		%construct unique fct identifier
		construct fctID [id]
			_ [unquote FunctionName]
		construct uniqueFctID [id]
			fctID [!]
		construct uniqueFctStringlit [stringlit]
			_ [quote uniqueFctID]
		construct finalCallFunction [stringlit]
			callFunctionMarker [+ FunctionName] [+ " "] [+ uniqueFctID]
		construct exprAsDeclStmMarker [declaration_or_statement]
			finalMappings
		construct callFctAsDeclStmMarker [declaration_or_statement]
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
			_ [+ "$ABST_"] [+ FunctionName] [+ "_"]  [+ RetVarStringlit] 
			
		%add declaration marker
		construct LineString [stringlit]
			"@DECL"
		%comment the line numbers	
		construct commentStartMarker [stringlit]
			"/*"
		construct commentEndMarker [stringlit]
			"*/ "

		construct testtt [stringlit]
			commentStartMarker [+ LineString] [+ commentEndMarker] [+ RetTypeStringlit] [+ ReplacementName] [+ ";"]
		construct testDeclMarker [declaration_or_statement]
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
			
		
		construct FinalArgsAsRepeatStrings [repeat stringlit]
			ArgsAsRepeatStrings [addArgumentsIntoListOfStringlitWhenJustOne ArgsNoBrackets]		
			
			
		export CurrentFunctionMappings [repeat symbol_mapping]
			_	
			
		export AbstractionFctMappings [repeat symbol_mapping]
			_
		export ListOfArgumentsForReturn [list id]
			_	
			
		construct ListOfDeclarations [repeat declaration_or_statement]
			_ [declarationArgsToStringlit ArgsSymbolTable FinalArgsAsRepeatStrings calledFctName uniqueFctStringlit]	
			
		import ListOfArgumentsForReturn [list id]	
			
			
		import CurrentFunctionMappings [repeat symbol_mapping]
		
		
		import AbstractionFctMappings [repeat symbol_mapping]
			
		construct uniqueFctNameAsID [id]
			_ [unquote uniqueFctStringlit]
		construct newFctInstMapping [function_instante_mappings]
			uniqueFctNameAsID CurrentFunctionMappings '@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
			
			
		construct newAbstractMappings [function_instante_mappings]
			uniqueFctNameAsID AbstractionFctMappings '@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

			
			
		import MappingsForFunctionInstantiation [repeat function_instante_mappings]
		export MappingsForFunctionInstantiation [repeat function_instante_mappings]
			MappingsForFunctionInstantiation [. newFctInstMapping]
			
		import CurrentMappingList [repeat function_instante_mappings]	
		
		export CurrentMappingList [repeat function_instante_mappings]	
			CurrentMappingList [. newAbstractMappings]	
		%construct the label
		construct labelMarkerS [stringlit]
			"LABEL_"
		construct labelNameString [stringlit]
			labelMarkerS [+ FunctionName] 
		construct LabelName [id]
			_ [unquote labelNameString]
		construct labelID [id]
			LabelName [!]
		construct labelString [stringlit]
			_ [quote labelID]
		construct finalLabelString [stringlit]
			labelString [+ " :"]
		construct noOpStmString [stringlit]
			"if(0){}"
		construct noOpDStm [declaration_or_statement]
			noOpStmString
		construct noOpDStmMarker [repeat declaration_or_statement]
			_ [. noOpDStm]
		construct fls [declaration_or_statement]
			finalLabelString	
		construct labelDeclOrStmMarker [repeat declaration_or_statement]
			_ [. fls]
	
		import ListOfAddedLabels [repeat declaration_or_statement]
		export ListOfAddedLabels
			ListOfAddedLabels [. fls]	
		



			
			
		construct currentCalledFunctionNameID [id]
			_ [unquote FunctionName]
		
		construct returnIfCase [repeat declaration_or_statement]
			_ [addReturnToLastFunction CoreFunction currentCalledFunctionNameID ListOfArgumentsForReturn]
			
		export ReplacedToken
			_ [. ListOfDeclarations] [.testDeclMarker] [. returnIfCase] [. callFctAsDeclStmMarker] [. exprAsDeclStmMarker] [.labelDeclOrStmMarker] [. noOpDStmMarker]
			%_ [. ListOfDeclarations] [. returnIfCase] [. callFctAsDeclStmMarker] [. exprAsDeclStmMarker]  [.testDeclMarker]
			%_ [. ListOfDeclarations] [. returnIfCase] [. callFctAsDeclStmMarker] [. exprAsDeclStmMarker]  [. msTEMP] [.testDeclMarker]
			
	by
		FTT
end rule


rule replaceNeededFunctionCallUnaryExpr	FunctionNameNON [stringlit]
										CurrentCalledRetNotUsed [return_structure]
										ArgsSymbolTableNOT_USED [repeat declaration]
										CoreFunction [id]
										ListOfCalledFunctions [repeat graph_entry]
										AllCalledReturnStruct [repeat return_structure]
	skipping [compound_statement]
	replace  $ [unary_expression]
		express [unary_expression]
	construct exprAsString [stringlit]
		_ [quote express]

		
	
	%deconstruct * [function_name_return] CurrentCalledRet
	%	calledFctName [function_name_return]
	
		
	%assure not replacing an already replaced one	
	%construct indexOfFunction [number]
	%	_ [index exprAsString FunctionName] [- 1]
	%construct initialPosition [number]
	%	indexOfFunction [- 15]
		
	%construct replacedSign [stringlit]
	%	exprAsString [: initialPosition indexOfFunction] 
	

	%construct FunctionNameCalled [stringlit]
		%_ [+ " "] [+ FunctionName] [+ " ("]		
	
		export FunctionName [stringlit]
		""
			export ArgsSymbolTable [repeat declaration]
		_
		
		export returnStructureOfCalled [repeat return_structure]
			_
		
	where 
		express [matchCoreFunctionCall ListOfCalledFunctions exprAsString]
		
		import FunctionName
		import ArgsSymbolTable
		import returnStructureOfCalled
		deconstruct * [return_structure] returnStructureOfCalled
			CurrentCalledRet [return_structure]
		deconstruct * [function_name_return] CurrentCalledRet
			calledFctName [function_name_return]
			
			
		
			construct retName [stringlit]
		"$ABSTRETVAL_ret_"
		
	%add here the array marker if case!!
	import ExtensionIfRequired [stringlit]
		
		
	construct initialVariableName [stringlit]
		retName [+ FunctionName]
	construct initialVariableNameID [id]
		_ [unquote initialVariableName]

	construct initialVariableNameIDUnique [id]
		initialVariableNameID [!]
		
	construct initialStringVarNameUnique [stringlit]
		_ [quote initialVariableNameIDUnique]
		
		
	construct variableName [stringlit]
		initialStringVarNameUnique [+ ExtensionIfRequired]
	construct variableID [id]
		_ [unquote variableName]
	construct FTT [unary_expression]
		variableID
		
	%where not
	%	replacedSign [= "$ABSTRETVAL_ret_"]
		%mapping table
		import ReplacedToken [repeat declaration_or_statement]
		construct mappingTableMarker [stringlit]
			"//Mappings for function: "
			
		construct callFunctionMarker [stringlit]
			"//call_the_function: "
		construct finalMappings [stringlit]
			mappingTableMarker [+ exprAsString] [+ ";"]
			
			
			
			
		%construct unique fct identifier
		construct fctID [id]
			_ [unquote FunctionName]
	
		construct uniqueFctID [id]
			fctID [!]
	
		construct uniqueFctStringlit [stringlit]
			_ [quote uniqueFctID]	
		
			
			
			
			
		construct finalCallFunction [stringlit]
			callFunctionMarker [+ FunctionName] [+ " "] [+ uniqueFctStringlit]
		construct exprAsDeclStmMarker [declaration_or_statement]
			finalMappings
		construct callFctAsDeclStmMarker [declaration_or_statement]
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
			_ [+ "$ABST_"] [+ FunctionName] [+ "_"]  [+ RetVarStringlit]
			
			
				%add declaration marker
		construct LineString [stringlit]
			"@DECL"
		%comment the line numbers	
		construct commentStartMarker [stringlit]
			"/*"
		construct commentEndMarker [stringlit]
			"*/ "
			
		construct testtt [stringlit]
			commentStartMarker [+ LineString] [+ commentEndMarker]	[+ RetTypeStringlit] [+ ReplacementName] [+ " ; "]
		construct testDeclMarker [declaration_or_statement]
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
			
		construct FinalArgsAsRepeatStrings [repeat stringlit]
			ArgsAsRepeatStrings [addArgumentsIntoListOfStringlitWhenJustOne ArgsNoBrackets]			


		%construct checkExp [unary_expression]
			%express [CheckAllTYPES]	
			
		export CurrentFunctionMappings [repeat symbol_mapping]	
			_
			
			
		export ListOfArgumentsForReturn [list id]
			_	
			

		export AbstractionFctMappings [repeat symbol_mapping]	
			_
		
		construct ListOfDeclarations [repeat declaration_or_statement]
			_ [declarationArgsToStringlit ArgsSymbolTable FinalArgsAsRepeatStrings calledFctName uniqueFctStringlit] 
			
		import ListOfArgumentsForReturn [list id]
			
		construct msss [repeat declaration_or_statement]
			ListOfDeclarations
		import CurrentFunctionMappings [repeat symbol_mapping]
		
		
		
		import AbstractionFctMappings [repeat symbol_mapping]


		
		
		
		
		
		construct uniqueFctNameAsID [id]
			_ [unquote uniqueFctStringlit]
		
		
		
		construct newAbstractMappings [function_instante_mappings]
			uniqueFctNameAsID AbstractionFctMappings '@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@


		
		construct newFctInstMapping [function_instante_mappings]
			uniqueFctNameAsID CurrentFunctionMappings '@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
			
			
		import MappingsForFunctionInstantiation [repeat function_instante_mappings]

		export MappingsForFunctionInstantiation [repeat function_instante_mappings]
			MappingsForFunctionInstantiation [. newFctInstMapping]	
			
		import CurrentMappingList [repeat function_instante_mappings]	
		
		export CurrentMappingList [repeat function_instante_mappings]	
			CurrentMappingList [. newAbstractMappings]
		%construct the label
		
		
		construct labelMarkerS [stringlit]
			"LABEL_"
		construct labelNameString [stringlit]
			labelMarkerS [+ FunctionName] 
		construct LabelName [id]
			_ [unquote labelNameString]
		construct labelID [id]
			LabelName [!]
		construct labelString [stringlit]
			_ [quote labelID]
		construct finalLabelString [stringlit]
			labelString [+ " :"]
		construct noOpStmString [stringlit]
			"if(0){}"
		construct noOpDStm [declaration_or_statement]
			noOpStmString
		construct noOpDStmMarker [repeat declaration_or_statement]
			_ [. noOpDStm]
		construct fls [declaration_or_statement]
			finalLabelString	
		construct labelDeclOrStmMarker [repeat declaration_or_statement]
			_ [. fls]


		import ListOfAddedLabels [repeat declaration_or_statement]
		export ListOfAddedLabels
			ListOfAddedLabels [. fls]	



		
		construct currentCalledFunctionNameID [id]
			_ [unquote FunctionName]
		
		construct returnIfCase [repeat declaration_or_statement]
			_ [addReturnToLastFunction CoreFunction currentCalledFunctionNameID ListOfArgumentsForReturn]
		
			

		export ReplacedToken
			_ [.ListOfDeclarations] [.testDeclMarker] [.returnIfCase] [.callFctAsDeclStmMarker]  [. exprAsDeclStmMarker]   [.labelDeclOrStmMarker] [.noOpDStmMarker]
			%_ [.ListOfDeclarations] [.returnIfCase] [.callFctAsDeclStmMarker]  [. exprAsDeclStmMarker] [.testDeclMarker]
			%_ [.ListOfDeclarations] [.returnIfCase] [.callFctAsDeclStmMarker]  [. exprAsDeclStmMarker] [. msTEMP] [.testDeclMarker]
			
	by
		FTT
end rule

function addReturnToLastFunction	CoreFunction [id]
									CurrentCalledFunction [id]
									ListOfDeclarations [list id]
	replace [repeat declaration_or_statement]
		current [repeat declaration_or_statement]
		
	
	
	construct returnMarker [stringlit]
		"/* RETURN_MARKER */ return "
	construct coreFunctionStringlit [stringlit]
		_ [quote CoreFunction]
	construct returnFunctionCall [stringlit]
		returnMarker [+ coreFunctionStringlit] [+ " ("]
	construct listOfDeclStringlit [stringlit]
		_ [quote ListOfDeclarations]
	construct finalReturnStatement [stringlit]
		returnFunctionCall [+ listOfDeclStringlit] [+ ");"]
	construct returnDeclStm [declaration_or_statement]
		finalReturnStatement
		
	where
		CoreFunction [= CurrentCalledFunction]
	by
		_ [. returnDeclStm]
end function








function addNumberAtStmFunctCallWithOneParameter	current [declaration_or_statement]
	replace [declaration_or_statement]
		modifiedStatement [declaration_or_statement]
		
		

		
	%check if it is declaration
	deconstruct current
		isDeclaration [declaration]	
	
		

	deconstruct * [base_declarator] current
		baseDeclFromCurrent [base_declarator] 
		
	construct baseDeclString [stringlit]
		_ [quote baseDeclFromCurrent]
	
	where
		baseDeclString [grep "("]
	where
		baseDeclString [grep ")"]		
		
	deconstruct not * [else_statement] current
		theElseStatement [else_statement]
		

	construct CurrentAsString [stringlit]
		_ [quote current]
	construct FirstTwoChars [stringlit]
		CurrentAsString [: 1 2]
	construct commentMark [stringlit]
		"//"	
	where not
		commentMark [= FirstTwoChars]	
	construct LineString [stringlit]
		"@STM"
	%comment the line numbers	
	construct commentStartMarker [stringlit]
		"/*"
	construct commentEndMarker [stringlit]
		"*/ "
	construct FinalLineString [stringlit]
		commentStartMarker [+ LineString] [+ commentEndMarker]	
	construct currentStatementString [stringlit]
		FinalLineString [quote current]
	construct currentStmLine [declaration_or_statement]
		currentStatementString
	by
		currentStmLine
end function












function addNumberAtMacros	current [declaration_or_statement]
	replace [declaration_or_statement]
		modifiedStatement [declaration_or_statement]

	deconstruct * [macro_specifier] current
		currentState444ment [macro_specifier] 
		
	deconstruct not * [else_statement] current
		theElseStatement [else_statement]
		
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
	construct LineString [stringlit]
		"@STM"
	%comment the line numbers	
	construct commentStartMarker [stringlit]
		"/*"
	construct commentEndMarker [stringlit]
		"*/ "
	construct FinalLineString [stringlit]
		commentStartMarker [+ LineString] [+ commentEndMarker]	
	construct currentStatementString [stringlit]
		FinalLineString [quote current]
	construct currentStmLine [declaration_or_statement]
		currentStatementString
	by
		currentStmLine
end function

%VERY USEFULL!!!!
rule CheckAllTYPESMacro	
	replace  $ [any]
		express [any]

	construct eString [stringlit]
		_ [quote express]
	construct typeT [id]
		_ [typeof express]
	construct stringType [stringlit]
		_ [quote typeT] [+ "  "]
	construct finalMessage [stringlit]
		stringType [+ eString] [fput "testMACRo.out"]

	by
		express
end rule

function matchJmpStatement
	match * [jump_statement]
		_ [jump_statement]
end function


function addNumberAtStatements
	replace [declaration_or_statement]
		current [declaration_or_statement]
	deconstruct * [statement] current
		currentState444ment [statement] 
		
	
	
	deconstruct not * [else_statement] current
		theElseStatement [else_statement]
		
	where not
		currentState444ment [matchJmpStatement]

	construct LineString [stringlit]
		"@STM"
		
	%comment the line numbers	
	construct commentStartMarker [stringlit]
		"/*"
	construct commentEndMarker [stringlit]
		"*/ "
	construct FinalLineString [stringlit]
		commentStartMarker [+ LineString] [+ commentEndMarker]
		
		
	construct currentStatementString [stringlit]
		FinalLineString [quote current]
	construct currentStmLine [declaration_or_statement]
		currentStatementString
	by
		currentStmLine
end function


function AddFromCompund CurrentStatement [declaration_or_statement]
	replace [repeat declaration_or_statement]
		currentList [repeat declaration_or_statement]
		
		
		
		
		
	deconstruct * [compound_statement_body] CurrentStatement
		currentCompund [compound_statement_body]	
		
		
	

		
	deconstruct * [structured_statement] CurrentStatement
		currentCompund2 [structured_statement]
	construct compundNoBody [declaration_or_statement]
		currentCompund2 [removeBodyFromCompund]
	construct compundString [stringlit]
		_ [quote compundNoBody] 
	construct lengthOfHeader [number]
		_ [# compundString] [- 2]
	construct removedEndOfBlock [stringlit]
		compundString [: 1 lengthOfHeader]

	deconstruct * [repeat declaration_or_statement] currentCompund
		declsFromCompund [repeat declaration_or_statement]
	construct declsMarkersFromCompund [repeat declaration_or_statement]	
		_ [ToDeclStmMarkers declsFromCompund] 	
	construct finalMarker [stringlit]
		"} "
	construct finalEndOfCompund [stringlit]
		finalMarker [+ "//"] [+ removedEndOfBlock] 
	construct addFinalMarker [declaration_or_statement]
		finalEndOfCompund
		
		
	
		
		
		
		
	by
		declsMarkersFromCompund [.addFinalMarker] [. currentList]
end function


function solveCompundStatement	CurrentStatement [declaration_or_statement]
								FunctionName [stringlit]
								CurrentCalledRet [return_structure]
								ArgsSymbolTable [repeat declaration]
								CoreFunction [id]
								ListOfCalledFunctions [repeat graph_entry]
								AllCalledReturnStruct [repeat return_structure]
	
	replace [declaration_or_statement]
		current [declaration_or_statement]
		
	deconstruct not CurrentStatement
		currentCompundds [else_statement]	
		
	deconstruct * [compound_statement] CurrentStatement
		notCompound [compound_statement]
		
		
		
	deconstruct * [compound_statement] CurrentStatement
		currentCompoundTEST [compound_statement]
		
	construct CurrentStatementNoElseClauses [declaration_or_statement]
		CurrentStatement[removeElseClause]	
		
		
		
		
	deconstruct * [structured_statement] CurrentStatementNoElseClauses
		currentCompund [structured_statement]		
	deconstruct * [compound_statement_body] CurrentStatementNoElseClauses
		justIfItHasBody [compound_statement_body]	
	construct compundNoBody [declaration_or_statement]
		currentCompund [removeBodyFromCompund] 
		
		
		
	construct exportContainedElse [repeat declaration_or_statement]
		CurrentStatement  [solveElseStatements]
		
	
		
		
		
		%%!!!!!!!!!!!!!!!!!!1!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	construct firstSolvedCallFunctions [declaration_or_statement]
		CurrentStatementNoElseClauses [solveCalledFunction CurrentStatementNoElseClauses FunctionName CurrentCalledRet ArgsSymbolTable CoreFunction ListOfCalledFunctions AllCalledReturnStruct] 



	import BeginCompoundMarker [repeat declaration_or_statement]
	import EndCompoundMarker [repeat declaration_or_statement]


	construct uniqueMarkerStringlit [stringlit]
		"COMP_MARK"
		
	construct uniqueMarkerID [id]
		_ [unquote uniqueMarkerStringlit]

	construct theUniqueID [id]
		uniqueMarkerID [!]
	
	construct theUniqueIDString [stringlit]
		_ [quote theUniqueID]
		
	construct startMark [stringlit]
		"//COMPOUND START: "

	construct startCompoundMark [stringlit]
		startMark [+ theUniqueID]
	construct compoundHeaderStringlit [stringlit]
		_ [quote compundNoBody]
		
	construct finalCompoundHeaderStringlit [stringlit]
		compoundHeaderStringlit [replaceStringlitWhenEmpty]
		
	construct startCompoundComplete [stringlit]
		startCompoundMark [+ finalCompoundHeaderStringlit]
		
		
		
		
		
		
	construct CompoundMarkDeclStm [declaration_or_statement]
		startCompoundComplete
	
	export BeginCompoundMarker
		_ [. CompoundMarkDeclStm]
	
	
	
	construct endMark [stringlit]
		"//COMPOUND END: "
		
	
	construct endCompoundMark [stringlit]
		 endMark [+ theUniqueID]
	construct endCompoundComplete [stringlit]
		endCompoundMark [+ finalCompoundHeaderStringlit]
	construct endCompundMarkDeclStm [declaration_or_statement]
		endCompoundComplete
	export EndCompoundMarker
		_ [. endCompundMarkDeclStm]
	
	by
		firstSolvedCallFunctions
end function































function solveElseCompounds		CurrentStatement [declaration_or_statement]
								FunctionName [stringlit]
								CurrentCalledRet [return_structure]
								ArgsSymbolTable [repeat declaration]
								CoreFunction [id]
								ListOfCalledFunctions [repeat graph_entry]
								AllCalledReturnStruct [repeat return_structure]
	
	replace [declaration_or_statement]
		current [declaration_or_statement]
		

	deconstruct CurrentStatement
		currentCompund [else_statement]	
		
	deconstruct currentCompund
		'else elseSubStm [else_sub_statement]
		
	construct elseSubStmNoElseClauses [else_sub_statement]
		elseSubStm[removeElseClause]	
		
	%construct exportContainedElse [repeat declaration_or_statement]
	%	elseSubStmNoElseClauses [solveElseStatements]	
		
		
		
	construct exportContainedElse [else_sub_statement]
		elseSubStm  [solveElseStatements]
		
		
		
	import ElseStatement [repeat declaration_or_statement]	

		
	construct newElsStatementNoElseBody [else_statement]
		'else elseSubStmNoElseClauses
		
	
	
	construct newStatement [declaration_or_statement]
		newElsStatementNoElseBody
		

	construct compundNoBody [declaration_or_statement]
		newElsStatementNoElseBody [removeBodyFromCompund] 
		
		

		
		
		%%!!!!!!!!!!!!!!!!!!1!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	construct firstSolvedCallFunctions [declaration_or_statement]
		newStatement [solveCalledFunction newStatement FunctionName CurrentCalledRet ArgsSymbolTable CoreFunction ListOfCalledFunctions AllCalledReturnStruct] 



	import BeginCompoundMarker [repeat declaration_or_statement]
	import EndCompoundMarker [repeat declaration_or_statement]


	construct uniqueMarkerStringlit [stringlit]
		"COMP_MARK"
		
	construct uniqueMarkerID [id]
		_ [unquote uniqueMarkerStringlit]

	construct theUniqueID [id]
		uniqueMarkerID [!]
	
	construct theUniqueIDString [stringlit]
		_ [quote theUniqueID]


	construct startMark [stringlit]
		"//COMPOUND START: "
	
	construct startCompoundMark [stringlit]
		startMark [+ theUniqueIDString]
	construct compoundHeaderStringlit [stringlit]
		_ [quote compundNoBody]
		
	construct finalCompoundHeaderStringlit [stringlit]
		compoundHeaderStringlit [replaceStringlitWhenEmpty]
		
	construct startCompoundComplete [stringlit]
		startCompoundMark [+ finalCompoundHeaderStringlit]
		
		
		
		
		
		
	construct CompoundMarkDeclStm [declaration_or_statement]
		startCompoundComplete
	
	export BeginCompoundMarker
		_ [. CompoundMarkDeclStm]
	
	
	construct endMark [stringlit]
		"//COMPOUND END: "
	
	construct endCompoundMark [stringlit]
		endMark [+ theUniqueIDString]
	construct endCompoundComplete [stringlit]
		endCompoundMark [+ finalCompoundHeaderStringlit]
	construct endCompundMarkDeclStm [declaration_or_statement]
		endCompoundComplete
	export EndCompoundMarker
		_ [. endCompundMarkDeclStm]
	
	by
		firstSolvedCallFunctions
end function








rule removeElseClause
	skipping [compound_statement_body]
	replace $ [opt else_statement]
		_ [opt else_statement]
	by
		
end rule


function solveElseStatements
	skipping [compound_statement]
	match * [else_statement] 
		theElseStatement [else_statement]
	
	
	%construct elseStatementStringlit [stringlit]
		%_ [quote theElseStatement]
		
	%construct shouldBeElse [stringlit]
		%elseStatementStringlit [: 1 4]
		
	%where
		%shouldBeElse [= "else"]
	
	
	%replace [repeat declaration_or_statement]
	%	current [repeat declaration_or_statement]
		
	%skipping [compound_statement]
	%%deconstruct * [else_statement] CurrentStatement
	%	theElseStatement [else_statement]
	construct newElseDeclStm [declaration_or_statement]
		theElseStatement
	
	import ElseStatement [repeat declaration_or_statement]
	export ElseStatement
		_ [. newElseDeclStm]

	
	%by
	%	_
end function


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
		stringType [+ eString] [fput "testElseStm.out"]

	by
		express
end rule

function replaceStringlitWhenEmpty
	replace [stringlit]
		current [stringlit]
	
	construct lengthOfInitial [number]
		_ [# current]
		
		
	import CompoundNumberMarker [number]
	
	construct compoundNumberMarkerString [stringlit]
		_ [quote CompoundNumberMarker]
		
		
	construct unnamendCompoundMarker [stringlit]
		"unnamend_compound_statement number: "
	construct noNamedCompoundReplacement [stringlit]
		unnamendCompoundMarker [+ compoundNumberMarkerString]
	
	
	export CompoundNumberMarker
		CompoundNumberMarker [+ 1]
	
	where
		lengthOfInitial [< 3]
	
	by
		noNamedCompoundReplacement
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
	skipping [struct_or_union_specifier]
	replace $ [id]
		current [id]
		
		
			
	construct writeRestCalled [stringlit]
		FctName 
		
		
	construct AbstractMarker [id]
		_ [unquote "$"]
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


function hasMacroSpec
	match * [macro_specifier]
		currentMacro [macro_specifier]
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



function determineReturnValuesListOfEntries ListOfGraphEntries [repeat graph_entry]
	replace [repeat return_structure]
		current [repeat return_structure]
	deconstruct ListOfGraphEntries
		first [graph_entry] rest [repeat graph_entry]
		
	construct CurrentReturned [repeat return_structure]
		_ [determineReturnValues first] 
		
	by
		current [. CurrentReturned]
		[determineReturnValuesListOfEntries rest]
end function



%retrieve return values:
%POTENTIALLY PROBLEM HERE!!!
function determineReturnValues	ListOfGraphEntries [graph_entry]
	replace [repeat return_structure ]
		current [repeat return_structure]
	import donorSourceFiles [stringlit] %with /!!!
	deconstruct ListOfGraphEntries
		first [graph_entry]
	deconstruct first
		fctName [id] srcToken [source_file_token] SourceFileName [source_file_element] 
	construct inputFileName [stringlit]
		_ [quote SourceFileName]
	construct path [stringlit]
		donorSourceFiles
	construct lengthOfFileName [number]
		_ [# inputFileName] [- 2]
	construct inputFilNameNoMarks [stringlit]
		inputFileName [: 3 lengthOfFileName]
	construct CompleteFileName [stringlit]
		path [+ inputFilNameNoMarks] 
	construct nonIfDefsOutput [stringlit]
		CompleteFileName [+ "NON"]

	import fixIfDefProg [stringlit]
	

	construct commandForNonIf [stringlit]
		_ [+ fixIfDefProg] [+ " "] [+ CompleteFileName] [+ " "] [+ CompleteFileName]  [+ " "]  [+ nonIfDefsOutput]
	construct CallCommand2 [id]
    	_ [system commandForNonIf]
	construct outputFileCompleteName [stringlit]
		_ [+ nonIfDefsOutput]
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
		"NO_RETURN"
	construct returnStatement [function_definition_or_declaration]
		FunctionDefinitionHost [determineReturnInstruction]
	import ReturnStatementValue [stringlit]
	deconstruct * [function_header] FunctionDefinitionHost
		fctHead [function_header]
		
	
	deconstruct fctHead
		declSpec [ decl_specifiers] declaratorF [declarator] fctExt [function_declarator_extension] 
		
	deconstruct declaratorF
		repPtr [repeat ptr_operator] baseDecl [base_declarator] declExt [repeat declarator_extension]
		
	construct ptrOpString [stringlit]
		_ [quote repPtr]
		
	export ExtensionIfRequired [stringlit]
		_ [quote declExt]
			
	construct declSpecString [stringlit]
		_ [quote declSpec]
	construct declaratorFString [stringlit]
		_ [quote declaratorF]
	construct declString [stringlit]
		_ [+ declSpecString]  [+ " "]  [+ ptrOpString] 		
	construct functionName [stringlit]
		StringFctName [+ "   "]
	construct msss [stringlit]
		functionName [+ declString] [+ ReturnStatementValue] 
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


%function constructReturnVarTypeFromHeader	FctHeader [function_header]




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








%extend all the declarations from the initial source code of a function

rule extendAllDeclarations
	replace $ [compound_statement_body]
		current [compound_statement_body]
	deconstruct current
		CurrentDeclStm [repeat declaration_or_statement]
	construct extendedBlockDeclStm [repeat declaration_or_statement]
		_ [replaceDeclInStatementBody CurrentDeclStm]
	construct extendedCompBody [compound_statement_body]
		extendedBlockDeclStm
	by
		extendedCompBody
end rule


function replaceDeclInStatementBody	DeclStmFromBody [repeat declaration_or_statement]
	replace [repeat declaration_or_statement]
		current [repeat declaration_or_statement]
	deconstruct DeclStmFromBody
		first [declaration_or_statement] rest [repeat declaration_or_statement]
	construct currentDeclStmAsRepeat [repeat declaration_or_statement]
		_ [. first]
	construct newListOfDecl [repeat declaration_or_statement]
		currentDeclStmAsRepeat [replaceIfDeclaration]
	by
		current [. newListOfDecl]
		[replaceDeclInStatementBody rest]
end function



function replaceIfDeclaration
	replace [repeat declaration_or_statement]
		current [repeat declaration_or_statement]
	deconstruct * [declaration_or_statement] current
		currentDecl [declaration_or_statement]
	deconstruct not * [statement] currentDecl
		currentNotStatement [statement] 
	deconstruct not * [macro_specifier] currentDecl
		currentNotMacro [macro_specifier] 
	deconstruct currentDecl
		theDeclaration [declaration]
		
		
	%remove qualifiers like const, static, etc for avoiding compilation errors
	construct theDeclarationRemovedQualifiers	[declaration]
		theDeclaration [removeUnnededQualifiers]
		
		
	construct repeatCurrentDecl [repeat declaration]
		_ [. theDeclarationRemovedQualifiers]
		
		
	construct separateListOfDecl [repeat declaration]
		repeatCurrentDecl [constructListOfSeparateDeclarations theDeclarationRemovedQualifiers]
	
	construct listOfDeclOrStm [repeat declaration_or_statement]
		_ [reparse separateListOfDecl]	
	
	by
		listOfDeclOrStm
end function

rule removeUnnededQualifiers
	replace $ [decl_specifiers]
		currentDeclSpec [decl_specifiers]
	deconstruct currentDeclSpec
		repeatDeclQualifiersOrTypeSpec [repeat decl_qualifier_or_type_specifier]
	construct newDeclSpecRepeat [repeat decl_qualifier_or_type_specifier]
		_ [removeTypeSpecifiers repeatDeclQualifiersOrTypeSpec]
	
	construct newDeclSpec [decl_specifiers]
		newDeclSpecRepeat
		
	by
		newDeclSpec
end rule

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













function constructListOfSeparateDeclarations currentVarDecl [declaration]
	replace [repeat declaration]
		decl [repeat declaration]
	deconstruct   currentVarDecl
		specT [decl_specifiers] declT [list init_declarator] ';
	where not
		currentVarDecl [hasMacroSpec]
	where
		declT [hasDecl]
    deconstruct specT
		repeatFromDecl [repeat decl_qualifier_or_type_specifier]
	construct newVarDeclSpecifiers [decl_specifiers]
		repeatFromDecl 
	construct allVars [repeat declaration]
		_ [separeDeclarations newVarDeclSpecifiers declT ] 
	by
		_ [. allVars]
end function
	
	
	
function separeDeclarations	specifier [decl_specifiers]
							declList [list init_declarator]
	replace [repeat declaration]
		variableDeclList [repeat declaration]
	deconstruct  declList
		First [init_declarator] , Rest [list init_declarator]
	construct newVarDecl [declaration]
		specifier First ';
	by
		variableDeclList [. newVarDecl]
		[separeDeclarations specifier Rest]
end function	



