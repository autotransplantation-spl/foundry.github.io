include "cOriginal.grm"

%redefine upper_macro_name
%   [upperlowerid] 
%end redefine



redefine label
	[EX] [label_id] ': [IN] 
    |   [EX][SP][SP] 'case [constant_expression] ': [IN] 
    |   [EX][SP][SP] 'default ': [IN] 
#ifdef GNU
    |   [EX][SP][SP] 'case [constant_expression] [SP] '... [SP] [constant_expression] ': [IN]    
#endif
end redefine


redefine declaration_or_statement
	...
	| [stringlit] [NL]
	| [id] [NL]
end redefine

define ids_with_line_break
	[id] [NL]
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
	match [program]
		P [program]
	export CompoundNumberMarker [number]
		0
	import TXLargs [repeat stringlit]
	deconstruct TXLargs
		outputFile [stringlit] 
	construct newP [program]
		P [constructNewGPFunctions]
	%output the new program
	construct outputProg [program]
		newP [write outputFile]
end function




function constructNewGPFunctions
	replace [program]
		P [program]
	%write the functions for GP
	construct programSeparateDecl [program]
		P [extendAllDeclarations]
	construct AnnotatedProgram [program]
		programSeparateDecl [fixEveryBlock] 
	construct AnnotatedProgramIDs [program]
		AnnotatedProgram [everyBlockToIDs] 	
	by
		AnnotatedProgramIDs
end function



rule everyBlockToIDs
	replace $ [compound_statement]
		currentBlock [compound_statement]
		deconstruct * [compound_statement_body] currentBlock
			currentBlockBody [compound_statement_body]
		construct blockReplacedDeclStm [compound_statement_body]
			currentBlockBody [replaceDeclStmNoBodyStringlit]
		construct replacedBlock [compound_statement]
			'{ blockReplacedDeclStm '}	
	by
		replacedBlock
end rule


rule replaceDeclStmNoBodyStringlit
	skipping [compound_statement]
	replace $ [declaration_or_statement]
		current [declaration_or_statement]
		
	deconstruct current
		currentStringlit [stringlit]	
	construct newDeclID [id]
		_ [unquote currentStringlit]
		
	construct declAsStringlit [stringlit]
		_ [quote current]
		


	construct finalReplacement [stringlit]
		declAsStringlit
	construct replacementAsDeclStatement [declaration_or_statement]
		finalReplacement
	deconstruct not * [compound_statement_body] current
		currentCompund [compound_statement_body]

	by
		newDeclID
end rule


%do it at blocks level!!!!
rule fixEveryBlock
	replace $ [compound_statement]
		currentBlock [compound_statement]
	deconstruct * [compound_statement_body] currentBlock
		currentBlockBody [compound_statement_body]
	deconstruct currentBlockBody
		currentBlockDeclStm [repeat declaration_or_statement]
	construct DeclAsStrings [repeat declaration_or_statement]
		_ [declToStringlit currentBlockDeclStm] 
	%construct blockReplacedDeclStm [compound_statement_body]
		%currentBlockBody [replaceDeclStmNoBody]
	construct newBlockBody [compound_statement_body]
		DeclAsStrings
	construct replacedBlock [compound_statement]
		'{ newBlockBody '}	
		
	by
		replacedBlock
end rule



function stringlitToId 	ListOfStrings [repeat declaration_or_statement]
	replace [repeat ids_with_line_break]
		current [repeat ids_with_line_break]
	deconstruct ListOfStrings 
		first [declaration_or_statement] rest [repeat declaration_or_statement]
	
	
	
	construct firstString [stringlit]
		_ [quote first]
		
	construct finalFirstStrng [stringlit]
		firstString [replaceIfItIsString first]
	
	construct firstId [id]
		_ [unquote finalFirstStrng]
	
	
	
	construct idWithLB [ids_with_line_break]
		firstId
	by
		current [. idWithLB]
		[stringlitToId rest]
end function




function declOrStatementToStringlit	CurrentDecl [declaration_or_statement]
	replace [declaration_or_statement]
		current [stringlit]
	deconstruct not CurrentDecl
		CurrentDeclStringlit [stringlit]	
		
		
	construct currentDeclStringlit [stringlit]
		_ [quote CurrentDecl]
		
	construct newDeclFromStringlit [declaration_or_statement]
		currentDeclStringlit
	by
		newDeclFromStringlit
end function






