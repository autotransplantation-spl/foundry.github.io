include "CNoComments.grm"

%include "cOriginal.grm"


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



define dependency_output
	'FUNCTION_NAME: [NL] [inLineComment] [NL] 'DECLARATION_LIST: [NL] [repeat inline_comment_with_line_end]  [end_marker] [NL]
end define

define inline_comment_with_line_end
	[inLineComment] [NL]
end define



function main
    match [program]
        P [program]
    import TXLargs [repeat stringlit]
    deconstruct * [stringlit] TXLargs
    	outputFile [stringlit]
	deconstruct P 
		interfaceCompUnit [compilation_unit]
   		
   	deconstruct interfaceCompUnit
   		interfaceFunctionsDefs [repeat function_definition_or_declaration]		
   	deconstruct * [function_definition_or_declaration] interfaceCompUnit
   		TheInterfaceFunction [function_definition_or_declaration]
   	export ListOfAllDependencies [repeat dependency_output]
   		_
    construct createTheListOfStatements [function_definition_or_declaration]
   		TheInterfaceFunction [fixEveryBlock TheInterfaceFunction]		
   	import ListOfAllDependencies [repeat dependency_output]
   	construct msss [repeat dependency_output]
   		ListOfAllDependencies [write outputFile]
end function 

%not sure this works well for compoun, since it goes just into every body, but not into
%compound statement
rule fixEveryBlock	TheInterfaceFunction [function_definition_or_declaration]
	replace $ [compound_statement]
		currentBlock [compound_statement]
	deconstruct * [compound_statement_body] currentBlock
		currentBlockBody [compound_statement_body]
	construct addStatements [compound_statement_body]
		currentBlockBody [matchAllStatements currentBlock TheInterfaceFunction]
	construct addStatementsFromDecl [compound_statement_body]
		currentBlockBody [matchStatementsFromDeclaration currentBlock TheInterfaceFunction]
	by
		currentBlock
end rule


rule matchStatementsFromDeclaration	CurrentBlock [compound_statement]
									TheInterfaceFunction [function_definition_or_declaration]
	skipping [compound_statement] 
	replace $ [declaration]
		current [declaration]
	%deconstruct * [macro_specifier] current
		%currentState444ment [macro_specifier] 
	construct currentDeclOrStm [declaration_or_statement]
		current
	export BlocksList [repeat compound_statement_body]
		_
	construct constructListOfBlocks [function_definition_or_declaration]
		TheInterfaceFunction [findAllBlocksThatContainsTheCurrentOne CurrentBlock]
	import BlocksList [repeat compound_statement_body] 
	construct allIdsFromStatement [repeat id]
		_ [^ currentDeclOrStm] 
	%the statement line marker
	deconstruct * [inLineComment] currentDeclOrStm
		StatementNumberMarker [inLineComment]	
	export repeatOfNeededDecl [repeat inline_comment_with_line_end]
		_
	%construct the needed decl list	
	construct addTheNeededDeclarations [repeat compound_statement_body]
		BlocksList [matchAllDeclarationOfNeededIDs allIdsFromStatement StatementNumberMarker]
	import repeatOfNeededDecl [repeat inline_comment_with_line_end]

	%don't add decl/statements for which there is no dependency
	construct dependOutputElNonEmpty [repeat dependency_output]
		_ [constructGlobalDependencyListWhenNonEmpty StatementNumberMarker repeatOfNeededDecl]

	import ListOfAllDependencies [repeat dependency_output]
	export ListOfAllDependencies
		ListOfAllDependencies [. dependOutputElNonEmpty]
	by
		current
end rule



function constructGlobalDependencyListWhenNonEmpty	CommentMarker [inLineComment]
													IdentifiedDecl [repeat inline_comment_with_line_end]
	replace [repeat dependency_output]
		current [repeat dependency_output]
	construct endMarker [end_marker]
		 '@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ 
	construct newNeededDependenciesForTypeDefs [dependency_output]
		'FUNCTION_NAME: CommentMarker 'DECLARATION_LIST: IdentifiedDecl endMarker
	construct lengthIdentified [number]	
		_ [length IdentifiedDecl]
	where
		lengthIdentified [> 0]
	by
		current [. newNeededDependenciesForTypeDefs]
end function













rule matchAllStatements	CurrentBlock [compound_statement]
						TheInterfaceFunction [function_definition_or_declaration]
	skipping [compound_statement] 
	replace $ [statement]
		current [statement]
	construct currentNoBody [statement]
		current [removeCompoundBody]
	construct currentDeclOrStm [declaration_or_statement]
		currentNoBody
	export BlocksList [repeat compound_statement_body]
		_
	construct constructListOfBlocks [function_definition_or_declaration]
		TheInterfaceFunction [findAllBlocksThatContainsTheCurrentOne CurrentBlock]
	import BlocksList [repeat compound_statement_body] 
	construct allIdsFromStatement [repeat id]
		_ [^ currentNoBody] 
	%the statement line marker
	deconstruct * [inLineComment] currentNoBody
		StatementNumberMarker [inLineComment]	
	export repeatOfNeededDecl [repeat inline_comment_with_line_end]
		_
	%construct the needed decl list	
	construct addTheNeededDeclarations [repeat compound_statement_body]
		BlocksList [matchAllDeclarationOfNeededIDs allIdsFromStatement StatementNumberMarker]
	import repeatOfNeededDecl [repeat inline_comment_with_line_end]
	%don't add decl/statements for which there is no dependency
	construct dependOutputElNonEmpty [repeat dependency_output]
		_ [constructGlobalDependencyListWhenNonEmpty StatementNumberMarker repeatOfNeededDecl]
	import ListOfAllDependencies [repeat dependency_output]
	export ListOfAllDependencies 
		ListOfAllDependencies [. dependOutputElNonEmpty]
	by
		current
		
