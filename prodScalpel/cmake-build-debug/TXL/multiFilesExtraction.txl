include "cOriginal.grm"

redefine upper_macro_name
   [upperlowerid] 
end redefine

define id_with_new_line
	[id] [NL]
end define



define gcov_output
	[repeat name_source]
end define

define name_source
	[stringlit] [stringlit]
end define


function main
	match [program]
			P[program]
	import TXLargs [repeat stringlit]
	
		construct nkdsajs [id]
		_ [message "SUGI PULA!"]		

	deconstruct TXLargs
		ProgramPath [stringlit] HeaderOutput [stringlit] SourceCodeOutput [stringlit] gcovOutputFile [stringlit] SourceContentFile [stringlit] 
		HeaderContentFile [stringlit] ListOfNeededHeaderFiles [stringlit] IfDefProgPath [stringlit]

	export SourceCodeOutput
	export HeaderOutput	
	export gcovOutputFile
	export SourceContentFile
	export HeaderContentFile
	export ListOfNeededHeaderFiles 
	
	construct PNoIfDefs [program]
		_ [removeIFDefs ProgramPath IfDefProgPath]
	
	
	construct gcovOutputFunctions [gcov_output]
		_ [read gcovOutputFile]
	
	
	where
	PNoIfDefs [addHeaderAndSourceCodes gcovOutputFunctions]
end function




function removeIFDefs	ProgramPath [stringlit]
						fixIfDefProg [stringlit]
	
	replace [program]
		P [program]
		
	
	construct nonIfDefsOutput [stringlit]
		ProgramPath [+ "NON"]					
	construct commandForNonIf [stringlit]
		_ [+ fixIfDefProg] [+ " "] [+ ProgramPath] [+ " "] [+ ProgramPath]  [+ " "]  [+ nonIfDefsOutput]
	construct CallCommand2 [id]
    	_ [system commandForNonIf]
	construct outputFileCompleteName [stringlit]
		_ [+ nonIfDefsOutput]
	construct ProgramSource [program]
		_ [read outputFileCompleteName]
		
	by
		ProgramSource
end function





