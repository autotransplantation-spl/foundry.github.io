include "cOriginal.grm"

redefine upper_macro_name
   [upperlowerid] 
end redefine

redefine program
	...
	|	[repeat stringlit]
end redefine


function main
	match * [program]
		P [program]
		
		
	%import TXLinput [stringlit]
	
	import TXLargs [repeat stringlit]
	
	deconstruct TXLargs
		MarkedFunctionsForTransplant [stringlit] OutputDesiredFunctions [stringlit] TargetFunctionName [stringlit]
		TargetFunctionNameOutputFile [stringlit]
		
	export TargetFunctionID [id]
		_ [unquote TargetFunctionName]
		
	%construct ListOfMarkedFunctionForTransplant [repeat id]
	%	_ [read MarkedFunctionsForTransplant]
	
	export ListOfMarkedFunctionForTransplant [repeat id]
		_ [read MarkedFunctionsForTransplant]
	
	deconstruct * [repeat stringlit] P
		ListOfSourceFiles [repeat stringlit]
		
	export AllDefinedFunctionsIDs [repeat id]
		_
		
	construct solveAllProbles [repeat id]
		_ [solveForAllPrograms ListOfSourceFiles]
		
	import AllDefinedFunctionsIDs
	%construct dsjia [id]
	%	_ [message AllDefinedFunctionsIDs]
		
	
	
	%construct markAllFunctionsNames [repeat id]
		%_ [replaceFunctionsNamesWithMarker ListOfSourceFiles AllDefinedFunctionsIDs]
	
	
	
	import ListOfMarkedFunctionForTransplant 
	
	
	
	
	construct outputNewListOfDesiredFunctionsIDs [repeat id]
		ListOfMarkedFunctionForTransplant [write OutputDesiredFunctions]
		
	import TargetFunctionID
	
	construct writeTargetFunctionID [id]
		TargetFunctionID [write TargetFunctionNameOutputFile]
	

end function

function replaceFunctionsNamesWithMarker	ListOfSourceFiles [repeat stringlit]
											ListOfExistingFunctions [repeat id]
	replace [repeat id]
		_ [repeat id]
		
	deconstruct ListOfSourceFiles
		first [stringlit] rest [repeat stringlit]	
	construct P [program]
		_ [read first]	
	construct newP [program]
		_ [addNewFunctionNames P ListOfExistingFunctions]
	construct outputNewP [program]
		newP [write first]		
	
	
	by
		_ 
		[replaceFunctionsNamesWithMarker rest ListOfExistingFunctions]
end function


function addNewFunctionNames	P [program]
								ListOfExistingFunctions [repeat id]
	replace [program]
		_ [program]	
	construct newP [program]
		P [replaceAllIdsInProgWithTransplantMarker P ListOfExistingFunctions]
	by
		newP
end function

function replaceAllIdsInProgWithTransplantMarker	P[program]
													StaticIDsList [repeat id]
	replace [program]
		_ [program]							
	deconstruct StaticIDsList 
		first [id] rest [repeat id]
	construct transplantMarkerStringlit [stringlit]
		"TRANSPLANTED_FUNCTION_"
	construct firstAsStringlit [stringlit]
		_[quote first]
	construct firstWithMarker [stringlit]
		transplantMarkerStringlit [+ firstAsStringlit]
	construct transplantMarkerAsID [id]
		_ [unquote firstWithMarker]
		
		
	construct exportNewCoreFctName [repeat id]
		_ [changeCoreFunctionNameIfCase first transplantMarkerAsID]	
		
		
	import ListOfMarkedFunctionForTransplant [repeat id]
	
	construct replaceChanghedFctName [repeat id]
		ListOfMarkedFunctionForTransplant [changeFunctionName first transplantMarkerAsID]
	
	export ListOfMarkedFunctionForTransplant [repeat id]	
		replaceChanghedFctName
		
	construct newP [program]
		P [replaceAllIds first transplantMarkerAsID]
	by 
		newP
		[replaceAllIdsInProgWithTransplantMarker newP rest]
end function

rule changeFunctionName	OldName [id]
						NewName [id]
	replace $ [id]
		current [id]
	where 
		current [= OldName]
	by
		NewName
end rule




function keepAllDefinedFunctionsName	AllHeaders [repeat function_header]
	replace [repeat id]
		current [repeat id]
	deconstruct AllHeaders
		first [function_header] rest [repeat function_header]
	deconstruct first 
	    declSpec [opt decl_specifiers] fctDecl [declarator] fctExt[function_declarator_extension] 
	deconstruct * [base_declarator] fctDecl
		fctBaseDecl [base_declarator]
	deconstruct * [id] fctBaseDecl
		fctNameID [id]
	by
		current [. fctNameID]
		[keepAllDefinedFunctionsName rest]
end function









function solveForAllPrograms	ListOfSourceFiles [repeat stringlit]
	replace [repeat id]
		current [repeat id]
	deconstruct ListOfSourceFiles
		first [stringlit] rest [repeat stringlit]	
	construct P [program]
		_ [read first]	
	construct newP [program]
		_ [solveStaticFunctions P]
	construct outputNewP [program]
		newP [write first]		
	by
		current
		[solveForAllPrograms rest]
end function







