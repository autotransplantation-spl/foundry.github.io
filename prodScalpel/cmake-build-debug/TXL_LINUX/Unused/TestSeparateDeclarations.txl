include "cOriginal.grm"

tokens
	end_source_files_mark "______________________________"
	end_call_graph_marker "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"
	current_function "^^\i+^^"
	source_file_element "@@[/\i]*.\i*@@"
	source_file_token "source_file:"

end tokens

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



function main
	match * [program]
		P [program]
		
	deconstruct * [function_definition] P
		currentFctDef [function_definition]
		
		
	construct extendedDecl [function_definition]
		currentFctDef [extendAllDeclarations]
		
	construct msss [id]
		_ [message extendedDecl]
	
end function


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
	construct repeatCurrentDecl [repeat declaration]
		_ [. theDeclaration]
	construct separateListOfDecl [repeat declaration]
		repeatCurrentDecl [constructListOfSeparateDeclarations theDeclaration]
	
	construct listOfDeclOrStm [repeat declaration_or_statement]
		_ [reparse separateListOfDecl]	
	
	by
		listOfDeclOrStm
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
	
	
	
	
	







function hasMacroSpec
	match * [macro_specifier]
		currentMacro [macro_specifier]
end function




function hasDecl
	match * [list init_declarator]
		AS [init_declarator]
end function
 
