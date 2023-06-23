include "cOriginal.grm"


redefine upper_macro_name
   [upperlowerid] 
end redefine


tokens
	commentToken	"[ \t]*//[(\\\n)(\"#[\"\n]*\")(/\*#[(\*/)]*\*/)#n]*"
	inLineComment  	"/\*#(\*/)*\*/" 
	end_marker		"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"
end tokens

%define inLineComment
%	[inLineCommentMarker] [NL]
%end define

define commentLine
	[commentToken] [NL]
end define




define declaration_with_marker
	[opt inLineComment] [declaration]
	|	[opt inLineComment] [declaration] HEADER_DECL [NL] [repeat header_declaration_with_marker] 
end define


define header_declaration_with_marker
	[opt inLineComment] [declaration]
end define


redefine program
	...
	|	[repeat stringlit]
end redefine












define declaration_output
	NORMAL_DECLARATION [NL] [repeat declaration_with_marker] STRUCT_DECLARATION [NL] [repeat declaration_with_marker]
	TYPEDEF_DECLARATION [NL] [repeat declaration_with_marker]
end define



define struct_declarations_output
	[repeat struct_needed_declarations] [end_marker] [NL]
end define


define struct_needed_declarations
	[repeat declared_types] [repeat declared_globals] [repeat dependency_list]
end define


define declared_types
	DECLARED_TYPES [NL] [inLineComment] [NL] [repeat id_with_line_break]
end define

define declared_globals
	DECLARED_GLOBALS [NL] [inLineComment] [NL] [repeat id_with_line_break]
end define
  
define dependency_list 
	FUNCTION_NAME: [NL] [inLineComment] [NL] DECLARATION_LIST:  [repeat inLineCommentLineBreak] [NL] [end_marker] [NL]
end define


define inLineCommentLineBreak
	[NL] [inLineComment] 
end define

define id_with_line_break
	[id] [NL]
end define



define function_definition_output
	[id] [stringlit] [NL]
end define



define global_function_dependency_output
	'DEPENDENCIES_FOR_GLOBAL [NL] [inLineComment] [NL] [repeat function_definition_output]
end define


function main
	match * [program]
		P [program]
		
	
	import TXLargs [repeat stringlit]
	deconstruct TXLargs
		outputFile [stringlit] outputFileDependencies [stringlit] outputDefinedTypesAndVars [stringlit] fixIfDefProg [stringlit]
		globalDefinesOutput [stringlit] globalIncludesOutput [stringlit] definedFunctionsFile [stringlit] 
		OutputFunctionsDependencies [stringlit]
		
		
		
	export DeclMarkerNumber [number]
		0

		
	export StructMarkerNumber [number]
		0
		
	export TypeDefMarkerNumber [number]
		0
	
	
	export StructDependList [repeat struct_declarations_output]
		_
	
	export GlobalDefines [repeat preprocessor]
		_
	
	export GlobalIncludesLib [repeat preprocessor]
		_
	
	deconstruct P
		listOfFiles [repeat stringlit]
		
		
		
		
	construct listOfFilesNoPath [repeat stringlit]
		_ [removePathFromListOfFiles listOfFiles]
		
	export ListOfExistingSourceHeaderFiles [repeat stringlit]
		listOfFilesNoPath
		
		
	
	construct listOfFunctionNames [repeat declaration]
		_ [extractGlobalDeclarations listOfFiles fixIfDefProg]
		
		
		
	import GlobalIncludesLib [repeat preprocessor]	
	construct mdsdsgf [repeat preprocessor]
		GlobalIncludesLib [write globalIncludesOutput]	
	
	import GlobalDefines [repeat preprocessor]
	construct mdsds [repeat preprocessor]
		GlobalDefines [write globalDefinesOutput]

	
	
	%first extend the struct typedefs into struct declaration and
	%separate typedef declarations
	
	construct replacedStructTypedefList [repeat declaration]
		_ [separateTypedefFromStruct listOfFunctionNames]
	

	construct extendedBlockDeclStm [repeat declaration]
		_ [replaceDeclInStatementBody replacedStructTypedefList]
		
		
	%global declarations are divided into 3: typedefs, struct/union and global
	%variable declarations
	construct listOfStructDeclaration [repeat declaration_with_marker]
		_ [keepJustStructDeclarators extendedBlockDeclStm]
	construct listOfTypedefDeclaration [repeat declaration_with_marker]
		_ [keepJustTypedefDecl extendedBlockDeclStm]
	construct listOfNormalDeclaration [repeat declaration_with_marker]
		_ [keepJustNormalDecl extendedBlockDeclStm]
		
		
	import 	StructDependList
	
	construct msss [repeat struct_declarations_output]
		StructDependList [write outputDefinedTypesAndVars]	
		
		
	construct declaredVariablesForNormalDecl [repeat base_declarator]
		_ [^ listOfNormalDeclaration]
		
		
		
		
	construct allTypeDeclarations [repeat declared_types]
		_ [^ StructDependList] 
		


		
	
	construct AllNeededGlobalsForStructs [repeat dependency_list]
		_ [constructListOfNeededDeclForStructs listOfStructDeclaration allTypeDeclarations]
		
	construct AllNeededGlobalsForTypeDefs [repeat dependency_list]
		_ [constructListOfNeededDeclForTypeDefs listOfTypedefDeclaration allTypeDeclarations]
		
	construct AllneededGlobalsForNormalDecl [repeat dependency_list]
		_ [constructListOfNeededDeclForTypeDefs listOfNormalDeclaration allTypeDeclarations]
		
		
	construct FinalListOfNeededGlobals [repeat dependency_list]
		AllNeededGlobalsForStructs [. AllNeededGlobalsForTypeDefs] [. AllneededGlobalsForNormalDecl]
	
	construct msddsdsds [repeat dependency_list]
		FinalListOfNeededGlobals [write outputFileDependencies]
		
	construct finalOutput [declaration_output]
		NORMAL_DECLARATION listOfNormalDeclaration STRUCT_DECLARATION listOfStructDeclaration
	TYPEDEF_DECLARATION listOfTypedefDeclaration
	
	
	construct AllDefinedFunctions [repeat function_definition_output]
		_ [read definedFunctionsFile]
	

	construct allGlobalDefinitionsDeclaration [repeat declaration_with_marker]
		_ [. listOfNormalDeclaration] [. listOfStructDeclaration] [.listOfTypedefDeclaration]
		
		

		
	construct allNeededFunctionsForExtraction [repeat global_function_dependency_output]
		_ [extractAllNeededFunctionsForGlobals allGlobalDefinitionsDeclaration AllDefinedFunctions]
		
	construct mdsad [repeat global_function_dependency_output]
		allNeededFunctionsForExtraction [write OutputFunctionsDependencies]
		
	construct printList [declaration_output]
		finalOutput [write outputFile]
end function



function extractAllNeededFunctionsForGlobals	ListOfGlobals [repeat declaration_with_marker]
												ListOfFunctions [repeat function_definition_output]
	replace [repeat global_function_dependency_output]
		currentDepend [repeat global_function_dependency_output]
	
	deconstruct ListOfGlobals
		first [declaration_with_marker] rest [repeat declaration_with_marker]
	
	export ListOfNeededFunctionsForCurrent [repeat function_definition_output]
		_
	
	
	construct neededFctForCurrentDeclaration [repeat function_definition_output]
		ListOfFunctions [declarationWithMarkerMatchAFunction first]	
		
	import ListOfNeededFunctionsForCurrent
	
	
	deconstruct * [inLineComment] first
		currentDeclMarker [inLineComment]
	
	%construct dependenciesForCurrent [global_function_dependency_output]
	%	currentDeclMarker ListOfNeededFunctionsForCurrent
	
	
	construct dependenciesForCurrent [repeat global_function_dependency_output]
		_ [addDependencyJustIfExist currentDeclMarker ListOfNeededFunctionsForCurrent]
	
		
	by
		currentDepend [. dependenciesForCurrent]
		[extractAllNeededFunctionsForGlobals rest ListOfFunctions]
end function


function addDependencyJustIfExist	DeclMarker [inLineComment]
									NeededFctForCurrent [repeat function_definition_output]
	replace [repeat global_function_dependency_output]
		_ [repeat global_function_dependency_output]
	
	
	%just if exists!
	
	deconstruct * [function_definition_output] NeededFctForCurrent
		justIfExists [function_definition_output]	
		
	construct dependenciesForCurrent [global_function_dependency_output]
		'DEPENDENCIES_FOR_GLOBAL DeclMarker NeededFctForCurrent
		
	by
		_ [. dependenciesForCurrent]
end function



rule declarationWithMarkerMatchAFunction	Declaration [declaration_with_marker]
	replace $ [function_definition_output]
		currentFctDef [function_definition_output]
		

		
	where
		Declaration [idInDeclarationMatchFunctionName currentFctDef]	
	where
		Declaration [upperMacoNameInDeclarationMatchFunctionName currentFctDef]
		
	by
		currentFctDef
end rule



rule idInDeclarationMatchFunctionName	FunctionName [function_definition_output]
	match [id]
		currentID [id]
	deconstruct FunctionName
		FctNameID [id] fctSourceFile [stringlit]
	where
		currentID [= FctNameID]
		
		import ListOfNeededFunctionsForCurrent [repeat function_definition_output]
		
		export ListOfNeededFunctionsForCurrent 
			ListOfNeededFunctionsForCurrent [. FunctionName]
		
end rule