function solveStaticFunctions	P [program]
	replace [program]
		_ [program]
	
	construct allFunctionsHeaderFromProgram [repeat function_header]
		_ [^ P]
		
		
	construct allFunctionsID [repeat id]
		_ [keepAllDefinedFunctionsName allFunctionsHeaderFromProgram]	
	import AllDefinedFunctionsIDs [repeat id]
	export AllDefinedFunctionsIDs 
		AllDefinedFunctionsIDs [. allFunctionsID]
	
		
	construct justStaticFunctionsIDs [repeat id]
		_ [keepJustStaticHeadersIDs allFunctionsHeaderFromProgram]
		
	
	construct newP [program]
		P [replaceAllIdsInProg P justStaticFunctionsIDs]
	
	
	construct newPRemovedStatic [program]
		newP [replaceFctHeaderIfStatic]
	
	%and now just remove the static header!
	
	
	by
		newPRemovedStatic
end function





rule replaceFctHeaderIfStatic 
	replace $ [function_header]
		current [function_header]
	where
		current [matchStaticHeader]
		
		deconstruct current 
	    	declSpec [decl_specifiers] fctDecl [declarator] fctExt[function_declarator_extension] 
	    deconstruct * [repeat decl_qualifier_or_type_specifier] declSpec
	    	repeatOfDeclSpec [repeat decl_qualifier_or_type_specifier]
	    construct newRepeatOfDeclSpec [repeat decl_qualifier_or_type_specifier]
	    	_ [removeStaticSPec repeatOfDeclSpec]
	
		construct newDeclSpec [decl_specifiers]
			newRepeatOfDeclSpec
		
		construct newHeader [function_header]
			newDeclSpec fctDecl fctExt
	
	
	by
		newHeader
end rule


function matchStaticHeader	
	match [function_header]
		FctHeader [function_header]	
	deconstruct * [decl_specifiers] FctHeader
		declSpec [decl_specifiers]
	where
		declSpec [matchStaticDecl]
end function



%remove qualifiers as const, static, etc
function removeStaticSPec	v1 [repeat decl_qualifier_or_type_specifier]
	replace [repeat decl_qualifier_or_type_specifier]
		varSpec [repeat decl_qualifier_or_type_specifier]
	deconstruct v1
		first [decl_qualifier_or_type_specifier] rest [repeat decl_qualifier_or_type_specifier] 
	construct finalDeclOrSpec [repeat decl_qualifier_or_type_specifier]
		_ [addJustIfNotStatic first]
	by
		varSpec [.finalDeclOrSpec]
		[removeStaticSPec rest]
end function


function addJustIfNotStatic	V1 [decl_qualifier_or_type_specifier]
	replace [repeat decl_qualifier_or_type_specifier]
		declOrType [repeat decl_qualifier_or_type_specifier]
		
	where not	
		V1 [matchStaticDecl]
	by
		declOrType [. V1]
end function


function replaceAllIdsInProg	P[program]
								StaticIDsList [repeat id]
	replace [program]
		_ [program]							
	deconstruct StaticIDsList 
		first [id] rest [repeat id]
	construct UniqueID [id]
		first [!]
		
	construct exportNewCoreFctName [repeat id]
		_ [changeCoreFunctionNameIfCase first UniqueID]
		
	import ListOfMarkedFunctionForTransplant [repeat id]
	construct exportCurrentInIfInDesiredList [repeat id]
		ListOfMarkedFunctionForTransplant [addCurrentIdIfNeeded first UniqueID]
	construct newP [program]
		P [replaceAllIds first UniqueID]
	by 
		newP
		[replaceAllIdsInProg newP rest]
end function

function changeCoreFunctionNameIfCase	OldName [id]
										NewName [id]
	replace [repeat id]
		_ [repeat id]
	
	import TargetFunctionID	[id]
	
	where 
		TargetFunctionID [= OldName]
		export TargetFunctionID
			NewName
	by
		_				
end function

rule addCurrentIdIfNeeded	OriginalName [id]
							NewName [id]
	match  [id]
		current [id]
	
	where
		current [= OriginalName]	
		
		
	import ListOfMarkedFunctionForTransplant [repeat id]
	
	export ListOfMarkedFunctionForTransplant
		ListOfMarkedFunctionForTransplant [. NewName]
end rule




rule replaceAllIds	SearchedID [id]
					UniqueID [id]
	replace $ [id]
		current [id]
	where
		current [= SearchedID]
	
	by
		UniqueID
end rule






function keepJustStaticHeadersIDs	AllHeaders [repeat function_header]
	replace [repeat id]
		current [repeat id]
	deconstruct AllHeaders
		first [function_header] rest [repeat function_header]
	deconstruct first 
	    declSpec [opt decl_specifiers] fctDecl [declarator] fctExt[function_declarator_extension] 
	deconstruct * [base_declarator] fctDecl
		fctBaseDecl [base_declarator]
	deconstruct * [id] fctBaseDecl
		fctNameID [id]
	construct firstJustIfStatic [repeat id]
		_ [addJustStatic first fctNameID]
	by
		current [. firstJustIfStatic]
		[keepJustStaticHeadersIDs rest]
end function









function addJustStatic	FctHeader [function_header]
						FctName [id]
	replace [repeat id]
		_ [repeat id]
		
	deconstruct * [decl_specifiers] FctHeader
		declSpec [decl_specifiers]
		
	where
		declSpec [matchStaticDecl]
		
	by
		_ [. FctName]
end function



rule matchStaticDecl
	match [sc_specifier]
		current [sc_specifier]
		
	construct currentStringlit [stringlit]
		_ [quote current]
	
	construct currentUppercase [stringlit]
		currentStringlit [toupper]
		
	where
		currentUppercase [= "STATIC"]
end rule