function replaceIfItIsString	Current [declaration_or_statement]
	replace [stringlit]
		_ [stringlit]
	deconstruct * [stringlit] Current
		currentString [stringlit]
	by
		currentString
		
end function


function ToDeclStmMarkers	Initial [repeat declaration_or_statement]
	replace [repeat declaration_or_statement]
		current [repeat declaration_or_statement]
	deconstruct Initial
		first [declaration_or_statement] rest [repeat declaration_or_statement]
	construct CurrDecl [declaration_or_statement]
		first
		
	by
		current [. CurrDecl]
		[ToDeclStmMarkers rest]
end function





function declToStringlit	Decl [repeat declaration_or_statement]
	replace [repeat declaration_or_statement]
		current [repeat declaration_or_statement]
	deconstruct Decl 
		first [declaration_or_statement] rest [repeat declaration_or_statement]
		
		
	export BeginCompoundMarker [repeat declaration_or_statement]
		_
	export EndCompoundMarker [repeat declaration_or_statement]
		_
	%add the function mark also at the beggining
	export AdditionalFunctionCall [repeat declaration_or_statement]
		_
	export LabelMarker [repeat declaration_or_statement]
		_	
	construct firstSolvedCallFunctions [declaration_or_statement]
		first 
	%fix order for compund statemend; it should be first
	
	
	%add markers at declarations!!!	
	construct firstSolvedStatement [declaration_or_statement]
		firstSolvedCallFunctions [addMarkerAtDeclarations]
	
	
	
	construct firstWithLineStatements [declaration_or_statement]
		firstSolvedStatement [addNumberAtStatements]	
		
		
	construct firstWithLineSolvedOneParamFctCall [declaration_or_statement]
		firstWithLineStatements [addNumberAtStmFunctCallWithOneParameter firstSolvedCallFunctions]
		
	construct firstWithLine [declaration_or_statement]
		firstWithLineSolvedOneParamFctCall [addNumberAtMacros firstSolvedCallFunctions] 
		
		

	export ElseStatement [repeat declaration_or_statement]
		_	
		
	construct finalStringNoElse [declaration_or_statement]
		firstWithLine [solveCompundStatement first]
	%construct finalRest [repeat declaration_or_statement]
		%rest [AddFromCompund first]
		
	
	construct finalString [declaration_or_statement]
		finalStringNoElse [solveElseCompounds first]
	
		
	import ElseStatement 
	import BeginCompoundMarker [repeat declaration_or_statement]
	import EndCompoundMarker [repeat declaration_or_statement]
	import AdditionalFunctionCall [repeat declaration_or_statement]
	import LabelMarker [repeat declaration_or_statement]	
	construct finalStringAddedFunctionCall [repeat declaration_or_statement]
		AdditionalFunctionCall [.BeginCompoundMarker] [. finalString] [. LabelMarker]

	construct newRest [repeat declaration_or_statement]
		rest [. ElseStatement]
		
	construct reallyFinalNewStm [repeat declaration_or_statement]
		finalStringAddedFunctionCall %[revertToOriginalIfCompound first]
	
	by
		current [. reallyFinalNewStm]  [. EndCompoundMarker]
		[declToStringlit newRest]
end function






function addMarkerAtDeclarations
	replace [declaration_or_statement]
		current [declaration_or_statement]
	deconstruct not * [statement] current
		currentNotStatement [statement] 
	deconstruct not * [macro_specifier] current
		currentNotMacro [macro_specifier] 
	construct LineString [stringlit]
		"@DECL"
	%comment the line numbers	
	construct commentStartMarker [stringlit]
		"/*"
	construct commentEndMarker [stringlit]
		"*/ "
	construct FinalLineString [stringlit]
		commentStartMarker [+ LineString] [+ commentEndMarker]
	construct currentStatementString [stringlit]
		FinalLineString [quote current]
	construct currentStmLine [declaration_or_statement]
		currentStatementString
	by
		currentStmLine
end function





function hasCompundBody
	match [declaration_or_statement]
		current [declaration_or_statement]
	
	deconstruct * [compound_statement_body] current
		currentCompund [compound_statement_body]
end function

					






