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


redefine declaration_or_statement
	...
	| [stringlit] [NL]
end redefine

define ids_with_line_break
	[id] [NL]
end define


define function_for_transplant
	[opt function_for_transplant_name] [NL] [repeat ids_with_line_break]   [end_call_graph_marker] [NL]
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
	[function_name] "->" [argument_symbol] ":" [repeat variable_symbol]
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









%char * donorSourceFiles, 
 %       char * modifiedFunctionLOCsOutput, "outputFCTLOCS.out"
 %char * SkeletonInstantiateMappings,   "SkeletonInstantiateMappings.out"
 % char * HostSymbolTableFile,  "HostSymbolTable.out"
  %      char * CurrentExistingMappings "CurrentExistingMappings.out"




function main
	match [program]
		P [program]
		

	
	export LineNumber [number]
		1
	
	
	%construct theCallGraph [program]
		%_ [read first] 
		
	deconstruct * [reverse_call_graph] P
		 CallGraph [reverse_call_graph]
		
	construct newP [reverse_call_graph]
		CallGraph [constructNewGPFunctions]
end function




function constructNewGPFunctions
	replace [reverse_call_graph]
		P [reverse_call_graph]
		
		
	
	import TXLargs [repeat stringlit]
	
	deconstruct TXLargs
		donorSourceFiles [stringlit] modifiedFunctionLOCsOutput [stringlit] 
		SkeletonInstantiateMappings [stringlit] HostSymbolTableFile [stringlit] CurrentExistingMappings [stringlit]	
		
	
	export donorSourceFiles
	
		
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
		
		
		
		
		
	export MappingsForFunctionInstantiation [repeat function_instante_mappings]
		_
		
	export HostSymbolTable [repeat symbol_table_entry]
		_
	
	export CurrentMappings [repeat symbol_mapping]	
		_
		
		
	
	%write the functions for GP
	construct Candidate [repeat function_for_transplant]
		_ [writeACandidate ListOfGraphEntries ListOfCalledEntries] [print] [write modifiedFunctionLOCsOutput]
	
	
	
	import MappingsForFunctionInstantiation [repeat function_instante_mappings]
	import HostSymbolTable [repeat symbol_table_entry]
	import CurrentMappings [repeat symbol_mapping]	
	
	construct msss [repeat function_instante_mappings]
		MappingsForFunctionInstantiation [write SkeletonInstantiateMappings]
		
	construct ms2 [repeat symbol_table_entry]
		HostSymbolTable [write HostSymbolTableFile]
		
	construct ms3 [repeat symbol_mapping]
		CurrentMappings [write CurrentExistingMappings]
	
	by
		P
		
end function





function writeACandidate	ListOfGraphEntries [repeat graph_entry]
							ListOfCalledEntries [repeat graph_entry]
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
	construct commandForNonIf [stringlit]
		_ [+ "/home/alex/workspace/Transplants/ifdef.x "] [+ CompleteFileName] [+ " "] [+ CompleteFileName]  [+ " "]  [+ nonIfDefsOutput]
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

	construct newFctDef [function_definition_or_declaration]
		FunctionDefinitionHost [fixEveryBlock] [write "FINALtEST.out"]
		
	%construct finalFctDef [function_definition_or_declaration]
		%newFctDef [fixCompHeaders] [write "reallyFinal.out"]


	by
		current %[. FunctionDefinitionHost]
		[writeACandidate rest restCalled]
end function



rule fixCompHeaders
	replace $ [declaration_or_statement]
		current [declaration_or_statement]
	
	construct declAsStringlit [stringlit]
		_ [quote current]
	
	construct replaceMarker [stringlit]
		"PULALALALALALALALALALALALALALALA: "
	construct finalReplacement [stringlit]
		replaceMarker [+ declAsStringlit]
			
	
	construct replacementAsDeclStatement [declaration_or_statement]
		finalReplacement
	
	
	deconstruct not  [stringlit] current
		currentStringlit [stringlit]
	
	by
		replacementAsDeclStatement
end rule

rule fixEveryBlock
	replace $ [compound_statement]
		currentBlock [compound_statement]
		deconstruct * [compound_statement_body] currentBlock
			currentBlockBody [compound_statement_body]
		construct blockReplacedDeclStm [compound_statement_body]
			currentBlockBody [replaceDeclStmNoBody]
		construct replacedBlock [compound_statement]
			'{ blockReplacedDeclStm '}	
	by
		replacedBlock
end rule


rule replaceDeclStmNoBody
	skipping [compound_statement]
	replace $ [declaration_or_statement]
		current [declaration_or_statement]
	construct declAsStringlit [stringlit]
		_ [quote current]
	construct replaceMarker [stringlit]
		"PULALALALALALALALALALALALALALALA: "
	construct finalReplacement [stringlit]
		replaceMarker [+ declAsStringlit]
	construct replacementAsDeclStatement [declaration_or_statement]
		finalReplacement
	deconstruct not * [compound_statement_body] current
		currentCompund [compound_statement_body]
	by
		finalReplacement
end rule












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


