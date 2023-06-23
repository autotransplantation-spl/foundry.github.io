include "c.grm"

tokens
	endMarker ">>>>>>>>>"
end tokens


define declaration_or_statement_markers
	[declaration_or_statement] 
	| [stringlit] [NL]
end define

define ids_with_line_break
	[id] [NL]
end define



function main
	match [program]
			P[program]
	
	import TXLargs [repeat stringlit]
	
	export LineNumber [number]
		1
	
	deconstruct * [repeat function_definition_or_declaration] P
		ProgDecl [repeat function_definition_or_declaration]
		
	construct newP[program]
		ProgDecl [ObtainNeededFunctions TXLargs] 
		
		
	import NeededFunction [function_definition_or_declaration]
	
	
		
	construct LOCsFromFct [function_definition_or_declaration]
		NeededFunction [rewriteAsLocs NeededFunction]
	
end function



function rewriteAsLocs FctDef [function_definition_or_declaration]
	replace [function_definition_or_declaration]
		current [function_definition_or_declaration]
	
	deconstruct * [compound_statement_body] FctDef
		currentFctBody [compound_statement_body]
	
	deconstruct * [repeat declaration_or_statement] currentFctBody
		FctDecl [repeat declaration_or_statement]
		
		
	construct FctDeclMarkers [repeat declaration_or_statement_markers]	
		_ [ToDeclStmMarkers FctDecl] 
		
		
		
	%deconstruct * [declaration_or_statement_markers] currentFctBody
		%testingJ [declaration_or_statement_markers]
		
		
		
		
		
	construct DeclAsStrings [repeat declaration_or_statement_markers]
		_ [declToStringlit FctDeclMarkers] 
		
		
		
	construct DeclAsIds [repeat ids_with_line_break]
		_ [stringlitToId DeclAsStrings]	 [write "BLANAAAAAA.out"]
		
	construct message [id]
		_ [message DeclAsIds]	
	
		
	by
		current
		
end function


function stringlitToId 	ListOfStrings [repeat declaration_or_statement_markers]
	replace [repeat ids_with_line_break]
		current [repeat ids_with_line_break]
	deconstruct ListOfStrings 
		first [declaration_or_statement_markers] rest [repeat declaration_or_statement_markers]
	
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



function replaceIfItIsString	Current [declaration_or_statement_markers]
	replace [stringlit]
		_ [stringlit]
	deconstruct * [stringlit] Current
		currentString [stringlit]
	by
		currentString
		
end function


function ToDeclStmMarkers	Initial [repeat declaration_or_statement]
	replace [repeat declaration_or_statement_markers]
		current [repeat declaration_or_statement_markers]
	deconstruct Initial
		first [declaration_or_statement] rest [repeat declaration_or_statement]
	construct CurrDecl [declaration_or_statement_markers]
		first
		
	by
		current [. CurrDecl]
		[ToDeclStmMarkers rest]
end function





function declToStringlit Decl [repeat declaration_or_statement_markers]
	replace [repeat declaration_or_statement_markers]
		current [repeat declaration_or_statement_markers]
	deconstruct Decl 
		first [declaration_or_statement_markers] rest [repeat declaration_or_statement_markers]
	%construct stringFromDecl [stringlit]
		%_ [quote first]
	
	
	
	
	
	construct firstWithLine [declaration_or_statement_markers]
		first [addNumberAtStatements]
	
	construct finalString [declaration_or_statement_markers]
		firstWithLine [solveCompundStatement first]

	construct finalRest [repeat declaration_or_statement_markers]
		rest [AddFromCompund first]
		
	by
		current [. finalString]
		[declToStringlit finalRest]
end function



function addNumberAtStatements
	replace [declaration_or_statement_markers]
		current [declaration_or_statement_markers]
	
	deconstruct * [statement] current
		currentStatement [statement]
	
	
	import LineNumber [number]
	
	construct LineString [stringlit]
		_ [quote LineNumber] [+ " "]
		
		
	construct currentStatementString [stringlit]
		LineString [quote currentStatement]
	construct currentStmLine [declaration_or_statement_markers]
		currentStatementString
	export LineNumber
		LineNumber [+ 1]
	
	by
		currentStmLine
end function


function AddFromCompund CurrentStatement [declaration_or_statement_markers]
	replace [repeat declaration_or_statement_markers]
		currentList [repeat declaration_or_statement_markers]
	
	deconstruct * [compound_statement_body] CurrentStatement
		currentCompund [compound_statement_body]	
	
	
	
	
	deconstruct * [structured_statement] CurrentStatement
		currentCompund2 [structured_statement]
	construct compundNoBody [declaration_or_statement_markers]
		currentCompund2 [removeBodyFromCompund]
	construct compundString [stringlit]
		_ [quote compundNoBody] 
	construct lengthOfHeader [number]
		_ [# compundString] [- 2]
	construct removedEndOfBlock [stringlit]
		compundString [: 1 lengthOfHeader]
	
	
	
	
	
	
	deconstruct * [repeat declaration_or_statement] currentCompund
		declsFromCompund [repeat declaration_or_statement]
		
		
	construct declsMarkersFromCompund [repeat declaration_or_statement_markers]	
		_ [ToDeclStmMarkers declsFromCompund] 	
		

	construct finalMarker [stringlit]
		"} "
		
	construct finalEndOfCompund [stringlit]
		finalMarker [+ "//"] [+ removedEndOfBlock] 
	
	construct addFinalMarker [declaration_or_statement_markers]
		finalEndOfCompund
	
	by
		declsMarkersFromCompund [.addFinalMarker] [. currentList]
end function


function solveCompundStatement CurrentStatement [declaration_or_statement_markers]
	replace [declaration_or_statement_markers]
		current [declaration_or_statement_markers]
	deconstruct * [structured_statement] CurrentStatement
		currentCompund [structured_statement]		
	construct compundNoBody [declaration_or_statement_markers]
		currentCompund [removeBodyFromCompund] 
	construct compundString [stringlit]
		_ [quote compundNoBody] 
	construct lengthOfHeader [number]
		_ [# compundString] [- 1]
	construct removedEndOfBlock [stringlit]
		compundString [: 1 lengthOfHeader] 
	import LineNumber [number]
	export LineNumber 
		LineNumber [- 1]	
	by
		removedEndOfBlock
end function



rule removeBodyFromCompund
	replace $ [compound_statement_body]
		_ [compound_statement_body]
	by
		_
		
end rule




rule ObtainNeededFunctions	FctList [repeat stringlit]%P [repeat function_definition_or_declaration]
	replace $ [function_definition]
		current [function_definition]
		
	deconstruct * [declarator] current
		CurrentFctHeader [declarator] 
	
	
	construct FctName [stringlit]
		_ [quote CurrentFctHeader]
	
	where 
		FctList [CheckIfInFctList FctName]
		
	construct messagggg [id]
		_ [message CurrentFctHeader]
	
	export NeededFunction [function_definition_or_declaration]
		current
	
	by
		current
		
end rule


function CheckIfInFctList CurrentFct [stringlit]
	match * [stringlit]
		FctInList [stringlit]
	
	where 
		FctInList [= CurrentFct]
end function

