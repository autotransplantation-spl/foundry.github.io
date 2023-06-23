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
    |	[addGraft]
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














define addGraft
	__INTERFACE_FUNCTION [NL]
	|	[repeat declaration_or_statement]
end define


define declaration_or_statement_markers
	[declaration_or_statement] 
	| [stringlit] [NL]
end define

redefine function_definition_or_declaration
	[function_definition]  
    |	[declaration] 
	|	[addGraft]

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
    replace [program]
        P [program]
    import TXLargs [repeat stringlit]
	construct separeSign [stringlit]
		 "%"
	deconstruct  TXLargs
		 PathToGraft [stringlit] %NewHostOutput [stringlit]
	export PathToGraft

   		
    construct NewP [program]
        P [insertGraftInFunction] [print]
    by
        NewP
end function 


function isAGraft
    match  [function_definition_or_declaration]
        AS [addGraft]
end function




function insertGraftInFunction
	replace * [addGraft]
		G [addGraft]
	%only apply this function if the graft is: __ADDGRAFTHERE__JUSTHERE
	%otherwise it was already replaced as a function
	deconstruct * G
		__INTERFACE_FUNCTION
	by
	 G [addTheGraftInFunction]
end function



function addTheGraftInFunction
	replace [addGraft]
		myGraft [addGraft]		
	import PathToGraft [stringlit]	
    construct P2 [program]
               _[read PathToGraft]    
    deconstruct * [compilation_unit] P2
    	compUnit [compilation_unit]
    deconstruct compUnit
    	functionsAndDeclFromGraft [repeat function_definition_or_declaration]
    





    deconstruct * [function_definition] functionsAndDeclFromGraft
    	fct_body [function_definition]    
    deconstruct fct_body
        headerG [function_header] paramDeclsG [opt KR_parameter_decls] statementCompG [compound_statement] 
    deconstruct * [compound_statement_body] statementCompG
        body [compound_statement_body] 
    deconstruct body
    	listFromBody [repeat declaration_or_statement] 
   	construct  listWithoutReturn [repeat declaration_or_statement]
   		listFromBody  [removeGraftSign]
	by 
		listWithoutReturn
end function


function removeGraftSign
    replace * [addGraft]
		_ [addGraft]
    by 
end function


function returnFunctionWithGraftFromDonor	V1 [repeat function_definition_or_declaration]
	replace [repeat function_definition_or_declaration]
		P[repeat function_definition_or_declaration]
	deconstruct V1 
		first [function_definition_or_declaration] rest [repeat function_definition_or_declaration]
	construct functionWithGraft [function_definition_or_declaration]
		_ [returnGraftPlace first]
	by
		P [. functionWithGraft]
		[returnFunctionWithGraftFromDonor rest]
end function


function returnGraftPlace	V1 [function_definition_or_declaration]
	replace [function_definition_or_declaration]
		_ [function_definition_or_declaration]
	deconstruct V1
		fctDef [function_definition_or_declaration]
	where 
		V1[containsAGraft]
	by	
		V1
end function


function containsAGraft
    match * [declaration_or_statement]
        AS [addGraft]
end function