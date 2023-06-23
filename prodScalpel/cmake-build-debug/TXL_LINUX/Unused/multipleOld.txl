include "c.grm"


function main
	match [program]
			P[program]
	where
	P [addHeaderAndSourceCodes]
end function



function addHeaderAndSourceCodes
	match * [repeat function_definition_or_declaration] 
		declFromP [repeat function_definition_or_declaration]
	%exporting global variables
	construct ExportGlobalVariables [repeat function_definition_or_declaration]
		declFromP [exportDeclList]
	%initial Path that is input/	
	construct nullPath [stringlit]
		"input/"
	%separate case for the input file, since its content must not be transplanted by this program
	construct includeList[repeat stringlit]
		_ [identifyIncludeFiles declFromP nullPath] 
	
	deconstruct includeList
		first [stringlit] rest [repeat stringlit]
	
	%function that calls readFromFiles!!!
	construct FinalListOfHeaderIncludes [repeat stringlit]
		includeList [readFromFiles includeList]

	import ListOfDeclFromHeaders [repeat function_definition_or_declaration]
		
	construct PrintListToFile [repeat function_definition_or_declaration]
		ListOfDeclFromHeaders [write "output/includeCode.h"]

	%constructing the list of all source files from the project
	construct CallCommand [id]
    	_ [system "./SourceContent input"]

	construct ListOfExistingSourceFiles [repeat stringlit]
		_ [read "output.out"]% [print]

	construct HeaderCommand [id]
		_ [system "./HeaderContent input"]
	
	construct ListOfExistingHeaderFiles [repeat stringlit]
		_ [read "outputHeader.out"] %[print]

	construct firstEmptyIdList [repeat id]
		
	%identify functions for import ID from headers
	construct ListOfFunctionsIdFromHeaders [repeat id]
		_ [identifyFunctionsNameFromList ListOfDeclFromHeaders ListOfExistingSourceFiles firstEmptyIdList] 


	%construct Message444 [id]
		%_ [message FinalListOfHeaderIncludes]

	construct FinallyTheListOfAllNeededIncludes [repeat id]
		ListOfFunctionsIdFromHeaders [addAllNeededIds ListOfExistingSourceFiles ListOfFunctionsIdFromHeaders] [print]
		
		construct AllFunctionsDefs [repeat function_definition_or_declaration]
		_ [addIDFromFiles ListOfExistingSourceFiles FinallyTheListOfAllNeededIncludes] [write "output/sourceCode.h"]


	%construct testAllProgram [repeat function_definition_or_declaration]
	%	_ [constructAllSourceCode ListOfExistingHeaderFiles] [write "output/allHeaders.h"]
	
end function


function addAllNeededIds SourceFiles [repeat stringlit] ListOfExistingIds [repeat id]
	replace [repeat id]
		current [repeat id]
	construct AllFunctionsDefs [repeat function_definition_or_declaration]
		_ [addIDFromFiles SourceFiles ListOfExistingIds] %[write "output/sourceCode.h"]
	construct newListOfID [repeat id]
		_ [identifyFunctionsNameFromFunctions AllFunctionsDefs SourceFiles ListOfExistingIds ] 
	construct newListOfExistingIds [repeat id]
		ListOfExistingIds [. newListOfID]
	construct currentLength [number]
		_ [length newListOfID]		
	where
		currentLength [> 0]
	by
		current [. newListOfID]
		[addAllNeededIds SourceFiles newListOfExistingIds]
end function






function identifyFunctionsNameFromFunctions	V1 [repeat function_definition_or_declaration] SourceCode [repeat stringlit]
										AllIdList [repeat id]
	replace [repeat id]
		currentIdList [repeat id]		
	construct currendAndAllIdsList [repeat id]
		AllIdList [.currentIdList]	
	deconstruct V1
		first [function_definition_or_declaration] rest [repeat function_definition_or_declaration]
	construct newIdList [repeat id]
		currentIdList  [addNextFctIfCaseFunctions currendAndAllIdsList first SourceCode] 
 
 	construct newCurrentAndAllIdsList [repeat id]
 		currendAndAllIdsList [. newIdList]
 
 	construct finalNewIdList [repeat id]
 		newIdList [addNextDeclIfCase newCurrentAndAllIdsList first SourceCode]
 		
 		construct testNewIdList [repeat id]
		_  [addNextFctIfCaseFunctions currendAndAllIdsList first SourceCode] 
 		 	construct testFinalNewIdList [repeat id]
 		_ [addNextDeclIfCase newCurrentAndAllIdsList first SourceCode]

	by 
		finalNewIdList
		[identifyFunctionsNameFromFunctions rest SourceCode AllIdList]