function addHeaderAndSourceCodes	SourceFileGraft [gcov_output]
	match * [repeat function_definition_or_declaration] 
		declFromP [repeat function_definition_or_declaration]
	%exporting global variables
	construct ExportGlobalVariables [repeat function_definition_or_declaration]
		declFromP [exportDeclList]
		
		
	export FinalListOfIncludeHeadersFromSourceFiles [repeat function_definition_or_declaration]
		first
	export FinalListOfIncludeLibrarysFromSourceFiles [repeat function_definition_or_declaration]
		first
	import SourceContentFile [stringlit]
	import HeaderContentFile [stringlit]
	%constructing the list of all source files from the project

	construct ListOfExistingSourceFiles [repeat stringlit]
		_ [read SourceContentFile] 

	%constructing the list of all header files from the project
	construct ListOfExistingHeaderFiles [repeat stringlit]
		_ [read HeaderContentFile] 
		
	export ListOfAllExistingHeaderFiles [repeat stringlit]
		ListOfExistingHeaderFiles

	%PROBLEMA!!!!!
	%construct FinallyTheListOfAllNeededIncludes [repeat id]
	%	_ [read SourceFileGraft] 
	construct cleanUp [id]
		_ [cleanUpGlobals]
		
		
	%list of all function headers, for the header file!!!
	export ListOfFunctionsHeaderDefinition [repeat id_with_new_line]	
		_
	
		
	deconstruct * [repeat name_source] SourceFileGraft
		NameSource [repeat name_source]
		
	construct justInternalNameSource [repeat name_source]
		_ [removeNonInternalFunctions NameSource]
		
		
	construct mdksadas [repeat name_source]
		justInternalNameSource
		
	construct AllFunctionsDefs [repeat function_definition_or_declaration]
		_ [addIDFromFilesNewGCOV justInternalNameSource] 
		
		
	import ListOfFunctionsHeaderDefinition
	
	
	import FinalListOfIncludeHeadersFromSourceFiles
	import FinalListOfIncludeLibrarysFromSourceFiles 
	
	deconstruct FinalListOfIncludeHeadersFromSourceFiles 
		first [function_definition_or_declaration] IncludeHeaders [repeat function_definition_or_declaration]
	deconstruct FinalListOfIncludeLibrarysFromSourceFiles 
		first1 [function_definition_or_declaration] IncludeLibrarys [repeat function_definition_or_declaration]
	
		construct forTransplantHeader [repeat function_definition_or_declaration]
		_ [constructFirstForTransplandIncludeFile IncludeHeaders] 
	construct forReadFile [repeat function_definition_or_declaration]
		_ [constructFirstForReadFile IncludeHeaders]
	
			construct forTransplantSource [repeat function_definition_or_declaration]
		_ [constructFirstForTransplandIncludeFile IncludeLibrarys] 
	

	import HeaderOutput [stringlit] 
	import SourceCodeOutput [stringlit]

	construct transplantHeaderSourceFile [stringlit]
		HeaderOutput
	construct transplantSourceSourceFile [stringlit]	
		SourceCodeOutput

	construct writeIncludeHeaders [repeat function_definition_or_declaration]
		forTransplantHeader %[write transplantHeaderSourceFile]
		
	%NOT used any more
	%(	
	construct IncludeMarkForHeaderName [stringlit]
		"#include"
	construct TransplantHeaderFile [stringlit]
		IncludeMarkForHeaderName [+ " \""] [+ JustHeaderFileName] [+ "\""] %"#include \"TransplantHeader.h\""
	construct preprocLineTransplantHeader [preprocessor_line]
		_ [unquote TransplantHeaderFile]
	construct preprocTransplantHeader [preprocessor]
		preprocLineTransplantHeader
	construct TransplantHeaderDeclaration [repeat function_definition_or_declaration]
		preprocTransplantHeader
	)%
		
	%all functions definition, to be added in transplant source file!!!
	construct allFunctionDefinitionsAndLybrarys [repeat function_definition_or_declaration]
		_  [. AllFunctionsDefs]
		%_ [.forTransplantSource] [. AllFunctionsDefs] %[write transplantSourceSourceFile]
	
	construct programInTransplantSourceFile [program]
		_ [read transplantSourceSourceFile]
	
	
	deconstruct * [repeat function_definition_or_declaration] programInTransplantSourceFile
		originalSourceContent [repeat function_definition_or_declaration]
	
	construct programWithNewFunctionsAdded [repeat function_definition_or_declaration]
		originalSourceContent [addNewContent allFunctionDefinitionsAndLybrarys]
	
	construct writeTheNewProgramToFile [repeat function_definition_or_declaration]
		programWithNewFunctionsAdded [write transplantSourceSourceFile]
		
		
	%same as above for header declarations for functions
	construct programInHeaderFile [program]
		_ [read transplantHeaderSourceFile]
		
	deconstruct * [repeat function_definition_or_declaration] programInHeaderFile
		originalHeaderContent [repeat function_definition_or_declaration]
	
	construct headerWithNewDefinitionsAdded [repeat id_with_new_line]
		_ [addNewHeaderContent originalHeaderContent ListOfFunctionsHeaderDefinition]
		
	construct writeHeaderFile [repeat id_with_new_line]
		headerWithNewDefinitionsAdded [write transplantHeaderSourceFile]
		
		

	%add additional header files that may be needed from current header files
	%initial Path that is input/	
	construct nullPath [stringlit]
		""
	%initial list of header files that was already written in header transplant
	%separate case for the input file, since its content must not be transplanted by this program
	construct includeList[repeat stringlit]
		_ [identifyIncludeFiles forReadFile nullPath]
	

	%function that calls readFromFiles!!!
	import ListOfNeededHeaderFiles [stringlit]
	construct FinalListOfHeaderIncludes [repeat stringlit]
		includeList [readFromFiles includeList] [write ListOfNeededHeaderFiles] 
end function


function removeNonInternalFunctions	Original [repeat name_source]
	replace [repeat name_source]
		newList [repeat name_source]
	
	deconstruct Original
		first [name_source] rest [repeat name_source]
		
	construct justInternalFunctions [repeat name_source]
		_ [addIfNotExternal first]
	
	by
		newList [. justInternalFunctions]
		[removeNonInternalFunctions rest]
end function

function addIfNotExternal	FunctionName [name_source]
	replace [repeat name_source]
		_ [repeat name_source]
	
	deconstruct FunctionName
		name [stringlit] sourceFile [stringlit]
	
	where not
		sourceFile [= "NOT_INTERNAL"]
	
	by
		_ [. FunctionName]	
end function










