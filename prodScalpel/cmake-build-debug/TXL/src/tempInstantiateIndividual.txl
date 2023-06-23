include "cOriginal.grm"


function main
	match * [program]
		P [program]
	import TXLargs [repeat stringlit]
	deconstruct TXLargs
		mappingFile [stringlit] outputFile [stringlit]
		
	construct mappingList [repeat stringlit]
		_ [read mappingFile]
	
	construct newP [program]
		_ [instantiateIndividual P mappingList]
		
		
	construct printFormatedProgram [program]
		newP [write outputFile]
end function


function instantiateIndividual	P [program]
								MappingList [repeat stringlit]
	replace [program]
		_ [program]
		
	deconstruct MappingList 
		abstractVar [stringlit] instantiationVar [stringlit] rest [repeat stringlit]
		
	construct newP [program]
		P [replaceAllAbstractOccurences abstractVar instantiationVar]
	
	by
		newP
		[instantiateIndividual newP rest]
end function


rule replaceAllAbstractOccurences	abstractVar [stringlit]
									instantiationVar [stringlit]
	replace $ [id]
		current [id]
		
	construct abstractVarAsID [id]
		_ [unquote abstractVar]
		
	construct instantiationVarID [id]
		_ [unquote instantiationVar]
		
	where 
		current [= abstractVar]
		
	by
		instantiationVarID
end rule
