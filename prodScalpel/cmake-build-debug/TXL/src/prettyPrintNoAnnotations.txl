include "cOriginal.grm"


function main
	match * [program]
		P [program]
	import TXLargs [repeat stringlit]
	deconstruct * [stringlit] TXLargs
		outputFile [stringlit]
	construct printFormatedProgram [program]
		P [write outputFile]
end function