rule upperMacoNameInDeclarationMatchFunctionName	FunctionName [function_definition_output]
	match [upper_macro_name]
		currentUMN [upper_macro_name]
		
	construct umnString [stringlit]
		_ [quote currentUMN]
	
	construct currentUMNID [id]
		_ [unquote umnString]
		
	deconstruct FunctionName
		FctNameID [id] fctSourceFile [stringlit]
	where
		currentUMNID [= FctNameID]
		
		import ListOfNeededFunctionsForCurrent [repeat function_definition_output]
		
		export ListOfNeededFunctionsForCurrent 
			ListOfNeededFunctionsForCurrent [. FunctionName] 
		
end rule


function removePathFromListOfFiles	ListOfFiles [repeat stringlit]
	replace [repeat stringlit]
		current [repeat stringlit]
		
	deconstruct ListOfFiles 
		first [stringlit] rest [repeat stringlit]
	
	construct firstNoPath [repeat stringlit]
		_ [removePath first]
	
	by
		current [. firstNoPath]
		[removePathFromListOfFiles rest]
end function


function removePath	SourceFile [stringlit]
	replace [repeat stringlit]
		current [repeat stringlit]
		
	construct indexOfSlash [number]
		_ [index SourceFile "/"] [+ 1]
		

	
	%construct firstPosAfterSlash [number]
	construct newSourceFile [stringlit]
		SourceFile [: indexOfSlash 999]
		
	construct newSourceFileAddedLibMarkers [stringlit]
		_ [+ "<"] [+ newSourceFile] [+ ">"]
		
	
	where
		indexOfSlash [>1]
	
	by
		_ [.newSourceFileAddedLibMarkers]
		[removePath newSourceFile]
end function


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%separete typedef from struct declarations and GLOBAL variable declarations

function separateTypedefFromStruct	ListOfAllDeclaration [repeat declaration]
	replace [repeat declaration]
		newListOfDecl [repeat declaration]
		
	deconstruct ListOfAllDeclaration 
		first [declaration] rest [repeat declaration]
		
	construct firstAsRepeat [repeat declaration]
		_ [. first]	
		
	construct firstReplacedTypedefStructs [repeat declaration]
		firstAsRepeat [separateStructWithTypeDef first]
	
	construct firstReplacedTypedefAndGlobalsStructs [repeat declaration]
		firstReplacedTypedefStructs [separateStructGlobalDeclarations first]
		
	by
		newListOfDecl [.firstReplacedTypedefAndGlobalsStructs]
		[separateTypedefFromStruct rest]
end function



function separateStructGlobalDeclarations	Decl [declaration]
	replace [repeat declaration]
		originalDecl [repeat declaration]
	
	%repeat is just for allowing NULL 

	
	deconstruct * [struct_or_union_body] Decl
		hasBody [struct_or_union_body]
		
	where not
		Decl [hasTypeDef]
		%struct definition, so for sure is the folowing type
		%of declaration:
		
		%construct CheckTypesDecl [declaration]
			%Decl [CheckAllTYPES]
		
		
		
		
		deconstruct Decl
			CurrentSpecs [decl_specifiers] initDecl [list init_declarator] semiMark[semi]
		deconstruct * [struct_or_union_specifier] Decl
			structSpec [struct_or_union_specifier]
			
		construct initialStruct [type_specifier]
			structSpec
		construct initialStructDeclQualOrType [decl_qualifier_or_type_specifier]
			initialStruct	
		construct initialStructDeclOrTypeRepeat [repeat decl_qualifier_or_type_specifier]
			_ [. initialStructDeclQualOrType]	
		construct newSpecifiersInitialStruct [repeat decl_qualifier_or_type_specifier+]
			initialStructDeclOrTypeRepeat
		construct originalStructDeclaration [declaration]
			newSpecifiersInitialStruct ;
			
			
			
			
			
			
			
			
			
			
			
			
			
		
		deconstruct CurrentSpecs
			specsInitial [repeat decl_qualifier_or_type_specifier+]
		

		deconstruct structSpec
			CurrentStructUnion [struct_or_union] AtrSpec1 [repeat attribute_spec]
			RefID [reference_id] body [struct_or_union_body]
			AtrSpec2 [repeat attribute_spec]
		construct newStructSpecNoBody [struct_or_union_specifier]
			CurrentStructUnion RefID
		construct structNoBodyTypeSpec [type_specifier]
			newStructSpecNoBody
		construct structNoDobyDeclQualOrType [decl_qualifier_or_type_specifier]
			structNoBodyTypeSpec	
		construct structDeclOrTypeRepeat [repeat decl_qualifier_or_type_specifier]
			_ [. structNoDobyDeclQualOrType]	
		construct newSpecifiers [repeat decl_qualifier_or_type_specifier+]
			structDeclOrTypeRepeat
			
			
		construct firstGlobalsFromInit [repeat declaration]
			_ [addStructGlobalsFromInitIfCase newSpecifiers initDecl]	
		
		construct lastGlobalsFromDeclSpec [repeat declaration]
			firstGlobalsFromInit [addStructGlobalsFromDeclSpecIfCase specsInitial initDecl newSpecifiers]
			
		construct structHeaderDecl [declaration]
			newSpecifiers ;
	by
		_ [.originalStructDeclaration][. lastGlobalsFromDeclSpec]
end function

function addStructGlobalsFromInitIfCase Specifiers [repeat decl_qualifier_or_type_specifier+]
										InitDeclarators [list init_declarator]
	replace [repeat declaration]
		current [repeat declaration]
	
	construct newDecl [declaration]
		Specifiers InitDeclarators ;
		
	
	construct lengthInitDecl [number]
		_ [length InitDeclarators]
	
	where
		lengthInitDecl [> 0]
	
	by
		_ [. newDecl]
end function



function addStructGlobalsFromDeclSpecIfCase InitialSpecifiers [repeat decl_qualifier_or_type_specifier+]
											InitDeclarators [list init_declarator]
											JustStructDefSpec [repeat decl_qualifier_or_type_specifier+]
	replace [repeat declaration]
		current [repeat declaration]
		
		
	deconstruct InitialSpecifiers
		structWithBody [decl_qualifier_or_type_specifier]
		rest [repeat decl_qualifier_or_type_specifier]	
		
		
	construct newSpecifiers [repeat decl_qualifier_or_type_specifier+]
		JustStructDefSpec [. rest]
		
		
		
	
	construct newDecl [declaration]
		newSpecifiers ;
	
	construct lengthInitDecl [number]
		_ [length InitDeclarators]

		
	construct lengthOfDeclSpec [number]
		_ [length rest]
	
	where
		lengthInitDecl [= 0]
	where 
		lengthOfDeclSpec [> 0]
	
	by
		_ [. newDecl]
end function














function separateStructWithTypeDef	Decl [declaration]
	replace [repeat declaration]
		originalDecl [repeat declaration]
	
	deconstruct * [struct_or_union_body] Decl
		hasBody [struct_or_union_body]
		
	where 
		Decl [hasTypeDef]
		%typedef with struct definition, so for sure is the folowing type
		%of declaration:
		
		deconstruct Decl
			CurrentSpecs [decl_specifiers] initDecl [list init_declarator] semiMark[semi]
		deconstruct * [struct_or_union_specifier] Decl
			structSpec [struct_or_union_specifier]

		construct structTypeSpec [type_specifier]
			structSpec
		construct structDeclQualOrType [decl_qualifier_or_type_specifier]
			structTypeSpec
			
		construct structAsRepeat [repeat decl_qualifier_or_type_specifier]	
			_ [. structDeclQualOrType]
		
		construct newSpecifiersStruct [repeat decl_qualifier_or_type_specifier+]
			structAsRepeat
			
		construct justStructDeclaration [declaration]
			newSpecifiersStruct semiMark

		%if the reference id is not present,it will be considered later
		%just as normal typedef, when outputing in the header file
		deconstruct structSpec
			CurrentStructUnion [struct_or_union] AtrSpec1 [repeat attribute_spec]
			RefID [reference_id] body [struct_or_union_body]
			AtrSpec2 [repeat attribute_spec]
		
		construct newStructSpecNoBody [struct_or_union_specifier]
			CurrentStructUnion RefID
		
		%this is the first sc spec, since it is a typedef
		deconstruct * [sc_specifier] Decl
			typedefSpec [sc_specifier]
		deconstruct CurrentSpecs
			specsRepeat [repeat decl_qualifier_or_type_specifier+] 
		deconstruct specsRepeat
			typedef [decl_qualifier_or_type_specifier] structWithBody [decl_qualifier_or_type_specifier]
			rest [repeat decl_qualifier_or_type_specifier]
		construct typeDefAsRepeat [repeat decl_qualifier_or_type_specifier]
			_ [. typedef]
		construct structNoBodyTypeSpec [type_specifier]
			newStructSpecNoBody
		construct structNoDobyDeclQualOrType [decl_qualifier_or_type_specifier]
			structNoBodyTypeSpec
		construct newSpecifiers [repeat decl_qualifier_or_type_specifier+]
			typeDefAsRepeat [. structNoDobyDeclQualOrType] [. rest] 
		construct typeDefDecl [declaration]
			newSpecifiers initDecl semiMark
		%first 2 decl specifiers are the typedef and struct declaration
	by
		_ [. justStructDeclaration] [. typeDefDecl]
end function




%end separete typedef from struct declarations
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%




