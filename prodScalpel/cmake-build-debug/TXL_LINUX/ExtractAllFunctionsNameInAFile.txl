include "cOriginal.grm"

redefine upper_macro_name
   [upperlowerid] 
end redefine

function main
	match * [program]
		P [program]
		
		
	import TXLargs [repeat stringlit]
	deconstruct * [stringlit] TXLargs
		outputFile [stringlit]
	
	
	export ListOfMarkers [list id]
		_
	
	construct listOfAllFunctionsMarkers [program]
		P [extractAllPresentFunctionsMarkers]
		
	import ListOfMarkers
	
	construct mdsdsa [list id]
		ListOfMarkers [write outputFile]
	
end function


rule extractAllPresentFunctionsMarkers 
	replace $ [function_definition]
		currentFunction [function_definition]
		
	deconstruct * [base_declarator] currentFunction
		currentFctName [base_declarator]
	
	construct currentFunctionNameString [stringlit]
		_ [quote currentFctName]
		
	construct currentFunctionNameMarker [stringlit]
		_ [+ "/* "] [+ currentFunctionNameString] [+ " */"]
		
	construct currentAsID [id]
		_ [unquote currentFunctionNameMarker]
		
	import ListOfMarkers [list id]
	
	export ListOfMarkers
		ListOfMarkers [, currentAsID]
	
	by
		currentFunction
		
end rule