function addIDFromFilesNewGCOV	NameSource [repeat name_source]
	replace [repeat function_definition_or_declaration]
		currList [repeat function_definition_or_declaration]

	deconstruct NameSource 
		first [name_source] rest [repeat name_source]
		
	deconstruct first
		firstFunctionName [stringlit] firstSource[stringlit]
		
	construct nonIfDefsOutput [stringlit]
		firstSource [+ "NON"]
	
	construct commandForNonIf [stringlit]
		_ [+"./ifdef.x "] [+ firstSource] [+ " "] [+ firstSource]  [+ " "] [+ nonIfDefsOutput]
	construct CallCommand2 [id]
    	_ [system commandForNonIf]
	
	construct outputFileCompleteName [stringlit]
		_ [+ nonIfDefsOutput]
	construct currentProgram [repeat function_definition_or_declaration]
		_[read outputFileCompleteName]	
		
	construct justLastFctDecl [repeat function_definition_or_declaration]
		_ [addCurrentProgrFunctNewGCOV currentProgram firstFunctionName firstSource] 		
		
	construct newFunctionDefsList [repeat function_definition_or_declaration]
		currList [. justLastFctDecl]
		
		
		
		
		
		
		
	deconstruct currentProgram
		fctDeclFromP [repeat function_definition_or_declaration]
	import FinalListOfIncludeHeadersFromSourceFiles [repeat function_definition_or_declaration]	
	import FinalListOfIncludeLibrarysFromSourceFiles [repeat function_definition_or_declaration]	
	construct IncludeFilesSigns [repeat stringlit]
		"\"" "\""
	construct LibraryFilesSigns [repeat stringlit]
		"<" ">"
	construct addNewIncludeFiles [repeat function_definition_or_declaration]
		FinalListOfIncludeHeadersFromSourceFiles [includeHeaderFilesIfItsCase currentProgram justLastFctDecl IncludeFilesSigns  "OriginalHeaders/"]  
	construct addNewLibrarys [repeat function_definition_or_declaration]
		FinalListOfIncludeLibrarysFromSourceFiles [includeHeaderFilesIfItsCase currentProgram justLastFctDecl LibraryFilesSigns ""]
	export FinalListOfIncludeHeadersFromSourceFiles
		addNewIncludeFiles
	export FinalListOfIncludeLibrarysFromSourceFiles
		addNewLibrarys
	by
		newFunctionDefsList
		[addIDFromFilesNewGCOV rest]
end function



function addCurrentProgrFunctNewGCOV	P [repeat function_definition_or_declaration]
										FunctionName [stringlit]
										ProgFileName [stringlit]
	replace [repeat function_definition_or_declaration]
		currList [repeat function_definition_or_declaration]
	deconstruct P
		first [function_definition_or_declaration] rest [repeat function_definition_or_declaration]
	construct newDeclList [repeat function_definition_or_declaration]
	%adding declarations or functions
	
	construct functionNameID [id]
		_ [unquote FunctionName]
	construct functionNameRepeatID [repeat id]
		_ [. functionNameID]
	
	construct DeclThatShouldBeAdded [repeat function_definition_or_declaration]
		currList [addDeclJustIfInIDsList first functionNameRepeatID ProgFileName]
	
	%adding define statements that are needed
	%construct AddedPreprocessor [repeat function_definition_or_declaration]
	%	DeclThatShouldBeAdded [addPreprocessorJustIfInIDsList first functionNameRepeatID]
	by	
		DeclThatShouldBeAdded
		[addCurrentProgrFunctNewGCOV rest FunctionName ProgFileName] 
end function






























%add new header content to the original header

function addNewHeaderContent	OriginalHeaderFctDef [repeat function_definition_or_declaration]
								NewHeaderDeclaration [repeat id_with_new_line]
	replace [repeat id_with_new_line]
		_ [repeat id_with_new_line]
		
	construct OriginalHeaderAsId [repeat id_with_new_line]
		_ [fctDefDeclToIdWithNewLine OriginalHeaderFctDef]
		
	construct NewHeaderDeclIfNotInOriginal [repeat id_with_new_line]
		_ [addHeaderDeclIfNotInOriginal OriginalHeaderAsId  NewHeaderDeclaration]
		
	construct finalHeaderContent [repeat id_with_new_line]
		OriginalHeaderAsId [. NewHeaderDeclIfNotInOriginal]
	
	by
		finalHeaderContent
end function


