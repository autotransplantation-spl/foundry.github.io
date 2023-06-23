include "CNoComments.grm"
tokens
	commentToken	"[ \t]*//[(\\\n)(\"#[\"\n]*\")(/\*#[(\*/)]*\*/)#n]*"
	inLineComment  	"/\*#(\*/)*\*/" 
	end_marker		"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"
end tokens

%define inLineComment
%	[inLineCommentMarker] [NL]
%end define

define commentLine
	[commentToken] [NL]
end define



redefine declaration_or_statement
    [declaration] 
    |	[statement] 
#ifdef PREPROCESSOR
    |	[preprocessor]
#endif
#ifdef GNU
    |	[function_definition]  
#endif
#ifdef MACROS
    |	[macro_declaration_or_statement]
#endif
	|	[commentLine]
    |	[not inLineComment]  [unknown_declaration_or_statement]
end redefine



redefine declaration
	[opt inLineComment] [decl_specifiers] [list init_declarator] [semi]
    | [opt inLineComment] 	[decl_specifiers] [declarator] '= [compound_initializer] [NL]	% no semi
    | 	[opt inLineComment] [extern_langauge_declaration] 
    | 	[opt inLineComment] [null_declaration]
#ifdef GNU
    | [opt inLineComment]	[local_label] [list declarator+] 
    | [opt inLineComment]	[asm_spec] 
#endif
#ifdef MACROS
    | 	[opt inLineComment] [machinestart_declaration] 
#endif
#ifdef PREPROCESSOR
    | 	[opt inLineComment][preprocessor]
#endif
end redefine



redefine compound_statement
    { [IN] [NL]
	[compound_statement_body] [EX]
    [opt inLineComment] } [opt ';] [NL]
#ifdef PREPROCESSOR
    [repeat preprocessor]
#endif
end redefine

redefine statement
#ifdef PREPROCESSOR
	 [repeat preprocessor]
#endif
	 [opt inLineComment] [repeat label] [unlabeled_statement]
    |  [opt inLineComment] [label]	% e.g. at end of switch block
#ifdef PREPROCESSOR
    |  [opt inLineComment]  [preprocessor]
#endif
	| [inLineComment]
end redefine


redefine do_statement
    'do [sub_statement] [opt inLineComment] 'while ( [expression_list] ) [semi] 
#ifdef MACROS
|   'do [sub_statement] [opt inLineComment] 'while [macro_call] [semi] 
|   'do [sub_statement] [whileeachid] ( [expression_list] ) [semi] 
#endif
end redefine




redefine function_definition
    [NL] [function_header]
#ifdef PREPROCESSOR
    [repeat preprocessor_function_header]
#endif
    [opt KR_parameter_decls]
    [compound_statement]
end redefine





define function_dependency_output
	[id] [NL][repeat needed_functions_name_source_file_id]  [end_marker] [NL]
end define


define dependency_output
	'FUNCTION_NAME: [NL] [inLineComment] [NL] 'DECLARATION_LIST: [NL] [repeat inline_comment_with_line_end]  [end_marker] [NL]
end define

define inline_comment_with_line_end
	[inLineComment] [NL]
end define

define needed_functions_name_source_file
	[id] [stringlit] [NL]
end define

define needed_functions_name_source_file_id
	[id] [id] [NL]
end define

function main
	match * [program]
		P [program]
	import TXLargs [repeat stringlit]
    deconstruct  TXLargs
    	outputFile [stringlit] existingFunctionsFile [stringlit]
	deconstruct P 
		interfaceCompUnit [compilation_unit]
   	deconstruct interfaceCompUnit
   		interfaceFunctionsDefs [repeat function_definition_or_declaration]		
   	deconstruct * [function_definition_or_declaration] interfaceCompUnit
   		TheInterfaceFunction [function_definition_or_declaration]
   	export ListOfAllDependencies [repeat dependency_output]
   		_
   	construct NeededFunctionsIDs [repeat needed_functions_name_source_file]
   		_ [read existingFunctionsFile]
   		
   		
   	
   	export FinalListOfCallDepend [repeat function_dependency_output]
   		_
    construct createTheListOfStatements [function_definition_or_declaration]
   		TheInterfaceFunction [addCallMarkers NeededFunctionsIDs]		
   		
   	import FinalListOfCallDepend [repeat function_dependency_output]	
   		
   	construct writeNewInterface [repeat function_dependency_output]
   		FinalListOfCallDepend [write outputFile]
   		
   		

end function


rule addCallMarkers	NeededFunctionsIDs [repeat needed_functions_name_source_file]
	%skipping [compound_statement]
	replace $ [declaration_or_statement]
		current [declaration_or_statement]
	deconstruct not * [commentLine] current
		commLine [commentLine]
	construct currentNoBody [declaration_or_statement]
		current [removeCompoundBody]
	deconstruct not * [jump_statement] currentNoBody
		notJumpStm [jump_statement]
	construct statementStringlit [stringlit]
		_ [quote currentNoBody]	
	construct idList [repeat id]
		_ [^ currentNoBody]
		
		
		
		
	export listOfMatchedID [repeat needed_functions_name_source_file_id]
		_ 
		
		
	construct constructListOfMatchedIDs [repeat id]
		idList [matchAnIdFromTheList NeededFunctionsIDs]
		
	import listOfMatchedID [repeat needed_functions_name_source_file_id]
	%check at least one was matched	
	deconstruct  * [id] listOfMatchedID
		testForExistence [id]
		
		
	deconstruct  * [inLineComment] current
		numberMarkerInLineComment [inLineComment]
		
		
	construct numberMarkerStringlit [stringlit]
		_ [quote numberMarkerInLineComment]
		
	
	construct numberMarkerID [id]
		_ [unquote numberMarkerStringlit]
	
		
		
	import FinalListOfCallDepend [repeat function_dependency_output]
	
		
	construct endMarker [end_marker]
		'@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
		
	construct callDependEl [function_dependency_output]	
		numberMarkerID listOfMatchedID endMarker
		
	export FinalListOfCallDepend
		FinalListOfCallDepend [. callDependEl]
	
	
	by
		current
end rule


rule removeInLineComment
	replace $ [repeat inLineComment]
		_ [repeat inLineComment]
	by
		_
end rule


rule matchAnIdFromTheList	ListOfNeededIDs [repeat needed_functions_name_source_file]
	replace $ [id]
		current [id]
	construct addMatchedIDs [repeat needed_functions_name_source_file]
		ListOfNeededIDs [matchInList current]
	by 
		current
end rule


rule matchInList	CurrentID[id]
	replace $ [needed_functions_name_source_file]
		currentNameAndSource [needed_functions_name_source_file]
	
	deconstruct currentNameAndSource
		current [id] sourceFile [stringlit]
	
	construct sourceFileAsID [id]
		_ [unquote sourceFile]
		
	construct newOutputWithID [needed_functions_name_source_file_id]
		current sourceFileAsID
	
	where
		
		current [= CurrentID]
		import listOfMatchedID [repeat needed_functions_name_source_file_id]	
		export listOfMatchedID
			listOfMatchedID [. newOutputWithID]
	by 
		currentNameAndSource
end rule








rule removeCompoundBody 
	replace $ [compound_statement_body]
		currentBody [compound_statement_body]
		
	by
		_	
end rule