%the list of dependency list for a repeat typedef
function constructListOfNeededDeclForTypeDefs	TypeDefs [repeat declaration_with_marker]
												DeclaredTypes [repeat declared_types]
	replace [repeat dependency_list]
		current [repeat dependency_list]
	
	

		
	deconstruct TypeDefs 
		first [declaration_with_marker] rest [repeat declaration_with_marker]
	deconstruct * [inLineComment] first
		commentMarker [inLineComment]
	deconstruct * [declaration] first
		justTheDeclaration [declaration]
	%all the needed structs / typedefs for structs
	construct neededDeclForCurrentTypeDefs [repeat inLineComment]
		_ [extractNeededDeclForCurrentTypeDef first DeclaredTypes]

	construct newNeededDependenciesForTypeDefs [repeat dependency_list]
		_ [constructGlobalDependencyListWhenNonEmpty commentMarker neededDeclForCurrentTypeDefs]
		
		
	
	by
		current [. newNeededDependenciesForTypeDefs]
		[constructListOfNeededDeclForTypeDefs rest DeclaredTypes]
end function

function constructGlobalDependencyListWhenNonEmpty	CommentMarker [inLineComment]
													IdentifiedDecl [repeat inLineComment]
	replace [repeat dependency_list]
		current [repeat dependency_list]
	
	construct endMarker [end_marker]
		 '@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@


	construct IdentifiedDeclNL [repeat inLineCommentLineBreak]
		_ [lineMarkerToLineMarkerNL IdentifiedDecl]

		 
	construct newNeededDependenciesForTypeDefs [dependency_list]
		'FUNCTION_NAME: CommentMarker 'DECLARATION_LIST: IdentifiedDeclNL endMarker
	
	construct lengthIdentified [number]	
		_ [length IdentifiedDecl]
		
	where
		lengthIdentified [> 0]
	by
		current [. newNeededDependenciesForTypeDefs]
end function


function lineMarkerToLineMarkerNL	ListOfLineMarkers [repeat inLineComment]
	replace [repeat inLineCommentLineBreak]
		current [repeat inLineCommentLineBreak]
		
	deconstruct ListOfLineMarkers 
		first [inLineComment] rest [repeat inLineComment]
		
	construct firstNL [inLineCommentLineBreak]	
		first
		
	by
		current [.firstNL]
		[lineMarkerToLineMarkerNL rest]
end function



function extractNeededDeclForCurrentTypeDef	CurrentDeclaration [declaration_with_marker]
											DeclaredTypes [repeat declared_types]
	replace [repeat inLineComment]
		current [repeat inLineComment]
	export CurrentMarkers [repeat inLineComment]
		_ 
	construct exportTheMarkers [repeat declared_types]
		DeclaredTypes [exportNeededMarkersTypeDef CurrentDeclaration]
	import CurrentMarkers
	by
		CurrentMarkers
end function

rule exportNeededMarkersTypeDef	CurrentDeclarationWithMarker [declaration_with_marker]
	replace $ [declared_types]
		current [declared_types]
	deconstruct * [inLineComment] CurrentDeclarationWithMarker
		justTheMarker [inLineComment]
	deconstruct * [declaration] CurrentDeclarationWithMarker
		CurrentDeclaration [declaration]
	deconstruct * [repeat id_with_line_break] current
		justTheTypeNames [repeat id_with_line_break]
		
	deconstruct * [inLineComment] current
		currentDependencyMarker [inLineComment]
		
		

	where
		justTheTypeNames [typeIdNameMatchedByDeclarationTypeDef CurrentDeclaration justTheMarker currentDependencyMarker]
		

		
		import CurrentMarkers [repeat inLineComment]
		export CurrentMarkers 
			CurrentMarkers [. currentDependencyMarker]
	by
		current
end rule


rule typeIdNameMatchedByDeclarationTypeDef	CurrentDeclaration [declaration]
											CurrentDeclarationMarker [inLineComment]
											CurrentDependencyMarker [inLineComment]
	match [id_with_line_break]
		current [id_with_line_break]
		

		
		
	construct idAsString [stringlit]
		_ [quote current]
	construct currentDeclAsString [stringlit]
		_ [quote CurrentDeclaration]
	where 
		CurrentDeclaration [aMemberDeclarationMatchIDTypeDef current] 
		[aMemberDeclarationMatchIDGlobalDecl current]
		[aMemberDeclarationMatchUpperMacroName current]
	where not
		CurrentDeclarationMarker [= CurrentDependencyMarker]
		
		

end rule


rule aMemberDeclarationMatchUpperMacroName	CurrentID [id_with_line_break]
	match [upper_macro_name]
		current [upper_macro_name]
		
	construct currentStringlit [stringlit]
		_ [quote current]
		
	deconstruct * [id] CurrentID
		justID [id]
		
	construct justIDStringlit [stringlit]
		_ [quote justID]
		
	where
		currentStringlit [= justIDStringlit]
	
end rule


function aMemberDeclarationMatchIDTypeDef	CurrentID [id_with_line_break]
	match [declaration]
		CurrentDecl [declaration]
	
	deconstruct * [type_specifier] CurrentDecl
		TypeSpec [type_specifier]
	construct TypeSpecString [stringlit]
		_ [quote TypeSpec]
	construct currentIDString [stringlit]
		_ [quote CurrentID]
	where
		TypeSpecString [= currentIDString]
end function


rule aMemberDeclarationMatchIDGlobalDecl	CurrentID [id_with_line_break]
	match [id]
		current [id]
		
	deconstruct * [id] CurrentID
		justID [id]
		
	where
		current [= justID]
	
end rule



















%the list of dependency list for a repeat structs
function constructListOfNeededDeclForStructs	Structs [repeat declaration_with_marker]
												DeclaredTypes [repeat declared_types]
	replace [repeat dependency_list]
		current [repeat dependency_list]
	deconstruct Structs 
		first [declaration_with_marker] rest [repeat declaration_with_marker]
	deconstruct * [inLineComment] first
		commentMarker [inLineComment]
	deconstruct * [declaration] first
		justTheDeclaration [declaration]
	%all the needed structs / typedefs for structs
	construct neededDeclForCurrentStruct [repeat inLineComment]
		_ [extractNeededDeclForCurrentStruct first DeclaredTypes]
		
		 
		 
	construct newNeededDependenciesForStructs [repeat dependency_list]
		_ [constructGlobalDependencyListWhenNonEmpty commentMarker neededDeclForCurrentStruct]
		
	%construct newNeededDependenciesForStructs [dependency_list]
	by
		current [. newNeededDependenciesForStructs]
		[constructListOfNeededDeclForStructs rest DeclaredTypes]
end function


function extractNeededDeclForCurrentStruct	CurrentDeclaration [declaration_with_marker]
											DeclaredTypes [repeat declared_types]
	replace [repeat inLineComment]
		current [repeat inLineComment]
		
	deconstruct  * [struct_or_union_body] CurrentDeclaration
		theMembersDeclarations [struct_or_union_body]
	export CurrentMarkers [repeat inLineComment]
		_ 
	construct exportTheMarkers [repeat declared_types]
		DeclaredTypes [exportNeededMarkersStructs CurrentDeclaration]
	import CurrentMarkers
	by
		CurrentMarkers
end function


rule exportNeededMarkersStructs	CurrentDeclarationWithMarker [declaration_with_marker]
	replace $ [declared_types]
		current [declared_types]
	deconstruct * [inLineComment] CurrentDeclarationWithMarker
		justTheMarker [inLineComment]
	deconstruct * [declaration] CurrentDeclarationWithMarker
		CurrentDeclaration [declaration]
	deconstruct * [repeat id_with_line_break] current
		justTheTypeNames [repeat id_with_line_break]
		
		
	deconstruct * [inLineComment] current
		currentDependencyMarker [inLineComment]
	where
		justTheTypeNames [typeIdNameMatchedByDeclaration CurrentDeclaration justTheMarker currentDependencyMarker]
		import CurrentMarkers [repeat inLineComment]
		export CurrentMarkers 
			CurrentMarkers [. currentDependencyMarker]
	by
		current
end rule


rule typeIdNameMatchedByDeclaration	CurrentDeclaration [declaration]
									CurrentDeclarationMarker [inLineComment]
									CurrentDependencyMarker [inLineComment]
	match [id_with_line_break]
		current [id_with_line_break]
	construct idAsString [stringlit]
		_ [quote current]
	construct currentDeclAsString [stringlit]
		_ [quote CurrentDeclaration]
	where 
		CurrentDeclaration [aMemberDeclarationMatchIDNew current]
	where not
		CurrentDeclarationMarker [= CurrentDependencyMarker]
end rule


rule aMemberDeclarationMatchIDNew	CurrentID [id_with_line_break]
	match [member_declaration]
		memberDecl [member_declaration]
	deconstruct * [type_specifier] memberDecl
		TypeSpec [type_specifier]
	construct TypeSpecString [stringlit]
		_ [quote TypeSpec]
	construct currentIDString [stringlit]
		_ [quote CurrentID]

		
	deconstruct * [id] CurrentID 
		CurrentJustID [id]
		
	
	where
		memberDecl [checkIfIDMatched CurrentJustID]
end rule



rule checkIfIDMatched	CurrentID [id]
	match [id]
		idInDeclaration[id]
		
	construct CurrentIDStringlit [stringlit]
		_ [quote CurrentID]
		
	construct idInDeclStringlit [stringlit]
		_ [quote idInDeclaration]
	
	where
		CurrentIDStringlit [grep idInDeclStringlit]
	