function addHeaderDeclIfNotInOriginal	OriginalHeaderDecl [repeat id_with_new_line]
										NewHeaderDecl [repeat id_with_new_line]
	replace [repeat id_with_new_line]
		current [repeat id_with_new_line]
		
	deconstruct NewHeaderDecl
		first [id_with_new_line] rest [repeat id_with_new_line]
	
	construct justIfUnique [repeat id_with_new_line]
		_ [addIfUniqueElementHeader OriginalHeaderDecl first]
	by
		current [.justIfUnique]
		[addHeaderDeclIfNotInOriginal OriginalHeaderDecl rest]
end function





function addIfUniqueElementHeader	OriginalDefinitions [repeat id_with_new_line]
									NewElement [id_with_new_line]
	replace [repeat id_with_new_line]
			_ [repeat id_with_new_line]
			
	where not
		OriginalDefinitions [checkIfElementIsUniqueHeader NewElement]
	
	by
		_ [. NewElement]
end function


function checkIfElementIsUniqueHeader	NewElement [id_with_new_line]
	match * [id_with_new_line]
		current [id_with_new_line]
		
	where
		current [= NewElement]
end function


















function fctDefDeclToIdWithNewLine	OriginalHeaderContent [repeat function_definition_or_declaration]
	replace [repeat id_with_new_line]
		current [repeat id_with_new_line]
	
	deconstruct OriginalHeaderContent 
		first [function_definition_or_declaration] rest [repeat function_definition_or_declaration]
		
	construct firstStringlit [stringlit]
		_ [quote first]
	
	construct firstID [id]
		_ [unquote firstStringlit]
		
	construct firstIdWithNewLine [id_with_new_line]
		firstID
	by
		current [. firstIdWithNewLine]
		[fctDefDeclToIdWithNewLine rest]
end function


%add new content to the original file

function addNewContent	NewContent [repeat function_definition_or_declaration]
	replace [repeat function_definition_or_declaration]
		originalContent [repeat function_definition_or_declaration]
		
		construct newContentIfUnique [repeat function_definition_or_declaration]
			_ [addIfNotInOriginal originalContent NewContent]
		construct newProgramSourceCode [repeat function_definition_or_declaration]
			_ [. originalContent] [.newContentIfUnique]
			
		
		%(
		construct preprocesorStatementOriginal [repeat preprocessor]
			_ [^ originalContent]
		construct newPreprocesorStatement [repeat preprocessor]
			_ [^ NewContent]
		construct nonPreprocessorStatementOriginal [repeat function_definition_or_declaration]
			_ [extractNonPreprocessorStatement originalContent]
		construct nonPreprocessorStatementNewContent [repeat function_definition_or_declaration]
			_ [extractNonPreprocessorStatement NewContent]
		construct originalPreprocAsFunctDeclDef [repeat function_definition_or_declaration]
			_ [reparse preprocesorStatementOriginal]
		construct newPreprocAsFunctDeclDef [repeat function_definition_or_declaration]
			_ [reparse newPreprocesorStatement]
		construct newPreprocAsFunctDeclDefUnique [repeat function_definition_or_declaration]
			_ [addIfNotInOriginal originalPreprocAsFunctDeclDef newPreprocAsFunctDeclDef]	
		construct nonPreprocessorStatementNewContentUnique [repeat function_definition_or_declaration]
			_ [addIfNotInOriginal nonPreprocessorStatementOriginal nonPreprocessorStatementNewContent]
			
		construct newProgramSourceCode [repeat function_definition_or_declaration]
			_ [. originalPreprocAsFunctDeclDef] [. newPreprocAsFunctDeclDefUnique] 
			[. nonPreprocessorStatementOriginal] [.nonPreprocessorStatementNewContentUnique ]
		)%
	by
		newProgramSourceCode
		
end function


function addIfNotInOriginal	OriginalDefinitions [repeat function_definition_or_declaration]
							NewDefinitions [repeat function_definition_or_declaration]
	replace [repeat function_definition_or_declaration]
		current [repeat function_definition_or_declaration]
	
	deconstruct NewDefinitions
		first [function_definition_or_declaration] rest [repeat function_definition_or_declaration]
	
	

	
	construct justIfUnique [repeat function_definition_or_declaration]
		_ [addIfUniqueElement OriginalDefinitions first]
	by
		current [.justIfUnique]
		[addIfNotInOriginal OriginalDefinitions rest]
end function	


function addIfUniqueElement	OriginalDefinitions [repeat function_definition_or_declaration]
							NewElement [function_definition_or_declaration]
	replace [repeat function_definition_or_declaration]
			_ [repeat function_definition_or_declaration]
			
	where not
		OriginalDefinitions [checkIfElementIsUnique NewElement]
	
	by
		_ [. NewElement]
