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




function main
    match [program]
        P [program]
    import TXLargs [repeat stringlit]
	deconstruct  TXLargs
		 CoreFeatureFile [stringlit] OutputFile [stringlit]
    construct P2 [program]
    	_[read CoreFeatureFile] 

	deconstruct P 
		interfaceCompUnit [compilation_unit]
   		
   	deconstruct interfaceCompUnit
   		interfaceFunctionsDefs [repeat function_definition_or_declaration]	
   		
   	deconstruct P2
   		coreCompUnit [compilation_unit]
   		
   	deconstruct coreCompUnit
  		coreFunctionsDefs [repeat function_definition_or_declaration]
  	
  	deconstruct interfaceFunctionsDefs
  		firstInclude [function_definition_or_declaration] restInterface [repeat function_definition_or_declaration]
  		
  	construct finalDefsDecls [repeat function_definition_or_declaration]
  		_ [. firstInclude] [. coreFunctionsDefs] [. restInterface] [write OutputFile]
  	
  	

end function 




function containsAnIncludeFile
	match * [preprocessor_line]
		currentLine [preprocessor_line]
	construct preprocessorAsString [stringlit]
		_ [quote currentLine]
	construct first_quote [number]
    	_ [index preprocessorAsString '"]
    where
    	preprocessorAsString [grep 'include]
    where 
    	first_quote [> 0]
end function