end rule


rule aMemberDeclarationMatchID	CurrentID [id_with_line_break]
	match [member_declaration]
		memberDecl [member_declaration]
	deconstruct * [type_specifier] memberDecl
		TypeSpec [type_specifier]
	construct TypeSpecString [stringlit]
		_ [quote TypeSpec]
	construct currentIDString [stringlit]
		_ [quote CurrentID]
	where
		TypeSpecString [= currentIDString]
end rule







function keepJustStructDeclarators	DeclarationList [repeat declaration]
	replace [repeat declaration_with_marker]
		current [repeat declaration_with_marker]
	
	deconstruct DeclarationList 
		first [declaration] rest [repeat declaration]
		
	construct firstRepeat [repeat declaration]
		_ [.first]
	construct justStructDecl [repeat declaration_with_marker]
		_ [addJustStructDecl first]	
	by
		current [. justStructDecl]
		[keepJustStructDeclarators rest]
end function



function addJustStructDecl Decl [declaration]
	replace [repeat declaration_with_marker]
		_ [repeat declaration_with_marker]
	deconstruct * [struct_or_union_specifier] Decl
		justIfStructUnion [struct_or_union_specifier]
	construct emptyRepDecl [repeat declaration_with_marker]
		_
		
	%if there is no body, than it is just a variable declaration	
	deconstruct * [struct_or_union_body] Decl
		hasBody [struct_or_union_body]	
		

		
	%where not
		%Decl [hasTypeDef]
		
		%construct the defined symbol for the struct

		import StructMarkerNumber [number]
		construct DeclMarkerNumberStringlit [stringlit]
			_ [quote StructMarkerNumber]
		export StructMarkerNumber 
			StructMarkerNumber [+ 1]
		construct inLineCommentStringlit [stringlit]
			_ [+ "/* STRUCT_DECL_"] [+ DeclMarkerNumberStringlit] [+ " */"]
		construct inLineComment [inLineComment]
			_ [unquote inLineCommentStringlit]
		%construct DeclWithMarker [declaration_with_marker]
		%	inLineComment Decl		
		%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
		%construct headerStructDeclaration for included into the header file
		
		construct headerStructDeclaration [repeat header_declaration_with_marker]
			_ [extractHeaderStructDeclaration Decl]
		construct DeclWithMarker [declaration_with_marker]
			inLineComment Decl HEADER_DECL headerStructDeclaration
			
			
			
				
			
			
			
			
			
		construct definedSymbol [repeat struct_needed_declarations]
			_ [structWithTypedef DeclWithMarker]
		
		construct finalDefinedSymbols [repeat struct_needed_declarations]
			definedSymbol [structNoTypedef DeclWithMarker]
		construct endMarker [end_marker]
		 '@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
		construct newStructDepend [struct_declarations_output]
				finalDefinedSymbols endMarker
		import StructDependList [repeat struct_declarations_output]
		
	
	
	
		export StructDependList
			StructDependList [. newStructDepend]
	by
		_ [.DeclWithMarker]
end function

function extractHeaderStructDeclaration Decl[declaration]
	replace [repeat header_declaration_with_marker]
		current [repeat header_declaration_with_marker]
	deconstruct * [struct_or_union_specifier] Decl
		structSpec [struct_or_union_specifier]
	deconstruct structSpec
		CurrentStructUnion [struct_or_union] AtrSpec1 [repeat attribute_spec]
		RefID [reference_id] body [struct_or_union_body]
		AtrSpec2 [repeat attribute_spec]
	construct newStructSpecNoBody [struct_or_union_specifier]
		CurrentStructUnion RefID
	construct structNoBodyTypeSpec [type_specifier]
		newStructSpecNoBody
	construct structNoDobyDeclQualOrType [decl_qualifier_or_type_specifier]
		structNoBodyTypeSpec	
	construct structDeclOrTypeRepeat [repeat decl_qualifier_or_type_specifier]
		_ [. structNoDobyDeclQualOrType]	
	construct newSpecifiers [repeat decl_qualifier_or_type_specifier+]
		structDeclOrTypeRepeat
	construct structHeaderDecl [declaration]
		newSpecifiers ;
	construct structHeaderDeclMarker [header_declaration_with_marker]
		structHeaderDecl
	by
		_ [. structHeaderDeclMarker]
end function

%if it is typedef, than the IDs after are TYPE names
function structWithTypedef	DeclWithMarker [declaration_with_marker]
	%two cases also: if there is a second ID, than it there are 2 type names defined:
	%the ID after the struct members, and the struct name type
	replace [repeat struct_needed_declarations]
		_ [repeat struct_needed_declarations]
	deconstruct * [declaration] DeclWithMarker
		Decl [declaration]
	deconstruct * [inLineComment] DeclWithMarker
		currentMarker [inLineComment]
	
	
	deconstruct * [struct_or_union_specifier] Decl
		theStructDeclaration [struct_or_union_specifier]
		
		
	deconstruct theStructDeclaration
		structOrUnion [struct_or_union] GNUAtrSpecBegin[repeat attribute_spec] refID [opt reference_id] 
		structBody [struct_or_union_body] GNUAtrSpecEnd[repeat attribute_spec]

	%it could be two: struct ... or the ID at the end
	construct initialDefinedTypes [repeat id_with_line_break]
		_ [addIfReferenceIdExists structOrUnion refID ]
	construct TypeDefNames [repeat id_with_line_break]
		_ [addFinalDeclarationsAfterStructBody Decl]	
	construct finalDefinedTypes [repeat id_with_line_break]
		initialDefinedTypes [. TypeDefNames]

	construct newStructDeclOut [repeat declared_types]
		_ [constructDeclaredTypesJustIfNotNull finalDefinedTypes currentMarker]
		%'DECLARED_TYPES currentMarker finalDefinedTypes
		
		
	construct newStructNeededDeclarations [struct_needed_declarations]
		newStructDeclOut
	
	where
		Decl [hasTypeDef]	
	by
		_ [. newStructNeededDeclarations]
end function









%if it is not typedef, than the IDs after are Global variable definitions

function structNoTypedef	DeclWithMarker[declaration_with_marker]
	replace [repeat struct_needed_declarations]
			_ [repeat struct_needed_declarations]
	deconstruct * [declaration] DeclWithMarker
		Decl [declaration]
	deconstruct * [struct_or_union_specifier] Decl
		structOrUnionSpec [struct_or_union_specifier]
	deconstruct * [inLineComment] DeclWithMarker
		currentMarker [inLineComment]
			
	
	
	deconstruct * [struct_or_union_specifier] Decl
		theStructDeclaration [struct_or_union_specifier]
		

	deconstruct theStructDeclaration
		structOrUnion [struct_or_union] GNUAtrSpecBegin[repeat attribute_spec] refID [opt reference_id] 
		structBody [struct_or_union_body] GNUAtrSpecEnd[repeat attribute_spec]
	
	
	%it could be two: struct ... or the ID at the end
	construct initialDefinedTypes [repeat id_with_line_break]
		_ [addIfReferenceIdExists structOrUnion refID ]
	construct newStructDeclOut [repeat declared_types]
		_ [constructDeclaredTypesJustIfNotNull initialDefinedTypes currentMarker]
		%'DECLARED_TYPES currentMarker initialDefinedTypes	
		
		
	construct GlobalDefinedVars [repeat id_with_line_break]
		_ [addFinalDeclarationsAfterStructBody Decl]	
	construct newGlobalDeclaredOutput [repeat declared_globals]
		_ [constructGlobalDefinedVarsJustIfNotNull GlobalDefinedVars currentMarker]
		
	construct newStructNeededDeclarations [struct_needed_declarations]
		newStructDeclOut newGlobalDeclaredOutput
		
		
	where not
		Decl [hasTypeDef]	
		
	by
		_ [. newStructNeededDeclarations] 
end function



function constructDeclaredTypesJustIfNotNull	DefinedTypes [repeat id_with_line_break]
												Marker [inLineComment]
	replace [repeat declared_types]
		_ [repeat declared_types]
		
	construct newDeclTypes [declared_types]
		'DECLARED_TYPES Marker DefinedTypes	
		
	construct lengthOfDeclaredTypes [number]
		_ [length DefinedTypes]
	where
		lengthOfDeclaredTypes [> 0]	
	by
		_ [. newDeclTypes]
end function



function constructGlobalDefinedVarsJustIfNotNull	GlobalDefinedVars [repeat id_with_line_break]
													Marker [inLineComment]
	replace [repeat declared_globals]
		_ [repeat declared_globals]
		
	construct newGlobalDeclaredOutput [declared_globals]
		'DECLARED_GLOBALS Marker GlobalDefinedVars
	construct lengthOfGlobalDefs [number]
		_ [length GlobalDefinedVars]
	where
		lengthOfGlobalDefs [> 0]
	by
		_ [. newGlobalDeclaredOutput]									
end function

rule hasTypeDef
	match [sc_specifier]
		justIfStructUnion [sc_specifier]
		
	construct firstSpecString [stringlit]
		_ [quote justIfStructUnion]
	construct firstUpperCase [stringlit]
		firstSpecString [toupper]
		
	where
		firstUpperCase [= "TYPEDEF"]
end rule











