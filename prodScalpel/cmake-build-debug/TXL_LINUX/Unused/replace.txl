include "c.grm"

function main
    replace [program]
        P [program]
	import TXLargs [repeat stringlit]
	construct separeSign [stringlit]
		 "+"
	deconstruct * TXLargs
		 separeSign idList [repeat stringlit]
	construct LengthSymbolTable [number]
		_ [length idList] [+ 1]	
	construct varList [repeat stringlit]
		 TXLargs [head LengthSymbolTable]
	         construct Message [id]
        _ [message varList]
    construct OldProg [program]
    	P
    construct NewP [program]
        P [changeConflictingIDs idList]  [replaceIdNames varList]
    by
        NewP
end function 

rule changeConflictingIDs hostSymbolTable [repeat stringlit]
	replace [id]
		Id [id]
	construct newID [stringlit]
		_ [+ '_] [ + Id] 
	construct oldId [stringlit]
		_ [quote Id]	
	deconstruct * [stringlit] hostSymbolTable
		oldId
	by
		_ [unquote newID]
end rule




function replaceIdNames listOfID [repeat stringlit]
	replace [program]
		P [program]
	deconstruct listOfID
		first [stringlit] second [stringlit] rest [repeat stringlit]
	
	construct newP [program]
		P [replaceID first second]
	
	by
		newP
		[replaceIdNames rest]
end function



rule replaceID 	currentIDStr [stringlit] 
				futureIDStr [stringlit]
	replace [id] 
		Id [id]
	where	
		Id [= currentIDStr] 
	by
		_ [unquote futureIDStr]
end rule