function addNumberAtStmFunctCallWithOneParameter	current [declaration_or_statement]
	replace [declaration_or_statement]
		modifiedStatement [declaration_or_statement]
		
		

		
	%check if it is declaration
	deconstruct current
		isDeclaration [declaration]	
	
		

	deconstruct * [base_declarator] current
		baseDeclFromCurrent [base_declarator] 
		
	construct baseDeclString [stringlit]
		_ [quote baseDeclFromCurrent]
	
	where
		baseDeclString [grep "("]
	where
		baseDeclString [grep ")"]		
		
	deconstruct not * [else_statement] current
		theElseStatement [else_statement]
		

	construct CurrentAsString [stringlit]
		_ [quote current]
	construct FirstTwoChars [stringlit]
		CurrentAsString [: 1 2]
	construct commentMark [stringlit]
		"//"	
	where not
		commentMark [= FirstTwoChars]	
	construct LineString [stringlit]
		"@STM"
	%comment the line numbers	
	construct commentStartMarker [stringlit]
		"/*"
	construct commentEndMarker [stringlit]
		"*/ "
	construct FinalLineString [stringlit]
		commentStartMarker [+ LineString] [+ commentEndMarker]	
	construct currentStatementString [stringlit]
		FinalLineString [quote current]
	construct currentStmLine [declaration_or_statement]
		currentStatementString
	by
		currentStmLine
end function












function addNumberAtMacros	current [declaration_or_statement]
	replace [declaration_or_statement]
		modifiedStatement [declaration_or_statement]

	deconstruct * [macro_specifier] current
		currentState444ment [macro_specifier] 
		
	deconstruct not * [else_statement] current
		theElseStatement [else_statement]
		
	construct TTTT [macro_specifier]
		currentState444ment 
	construct CurrentAsString [stringlit]
		_ [quote current]
	construct FirstTwoChars [stringlit]
		CurrentAsString [: 1 2]
	construct commentMark [stringlit]
		"//"	
	where not
		commentMark [= FirstTwoChars]	
	construct LineString [stringlit]
		"@STM"
	%comment the line numbers	
	construct commentStartMarker [stringlit]
		"/*"
	construct commentEndMarker [stringlit]
		"*/ "
	construct FinalLineString [stringlit]
		commentStartMarker [+ LineString] [+ commentEndMarker]	
	construct currentStatementString [stringlit]
		FinalLineString [quote current]
	construct currentStmLine [declaration_or_statement]
		currentStatementString
	by
		currentStmLine
end function

%VERY USEFULL!!!!
rule CheckAllTYPESMacro	
	replace  $ [any]
		express [any]

	construct eString [stringlit]
		_ [quote express]
	construct typeT [id]
		_ [typeof express]
	construct stringType [stringlit]
		_ [quote typeT] [+ "  "]
	construct finalMessage [stringlit]
		stringType [+ eString] [fput "testMACRo.out"]

	by
		express
end rule

function matchJmpStatement
	match * [jump_statement]
		_ [jump_statement]
end function


function addNumberAtStatements
	replace [declaration_or_statement]
		current [declaration_or_statement]
	deconstruct * [statement] current
		currentState444ment [statement] 
		
	
	
	deconstruct not * [else_statement] current
		theElseStatement [else_statement]
		
	%here we also mark the jump statement!!!
	%where not
		%currentState444ment [matchJmpStatement]

	construct LineString [stringlit]
		"@STM"
		
	%comment the line numbers	
	construct commentStartMarker [stringlit]
		"/*"
	construct commentEndMarker [stringlit]
		"*/ "
	construct FinalLineString [stringlit]
		commentStartMarker [+ LineString] [+ commentEndMarker]
		
		
	construct currentStatementString [stringlit]
		FinalLineString [quote current]
	construct currentStmLine [declaration_or_statement]
		currentStatementString
	by
		currentStmLine
end function