function addFinalDeclarationsAfterStructBody	Decl [declaration]
	replace [repeat id_with_line_break]
		_ [repeat id_with_line_break]
		
	
	construct declRemovedStructBody [declaration]
		Decl [removeStructBody]
		
	%construct checkDeclTypes [declaration]
	%	declRemovedStructBody [CheckAllTYPES]
		
	construct listOfDeclaredNames [repeat id_with_line_break]
		_ [addAllTheDeclarations declRemovedStructBody]
		
	construct listOfDeclaredNamesUpperMacro [repeat id_with_line_break]
		listOfDeclaredNames [addAllTheDeclarationsFromUpperMacroName declRemovedStructBody]
	
	
	by
		listOfDeclaredNamesUpperMacro
end function



function addAllTheDeclarationsFromUpperMacroName Decl [declaration]
	replace [repeat id_with_line_break]
		current [repeat id_with_line_break]
		
	construct upperMacroNames [repeat upper_macro_name]
		_ [^ Decl]
		
	construct upperMacroNamesIdNL [repeat id_with_line_break]
		_ [upperMacroNameToIdLineBreak upperMacroNames]
	
	by
		current [. upperMacroNamesIdNL]
	
end function

function upperMacroNameToIdLineBreak UpperMacros [repeat upper_macro_name]
	replace [repeat id_with_line_break]
		current [repeat id_with_line_break]
		
	deconstruct UpperMacros
		first [upper_macro_name] rest [repeat upper_macro_name]
		
	construct firstStringlit [stringlit]
		_ [quote first]
		
	construct firstID [id]
		_ [unquote firstStringlit]
	
	construct firstIDLineBreak [id_with_line_break]
		firstID
	
	by
		current [. firstIDLineBreak]
		[upperMacroNameToIdLineBreak rest]
end function

function addAllTheDeclarations	Decl [declaration]
	replace [repeat id_with_line_break]
		_ [repeat id_with_line_break]
	
	
	construct checkTypedefT [repeat id]
		_ [checkTypeDef Decl]
	
	
	deconstruct * [list init_declarator] Decl
		listOfInitDecl [list init_declarator]
		
	
	construct checkDeclTYPE [repeat id]
			_ [checkTypeDef Decl]
		
		
	construct listOfStringlit [repeat id_with_line_break]
		_ [addStringsFromInitDecl listOfInitDecl]
	construct finalListOfDecl [repeat id_with_line_break]
		listOfStringlit [addNameStructFromOneDecl Decl]
	by
		finalListOfDecl
end function



function checkTypeDef	Decl [declaration]
	replace [repeat id]
		_ [repeat id]
	
	construct declStringlit [stringlit]
		_ [quote Decl]
	
	where
		declStringlit [grep "typedef struct symbol Symbol"]
		construct mdasdas [declaration]
		Decl
		
		construct checkAllTTT [declaration]
			Decl [CheckAllTYPES]
	
	by
		_
	
end function



%VERY USEFULL!!!!
rule CheckAllTYPES	
	replace  $ [any]
		express [any]

	construct eString [stringlit]
		_ [quote express]
	construct typeT [id]
		_ [typeof express]
	construct stringType [stringlit]
		_ [quote typeT] [+ "  "]
	construct finalMessage [stringlit]
		stringType [+ eString]

	by
		express
end rule






function addStringsFromInitDecl	ListOfInitDecl [list init_declarator]
	replace [repeat id_with_line_break]
		current [repeat id_with_line_break]
	deconstruct ListOfInitDecl 
		first [init_declarator] , rest [list init_declarator]
		
		
	
	%just the base declarator	
	deconstruct * [base_declarator] first
		firstBaseDecl [base_declarator]
	
	construct firstString [stringlit]
		_ [quote firstBaseDecl]
	construct firstID [id]
		_ [unquote firstString]
	construct firstIDLineBreak [id_with_line_break]
		firstID
	by
		current [. firstIDLineBreak]
		[addStringsFromInitDecl rest]
end function


function addNameStructFromOneDecl	Decl [declaration]
	replace [repeat id_with_line_break]
		_ [repeat id_with_line_break]
	deconstruct * [simple_type_name] Decl
		justOneName [simple_type_name]
	construct nameStringlit [stringlit]
		_ [quote justOneName]
		
	construct AllIdsFromDecl [repeat id]
		_ [^ Decl]	
		
	construct nameID [id]
		_ [returnLastID AllIdsFromDecl]
	construct nameIDLineBreak [id_with_line_break]	
		nameID
	by
		_ [. nameIDLineBreak]
end function


function returnLastID	IDList [repeat id]
	replace [ id]
		_ [ id]
	deconstruct IDList 
		first [id] rest [repeat id]
	by
		 first
		[returnLastID rest]
end function








rule removeStructBody 
	replace $ [repeat member_declaration]
		current [repeat member_declaration]
		
	by
		_
end rule




function addIfReferenceIdExists	StructOrUnion [struct_or_union] 
								RefID [opt reference_id]
	replace [repeat id_with_line_break]
		_ [repeat id_with_line_break]
		
	%check if the reference id exists
	deconstruct * [reference_id] RefID
		exists [reference_id]	
	
	construct structUnionString [stringlit]
		_ [quote StructOrUnion]
	
	construct refIdString [stringlit]
		_ [quote RefID]
	
	construct definedType [stringlit]
		structUnionString [+ " "] [+ refIdString]
		
	construct definedTypeID [id]
		_ [unquote definedType]
		
	construct definedTypeIDLineBreak [id_with_line_break]	
		definedTypeID
		
	by
		_ [. definedTypeIDLineBreak]		
end function












function keepJustTypedefDecl	DeclarationList [repeat declaration]
	replace [repeat declaration_with_marker]
		current [repeat declaration_with_marker]
	deconstruct DeclarationList 
		first [declaration] rest [repeat declaration]
	construct firstRepeat [repeat declaration]
		_ [.first]
	construct justStructDecl [repeat declaration_with_marker]
		_ [addJustTypedefDecl first]	
	by
		current [. justStructDecl]
		[keepJustTypedefDecl rest]
end function



function addJustTypedefDecl Decl [declaration]
	replace [repeat declaration_with_marker]
		_ [repeat declaration_with_marker]
	deconstruct * [sc_specifier] Decl
		justIfStructUnion [sc_specifier]
	construct firstSpecString [stringlit]
		_ [quote justIfStructUnion]
	construct firstUpperCase [stringlit]
		firstSpecString [toupper]
		
	deconstruct not * [struct_or_union_body] Decl 
		notBody [struct_or_union_body]
		
		
	
	
		
	where
		firstUpperCase [= "TYPEDEF"]
		
		import TypeDefMarkerNumber [number]
		construct DeclMarkerNumberStringlit [stringlit]
			_ [quote TypeDefMarkerNumber]
		export TypeDefMarkerNumber 
			TypeDefMarkerNumber [+ 1]
		construct inLineCommentStringlit [stringlit]
			_ [+ "/* TYPEDEF_DECL_"] [+ DeclMarkerNumberStringlit] [+ " */"]
		construct inLineComment [inLineComment]
			_ [unquote inLineCommentStringlit]
		construct DeclWithMarker [declaration_with_marker]
			inLineComment Decl	
			
			
		construct definedTypesNoUpperMacro [repeat id_with_line_break]
			_ [addAllTheDeclarations Decl]	
			
		construct definedTypes [repeat id_with_line_break]
			definedTypesNoUpperMacro [addAllTheDeclarationsFromUpperMacroName Decl]
		

		
		construct declaredTypes [repeat declared_types]	
			_ [constructDeclaredTypesJustIfNotNull definedTypes inLineComment]
			%'DECLARED_TYPES inLineComment definedTypes
			

			
		construct structNeededDecl [struct_needed_declarations]
			declaredTypes
			
			

			
		construct endMarker [end_marker]
		 '@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
		construct newStructDepend [struct_declarations_output]
				structNeededDecl endMarker
				
				
		import StructDependList [repeat struct_declarations_output]
	
		export StructDependList
			StructDependList [. newStructDepend]
			
			
		
	by
		_ [.DeclWithMarker]
end function













function keepJustNormalDecl	DeclarationList [repeat declaration]
	replace [repeat declaration_with_marker]
		current [repeat declaration_with_marker]
	deconstruct DeclarationList 
		first [declaration] rest [repeat declaration]
	construct firstRepeat [repeat declaration]
		_ [.first]
	construct justStructDecl [repeat declaration_with_marker]
		_ [addJustNormalDecl first]	
	by
		current [. justStructDecl]
		[keepJustNormalDecl rest]
end function