end function


function addNextDeclIfCase ListOfAllIds [repeat id] NextFct [function_definition_or_declaration] SourceCode [repeat stringlit]
	replace [repeat id]
		currIdList [repeat id]
	deconstruct NextFct
		testIfDeclaration [declaration]
	construct FunctionIDUsage [repeat id]
	export FunctionIDUsage
	construct testID [function_definition_or_declaration]
		NextFct [matchAllIds]
	construct newListOfIds [repeat id]
		_ [addEveryID FunctionIDUsage ListOfAllIds]
	by
		currIdList [. newListOfIds]
		
end function


function addNextFctIfCaseFunctions	ListOfAllIds [repeat id] NextFct [function_definition_or_declaration] SourceCode [repeat stringlit]
	replace [repeat id]
		currIdList [repeat id]
	
	deconstruct * [function_header] NextFct
		currentFctHeader [function_header]
	
	construct testMacroHeader [repeat id]
		_ [addForMacroHeaderType currentFctHeader] %[print]
	
	
	deconstruct * [compound_statement_body] NextFct
		fctBody [compound_statement_body]
	deconstruct * [id] fctBody
		idOfFct [id]
	construct FunctionIDUsage [repeat id]
	export FunctionIDUsage
	construct testID [compound_statement_body]
		fctBody [matchAllIds]
	construct FunctionIDUsageFinal [repeat id]
		FunctionIDUsage [.testMacroHeader]
	construct newListOfIds [repeat id]
		_ [addEveryID FunctionIDUsageFinal ListOfAllIds]
	%where not
		%ListOfAllIds [fctNameInIDsList idOfFct]
	by
		currIdList [. newListOfIds]
end function

function addForMacroHeaderType	FunctionHeader [function_header]
	replace [repeat id]
		current [repeat id]
	
		
	deconstruct * [decl_specifiers] FunctionHeader
		DeclSpecFromHeader [decl_specifiers]	
	deconstruct *   [repeat decl_qualifier_or_type_specifier] DeclSpecFromHeader
		declSpecifiers  [repeat decl_qualifier_or_type_specifier]
	construct finalIdsList [repeat id]
		_ [addIdsFromDeclSpecifier declSpecifiers]
	by
		finalIdsList
end function

function addIdsFromDeclSpecifier	DeclSpecifiers [repeat decl_qualifier_or_type_specifier]
	replace [repeat id]
		currentIds [repeat id]
		deconstruct DeclSpecifiers
			first [decl_qualifier_or_type_specifier] rest [repeat decl_qualifier_or_type_specifier]
		construct stringFromFirst [stringlit]
			_ [quote first]
		construct idFromFirst[id]
			_ [unquote stringFromFirst]
	by
		currentIds [. idFromFirst]
end function







function addEveryID CurrentIDs [repeat id] AllIdList [repeat id]
	replace [repeat id]
		current [repeat id]
	deconstruct CurrentIDs 
		first [id]	rest [repeat id]
	construct newCurrentList [repeat id]
		current [addJustIfIDUnique AllIdList first]
	construct newIDList [repeat id]
		AllIdList [addJustIfIDUnique AllIdList first]
	by
		newCurrentList
		[addEveryID rest newIDList]
		
end function

function addJustIfIDUnique AllIdList [repeat id] CurrentId [id]
	replace [repeat id]
		currentIdList [repeat id]
	where not
		AllIdList [fctNameInIDsList CurrentId]
	by
		currentIdList [. CurrentId]
		
end function

rule matchAllIds
	replace $ [id] 
		currId [id] 
	import FunctionIDUsage [repeat id]
	
	export FunctionIDUsage
		FunctionIDUsage [. currId]
		
	%construct Message [id]
	%	_ [message currId]
		
	by
		currId
		