end rule




rule matchAllDeclarationOfNeededIDs	ListOfIDs [repeat id]
									CurrentStatementDeclForWhichIsSearchedDependency [inLineComment]
	skipping [compound_statement]
	replace $ [declaration]
		currentDecl [declaration]
	
	deconstruct not * [macro_specifier] currentDecl
		currentNotMacro [macro_specifier] 	
		
		
	construct addedDeclFromBaseDecl [repeat inline_comment_with_line_end]
		_ [addDeclIfCaseFromBaseDecl currentDecl ListOfIDs CurrentStatementDeclForWhichIsSearchedDependency]
	
	construct addedDeclFromTypeSpec [repeat inline_comment_with_line_end]
		addedDeclFromBaseDecl [addDeclIfCaseFromTypeSpecifier currentDecl ListOfIDs CurrentStatementDeclForWhichIsSearchedDependency]
		
	import repeatOfNeededDecl [repeat inline_comment_with_line_end]
	
	export repeatOfNeededDecl 
		repeatOfNeededDecl [. addedDeclFromTypeSpec]
	by
		currentDecl
end rule





function addDeclIfCaseFromBaseDecl	CurrentDeclaration [declaration]
									ListOfNeededIDs [repeat id]
									CurrentStatementDeclForWhichIsSearchedDependency [inLineComment]
	replace [repeat inline_comment_with_line_end]
		_ [repeat inline_comment_with_line_end]
	construct listOfBaseDecl [repeat base_declarator]
		_ [^ CurrentDeclaration]
	construct listOfIDs [repeat id]
		_ [^ listOfBaseDecl]
		
	deconstruct * [inLineComment] CurrentDeclaration
		currentDeclMarker [inLineComment]
	construct currentDeclMarkerNL [inline_comment_with_line_end]
		currentDeclMarker
	where
		listOfIDs [matchAnIdFromTheList ListOfNeededIDs]
	where not
		CurrentStatementDeclForWhichIsSearchedDependency [= currentDeclMarker]
	by
		_ [. currentDeclMarkerNL]
end function


%when just one variable is declared, we must do different since it will not be matched as base declarator
%because of a bug in grammar
function addDeclIfCaseFromTypeSpecifier	CurrentDeclaration [declaration]
										ListOfNeededIDs [repeat id]
										CurrentStatementDeclForWhichIsSearchedDependency [inLineComment]
	replace [repeat inline_comment_with_line_end]
		_ [repeat inline_comment_with_line_end]	
	deconstruct CurrentDeclaration
		inlineComm [opt inLineComment] declSpec[decl_specifiers] semiMark [semi]
	construct idsFromDeclSpec [repeat id]
		_ [^ declSpec]		
	construct lastID [repeat id]
		_ [returnLastID idsFromDeclSpec]
	deconstruct * [inLineComment] CurrentDeclaration
		currentDeclMarker [inLineComment]
	construct currentDeclMarkerNL [inline_comment_with_line_end]
		currentDeclMarker
	where
		lastID [matchAnIdFromTheList ListOfNeededIDs]
	where not
		CurrentStatementDeclForWhichIsSearchedDependency [= currentDeclMarker]
	by
		_ [.currentDeclMarkerNL]
end function


function returnLastID	IDList [repeat id]
	replace [repeat id]
		_ [repeat id]
	deconstruct IDList 
		first [id] rest [repeat id]
	by
		_ [. first]
		[returnLastID rest]
end function



function matchAnIdFromTheList	ListOfNeededIDs [repeat id]
	match * [id]
		current [id]
	where
		ListOfNeededIDs [matchInList current]
end function

function matchInList	CurrentID[id]
	match * [id]
		current [id]
	where
		current [= CurrentID]
end function




rule findAllBlocksThatContainsTheCurrentOne	CurrentBlock [compound_statement]
	replace $ [compound_statement]
		current [compound_statement]
	where
		current [containsTheBlock CurrentBlock]
		
		import BlocksList [repeat compound_statement_body]
		
		deconstruct * [compound_statement_body] current
			justTheBody [compound_statement_body]
		
		export BlocksList 
			BlocksList [. justTheBody]
	by
		current
end rule


function containsTheBlock	CurrentBlock[compound_statement]
	match * [compound_statement]
		currentCompound [compound_statement]
	
	where 
		currentCompound [= CurrentBlock]
end function
		


rule removeCompoundBody 
	replace $ [compound_statement_body]
		currentBody [compound_statement_body]
		
	by
		_	
end rule