function addJustNormalDecl OriginalDecl [declaration]
	replace [repeat declaration_with_marker]
		_ [repeat declaration_with_marker]		
	construct emptyRepDecl [repeat declaration_with_marker]
		_
		
	deconstruct not* [struct_or_union_body] OriginalDecl
		hasBody [struct_or_union_body]
		
	deconstruct not * [function_declarator_extension] OriginalDecl
		notFunctionDeclarator [function_declarator_extension]
		
			

		
	where not
		OriginalDecl [hasTypeDef]
		
		

	%where not
		%emptyRepDecl [? addJustStructDecl Decl]
		
		
			%construct checTTT [declaration]
		%Decl [CheckAllTYPES]
		
		
		%construct dependency list declarations for enum!!!
		
		
		%remove static atribute!!!!
		
		construct DeclNoSpecs [declaration]
			OriginalDecl [noStaticSpec]	
		
		
		import DeclMarkerNumber [number]
		construct DeclMarkerNumberStringlit [stringlit]
			_ [quote DeclMarkerNumber]
		export DeclMarkerNumber 
			DeclMarkerNumber [+ 1]
		construct inLineCommentStringlit [stringlit]
			_ [+ "/* GLOBAL_DECL_"] [+ DeclMarkerNumberStringlit] [+ " */"]
		construct inLineCommentFixedEnums [stringlit]
			inLineCommentStringlit [replaceCommentForEnumsAndAddDeclaredTypes DeclNoSpecs DeclMarkerNumberStringlit]
		construct inLineComment [inLineComment]
			_ [unquote inLineCommentFixedEnums]
			
			
		construct repeatOfNeededHeaderDecl [repeat header_declaration_with_marker]
			_ [extractNormalDeclHeaderDecl DeclNoSpecs]	
			
			
		construct DeclWithMarker [declaration_with_marker]
			inLineComment DeclNoSpecs HEADER_DECL repeatOfNeededHeaderDecl
			
			
			
			
		
		construct declaredGlobalVariables [repeat id_with_line_break]
			_ [extractDeclaredGlobalVariablesNormalDecl DeclNoSpecs]	
			
			
			
		construct declaredTypes [repeat declared_types]	
			_ [constructDeclaredTypesJustIfNotNull declaredGlobalVariables inLineComment]
		construct structNeededDecl [struct_needed_declarations]
			declaredTypes
		construct endMarker [end_marker]
		 '@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
		construct newStructDepend [struct_declarations_output]
				structNeededDecl endMarker
				
		import StructDependList [repeat struct_declarations_output]
	
		export StructDependList
			StructDependList [. newStructDepend]	
			

			
	by
		_ [.DeclWithMarker]
end function


%remove qualifiers as const, static, etc
rule noStaticSpec	
	replace $ [decl_specifiers]
		declSpec [decl_specifiers]
	deconstruct * [repeat decl_qualifier_or_type_specifier] declSpec
		varSpec [repeat decl_qualifier_or_type_specifier]
	construct newVarSpec [repeat decl_qualifier_or_type_specifier]
		_ [removeTypeSpecifiersGlobals varSpec]
	construct newDeclSpec[decl_specifiers]
		newVarSpec
	by
		newDeclSpec
end rule


%remove qualifiers as const, static, etc
function removeTypeSpecifiersGlobals	v1 [repeat decl_qualifier_or_type_specifier]
	replace [repeat decl_qualifier_or_type_specifier]
		varSpec [repeat decl_qualifier_or_type_specifier]
	deconstruct v1
		first [decl_qualifier_or_type_specifier] rest [repeat decl_qualifier_or_type_specifier] 
	construct finalDeclOrSpec [repeat decl_qualifier_or_type_specifier]
		_ [addJustIfTypeSpecGlobals first]
	%construct finalDeclOrSpecAddedMacroSpecs [repeat decl_qualifier_or_type_specifier]
		%finalDeclOrSpec [addIfDeconstructInMacroSpecifier first]
	by
		varSpec [.finalDeclOrSpec]
		[removeTypeSpecifiersGlobals rest]
end function


function addJustIfTypeSpecGlobals	V1 [decl_qualifier_or_type_specifier]
	replace [repeat decl_qualifier_or_type_specifier]
		declOrType [repeat decl_qualifier_or_type_specifier]
		
	deconstruct not * [sc_specifier] V1
		notSC [sc_specifier]
	by
		declOrType [. V1]
end function





function addIfDeconstructInMacroSpecifier V1 [decl_qualifier_or_type_specifier]
	replace [repeat decl_qualifier_or_type_specifier]
		declOrType [repeat decl_qualifier_or_type_specifier]
	
	deconstruct * [cv_qualifier] V1
		cvQualifier [cv_qualifier]
		
	deconstruct * [upper_macro_name] cvQualifier
		upperMacroName [upper_macro_name]
	
	by
		declOrType [.V1]
end function











function extractDeclaredGlobalVariablesNormalDecl	Decl[declaration]
	replace [repeat id_with_line_break]
		current [repeat id_with_line_break]
		
	deconstruct not * [enum_specifier] Decl
		enumSpec [enum_specifier]
	
	construct globalsFromNormalDecl [repeat id_with_line_break]
		_ [extractDeclaredGlobalsFromNormalDeclaration Decl]
		
	construct addedFromCompoundInit [repeat id_with_line_break]
		globalsFromNormalDecl [extractDeclaredGlobalsFromCompoundInitDeclaration Decl]
	
	
	by
		addedFromCompoundInit
end function



function extractDeclaredGlobalsFromNormalDeclaration	Decl[declaration]
	replace [repeat id_with_line_break]
		current [repeat id_with_line_break]
	
	deconstruct Decl
		DeclSpec [decl_specifiers] ListInitDecl [list init_declarator] SemiMarker [semi]
	
	construct listOfDeclaredIDsFromBaseDecls [repeat id_with_line_break]
		_ [addDeclIfCaseFromBaseDecl Decl]
		
	construct addedFromTypeSpecIfCase [repeat id_with_line_break]
		listOfDeclaredIDsFromBaseDecls [addDeclIfCaseFromTypeSpecifier Decl]
	
	
	by
		current [. addedFromTypeSpecIfCase]
end function


function extractDeclaredGlobalsFromCompoundInitDeclaration	Decl[declaration]
	replace [repeat id_with_line_break]
		current [repeat id_with_line_break]
		
	deconstruct Decl
		DeclSpec [decl_specifiers] Declarator [declarator] '= CompInit [compound_initializer]
		
	construct listOfDeclaredIDsFromBaseDecls [repeat id_with_line_break]
		_ [addDeclIfCaseFromBaseDecl Decl]	
		
	by
		current [. listOfDeclaredIDsFromBaseDecls]
end function



%if there are more then one variable declared, and there is no compound init
function addDeclIfCaseFromBaseDecl	CurrentDeclaration [declaration]
	replace [repeat id_with_line_break]
		_ [repeat id_with_line_break]
	construct listOfBaseDecl [repeat base_declarator]
		_ [^ CurrentDeclaration]
	construct listOfIDs [repeat id]
		_ [^ listOfBaseDecl]
		
	construct lastIDLineBreak [repeat id_with_line_break]
		_ [repeatIdToRepeatIdLineBreak listOfIDs]	
	by
		_ [. lastIDLineBreak]
end function


%when just one variable is declared, we must do different since it will not be matched as base declarator
%because of a bug in grammar
function addDeclIfCaseFromTypeSpecifier	CurrentDeclaration [declaration]	
	replace [repeat id_with_line_break]
		_ [repeat id_with_line_break]	
		
		
		
	deconstruct CurrentDeclaration
		declSpec[decl_specifiers] semiMark [semi]

		
	construct idsFromDeclSpec [repeat id]
		_ [^ declSpec]			
	construct lastID [repeat id]
		_ [returnLastIDFrGlobalDecls idsFromDeclSpec]	
	construct lastIDLineBreak [repeat id_with_line_break]
		_ [repeatIdToRepeatIdLineBreak lastID]
	by
		_ [.lastIDLineBreak]
end function



function returnLastIDFrGlobalDecls	IDList [repeat id]
	replace [repeat id]
		_ [repeat id]		
	deconstruct IDList 
		first [id] rest [repeat id]
	by
		_ [. first]
		[returnLastIDFrGlobalDecls rest]
end function





function repeatIdToRepeatIdLineBreak	ListOfIDs [repeat id]
	replace [repeat id_with_line_break]
		current [repeat id_with_line_break]
		
	deconstruct ListOfIDs
		first [id] rest [repeat id]
		
	construct firstLineBreak [id_with_line_break]
		first
	
	by
		current [. firstLineBreak]
		[repeatIdToRepeatIdLineBreak rest]
end function




%for declarations with compound initializer --- probably the same as the previous!
%(
function addDeclIfCaseFromCompoundInit CurrentDeclaration [declaration]
	replace [repeat id]
		_ [repeat id]
		
	construct baseDecleclarators[repeat base_declarator]
		_ [^ CurrentDeclarator]
		
	by
		_
end function
)%














function replaceCommentForEnumsAndAddDeclaredTypes	Decl [declaration]
													DeclMarkerNumber [stringlit]
	replace [stringlit]
		current [stringlit]
		
	construct newComment [stringlit]
		_ [+ "/* ENUM_DECL_"] [+ DeclMarkerNumber] [+ " */"]
	deconstruct * [enum_specifier] Decl
		hasEnum [enum_specifier]
		
	construct enumMarker [inLineComment]
		_ [unquote newComment]

		
	construct exportDeclared [repeat id]
		_ [exportEnumDeclaredType Decl enumMarker]
		
	by
		newComment
end function



function enumDefinedTypesVars Decl [declaration]
	replace [repeat id_with_line_break]
		current [repeat id_with_line_break]
		
	deconstruct * [reference_id] Decl
		enumRefID [reference_id]
		
	deconstruct * [id] enumRefID
		enumID [id]
		
	construct enumStringlit [stringlit]
		_ [quote enumID]
	
	construct enumDeclMarker [stringlit]
		"enum "
	
	construct enumFullDeclStringlit [stringlit]
		enumDeclMarker [+ enumStringlit]
	
	construct fullEnumID [id]
		_ [unquote enumFullDeclStringlit]
	
	
	construct enumRefIDLineBreak [id_with_line_break]
		fullEnumID
	
	by
		current [. enumRefIDLineBreak]
end function