function AddFromCompund CurrentStatement [declaration_or_statement]
	replace [repeat declaration_or_statement]
		currentList [repeat declaration_or_statement]
		
		
		
		
		
	deconstruct * [compound_statement_body] CurrentStatement
		currentCompund [compound_statement_body]	
		
		
	

		
	deconstruct * [structured_statement] CurrentStatement
		currentCompund2 [structured_statement]
	construct compundNoBody [declaration_or_statement]
		currentCompund2 [removeBodyFromCompund]
	construct compundString [stringlit]
		_ [quote compundNoBody] 
	construct lengthOfHeader [number]
		_ [# compundString] [- 2]
	construct removedEndOfBlock [stringlit]
		compundString [: 1 lengthOfHeader]

	deconstruct * [repeat declaration_or_statement] currentCompund
		declsFromCompund [repeat declaration_or_statement]
	construct declsMarkersFromCompund [repeat declaration_or_statement]	
		_ [ToDeclStmMarkers declsFromCompund] 	
	construct finalMarker [stringlit]
		"} "
	construct finalEndOfCompund [stringlit]
		finalMarker [+ "//"] [+ removedEndOfBlock] 
	construct addFinalMarker [declaration_or_statement]
		finalEndOfCompund
		
		
	
		
		
		
		
	by
		declsMarkersFromCompund [.addFinalMarker] [. currentList]
end function


function solveCompundStatement	CurrentStatement [declaration_or_statement]
	
	replace [declaration_or_statement]
		current [declaration_or_statement]
		
	deconstruct not CurrentStatement
		currentCompundds [else_statement]	
		
	deconstruct * [compound_statement] CurrentStatement
		notCompound [compound_statement]
		
		
		
	deconstruct * [compound_statement] CurrentStatement
		currentCompoundTEST [compound_statement]
		
	construct CurrentStatementNoElseClauses [declaration_or_statement]
		CurrentStatement[removeElseClause]	
		
		
		
		
	deconstruct * [structured_statement] CurrentStatementNoElseClauses
		currentCompund [structured_statement]		
	deconstruct * [compound_statement_body] CurrentStatementNoElseClauses
		justIfItHasBody [compound_statement_body]	
	construct compundNoBody [declaration_or_statement]
		currentCompund [removeBodyFromCompund] 
		
		
		
	construct exportContainedElse [repeat declaration_or_statement]
		CurrentStatement  [solveElseStatements]
		
	
		
		
		
		%%!!!!!!!!!!!!!!!!!!1!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	construct firstSolvedCallFunctions [declaration_or_statement]
		CurrentStatementNoElseClauses



	import BeginCompoundMarker [repeat declaration_or_statement]
	import EndCompoundMarker [repeat declaration_or_statement]


	construct uniqueMarkerStringlit [stringlit]
		"COMP_MARK"
		
	construct uniqueMarkerID [id]
		_ [unquote uniqueMarkerStringlit]

	construct theUniqueID [id]
		uniqueMarkerID [!]
	
	construct theUniqueIDString [stringlit]
		_ [quote theUniqueID]
		
	construct startMark [stringlit]
		"//COMPOUND START: "

	construct startCompoundMark [stringlit]
		startMark [+ theUniqueID]
	construct compoundHeaderStringlit [stringlit]
		_ [quote compundNoBody]
		
	construct finalCompoundHeaderStringlit [stringlit]
		compoundHeaderStringlit [replaceStringlitWhenEmpty]
		
	construct startCompoundComplete [stringlit]
		startCompoundMark [+ finalCompoundHeaderStringlit]
		
		
		
		
		
		
	construct CompoundMarkDeclStm [declaration_or_statement]
		startCompoundComplete
	
	export BeginCompoundMarker
		_ [. CompoundMarkDeclStm]
	
	
	
	construct endMark [stringlit]
		"//COMPOUND END: "
		
	
	construct endCompoundMark [stringlit]
		 endMark [+ theUniqueID]
	construct endCompoundComplete [stringlit]
		endCompoundMark [+ finalCompoundHeaderStringlit]
	construct endCompundMarkDeclStm [declaration_or_statement]
		endCompoundComplete
	export EndCompoundMarker
		_ [. endCompundMarkDeclStm]
	
	by
		firstSolvedCallFunctions
end function


function solveElseCompounds		CurrentStatement [declaration_or_statement]
	
	replace [declaration_or_statement]
		current [declaration_or_statement]
		

	deconstruct CurrentStatement
		currentCompund [else_statement]	
		
	deconstruct currentCompund
		'else elseSubStm [else_sub_statement]
		
	construct elseSubStmNoElseClauses [else_sub_statement]
		elseSubStm[removeElseClause]	
		
	%construct exportContainedElse [repeat declaration_or_statement]
	%	elseSubStmNoElseClauses [solveElseStatements]	
		
		
		
	construct exportContainedElse [else_sub_statement]
		elseSubStm  [solveElseStatements]
		
		
		
	import ElseStatement [repeat declaration_or_statement]	

		
	construct newElsStatementNoElseBody [else_statement]
		'else elseSubStmNoElseClauses
		
	
	
	construct newStatement [declaration_or_statement]
		newElsStatementNoElseBody
		

	construct compundNoBody [declaration_or_statement]
		newElsStatementNoElseBody [removeBodyFromCompund] 
		
		

		
		
		%%!!!!!!!!!!!!!!!!!!1!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	construct firstSolvedCallFunctions [declaration_or_statement]
		newStatement 



	import BeginCompoundMarker [repeat declaration_or_statement]
	import EndCompoundMarker [repeat declaration_or_statement]


	construct uniqueMarkerStringlit [stringlit]
		"COMP_MARK"
		
	construct uniqueMarkerID [id]
		_ [unquote uniqueMarkerStringlit]

	construct theUniqueID [id]
		uniqueMarkerID [!]
	
	construct theUniqueIDString [stringlit]
		_ [quote theUniqueID]


	construct startMark [stringlit]
		"//COMPOUND START: "
	
	construct startCompoundMark [stringlit]
		startMark [+ theUniqueIDString]
	construct compoundHeaderStringlit [stringlit]
		_ [quote compundNoBody]
		
	construct finalCompoundHeaderStringlit [stringlit]
		compoundHeaderStringlit [replaceStringlitWhenEmpty]
		
	construct startCompoundComplete [stringlit]
		startCompoundMark [+ finalCompoundHeaderStringlit]
		
	construct CompoundMarkDeclStm [declaration_or_statement]
		startCompoundComplete
	
	export BeginCompoundMarker
		_ [. CompoundMarkDeclStm]
	
	
	construct endMark [stringlit]
		"//COMPOUND END: "
	
	construct endCompoundMark [stringlit]
		endMark [+ theUniqueIDString]
	construct endCompoundComplete [stringlit]
		endCompoundMark [+ finalCompoundHeaderStringlit]
	construct endCompundMarkDeclStm [declaration_or_statement]
		endCompoundComplete
	export EndCompoundMarker
		_ [. endCompundMarkDeclStm]
	
	by
		firstSolvedCallFunctions
end function


rule removeElseClause
	skipping [compound_statement_body]
	replace $ [opt else_statement]
		_ [opt else_statement]
	by
		
end rule


function solveElseStatements
	skipping [compound_statement]
	match * [else_statement] 
		theElseStatement [else_statement]
	construct newElseDeclStm [declaration_or_statement]
		theElseStatement
	
	import ElseStatement [repeat declaration_or_statement]
	export ElseStatement
		_ [. newElseDeclStm]
end function




function replaceStringlitWhenEmpty
	replace [stringlit]
		current [stringlit]
	
	construct lengthOfInitial [number]
		_ [# current]
		
		
	import CompoundNumberMarker [number]
	
	construct compoundNumberMarkerString [stringlit]
		_ [quote CompoundNumberMarker]
		
		
	construct unnamendCompoundMarker [stringlit]
		"unnamend_compound_statement number: "
	construct noNamedCompoundReplacement [stringlit]
		unnamendCompoundMarker [+ compoundNumberMarkerString]
	
	
	export CompoundNumberMarker
		CompoundNumberMarker [+ 1]
	
	where
		lengthOfInitial [< 3]
	
	by
		noNamedCompoundReplacement
end function



rule removeBodyFromCompund
	replace $ [compound_statement_body]
		_ [compound_statement_body] 
	by
		_
		
end rule


function hasMacroSpec
	match * [macro_specifier]
		currentMacro [macro_specifier]
end function


function hasDecl
	match * [list init_declarator]
		AS [init_declarator]
end function
 
 
%extend all the declarations from the initial source code of a function

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
		
		
	%remove qualifiers like const, static, etc for avoiding compilation errors
	construct theDeclarationRemovedQualifiers	[declaration]
		theDeclaration [removeUnnededQualifiers]
		
		
	construct repeatCurrentDecl [repeat declaration]
		_ [. theDeclarationRemovedQualifiers]
		
		
	construct separateListOfDecl [repeat declaration]
		repeatCurrentDecl [constructListOfSeparateDeclarations theDeclarationRemovedQualifiers]
	
	construct listOfDeclOrStm [repeat declaration_or_statement]
		_ [reparse separateListOfDecl]	
	
	by
		listOfDeclOrStm
end function

rule removeUnnededQualifiers
	replace $ [decl_specifiers]
		currentDeclSpec [decl_specifiers]
	deconstruct currentDeclSpec
		repeatDeclQualifiersOrTypeSpec [repeat decl_qualifier_or_type_specifier]
	construct newDeclSpecRepeat [repeat decl_qualifier_or_type_specifier]
		_ [removeTypeSpecifiers repeatDeclQualifiersOrTypeSpec]
	
	construct newDeclSpec [decl_specifiers]
		newDeclSpecRepeat
		
	by
		newDeclSpec
end rule

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