end function


function checkIfElementIsUnique	NewElement [function_definition_or_declaration]
	match * [function_definition_or_declaration]
		current [function_definition_or_declaration]
	where
		current [= NewElement]
end function




function extractNonPreprocessorStatement Content [repeat function_definition_or_declaration]
	replace [repeat function_definition_or_declaration]
		current [repeat function_definition_or_declaration]
	deconstruct Content
		first [function_definition_or_declaration] rest [repeat function_definition_or_declaration]
	construct newElement [repeat function_definition_or_declaration]
		_ [addIfNotPreprocessor first]
	by
		current [. newElement]
		[extractNonPreprocessorStatement rest]
		
end function


function addIfNotPreprocessor Element [function_definition_or_declaration]
	replace [repeat function_definition_or_declaration]
		current [repeat function_definition_or_declaration]
		
	deconstruct not * [preprocessor] Element
		notPreprocessor [preprocessor]
	
	by
		_ [. Element]
end function








function constructFirstForTransplandIncludeFile	List [repeat function_definition_or_declaration]
	replace [repeat function_definition_or_declaration]
		currentDecl [repeat function_definition_or_declaration]
	deconstruct List 
		first [function_definition_or_declaration] second [function_definition_or_declaration] rest [repeat function_definition_or_declaration]
	by
		currentDecl [.first]
		[constructFirstForTransplandIncludeFile rest]
end function


function constructFirstForReadFile	List [repeat function_definition_or_declaration]
	replace [repeat function_definition_or_declaration]
		currentDecl [repeat function_definition_or_declaration]
	deconstruct List 
		first [function_definition_or_declaration] second [function_definition_or_declaration] rest [repeat function_definition_or_declaration]
	by
		currentDecl [.second]
		[constructFirstForReadFile rest]
end function


function readFromFiles	currIncludeList [repeat stringlit] 
	replace [repeat stringlit]
		FinalIncludeList [repeat stringlit]	
	construct inputS [stringlit]
		"input/"
	deconstruct currIncludeList
		first [stringlit] rest [repeat stringlit]	
		
		
		
		
	
	construct includeListWithoutRepetitions[repeat stringlit]
    	_ [readJustIfFileExist  first FinalIncludeList]

		
	construct addedNewIncludes [repeat stringlit]
    	rest [. includeListWithoutRepetitions]  
    construct newListOfAllIncludes [repeat stringlit]
    	FinalIncludeList [. includeListWithoutRepetitions]	
			
	by
		newListOfAllIncludes
		[readFromFiles addedNewIncludes]
end function




function readJustIfFileExist	first [stringlit]
								FinalIncludeList [repeat stringlit]
	replace [repeat stringlit]
		_ [repeat stringlit]

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
	construct msss [id]
		_ [message first]
		
		
	import ListOfAllExistingHeaderFiles [repeat stringlit]
	construct msssss [id]
		_ [message ListOfAllExistingHeaderFiles]
	where
		ListOfAllExistingHeaderFiles [matchSourceFile path]
	
	
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
    	_ [addIncludeJustIfNotRepetitionHeaderList  includeList FinalIncludeList]
    
    by 
    	includeListWithoutRepetitions

    
end function


function matchSourceFile 	Name [stringlit]
	match * [stringlit]
		current [stringlit]
	where
		current [= Name]
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

function addIncludeJustIfNotRepetitionHeaderList	CurrentIncludeList [repeat stringlit] ListOfAllIncludes [repeat stringlit]
	replace [repeat stringlit]
		finalIncludeList [repeat stringlit]
	
	deconstruct CurrentIncludeList 
		first [stringlit] rest [repeat stringlit]
	
	
	construct newFinalIncludeList [repeat stringlit]
		finalIncludeList [addIfUniqueHeaderList first ListOfAllIncludes]
	by
		newFinalIncludeList
		[addIncludeJustIfNotRepetitionHeaderList rest ListOfAllIncludes]
		
end function

function addIfUniqueHeaderList V1 [stringlit] ListOfAllIncludes [repeat stringlit]
	replace [repeat stringlit]
		listOfIncl [repeat stringlit]
	where not
		ListOfAllIncludes [containsAlreadyHeaderList V1]
	where 
		V1 [checkIfItsHeader]
	by
		listOfIncl [. V1]
end function