function exportEnumDeclaredType	Decl [declaration]
								inLineComment [inLineComment]
	replace [repeat id]
		_ [repeat id]
		
	construct definedTypes [repeat id_with_line_break]
		_ [enumDefinedTypesVars Decl]	
		
	construct declaredTypes [repeat declared_types]	
		_ [constructDeclaredTypesJustIfNotNull definedTypes inLineComment]
	%'DECLARED_TYPES inLineComment definedTypes
			

			
	construct structNeededDecl [struct_needed_declarations]
		declaredTypes
			
			

			
	construct endMarker [end_marker]
		'@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
	construct newStructDepend [struct_declarations_output]
			structNeededDecl endMarker
				
	import StructDependList [repeat struct_declarations_output]
	
	export StructDependList
		StructDependList [. newStructDepend]
					
		
		
	by
		_
end function


function extractNormalDeclHeaderDecl	Decl [declaration]
	replace [repeat header_declaration_with_marker]
		current [repeat header_declaration_with_marker]
		
	construct addedDeclNotInitializer	[repeat header_declaration_with_marker]
		_ [addNotInitializer Decl]
	
	construct addedDeclWithInitializer [repeat header_declaration_with_marker]
		addedDeclNotInitializer [addWithInitializer Decl]
	
		
	by
		current [.addedDeclWithInitializer]
end function




function notConstantExpressionInArray
	match [declaration]
		Decl [declaration]
	deconstruct * [array_declarator_extension] Decl
		arrayExt [array_declarator_extension]
	deconstruct arrayExt
		'[ ctExpr [constant_expression] ']
end function


rule matchStaticQualifier
	match [sc_specifier]
		current [sc_specifier]
	construct currentStringlit [stringlit]
		_ [quote current]
	
	construct currentUpperCase [stringlit]
		currentStringlit [toupper]
		
		
		
	where
		currentUpperCase [= "STATIC"]
		
end rule



rule matchConstQualifier
	match [cv_qualifier]
		current [cv_qualifier]
	construct currentStringlit [stringlit]
		_ [quote current]
	
	construct currentUpperCase [stringlit]
		currentStringlit [toupper]
		
		
		
	where
		currentUpperCase [= "CONST"]
		
end rule




function addWithInitializer	Decl [declaration]
	replace [repeat header_declaration_with_marker]
		current [repeat header_declaration_with_marker]
		
	%just if it is not static!!!! or constant!!!!
	where not
		Decl [matchStaticQualifier]
	%where not
		%Decl [matchConstQualifier]
	%where not
		%Decl [notConstantExpressionInArray]
	
	%deconstruct not * [array_declarator_extension] Decl
	%	notHavingDeclExtension [array_declarator_extension]

	
	
	construct checkAllTypesDecl [declaration]
		Decl [CheckAllTYPES]	
		
	deconstruct Decl
		DeclSpec [decl_specifiers] currentDeclarator [declarator] '= CompInit[compound_initializer] 
 
	
		
	deconstruct DeclSpec
		repeatQualifierOrTypeSpec [repeat decl_qualifier_or_type_specifier+] 
	construct scSpec [sc_specifier]	
		extern
	construct externDeclQual [decl_qualifier]
		scSpec
	construct externDeclQuaOrTypeSpecl [decl_qualifier_or_type_specifier]
		externDeclQual
	construct externRepeatQualOrType [repeat decl_qualifier_or_type_specifier]
		_ [. externDeclQuaOrTypeSpecl]
	construct addedExterDeclQualifierTypeSpec [repeat decl_qualifier_or_type_specifier+]
		externRepeatQualOrType [. repeatQualifierOrTypeSpec]
		
	construct newHeaderJustDecl [declaration]
		addedExterDeclQualifierTypeSpec ;
	
	construct newHeaderDecl [header_declaration_with_marker]
		newHeaderJustDecl
		
	construct newHeaderRepeat [repeat header_declaration_with_marker]
		_ [. newHeaderDecl]
		
	construct newHeaderDeclFixedStructArrays [repeat header_declaration_with_marker]
		newHeaderRepeat [fixStructArrayDecl externDeclQuaOrTypeSpecl externRepeatQualOrType Decl]


	by
		_ [. newHeaderDeclFixedStructArrays]
end function


function fixStructArrayDecl ExternalDeclQualifierMarker [decl_qualifier_or_type_specifier]
							RestOfDeclQualifiers [repeat decl_qualifier_or_type_specifier]
							Decl [declaration]
	replace [repeat header_declaration_with_marker]
		_ [repeat header_declaration_with_marker]
		
		
	where 
		Decl [structHasArrayExtension]
		
	construct StructArrayMarker [stringlit]
		"/* STRUCT_WITH_ARRAY */"
		
	construct structArrayMarkerInLineComm [inLineComment]
		_ [unquote StructArrayMarker]
		
	construct newDecl [declaration]
			RestOfDeclQualifiers ;
		
	construct newHeaderDecl [header_declaration_with_marker]
		structArrayMarkerInLineComm newDecl
	by
		_ [. newHeaderDecl]
end function




function addNotInitializer	Decl [declaration]
	replace [repeat header_declaration_with_marker]
		current [repeat header_declaration_with_marker]
		
	where not
		Decl [matchStaticQualifier]	
	%where not
		%Decl [notConstantExpressionInArray]
	
	%where not
		%[st]
	
	deconstruct not * [enum_specifier] Decl
		notEnumSpec [enum_specifier]
		
	%deconstruct not * [array_declarator_extension] Decl
		%structNotHavingArrayExtension [array_declarator_extension]
		
		
	deconstruct Decl
		DeclSpec [decl_specifiers] ListInitDecl [list init_declarator] SemiMarker[semi]
	construct removedInitializersListInitDecl [list init_declarator]
		ListInitDecl [removeInitializers]
	deconstruct DeclSpec
		repeatQualifierOrTypeSpec [repeat decl_qualifier_or_type_specifier] 
		
		
	%remove const, void, ...	
	construct repeatQualifierOrTypeSpecRemovedAddtionals [repeat decl_qualifier_or_type_specifier] 
		_ [removeTypeSpecifiers repeatQualifierOrTypeSpec]
	
	construct scSpec [sc_specifier]	
		extern
	construct externDeclQual [decl_qualifier]
		scSpec
	construct externDeclQuaOrTypeSpecl [decl_qualifier_or_type_specifier]
		externDeclQual
	construct externRepeatQualOrType [repeat decl_qualifier_or_type_specifier]
		_ [. externDeclQuaOrTypeSpecl]
	construct addedExterDeclQualifierTypeSpec [repeat decl_qualifier_or_type_specifier+]
		externRepeatQualOrType [. repeatQualifierOrTypeSpecRemovedAddtionals]
	construct newHeaderJustDecl [declaration]
		addedExterDeclQualifierTypeSpec removedInitializersListInitDecl SemiMarker
		
		
	
	construct newHeaderDecl [header_declaration_with_marker]
		newHeaderJustDecl
		
	construct newHeaderRepeat [repeat header_declaration_with_marker]
		_ [. newHeaderDecl]
		
	construct newHeaderDeclFixedStructArrays [repeat header_declaration_with_marker]
		newHeaderRepeat [fixStructArrayDeclNotInit repeatQualifierOrTypeSpecRemovedAddtionals removedInitializersListInitDecl Decl]	
		
		
		
		
		
		
		
	by
		_ [. newHeaderDeclFixedStructArrays]
end function



function fixStructArrayDeclNotInit	RestOfDeclQualifiers [repeat decl_qualifier_or_type_specifier]
									InitDeclList [list init_declarator]
									Decl [declaration]
	replace [repeat header_declaration_with_marker]
		_ [repeat header_declaration_with_marker]
		
		
	where 
		Decl [structHasArrayExtension]
		
	construct StructArrayMarker [stringlit]
		"/* STRUCT_WITH_ARRAY */"
		
	construct structArrayMarkerInLineComm [inLineComment]
		_ [unquote StructArrayMarker]
		
	construct newDecl [declaration]
			RestOfDeclQualifiers InitDeclList ;
		
	construct newHeaderDecl [header_declaration_with_marker]
		structArrayMarkerInLineComm newDecl
	by
		_ [. newHeaderDecl]
end function





function structHasArrayExtension
	match [declaration]
		current [declaration]
	deconstruct  * [array_declarator_extension] current
		structNotHavingArrayExtension [array_declarator_extension]	
		
	deconstruct * [struct_or_union] current
		structSpec [struct_or_union]
	
end function


%remove qualifiers as const, static, etc
function removeTypeSpecifiers	v1 [repeat decl_qualifier_or_type_specifier]
	replace [repeat decl_qualifier_or_type_specifier]
		varSpec [repeat decl_qualifier_or_type_specifier]
	deconstruct v1
		first [decl_qualifier_or_type_specifier] rest [repeat decl_qualifier_or_type_specifier] 
	construct finalDeclOrSpec [repeat decl_qualifier_or_type_specifier]
		_ [addJustIfTypeSpec first]
		
	%construct finalDeclOrSpecAddedMacroSpecs [repeat decl_qualifier_or_type_specifier]
		%finalDeclOrSpec [addIfDeconstructInMacroSpecifier first]	
	
	by
		varSpec [.finalDeclOrSpec]
		[removeTypeSpecifiers rest]
end function


function addJustIfTypeSpec	V1 [decl_qualifier_or_type_specifier]
	replace [repeat decl_qualifier_or_type_specifier]
		declOrType [repeat decl_qualifier_or_type_specifier]
	%deconstruct not * [cv_qualifier] V1
		%notCV [cv_qualifier]
	deconstruct not * [sc_specifier] V1
		notSC [sc_specifier]
	by
		declOrType [. V1]
