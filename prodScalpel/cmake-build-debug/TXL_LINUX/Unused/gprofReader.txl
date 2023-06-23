tokens
	recordBegin "-----------------------------------------------"
	%demarker "/"
	called "[\d]+/[\d]+"
	fctID "\[[\d]+\]"
	addition "[\d]+\+[\d]+"
end tokens

define expression
	[number]
	| [expression] + [number]
	| [expression] / [number]
end define



define program
	[repeat profileEntry]
end define

define profileEntry
	[repeat callersFct] [currentFunction] [repeat calledFct] [recordBegin] [NL]
end define

define callersFct
	%empty
    [number] [number] [called] [id] [fctID] [NL]
    |	[number] [id] [fctID] [NL]
end define

define currentFunction
	%empty
	[fctID] [number] [number] [number] [numberOrAddition] [id] [fctID] [NL]
	
end define

define numberOrAddition
	[number]
	|	[addition]
end define

define calledFct
	%empty
	[number] [number] [called] [id] [fctID] [NL]
	|	[number] [id] [fctID] [NL]
	
end define


%%rules

function main
	match [program]
			P[program]
			
	deconstruct P
		listOfFct [repeat profileEntry]
		
		
	import TXLargs [repeat stringlit]	
	deconstruct * [stringlit] TXLargs
		something [stringlit]
		
	construct idFromFct [id]
		_ [unquote something]
		
	construct listOfId [repeat id]
		_ [. idFromFct]
	
	construct newP[repeat id]
		listOfId [identifyFunctionsNameFromFunctions  listOfId listOfFct] [write "ListOfNeededFunctions.out"] 
	construct mssss [id]
		_ [message newP]
	
end function


function identifyFunctionsNameFromFunctions	 	AllFunctionsList [repeat id]
												P [repeat profileEntry]				

	replace [repeat id]
		currentIdList [repeat id]		
	
	deconstruct AllFunctionsList 
		first [id] rest [repeat id]
		
	construct FctFromCurrent [repeat id]
		_ [addCalledFunctions P first]
		
	construct ListOfNewFunctions [repeat id]
		_ [addFctJustIfUnique currentIdList FctFromCurrent] 
		
	construct newListOfAllFunctions [repeat id]
		rest [. ListOfNewFunctions]

	by 
		currentIdList [. ListOfNewFunctions]
		[identifyFunctionsNameFromFunctions newListOfAllFunctions P]
end function


function addFctJustIfUnique	AllFunctions[repeat id]
							CurrentFunctions [repeat id]
	replace [repeat id]
		current [repeat id]		
	
		
	deconstruct CurrentFunctions 
		first [id] rest [repeat id]
	
	construct newEntry [repeat id]
		_ [addIfNotInList AllFunctions first] 	
	by
		current [.newEntry]
		[addFctJustIfUnique AllFunctions rest] 
end function



function addIfNotInList	AllFct [repeat id]
						CurrentFct [id]
	replace [repeat id]
		_ [repeat id]
	
	where not
		AllFct [ListCheck CurrentFct]
	
	by
		CurrentFct
end function


function ListCheck FunctionName [id]
	match * [id]
		 current [id]
	where 
		current [= FunctionName]
end function





function addCalledFunctions 	P [repeat profileEntry]
								Name [id]		

	replace [repeat id]
		currentList [repeat id]
	deconstruct P
		currentFct [profileEntry] rest [repeat profileEntry]
	construct newCurrentFunction [repeat id]
		_ [addIfSearchedFct currentFct Name]
	
	by
		currentList [. newCurrentFunction]
		[addCalledFunctions rest Name]
end function


function addIfSearchedFct	Entry [profileEntry]
							Name [id]
	replace [repeat id]
		_ [repeat id]
	deconstruct  Entry
		callers [repeat callersFct] myFct [currentFunction] called [repeat calledFct] tt [recordBegin]
	deconstruct * [id] myFct
		currentFunctionName [id]

	where
		currentFunctionName [= Name]
		construct ListOfCalledFunctions [repeat id]
			_ [addFctNamesFromCalledFct called]
	by
		ListOfCalledFunctions
end function


function addFctNamesFromCalledFct	FctList[repeat calledFct]
	replace [repeat id]
		currentList [repeat id]
	deconstruct FctList
		first [calledFct] rest [repeat calledFct]
	deconstruct * [id] first
		currName [id]
	construct stringName [id]
		currName
	by
		currentList [. stringName]
		[addFctNamesFromCalledFct rest] 
		
end function

