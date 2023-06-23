include "cOriginal.grm"

define declMapping
	[id] [id]
end define


function main
	match * [program]
		P [program]
	import TXLargs [repeat stringlit]
	deconstruct  TXLargs
		outputFile [stringlit] uniqueIDString [stringlit]
		
		
	export uniqueID [id]
		_ [unquote uniqueIDString]
	
	construct uniqueLocalDecls [repeat declMapping]
		_ [constructUniqueLocalDecls P]
	
	construct outputMappings [repeat declMapping]
		uniqueLocalDecls [fput outputFile]
	
end function



function constructUniqueLocalDecls	P [program]
	replace [repeat declMapping]
		_ [repeat declMapping]
		
	construct allVariableDeclaration [repeat declaration]
		_ [^ P]	
	
	construct listOfAllMappings [repeat declMapping]
		_ [constructListOfMappings allVariableDeclaration]
	
	by
		_ [. listOfAllMappings]
end function


function constructListOfMappings	CurrentDeclList [repeat declaration]
	replace [repeat declMapping]
		currentList [repeat declMapping]
	
	
	deconstruct CurrentDeclList 
		CurrentDecl [declaration] rest [repeat declaration]
	
	
	deconstruct not * [macro_specifier] CurrentDecl
		currentNotMacro [macro_specifier] 	
		
		
	construct addedDeclFromBaseDecl [repeat declMapping]
		_ [addDeclIfCaseFromBaseDecl CurrentDecl]
	
	construct addedDeclFromTypeSpec [repeat declMapping]
		addedDeclFromBaseDecl [addDeclIfCaseFromTypeSpecifier CurrentDecl]
		
	by
		currentList [. addedDeclFromTypeSpec]
		[constructListOfMappings rest]
end function





function addDeclIfCaseFromBaseDecl	CurrentDeclaration [declaration]
	replace [repeat declMapping]
		_ [repeat declMapping]
	construct listOfBaseDecl [repeat base_declarator]
		_ [^ CurrentDeclaration]
	construct listOfIDs [repeat id]
		_ [^ listOfBaseDecl]
		
	%all the declaration are one at a line, so here we are interested just about the first one
	deconstruct * [id] listOfIDs
		firstDeclared [id]

	import uniqueID [id]
	construct nameWithIdAdded [id]
		firstDeclared [_ uniqueID]

		
	construct declMapping [declMapping]
		firstDeclared nameWithIdAdded	
		
	by
		_ [. declMapping]
end function


%when just one variable is declared, we must do different since it will not be matched as base declarator
%because of a bug in grammar
function addDeclIfCaseFromTypeSpecifier	CurrentDeclaration [declaration]
	replace [repeat declMapping]
		_ [repeat declMapping]	
	deconstruct CurrentDeclaration
		declSpec[decl_specifiers] semiMark [semi]
	construct idsFromDeclSpec [repeat id]
		_ [^ declSpec]		
	%this is the name of the function
	construct lastIDList [repeat id]
		_ [returnLastID idsFromDeclSpec]
		
	deconstruct * [id] lastIDList
		lastID [id]
		
	import uniqueID [id]
	construct nameWithIdAdded [id]
		lastID [_ uniqueID]

		
	construct declMapping [declMapping]
		lastID nameWithIdAdded	
	by
		_ [. declMapping]
end function


function returnLastID	IDList [repeat id]
	replace [repeat id]
		_ [repeat id]
	deconstruct IDList 
		first [id] rest [repeat id]
	by
		_ [. first]
		[returnLastID rest]
end function









