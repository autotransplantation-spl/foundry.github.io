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



define line_marker_tokenized
	[inLineComment] @
end define






function main
	match * [program]
		P [program]
	import TXLargs [repeat stringlit]
	
	deconstruct TXLargs
		outputFile [stringlit] outputFileAbstractMarkers [stringlit]
		
	export ListOfAllMarkers [list inLineComment]
		_
	construct printFormatedProgram [program]
		P [matchStmOrCompoundLineMarker]
		
	import ListOfAllMarkers [list inLineComment]
	
	
	export ListOfAbstractMarkers [list inLineComment]
		_
	construct generateListOfAbstractMarkers [program]
		P [fixEveryBlockForAbstract]
	
	import ListOfAbstractMarkers [list inLineComment]
	
	construct printAbstractMarkers [list inLineComment]
		ListOfAbstractMarkers [write outputFileAbstractMarkers]
	
	construct printListOfAllMarkers [list inLineComment]
		ListOfAllMarkers [write outputFile]
			
end function






rule fixEveryBlockForAbstract	
	replace $ [compound_statement]
		currentBlock [compound_statement]
	deconstruct * [compound_statement_body] currentBlock
		currentBlockBody [compound_statement_body]
	construct addStatementsFromDecl [compound_statement_body]
		currentBlockBody [extractListOfMarkersForAbstract]
	by
		currentBlock
end rule


rule extractListOfMarkersForAbstract
	skipping [compound_statement]
	%ABstract values appear only in declarations, before functions in reverse call graph are called
	replace $ [declaration_or_statement]
		currentDeclOrStm [declaration_or_statement]
		
	deconstruct currentDeclOrStm
		currentDecl [declaration]
	deconstruct *[inLineComment] currentDecl
		currentComment [inLineComment] 
		
	construct currentDeclStringlit [stringlit]
		_ [quote currentDecl]
	
	where
		currentDeclStringlit [grep "$ABSTRACT_"]
		import ListOfAbstractMarkers [list inLineComment]
			
		export ListOfAbstractMarkers
			ListOfAbstractMarkers [, currentComment]

	by
		currentDecl
end rule












rule matchStmOrCompoundLineMarker
	replace $ [inLineComment]
		currentComment [inLineComment]
	
	construct currentCommentStringlit [stringlit]
		_ [quote currentComment]
	
	where not
		currentCommentStringlit [grep "/* DECL:"]
	where not
		currentCommentStringlit [grep "RETURN_MARKER"]
		import ListOfAllMarkers [list inLineComment]
		
		construct currentCommentID [id]
			_ [unquote currentCommentStringlit]
			
		%construct newToken [line_marker_tokenized]
			%currentComment @
			
		export ListOfAllMarkers
			ListOfAllMarkers [, currentComment]

	by
		currentComment
end rule