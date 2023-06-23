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


redefine label
       [EX] [label_id] ': [IN] 
    |   [EX][SP][SP] 'case [constant_expression] ': [IN] 
    |   [EX][SP][SP] 'default ': [IN] 
#ifdef GNU
    |   [EX][SP][SP] 'case [constant_expression] [SP] '... [SP] [constant_expression] ': [IN]    
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



define gotoMarkers
	[id] [NL] [id] [NL]
end define



function main
	match * [program]
		P [program]
	import TXLargs [repeat stringlit]
	
	deconstruct * [stringlit] TXLargs
		outputFile [stringlit]
		
		
	export listOfAllAddedMarkers [repeat gotoMarkers]
		_
		
	construct newP [program]
		P [fixEveryBlock]
	
	import listOfAllAddedMarkers 
	
	construct outputAddedMarekrs [repeat gotoMarkers]
		listOfAllAddedMarkers [write outputFile]
		
end function




rule fixEveryBlock
	replace $ [declaration_or_statement]
		currentStm [declaration_or_statement] 
		
		deconstruct * [compound_statement] currentStm
			hasCompoundStatement [compound_statement]
		
		
		deconstruct * [inLineComment] currentStm
			currentComment [inLineComment]
		
		
		
	
		
		
		deconstruct * [compound_statement_body] currentStm
			currentBlockBody [compound_statement_body]
		
		
		construct newBody [compound_statement_body]
			currentBlockBody [annotateGotos currentComment]
		
		
	by
		currentStm
	
end rule



rule annotateGotos	Annotation [inLineComment]
	skipping [compound_statement]
	replace $ [declaration_or_statement]
		currentDecl [declaration_or_statement]
		
	
	skipping [compound_statement]	
	deconstruct * [jump_statement] currentDecl
		currentJmp [jump_statement]
		
	construct jumpStatementString [stringlit]
		_ [quote currentJmp]
		
	where 
		jumpStatementString [grep "goto"]	

	deconstruct * [statement] currentDecl
		currentStm [statement]
		
	deconstruct * [unlabeled_statement] currentStm
		currentUnlabeledStm [unlabeled_statement]
		
	construct emptyLabel [repeat label]
		_ 
		
	construct newStm [statement] 
		Annotation emptyLabel currentUnlabeledStm
		
	construct newDeclStm [declaration_or_statement]
		newStm
	
	construct currentJmpId [id]
		_ [unquote jumpStatementString]
	

	construct newJumpString [stringlit]
		_ [quote newDeclStm]
	construct newJumpId [id]
		_ [unquote newJumpString]
		
	construct newMarkerAdded [gotoMarkers]
		currentJmpId newJumpId 
		
	import listOfAllAddedMarkers [repeat gotoMarkers]
	export listOfAllAddedMarkers
		listOfAllAddedMarkers [. newMarkerAdded]
		
	by
		newDeclStm
end rule








