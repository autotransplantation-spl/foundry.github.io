include "cOriginal.grm"

redefine upper_macro_name
   [upperlowerid] 
end redefine


%This program will just transplant all the source code of an input program
%at the begining of the output source code file
%and will pretty print the result


function main
	match * [program]
		P [program]
		
	import TXLargs [repeat stringlit]
	
	deconstruct * [stringlit] TXLargs
		outputFile [stringlit]
		
	deconstruct * [repeat function_definition_or_declaration] P
		sourceCodeInput [repeat function_definition_or_declaration]
	
	construct outputP [program]
		_ [read outputFile]
		
	deconstruct * [repeat function_definition_or_declaration] outputP
		sourceCodeOriginalInOutput [repeat function_definition_or_declaration]
		
	construct newSourceCode [repeat function_definition_or_declaration]
		sourceCodeInput [addNewContent sourceCodeOriginalInOutput]
		

		
	construct newCompUnit [compilation_unit]
		newSourceCode
		
	construct newP [program]
		newCompUnit
		
	construct outputNewCode [program]
		newP [write outputFile]
	
end function











%add new content to the original file

function addNewContent	NewContent [repeat function_definition_or_declaration]
	replace [repeat function_definition_or_declaration]
		originalContent [repeat function_definition_or_declaration]
		construct preprocesorStatementOriginal [repeat function_definition_or_declaration]
			_ [extractJustPreprocessor originalContent]
		construct newPreprocesorStatement [repeat function_definition_or_declaration]
			_ [extractJustPreprocessor NewContent]
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
		
	deconstruct not  Element
		notPreprocessor [preprocessor]
	
	by
		_ [. Element]
end function






function extractJustPreprocessor Content [repeat function_definition_or_declaration]
	replace [repeat function_definition_or_declaration]
		current [repeat function_definition_or_declaration]
	deconstruct Content
		first [function_definition_or_declaration] rest [repeat function_definition_or_declaration]
	construct newElement [repeat function_definition_or_declaration]
		_ [addIfPreprocessor first]
	by
		current [. newElement]
		[extractJustPreprocessor rest]
		
end function


function addIfPreprocessor Element [function_definition_or_declaration]
	replace [repeat function_definition_or_declaration]
		current [repeat function_definition_or_declaration]
		
	deconstruct  Element
		notPreprocessor [preprocessor]
	
	by
		_ [. Element]
end function



