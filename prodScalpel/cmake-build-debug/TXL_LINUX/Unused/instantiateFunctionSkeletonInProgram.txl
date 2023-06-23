include "ANSIC.grm"


function main
    replace [program]
        P [program]
    import TXLargs [repeat stringlit]
	deconstruct  TXLargs
		 PathToSymbolTable [stringlit]  OutputFile [stringlit]
	export SymbolsArgument [repeat id]
		_ [read PathToSymbolTable]
    construct NewP [program]
        P [insertGraftAsEntireFunction] [write OutputFile]
    by
        NewP
end function 


function insertGraftAsEntireFunction
	replace  [program]
		G [program]

    construct addGraftTest [program]
       	G [addTheGraftAsFunction]
	by
	 addGraftTest
end function



function addTheGraftAsFunction
	replace [program]
		P [program]		
    construct newP [program]
    	P [fixIdentifiersForTransplant]			    
	by 
		newP
end function


function fixIdentifiersForTransplant
    replace [program]
        F [program]
	import SymbolsArgument [repeat id]
    construct NewF [program]
        F   [replaceIdNames SymbolsArgument]
    by
        NewF
end function 


function replaceIdNames listOfID [repeat id]
	replace [program]
		F [program]
	deconstruct listOfID
		first [id] second [id] rest [repeat id]		
	construct newF [program]
		F [replaceID first second] 
	by
		newF
		[replaceIdNames rest]
end function


rule replaceID 	currentIDStr [id] 
				futureIDStr [id]
	replace $ [id] 
		Id [id]
	where	
		Id [= currentIDStr] 
	by
		futureIDStr
end rule