rule containsAlreadyHeaderList V1 [stringlit]
	match [stringlit]
		currentValue [stringlit]
	where 
		currentValue [= V1]
end rule


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






















function cleanUpGlobals
	replace [id]
		nothing [id]
	import FinalListOfIncludeHeadersFromSourceFiles [repeat function_definition_or_declaration]
	export FinalListOfIncludeHeadersFromSourceFiles 
		"first"
	import FinalListOfIncludeLibrarysFromSourceFiles [repeat function_definition_or_declaration]
	export FinalListOfIncludeLibrarysFromSourceFiles 
		"first"
	by
		nothing
end function


%(
function addAllNeededIds SourceFiles [repeat stringlit] ListOfExistingIds [repeat id]
	replace [repeat id]
		current [repeat id]
	construct AllFunctionsDefs [repeat function_definition_or_declaration]
		_ [addIDFromFiles SourceFiles ListOfExistingIds]
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
)%





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
	by
		currId
end rule




























%(
function addIDFromFiles	ListOfSourceFiles [repeat stringlit] ListOfID [repeat id]
	replace [repeat function_definition_or_declaration]
		currList [repeat function_definition_or_declaration]

	deconstruct ListOfSourceFiles 
		first [stringlit] rest [repeat stringlit]
		
	construct nonIfDefsOutput [stringlit]
		first [+ "NON"]
	
	construct commandForNonIf [stringlit]
		_ [+"./ifdef.x "] [+ first] [+ " "] [+ first]  [+ " "] [+ nonIfDefsOutput]
	construct CallCommand2 [id]
    	_ [system commandForNonIf]
	
	construct outputFileCompleteName [stringlit]
		_ [+ nonIfDefsOutput]
	construct currentProgram [repeat function_definition_or_declaration]
		_[read outputFileCompleteName]	
		
	construct justLastFctDecl [repeat function_definition_or_declaration]
		_ [addCurrentProgrFunct currentProgram ListOfID first] 		
		
	construct newFunctionDefsList [repeat function_definition_or_declaration]
		currList [. justLastFctDecl]
	deconstruct currentProgram
		fctDeclFromP [repeat function_definition_or_declaration]
	import FinalListOfIncludeHeadersFromSourceFiles [repeat function_definition_or_declaration]	
	import FinalListOfIncludeLibrarysFromSourceFiles [repeat function_definition_or_declaration]	
	construct IncludeFilesSigns [repeat stringlit]
		"\"" "\""
	construct LibraryFilesSigns [repeat stringlit]
		"<" ">"
	construct addNewIncludeFiles [repeat function_definition_or_declaration]
		FinalListOfIncludeHeadersFromSourceFiles [includeHeaderFilesIfItsCase currentProgram justLastFctDecl IncludeFilesSigns  "OriginalHeaders/"]  
	construct addNewLibrarys [repeat function_definition_or_declaration]
		FinalListOfIncludeLibrarysFromSourceFiles [includeHeaderFilesIfItsCase currentProgram justLastFctDecl LibraryFilesSigns ""]
	export FinalListOfIncludeHeadersFromSourceFiles
		addNewIncludeFiles
	export FinalListOfIncludeLibrarysFromSourceFiles
		addNewLibrarys
	by
		newFunctionDefsList
		[addIDFromFiles rest ListOfID]
end function
)%

function includeHeaderFilesIfItsCase	ProgramDecl [repeat function_definition_or_declaration]
										DeclFromCurrentSource [repeat function_definition_or_declaration]
										TypeOfIncludeSigns [repeat stringlit]
										PathToResource [stringlit]
	replace [repeat function_definition_or_declaration]
		current [repeat function_definition_or_declaration]
	construct IncludedHeadersFromSourceFile [repeat function_definition_or_declaration]
			_ [identifyIncludeFilesFromSource ProgramDecl PathToResource current TypeOfIncludeSigns] 
			
				construct lengthOfDecl [number]
					_ [length DeclFromCurrentSource]
		where
			lengthOfDecl[> 0]
	by
		current [.IncludedHeadersFromSourceFile]
		
end function