end rule






%construct all source code of the program, for later usage
function constructAllSourceCode SourceCodeFiles [repeat stringlit]
	replace [repeat function_definition_or_declaration]
		ListOfSourceCode [repeat function_definition_or_declaration]
	deconstruct SourceCodeFiles 
		first [stringlit] rest [repeat stringlit]
	construct currentProgram [repeat function_definition_or_declaration]
		_[read first]
	by
		ListOfSourceCode [. currentProgram]
		[constructAllSourceCode rest]
		
end function


function identifyIncludeFiles	V1 [repeat function_definition_or_declaration]
								CurrentPath [stringlit]
	replace [repeat stringlit]
		includeDecl [repeat stringlit]
	deconstruct V1
		First [function_definition_or_declaration] Rest [repeat function_definition_or_declaration]


	construct includeInstruction [stringlit]
		_ [addInclude First CurrentPath]
	construct newIncludeInstructions [repeat stringlit]
		includeDecl [addIfNotNull includeInstruction]
	

	by
		newIncludeInstructions
		[identifyIncludeFiles Rest CurrentPath]
end function


function addIfNotNull	V1 [stringlit]
	replace [repeat stringlit]
		currentList [repeat stringlit]
	construct currentLength [number]
    	_ [# V1] 
	where
		currentLength [> 0]
	by
		currentList [. V1]
end function

function addInclude	V1 [function_definition_or_declaration]
					CurrentPath [stringlit]
	replace [stringlit]
		currStatement [stringlit]
	deconstruct * [preprocessor] V1
		prepocLin [preprocessor]
	deconstruct * [preprocessor_line] prepocLin
		prepocessorLin [preprocessor_line]
	construct stringInclude [stringlit]
		 _ [quote  prepocessorLin]	 
    construct first_quote [number]
    	_ [index stringInclude '"] [+ 1]
    construct lengthOfInclude [number]
    	_ [# stringInclude] [- 1]	
    construct pathFromFirstQuote [stringlit]
    	stringInclude [: first_quote lengthOfInclude]	
    construct second_quote [number]
    	_ [index pathFromFirstQuote '"] [- 1]
    construct fileToInclude [stringlit]
        pathFromFirstQuote [: 1 second_quote]	
    construct fileWithEntirePath [stringlit]
    	CurrentPath [+ fileToInclude]
	where
		stringInclude [grep 'include]
	where
		first_quote [> 2]

	by
		fileWithEntirePath
end function



function readFromFiles	currIncludeList [repeat stringlit] 
	replace [repeat stringlit]
		FinalIncludeList [repeat stringlit]	
	construct inputS [stringlit]
		"input/"
	deconstruct currIncludeList
		first [stringlit] rest [repeat stringlit]	
	construct currentHeaderFileName [stringlit]
		first [constructHeaderFile]
	construct lengthOfHeaderFileName [number]
		_ [# currentHeaderFileName]
	construct lengthOfPathWithoutHeader [number]
		_ [# first] [- lengthOfHeaderFileName]	
	construct justThePath [stringlit]
		first [: 1 lengthOfPathWithoutHeader]
	construct path [stringlit]
			first   
	construct P2 [program]
    	_[read path] 

    deconstruct * [repeat function_definition_or_declaration] P2
		declFromP [repeat function_definition_or_declaration]
	import ListOfDeclFromHeaders [repeat function_definition_or_declaration]
	export ListOfDeclFromHeaders 
		ListOfDeclFromHeaders [. declFromP]
    construct includeList[repeat stringlit]
		_ [identifyIncludeFiles declFromP justThePath] 
    construct includeListWithoutRepetitions[repeat stringlit]
    	_ [addIncludeJustIfNotRepetition  includeList FinalIncludeList]
    construct addedNewIncludes [repeat stringlit]
    	rest [. includeListWithoutRepetitions]  
    construct newListOfAllIncludes [repeat stringlit]
    	FinalIncludeList [. includeListWithoutRepetitions]				
	by
		newListOfAllIncludes
		[readFromFiles addedNewIncludes]
end function


function identifyFunctionsNameFromList	V1 [repeat function_definition_or_declaration] SourceCode [repeat stringlit]
										AllIdList [repeat id]
	replace [repeat id]
		currentIdList [repeat id]		
	construct currendAndAllIdsList [repeat id]
		AllIdList [.currentIdList]	
	deconstruct V1
		first [function_definition_or_declaration] rest [repeat function_definition_or_declaration]
	construct newIdList [repeat id]
		currentIdList [addNextFctIfCase currendAndAllIdsList first SourceCode]
 
	by 
		newIdList
		[identifyFunctionsNameFromList rest SourceCode AllIdList]
end function

function addNextFctIfCase	ListOfAllIds [repeat id] NextFct [function_definition_or_declaration] SourceCode [repeat stringlit]
	replace [repeat id]
		currIdList [repeat id]
	deconstruct * [declarator] NextFct
		HeaderOfF [declarator]
	deconstruct * [id] HeaderOfF
		idOfFct [id]
	where not
		ListOfAllIds [fctNameInIDsList idOfFct]
	by
		currIdList [. idOfFct]
		
end function







function addIDFromFiles	ListOfSourceFiles [repeat stringlit] ListOfID [repeat id]
	replace [repeat function_definition_or_declaration]
		currList [repeat function_definition_or_declaration]
		
	deconstruct ListOfSourceFiles 
		first [stringlit] rest [repeat stringlit]
	construct currentProgram [repeat function_definition_or_declaration]
		_[read first]
			
	construct newFunctionDefsList [repeat function_definition_or_declaration]
		currList [addCurrentProgrFunct currentProgram ListOfID]
	by
		newFunctionDefsList
		[addIDFromFiles rest ListOfID]
		
end function

function addCurrentProgrFunct	P [repeat function_definition_or_declaration]
								IDsList [repeat id]
	replace [repeat function_definition_or_declaration]
		currList [repeat function_definition_or_declaration]
	
	deconstruct P
		first [function_definition_or_declaration] rest [repeat function_definition_or_declaration]
	
	construct newDeclList [repeat function_definition_or_declaration]
	
	%adding declarations or functions
	construct DeclThatShouldBeAdded [repeat function_definition_or_declaration]
		currList [addDeclJustIfInIDsList first IDsList]
	
	%adding define statements that are needed
	construct AddedPreprocessor [repeat function_definition_or_declaration]
		DeclThatShouldBeAdded [addPreprocessorJustIfInIDsList first IDsList]
		
			%construct Message [id]
			%_ [message DeclThatShouldBeAdded]
	%ADD TO GLOBAL TABLE from DeclThatShouldBeAdded
	by	
		AddedPreprocessor
		[addCurrentProgrFunct rest IDsList] 
end function

function addPreprocessorJustIfInIDsList Preproc [function_definition_or_declaration]
										IDsList [repeat id]
		replace [repeat function_definition_or_declaration]
			currentList [repeat function_definition_or_declaration]
		deconstruct Preproc
			currentPreprocessor [preprocessor]
		deconstruct * [preprocessor_line] currentPreprocessor
			prepocessorLine [preprocessor_line]
		construct stringDefine [stringlit]
			 _ [quote  prepocessorLine]	
		construct lengthOfDefine [number]
    	_ [# stringDefine] [- 1]	
    	construct prepocWithoutDefineKeyWord [stringlit]
    		stringDefine [: 9 999]
    						%construct Mess3age [id]
		%_ [message IDsList]
		where
			 IDsList [containsAnNeededID stringDefine]
		by
			currentList [. Preproc]
end function

function containsAnNeededID	CurrentID [stringlit]
	match * [id]
		anID [id]
	construct stringID [stringlit]
		_ [quote anID]
	construct spaceStringLit [stringlit]
		" "
	construct withSpaces [stringlit]
		spaceStringLit [+ stringID] [+ spaceStringLit] 
	construct stringWithPharantesis [stringlit]
		"("
	construct withPharantesis [stringlit]
		spaceStringLit [+ stringID] [+stringWithPharantesis]	

	
	
	where
		CurrentID [grep withPharantesis] [grep withSpaces] %[grep "#define"]
	where 
		CurrentID [grep "#define"]
			construct Message [id]
		_ [message CurrentID]
		
end function






function addDeclJustIfInIDsList	Decl [function_definition_or_declaration] 
								IDsList [repeat id]
		replace [repeat function_definition_or_declaration]
			currentList [repeat function_definition_or_declaration]
		construct IDFromDecl [id]
			_ [deconstructDeclaration Decl]
		construct FinalIdFromDeclFct [id]
			IDFromDecl [deconstructFunctionDefinition Decl]
		where
			IDsList [fctNameInIDsList FinalIdFromDeclFct]
		by
			currentList [.Decl]
end function





function deconstructDeclaration currentDecl [function_definition_or_declaration]
	replace [id]
		nullId [id]
	deconstruct  [function_definition_or_declaration] currentDecl
		justDecl [variableDeclaration]  
	construct testinAddDecl [id]
		_ [addVarIfJustDeclaration justDecl]
	
	construct finalIdWithDecl [id]
		testinAddDecl [addVarIfHasDeclarator justDecl]
	
	by
		finalIdWithDecl
end function


function addVarIfHasDeclarator var [variableDeclaration]
	replace [id]
		nullDecl [id]

	deconstruct var
		declSpec [decl_specifiers] initDecl [list init_declarator]  ';
	construct lengthOfInitiDecl [number]
		_ [length initDecl]
	deconstruct * [id] initDecl
		currentId [id]
	where
		lengthOfInitiDecl [> 0]
	by
		currentId
		
end function


function addVarIfJustDeclaration	var [variableDeclaration]
	replace [id]
		_ [id]
		deconstruct   var
		specT [decl_specifiers] declT [list init_declarator] ';
		deconstruct specT
			repeatFromDecl [repeat decl_qualifier_or_type_specifier]
		
		construct testT [repeat decl_qualifier_or_type_specifier]
			_ [removeTypeSpecifiers repeatFromDecl]
		
		construct newVarDeclSpecifiers [decl_specifiers]
			testT
		construct newVar [variableDeclaration]
			newVarDeclSpecifiers ';
		deconstruct * testT
			justID [id]
	where not
		declT [hasDecl]
	by
		justID	
end function	




function removeTypeSpecifiers	v1 [repeat decl_qualifier_or_type_specifier]
	replace [repeat decl_qualifier_or_type_specifier]
		varSpec [repeat decl_qualifier_or_type_specifier]
	deconstruct v1
		first [decl_qualifier_or_type_specifier] rest [repeat decl_qualifier_or_type_specifier] 

	construct finalDeclOrSpec [decl_qualifier_or_type_specifier]
		_ [addJustIfTypeSpec first]

	by
		varSpec [.finalDeclOrSpec]
		[removeTypeSpecifiers rest]
		
end function

function addJustIfTypeSpec	V1 [decl_qualifier_or_type_specifier]
	replace [decl_qualifier_or_type_specifier]
		declOrType [decl_qualifier_or_type_specifier]
	


	deconstruct  V1
		typeSpec [type_specifier]
	where not 
		V1 [hasStructUnion]
	by
		V1
end function

function hasStructUnion
	match * [decl_qualifier_or_type_specifier]
		AS [struct_or_union_specifier]
end function

function hasDecl
	match * [list init_declarator]
		AS [init_declarator]
end function





function deconstructFunctionDefinition currentFctDef [function_definition_or_declaration]
	replace [id]
		_ [id]
	
	deconstruct * [function_definition] currentFctDef
			justFunct [function_definition]
		deconstruct * [function_header] justFunct
			fctHeader [function_header]
		deconstruct * [opt KR_parameter_decls] justFunct
			fctKR [opt KR_parameter_decls]	
				deconstruct * [compound_statement] justFunct
			fctStatement [compound_statement]
		deconstruct * [compound_statement_body] fctStatement
			fctStatementBody [compound_statement_body]
		construct fctStatementWithoutPreprocessor [compound_statement]
			{ fctStatementBody }
		construct functionWithoutPreprocessor [function_definition]
			fctHeader fctKR fctStatementWithoutPreprocessor 
		deconstruct fctHeader
			spec [opt decl_specifiers] decl [declarator] ext[function_declarator_extension] 
		construct stringFromDecl [stringlit]
			_ [quote decl]
		construct IDFromDecl [id]
			_ [unquote stringFromDecl]
	by
		IDFromDecl
end function


function addIdIfNotRepetition	CurrentIDList [repeat id] ListOfAllIDs [repeat id]
	replace [repeat id]
		finalIncludeList [repeat id]
	deconstruct CurrentIDList 
		first [id] rest [repeat id]

	%construct newFinalIncludeList [repeat id]
		%finalIncludeList [addIfUnique first ListOfAllIDs]
	by
		%newFinalIncludeList
		%[addIdIfNotRepetition rest ListOfAllIDs]
		
end function

function addIDIfUnique V1 [id] ListOfAllID [repeat id]
	replace [repeat id]
		listOfIncl [repeat id]
	
	where not
		ListOfAllID [fctNameInIDsList V1]

	by
		listOfIncl [. V1]
end function

function fctNameInIDsList	FctName [id]
	match * [id]
		FctName
end function





















function exportDeclList
	replace [repeat function_definition_or_declaration]
		currentDecl [repeat function_definition_or_declaration]
	construct emptyDecl [function_definition_or_declaration]
	export ListOfDeclFromHeaders [repeat function_definition_or_declaration ]
		emptyDecl
	by
		currentDecl
		
end function



function identifyFunctionsName	V1 [repeat function_definition_or_declaration]
	replace [id]
		nothing [id]
				
	deconstruct * [list init_declarator] V1
		currFct [list init_declarator]
	%construct Message2 [id]
	%	_ [message V1]
	%deconstruct * [function_header] currFct
	%	currFctHeader [function_header]
	%construct MMessage [id]
		%_ [message currFct]
	by nothing
end function







rule constructHeaderFile
	replace [stringlit]
		currentName [stringlit]
		
	construct first_path_separator [number]
    	_ [index currentName '/] [+ 1]

    construct pathFromFirstQuote [stringlit]
    	currentName [: first_path_separator 999]
    where
    	first_path_separator [>1]
	by
		pathFromFirstQuote
end rule


function addIncludeJustIfNotRepetition	CurrentIncludeList [repeat stringlit] ListOfAllIncludes [repeat stringlit]
	replace [repeat stringlit]
		finalIncludeList [repeat stringlit]
	
	deconstruct CurrentIncludeList 
		first [stringlit] rest [repeat stringlit]
	
	
	construct newFinalIncludeList [repeat stringlit]
		finalIncludeList [addIfUnique first ListOfAllIncludes]
	by
		newFinalIncludeList
		[addIncludeJustIfNotRepetition rest ListOfAllIncludes]
		
end function

function addIfUnique V1 [stringlit] ListOfAllIncludes [repeat stringlit]
	replace [repeat stringlit]
		listOfIncl [repeat stringlit]
	where not
		ListOfAllIncludes [containsAlready V1]
	where 
		V1 [checkIfItsHeader]
	by
		listOfIncl [. V1]
end function



function checkIfItsHeader
	match [stringlit]
		currentValue [stringlit]
	construct lengthOfVal [number]
		_ [# currentValue]
	construct positionDot [number]
		lengthOfVal [- 1]
	construct lastChar [stringlit]
		currentValue [: lengthOfVal lengthOfVal]
	construct dot [stringlit]
		currentValue [: positionDot positionDot]
	where 
		lastChar [= "h"]
	where
		dot [= "."]
end function


rule containsAlready V1 [stringlit]
	match [stringlit]
		currentValue [stringlit]
	where 
		currentValue [= V1]
end rule





















rule identifyFunctionById FunctionID [id] 
	replace  [repeat function_definition_or_declaration]
		sourceList [repeat function_definition_or_declaration]
	deconstruct sourceList
		first [function_definition_or_declaration] rest [repeat function_definition_or_declaration]
		%construct Message [id]
		%_ [message first]
	where not
		first [functionDefinitionForID FunctionID]
	by
		rest
		
end rule


function functionDefinitionForID FunctionID [id]
	match * [function_header]
		FctHeader [function_header]
	deconstruct * [declarator] FctHeader
		HeaderOfF [declarator]
	deconstruct * [id] HeaderOfF
		idOfFct [id]
	where 
		FunctionID [=idOfFct]
end function