end function









rule removeInitializers 
	replace $[opt initialization]
		current [opt initialization]
	by
		%empty
end rule



function extractGlobalDeclarations	ListOfFiles [repeat stringlit]
									FixIfDefProg [stringlit]
	replace [repeat declaration]
		current [repeat declaration]
	deconstruct ListOfFiles
		first [stringlit] rest [repeat stringlit]
	construct nonIfDefsOutput [stringlit]
		first [+ "NONExt"]
	construct commandForNonIf [stringlit]
		_ [+ FixIfDefProg] [+ " "] [+ first] [+ " "] [+ first]  [+ " "]  [+ nonIfDefsOutput]
	construct CallCommand2 [id]
    	_ [system commandForNonIf]
	construct ProgramSource [ program]
		_ [read nonIfDefsOutput] 
			
	
	deconstruct * [repeat function_definition_or_declaration] ProgramSource
		ProgramFctDefOrDecl [repeat function_definition_or_declaration]
		
		
	%construct the list of global defines from current
	construct definesFromCurrent [repeat preprocessor]
		_ [extractDefineDeclarations ProgramFctDefOrDecl]	
		
		
		
	import GlobalDefines [repeat preprocessor]
	
	
	construct addedUniqueNewDefines [repeat preprocessor]
		GlobalDefines [addUniqueIncludes definesFromCurrent]
	export GlobalDefines
		addedUniqueNewDefines	

	%export GlobalDefines
		%GlobalDefines [. definesFromCurrent]
		
	
	%construct the list of included libraries from current
	construct includesFromCurrent [repeat preprocessor]
		_ [extractIncludes ProgramFctDefOrDecl] 
	import GlobalIncludesLib [repeat preprocessor]		
	construct addedUniqueNewIncludes [repeat preprocessor]
		GlobalIncludesLib [addUniqueIncludes includesFromCurrent]
	export GlobalIncludesLib
		addedUniqueNewIncludes	
	construct globalDefinitions [repeat declaration]
		_ [extractAlGlobalDeclarations ProgramFctDefOrDecl] 
		
	by
		current	[. globalDefinitions]
		[extractGlobalDeclarations rest FixIfDefProg]
end function


function extractIncludes	ProgramDecl [repeat function_definition_or_declaration]
	replace [repeat preprocessor]
		current [repeat preprocessor]
		
	deconstruct ProgramDecl 
		first [function_definition_or_declaration] rest [repeat function_definition_or_declaration]	
	construct firstIfInclude [repeat preprocessor]
		_ [addJustIncludes first]	
	by
		current [.firstIfInclude]
		[extractIncludes rest]
end function


function addJustIncludes	CurrentDecl [function_definition_or_declaration]
	replace [repeat preprocessor]
		_ [repeat preprocessor]
	
	deconstruct CurrentDecl
		currentPreprocDecl [preprocessor]
	
	construct currentPreprocDeclString [stringlit]
		_ [quote currentPreprocDecl]
		
	import ListOfExistingSourceHeaderFiles [repeat stringlit]
		
	where
		currentPreprocDeclString [grep "#include"]
	where
		currentPreprocDeclString [grep "<"]
	where
		currentPreprocDeclString [grep ">"]
	where not
		ListOfExistingSourceHeaderFiles [searchIncludeInHeaderFiles currentPreprocDeclString]
		
	by
		_ [.currentPreprocDecl]
end function


rule searchIncludeInHeaderFiles	CurrentInclude [stringlit]
	match [stringlit]
		existingHeader [stringlit]
		
	where
		CurrentInclude [grep existingHeader]
		
end rule





function addUniqueIncludes	NewIncludes [repeat preprocessor]
	replace [repeat preprocessor]
		currentIncludes [repeat preprocessor]
		
	deconstruct NewIncludes
		first [preprocessor] rest [repeat preprocessor]
		
	construct uniqueInclude [repeat preprocessor]
		_ [addIfUnique first currentIncludes]
	by
		currentIncludes [. uniqueInclude]
		[addUniqueIncludes rest]
end function


function addIfUnique	V1 [preprocessor] 
						ListOfAllIncludes [repeat preprocessor]
	replace [repeat preprocessor]
		listOfIncl [repeat preprocessor]
	where not
		ListOfAllIncludes [containsAlready V1]
	by
		listOfIncl [. V1]
end function


rule containsAlready	V1 [preprocessor]
	match [preprocessor]
		currentValue [preprocessor]
	construct currentValueString [stringlit]
		_ [quote currentValue]
	construct V1String [stringlit]
		_ [quote V1]
	where 
		currentValueString [= V1String]
end rule


































function extractDefineDeclarations	ProgramDecl [repeat function_definition_or_declaration]
	replace [repeat preprocessor]
		current [repeat preprocessor]
		
	deconstruct ProgramDecl 
		first [function_definition_or_declaration] rest [repeat function_definition_or_declaration]	
	
	
	construct firstIfDefine [repeat preprocessor]
		_ [addJustDefines first]
		
	by
		current [.firstIfDefine]
		[extractDefineDeclarations rest]
end function


function addJustDefines	CurrentDecl [function_definition_or_declaration]
	replace [repeat preprocessor]
		_ [repeat preprocessor]
	
	

	
	deconstruct CurrentDecl
		currentPreprocDecl [preprocessor]
	
	construct currentPreprocDeclString [stringlit]
		_ [quote currentPreprocDecl]
		
		
		
		
	where
		currentPreprocDeclString [grep "#define"]
		
	by
		_ [.currentPreprocDecl]
		
end function









function extractAlGlobalDeclarations	ProgramFctDefOrDecl [repeat function_definition_or_declaration]
	replace [repeat declaration]
		current [repeat declaration]
		

	
		
	deconstruct ProgramFctDefOrDecl
		first [function_definition_or_declaration] rest [repeat function_definition_or_declaration]
		
	construct addFirstJustIfDecl [repeat declaration]
		_ [addJustDeclarations first]	
		
	by
		current [.addFirstJustIfDecl]
		[extractAlGlobalDeclarations rest]
end function




function addJustDeclarations	Decl [function_definition_or_declaration]
	replace [repeat declaration]
		_ [repeat declaration]
	
	
	deconstruct not * [macro_specifier] Decl
		notMacroSpec [macro_specifier]
	
	%skipping [function_definition_or_declaration]
	deconstruct Decl
		justDecl [declaration]
	
	where
		Decl [isDecl]
	where not
		Decl [isPreproc]
	
	where not
		Decl [isExtern]
	

	by
		_ [. justDecl]
		
end function


function isDecl
	match  [function_definition_or_declaration]
		AS [declaration]
end function
 

function isPreproc
	match  [function_definition_or_declaration]
		AS [preprocessor]
end function
 
%do not add extern declarations, since them are already added from the real declaration

function isExtern
	match * [sc_specifier]
		currentSpec [sc_specifier]
	construct currentSpecString [stringlit]
		_ [quote currentSpec]
	
	construct currentSpecUppercase [stringlit]
		currentSpecString [toupper]
	
	where	
		currentSpecUppercase [= "EXTERN"]
	
end function







%extend all the declarations from the initial source code of a function



function replaceDeclInStatementBody	DeclStmFromBody [repeat declaration]
	replace [repeat declaration]
		current [repeat declaration]
	deconstruct DeclStmFromBody
		first [declaration] rest [repeat declaration]
	construct currentDeclStmAsRepeat [repeat declaration]
		_ [. first]
	construct newListOfDecl [repeat declaration]
		currentDeclStmAsRepeat [replaceIfDeclaration]
	by
		current [. newListOfDecl]
		[replaceDeclInStatementBody rest]
end function



function replaceIfDeclaration
	replace [repeat declaration]
		current [repeat declaration]
	%if it has struct body, it is a declaration in it so it should not be separated
	%since it will cause errors at compilation declaring the same struct /union
	%more times
	deconstruct not * [struct_or_union_body] current
		notHasStructBody [struct_or_union_body]


		
	deconstruct * [declaration] current
		justOneDecl [declaration]
		
		
	construct repeatCurrentDecl [repeat declaration]
		_ [. current]
	construct separateListOfDecl [repeat declaration]
		repeatCurrentDecl [constructListOfSeparateDeclarations justOneDecl]
	
	
	by
		separateListOfDecl
end function


function constructListOfSeparateDeclarations currentVarDecl [declaration]
	replace [repeat declaration]
		decl [repeat declaration]
	deconstruct   currentVarDecl
		specT [decl_specifiers] declT [list init_declarator] ';
    deconstruct specT
		repeatFromDecl [repeat decl_qualifier_or_type_specifier]
	construct newVarDeclSpecifiers [decl_specifiers]
		repeatFromDecl 
	construct allVars [repeat declaration]
		_ [separeDeclarations newVarDeclSpecifiers declT ] 
	
	construct countAllVars [number]
		_ [length allVars]
	
	where
		countAllVars [> 0]
	
	by
		_ [. allVars]
end function
	
	
	
function separeDeclarations	specifier [decl_specifiers]
							declList [list init_declarator]
	replace [repeat declaration]
		variableDeclList [repeat declaration]
	deconstruct  declList
		First [init_declarator] , Rest [list init_declarator]
	construct newVarDecl [declaration]
		specifier First ';
	by
		variableDeclList [. newVarDecl]
		[separeDeclarations specifier Rest]
end function	