function identifyIncludeFilesFromSource	V1 [repeat function_definition_or_declaration]
										CurrentPath [stringlit]
										ListOfIncludeFiles [repeat function_definition_or_declaration]
										TypeOfIncludeSigns [repeat stringlit]
	replace [repeat function_definition_or_declaration]
		includeDecl [repeat function_definition_or_declaration]
	deconstruct V1
		First [function_definition_or_declaration] Rest [repeat function_definition_or_declaration]


	construct includeInstruction [repeat function_definition_or_declaration]
		_ [addIncludeHeader First CurrentPath TypeOfIncludeSigns] 
	construct newIncludeInstructions [repeat function_definition_or_declaration]
		includeDecl [addIfNotNullHeader includeInstruction] 
	construct newListOfUniqueInstr [repeat function_definition_or_declaration]
		_ [addIncludeJustIfNotRepetition newIncludeInstructions ListOfIncludeFiles] 
		
	construct newListOfIncludeFiles [repeat function_definition_or_declaration]
		ListOfIncludeFiles [. newIncludeInstructions]
	by
		includeDecl [. newListOfUniqueInstr]
		[identifyIncludeFilesFromSource Rest CurrentPath newListOfIncludeFiles TypeOfIncludeSigns]
end function


function addIncludeJustIfNotRepetition	CurrentIncludeList [repeat function_definition_or_declaration] ListOfAllIncludes [repeat function_definition_or_declaration]
	replace [repeat function_definition_or_declaration]
		finalIncludeList [repeat function_definition_or_declaration]
	deconstruct CurrentIncludeList 
		first [function_definition_or_declaration] rest [repeat function_definition_or_declaration]
	construct newFinalIncludeList [repeat function_definition_or_declaration]
		finalIncludeList [addIfUnique first ListOfAllIncludes]
	by
		newFinalIncludeList
		[addIncludeJustIfNotRepetition rest ListOfAllIncludes]
		
end function


