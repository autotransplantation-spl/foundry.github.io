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


redefine program
	[repeat declaration_or_statement]	
end redefine




define function_dependency_output
	[id] @ [repeat id] [NL]
end define

%cv_qualifier sc_specifier


define dependency_output
	'FUNCTION_NAME: [NL] [inLineComment] [NL] 'DECLARATION_LIST: [NL] [repeat inline_comment_with_line_end]  [end_marker] [NL]
end define

define inline_comment_with_line_end
	[inLineComment] [NL]
end define



define symbol_table_entry
	[inLineComment] @ [decl_specifiers] @ [declarator]  [NL]
end define















function main
	match * [program]
		P [program]
		
	deconstruct P
		declOrStmList [repeat declaration_or_statement]
		
		
	import TXLargs [repeat stringlit]
	
	deconstruct * [stringlit] TXLargs
		outputFile [stringlit]
	
	construct listOfSymbols [repeat symbol_table_entry]
		_ [constructSymbolTable declOrStmList]
		
		
		
	construct msss [repeat symbol_table_entry]
		listOfSymbols [write outputFile]
		
end function







function constructSymbolTable	DeclList [repeat declaration_or_statement]
	replace [repeat symbol_table_entry]
		current [repeat symbol_table_entry]
	
	deconstruct DeclList
		first [declaration_or_statement] rest [repeat declaration_or_statement]
		
	deconstruct * [declaration] first
		justDecl [declaration]
		
	%construct declNoInLineComm [declaration]
		%first [removeInLineComment]
		
	deconstruct * [inLineComment] first
		lineMarker [inLineComment]
		
		
	construct newSymbolTableEl [repeat symbol_table_entry]
		_ [addNextDecl justDecl lineMarker]
		
	
	by
		current [. newSymbolTableEl]
		[constructSymbolTable rest]
end function

rule removeInLineComment
	replace $ [repeat inLineComment]
		_ [repeat inLineComment]
	by
		_
end rule


function addNextDecl	currentVarDeclInlineCom [declaration]
						LineMarker [inLineComment]
	
	replace [repeat symbol_table_entry]
		decl [repeat symbol_table_entry]
		
		
		
	deconstruct currentVarDeclInlineCom
		unusedInlineCom [opt inLineComment] specT [decl_specifiers] declT [list init_declarator] ';
		
	construct   currentVarDecl[declaration]
		specT declT ';
		
		
					construct mdsak [id]
		_ [message "<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"]
		
		
	construct currentVarDeclStringlit [stringlit]
		_ [quote currentVarDecl]
	
	where not
		currentVarDecl [hasMacroSpec]
	where not
		currentVarDeclStringlit [grep "$ABSTRACT_"]
    construct initialVars [repeat symbol_table_entry]
    	_  [addVarIfJustDeclaration currentVarDecl LineMarker] 	
    deconstruct specT
		repeatFromDecl [repeat decl_qualifier_or_type_specifier]
	construct removedQualifiers [repeat decl_qualifier_or_type_specifier]
		_ [removeTypeSpecifiers repeatFromDecl] 
	%construct 
	construct newVarDeclSpecifiers [decl_specifiers]
		removedQualifiers 
	%fix here for adding qualifiers also and in the next function!!!
	construct allVars [repeat symbol_table_entry]
		initialVars [alldeclarationSeparedList newVarDeclSpecifiers declT LineMarker] 
	by
		decl [. allVars]
end function
	
	
function addVarIfJustDeclaration	var [declaration]
									lineMarker [inLineComment]
	replace [repeat symbol_table_entry]
		varDecl [repeat symbol_table_entry]
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
			
			
		construct newSTEntry [symbol_table_entry]
			lineMarker 	@ typesModifiersDeclSpec @ varDeclsss 
			
			
			
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
		varDecl [.newSTEntry]	
end function	





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
									lineMarker [inLineComment]
	replace [repeat symbol_table_entry]
		variableDeclList [repeat symbol_table_entry]
	deconstruct * [init_declarator] declList
		First [init_declarator] 
	construct Rest [list init_declarator]
		declList [tail 2]	
	
	deconstruct * [declarator] First
		currentDeclarator [declarator]

		
		
		
	construct newSTEntry [symbol_table_entry]
		lineMarker @ specifier @ currentDeclarator 
		
	
	by
		variableDeclList [. newSTEntry]
		[alldeclarationSeparedList specifier Rest lineMarker]
end function









