include "cOriginal.grm"


function main
	match * [program]
		P [program]
	import TXLargs [repeat stringlit]
	deconstruct * [stringlit] TXLargs
		outputFile [stringlit]
	construct preprocDefs [repeat preprocessor]
		_ [^ P]
	construct repeatOfIncludes [repeat preprocessor]
		_ [keepJustIncludes preprocDefs]
	construct printPreproc [repeat preprocessor]
		repeatOfIncludes [write outputFile]
end function


function keepJustIncludes PreprocDefs [repeat preprocessor]
	replace [repeat preprocessor]
		current [repeat preprocessor]
	deconstruct PreprocDefs
		first [preprocessor] rest [repeat preprocessor]
	construct justIncludes [repeat preprocessor]
		_ [addJustIfInclude first]
	by
		current [. justIncludes]
		[keepJustIncludes rest]
end function


function addJustIfInclude Definition [preprocessor]
	replace [repeat preprocessor]
		_ [repeat preprocessor]
	construct defString [stringlit]
		_ [quote Definition]
	where defString[grep "#include"]
	by
		_ [. Definition]
end function