function addIncludeHeader	V1 [function_definition_or_declaration]
							CurrentPath [stringlit]
							TypeOfIncludeSigns [repeat stringlit]
	replace [repeat function_definition_or_declaration]
		currStatement [repeat function_definition_or_declaration]
		
	deconstruct TypeOfIncludeSigns
		firstSign [stringlit] lastSign [stringlit]
	deconstruct * [preprocessor] V1
		prepocLin [preprocessor]
	deconstruct * [preprocessor_line] prepocLin
		prepocessorLin [preprocessor_line]
	construct stringInclude [stringlit]
		 _ [quote  prepocessorLin]	 
    construct first_quote [number]
    	_ [index stringInclude firstSign] [+ 1]% [print]
    construct lengthOfInclude [number]
    	_ [# stringInclude] [- 1]	
    construct pathFromFirstQuote [stringlit]
    	stringInclude [: first_quote lengthOfInclude]	 %[print]
    construct second_quote [number]
    	_ [index pathFromFirstQuote lastSign] [- 1]
    construct fileToInclude [stringlit]
        pathFromFirstQuote [: 1 second_quote]	
    construct fileWithEntirePath [stringlit]
    	CurrentPath [+ fileToInclude]
    construct includedFirstQuote [number]
    	first_quote [- 1]
    construct positionOfLastQuote [number]
    	_ [# stringInclude] % [print] %[+ first_quote] 
    construct newDeclarationBeginining [stringlit]
    	stringInclude [: 1 includedFirstQuote]
    construct newDeclarationEnd [stringlit]
    	stringInclude [: positionOfLastQuote 999]
    construct finalDeclString [stringlit]
    	newDeclarationBeginining [+ fileWithEntirePath] [+ newDeclarationEnd]
	construct newPrepocLine [preprocessor_line]
		_ [unquote finalDeclString] 
	construct newPreprocessor [preprocessor]
		newPrepocLine
	construct newFctDef [function_definition_or_declaration]
		newPreprocessor
	where
		stringInclude [grep 'include]
	where
		first_quote [> 2]

	by
		newFctDef V1
end function


function addIfNotNullHeader	V1 [repeat function_definition_or_declaration]
	replace [repeat function_definition_or_declaration]
		currentList [repeat function_definition_or_declaration]
	construct currentLength [number]
    	_ [length V1] 
	where
		currentLength [> 0]
	by
		currentList [. V1]
end function






function addCurrentProgrFunct	P [repeat function_definition_or_declaration]
								IDsList [repeat id]
								ProgFileName [stringlit]
	replace [repeat function_definition_or_declaration]
		currList [repeat function_definition_or_declaration]
	deconstruct P
		first [function_definition_or_declaration] rest [repeat function_definition_or_declaration]
	construct newDeclList [repeat function_definition_or_declaration]
	%adding declarations or functions
	construct DeclThatShouldBeAdded [repeat function_definition_or_declaration]
		currList [addDeclJustIfInIDsList first IDsList ProgFileName]
	%adding define statements that are needed
	construct AddedPreprocessor [repeat function_definition_or_declaration]
		DeclThatShouldBeAdded [addPreprocessorJustIfInIDsList first IDsList]
	by	
		AddedPreprocessor
		[addCurrentProgrFunct rest IDsList ProgFileName] 
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
end function


function addDeclJustIfInIDsList	Decl [function_definition_or_declaration] 
								IDsList [repeat id]
								ProgName [stringlit]
		replace [repeat function_definition_or_declaration]
			currentList [repeat function_definition_or_declaration]
		construct IDFromDecl [id]
			_ [deconstructDeclaration Decl]
			
		deconstruct * [function_header] Decl
			hasFunctionHeader [function_header]
			
		
		construct FinalIdFromDeclFct [id]
			IDFromDecl [deconstructFunctionDefinition Decl]
			
		where
			IDsList [fctNameInIDsList FinalIdFromDeclFct]
			
			deconstruct not  Decl
				notPreproc [preprocessor]
			
			construct exportHeaderDeclaration [function_definition_or_declaration]
				Decl [exportHeaderIfCase]
		
		by
			currentList [.Decl]
end function








function exportHeaderIfCase	
	match [function_definition_or_declaration]
		current [function_definition_or_declaration]
				
	deconstruct * [function_header] current
		currentFctHeader [function_header]
	
	construct fctHeaderStringlit [stringlit]
		_ [quote currentFctHeader]
	
	construct fctDeclarationStringlit [stringlit]
		fctHeaderStringlit [+ ";"]
		
	construct fctHeaderID [id]
		_ [unquote fctDeclarationStringlit]
			
	
	construct fctHeaderIdNewLine [id_with_new_line]
		fctHeaderID
	
	import ListOfFunctionsHeaderDefinition [repeat id_with_new_line]
	export ListOfFunctionsHeaderDefinition 
		ListOfFunctionsHeaderDefinition [. fctHeaderIdNewLine]
		
end function


function deconstructDeclaration currentDecl [function_definition_or_declaration]
	replace [id]
		nullId [id]
	deconstruct  [function_definition_or_declaration] currentDecl
		justDecl [declaration]  
	construct testinAddDecl [id]
		_ [addVarIfJustDeclaration justDecl]
	
	construct finalIdWithDecl [id]
		testinAddDecl [addVarIfHasDeclarator justDecl]
	by
		finalIdWithDecl
end function


function addVarIfHasDeclarator var [declaration]
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


function addVarIfJustDeclaration	var [declaration]
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
		construct newVar [declaration]
			newVarDeclSpecifiers ';
		deconstruct * testT
			justID [id]
	where not
		declT [hasDecl]
	by
		justID	
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
	deconstruct  V1
		typeSpec [type_specifier]
	by
		declOrType [. V1]
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
		
		
		deconstruct *  [base_declarator] decl
			FinalIdFromDeclFct [base_declarator]
			
		construct stringFromDecl [stringlit]
			_ [quote FinalIdFromDeclFct] 
		construct IDFromDecl [id]
			_ [unquote stringFromDecl] 
	by
		IDFromDecl
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
	export ListOfDeclFromHeaders [repeat function_definition_or_declaration ]
		_
	by
		currentDecl
end function


function identifyFunctionsName	V1 [repeat function_definition_or_declaration]
	replace [id]
		nothing [id]
				
	deconstruct * [list init_declarator] V1
		currFct [list init_declarator]
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


function addIfUnique V1 [function_definition_or_declaration] ListOfAllIncludes [repeat function_definition_or_declaration]
	replace [repeat function_definition_or_declaration]
		listOfIncl [repeat function_definition_or_declaration]
	where not
		ListOfAllIncludes [containsAlready V1]
	by
		listOfIncl [. V1]
end function


rule containsAlready V1 [function_definition_or_declaration]
	match [function_definition_or_declaration]
		currentValue [function_definition_or_declaration]
	construct currentValueString [stringlit]
		_ [quote currentValue]
	construct V1String [stringlit]
		_ [quote V1]
	where 
		currentValueString [= V1String]
end rule


rule identifyFunctionById FunctionID [id] 
	replace  [repeat function_definition_or_declaration]
		sourceList [repeat function_definition_or_declaration]
	deconstruct sourceList
		first [function_definition_or_declaration] rest [repeat function_definition_or_declaration]
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