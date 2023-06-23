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














define id_or_nr
	[id] | [number]
end define





function main
    replace [program]
        P [program]
    import TXLargs [repeat stringlit]
	deconstruct  TXLargs
		 PathToSymbolTable [stringlit]  OutputFile [stringlit]
		 
		
	construct SymbolsArgsString [repeat stringlit]
		_ [read PathToSymbolTable]
		
	construct SymbolsArgument [repeat id_or_nr]
		_ [stringLitToID SymbolsArgsString] 
		
		 
	export SymbolsArgument 
	
	
    construct NewP [program]
        P [insertGraftAsEntireFunction] [write OutputFile]
        
    by
        NewP
end function 


function stringLitToID ListOfStrings [repeat stringlit]
	replace [repeat id_or_nr]
		current [repeat id_or_nr]
	
	deconstruct ListOfStrings 
		first [stringlit] rest [repeat stringlit]
	
	construct firstID [id]
		_ [unquote first]	
		
	construct firstIDNo [id_or_nr]
		firstID
	
	by
		current [. firstIDNo]
		[stringLitToID rest]
end function




function insertGraftAsEntireFunction
	replace  [program]
		G [program]

    construct addGraftTest [program]
       	G [addTheGraftAsFunction]
	by
	 addGraftTest
end function



function addTheGraftAsFunction
	replace [program]
		P [program]		
    construct newP [program]
    	P [fixIdentifiersForTransplant]			    
	by 
		newP
end function


function fixIdentifiersForTransplant
    replace [program]
        F [program]
	import SymbolsArgument [repeat id_or_nr]
    construct NewF [program]
        F   [replaceIdNames SymbolsArgument]
    by
        NewF
end function 


function replaceIdNames listOfID [repeat id_or_nr]
	replace [program]
		F [program]
	deconstruct listOfID
		first [id_or_nr] second [id_or_nr] rest [repeat id_or_nr]		
	construct newF [program]
		F [replaceID first second] 
	by
		newF
		[replaceIdNames rest]
end function


rule replaceID 	currentIDStr [id_or_nr] 
				futureIDStr [id_or_nr]
	replace $ [id] 
		Id [id]
	construct ruleIDStringlit [stringlit]
		_ [quote Id]
	construct currentIDStringlit [stringlit]
		_ [quote currentIDStr]
		
	construct futureIDStringlit [stringlit]
		_ [quote futureIDStr]
	construct finalFutureID [id]
		_ [unquote futureIDStringlit]	
		
	where	
		ruleIDStringlit [= currentIDStringlit] 
	by
		finalFutureID
end rule


