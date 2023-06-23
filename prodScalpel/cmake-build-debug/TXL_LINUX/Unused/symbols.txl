include "cOriginal.grm"




tokens
	%idd "\u\i*"
	end_source_files_mark "______________________________"
	end_call_graph_marker "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"
	current_function "^^\i+^^"
	
		%source_file_element3 "\i+/.\i+"
	
	
	source_file_element "@@\i*.\i*@@"
	source_file_token "source_file:"

end tokens

%redefine program
%	[reverse_call_graph]
%end redefine


redefine program
    [compilation_unit]
    |	[list argument_declaration]
    |	[reverse_call_graph]
end redefine

define reverse_call_graph
	[source_files] [NL][current_function] [NL] [repeat graph]
end define

define source_files
	[repeat source_file_element] [NL] [end_source_files_mark] [NL] [NL]
end define

define graph
	[repeat graph_entry] [end_call_graph_marker] [NL]
end define

define graph_entry
	[id] [source_file_token] [source_file_element] [NL]
end define


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


define function_for_transplant
	[opt function_for_transplant_name] [NL] [NL] [repeat ids_with_line_break] [NL] [end_call_graph_marker] [NL] [NL] [NL] [NL] [NL]
end define

define function_for_transplant_name
	[stringlit]
end define










define variableDeclaration
	[decl_specifiers] [list init_declarator] [semi]
end define



















function main
	match [program]
			P[program]
	import TXLargs [repeat stringlit]
	deconstruct TXLargs
		first [stringlit] rest [repeat stringlit]
	export LineNumber [number]
		1
	
	
	construct theCallGraph [program]
		_ [read first] 
		
	deconstruct * [reverse_call_graph] theCallGraph
		 CallGraph [reverse_call_graph]
		
	construct newP [reverse_call_graph]
		CallGraph [constructNewGPFunctions]
end function





function constructNewGPFunctions
	replace [reverse_call_graph]
		P [reverse_call_graph]
		
		
	
	deconstruct * [reverse_call_graph] P
		CallGraphOfProgram [reverse_call_graph]
	
	deconstruct * [repeat graph] CallGraphOfProgram
		listOfCallGraphs [repeat graph]
	
	deconstruct listOfCallGraphs
		first [graph] rest [repeat graph]
		
	deconstruct * [repeat graph_entry] first
		ListOfGraphEntries [repeat graph_entry]
		
		
		
	%construct current function as a graph entry	
	deconstruct * [current_function] CallGraphOfProgram
		currentFunctionToken [current_function]
		
	construct currentFunctionTokenString [stringlit]
		_ [quote currentFunctionToken]
	construct lengthCFT [number]
		_ [# currentFunctionTokenString] [- 2]
	
	construct currentFunctionString [stringlit]
		currentFunctionTokenString [: 3 lengthCFT] [fput "CURRENTFCT.out"]
	construct currentFunctionID [id]
		_ [unquote currentFunctionString]
	construct SourceFileTok	[source_file_token] 
		'source_file:
	construct SourceFileElTok [source_file_element]	
		'@@graftFunct.c@@
	construct currentFctGraphEntry [graph_entry]
		currentFunctionID SourceFileTok SourceFileElTok 
		
		
		
		
	deconstruct ListOfGraphEntries
		firstEntry [graph_entry] calledEntries [repeat graph_entry]
	construct ListOfCalledEntries [repeat graph_entry]
		calledEntries [. currentFctGraphEntry]
				construct msmsss [repeat graph_entry]
			ListOfCalledEntries [fput "CURRENTFCT.out"]
		
	
	
	construct Candidate [repeat function_for_transplant]
		_ [writeACandidate ListOfGraphEntries ListOfCalledEntries] [print] [write "outputFCTLOCS!!!.out"]
	by
		P
		
end function

















function writeACandidate	ListOfGraphEntries [repeat graph_entry]
							ListOfCalledEntries [repeat graph_entry]
	replace [repeat function_for_transplant]
		current [repeat function_for_transplant]
	deconstruct ListOfGraphEntries
		first [graph_entry] rest [repeat graph_entry]
	%current called for marking in the formatted function
	deconstruct ListOfCalledEntries
		currentCalled [graph_entry] restCalled [repeat graph_entry]
	deconstruct * [id] currentCalled
		currentCalledID [id]
	construct currentCalledString [stringlit]
		_ [quote currentCalledID]
	deconstruct first
		fctName [id] srcToken [source_file_token] SourceFileName [source_file_element] 
	construct inputFileName [stringlit]
		_ [quote SourceFileName]
	construct path [stringlit]
		"input/"	
	construct lengthOfFileName [number]
		_ [# inputFileName] [- 2]
	construct inputFilNameNoMarks [stringlit]
		inputFileName [: 3 lengthOfFileName]
	construct CompleteFileName [stringlit]
		path [+ inputFilNameNoMarks] 
	construct nonIfDefsOutput [stringlit]
		CompleteFileName [+ "NON"]
	construct commandForNonIf [stringlit]
		_ [+"./ifdef.x "] [+ CompleteFileName] [+ " "] [+ CompleteFileName]  [+ " "] [+ "/home/alex/workspace/Transplants/"] [+ nonIfDefsOutput]
	construct CallCommand2 [id]
    	_ [system commandForNonIf]
	construct outputFileCompleteName [stringlit]
		_ [+ "/home/alex/workspace/Transplants/"] [+ nonIfDefsOutput]
	construct ProgramSource [repeat program]
		_ [read outputFileCompleteName] 
	deconstruct * [repeat function_definition_or_declaration] ProgramSource
		ProgramFunctions [repeat function_definition_or_declaration]
	construct StringFctName [stringlit]
		_ [quote fctName] 
	construct NeededFunction [repeat function_definition_or_declaration]
		ProgramFunctions [extractNeededFunction StringFctName]
	import FunctionDefinitionHost [function_definition_or_declaration]
	
	








	construct functionName [stringlit]
		StringFctName [fput "OUTPUTSYMBOLTABLE.out"]

	
    construct localAndGlobalSymbolTable [repeat declaration]
     	%_[symbolTableGlobalVars P] [constructLocalSymbolTable fuctUntilGraft] [write something]
     	_ [constructLocalSymbolTable FunctionDefinitionHost] [fput "OUTPUTSYMBOLTABLE.out"]
    construct Message [id]
        _ [message localAndGlobalSymbolTable] 	
     	construct msss [stringlit]
     		">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"
     		
     	construct endMarker [stringlit]
		msss [fput "OUTPUTSYMBOLTABLE.out"]	
     construct test [repeat declaration]
     	localAndGlobalSymbolTable [checkVariableDecl]	


	construct listOfBaseDeclarators [repeat base_declarator]
		_ [^ localAndGlobalSymbolTable] [fput "OUTPUTSYMBOLTABLE22.out"]
		
		
	construct listOfBaseDeclaratorsAsIDs[repeat id]
		_ [^ listOfBaseDeclarators] [fput "OUTPUTSYMBOLTABLE22.out"]

	construct newFunctionDefinition [function_definition_or_declaration]
		FunctionDefinitionHost [abstractAllId listOfBaseDeclaratorsAsIDs StringFctName] [fput "ABSTRACT_FUNCTIONS!.out"]
		
		
		
		

	by
		current %[. completeFunction]
		[writeACandidate rest restCalled]
end function

rule abstractAllId	ListOfIDs [repeat id]
					FctName [stringlit]
	replace $ [id]
		current [id]
	construct AbstractMarker [id]
		_ [unquote "@ABST"]
	construct FctNameId [id]
		_ [unquote FctName]
	construct finalIdReplacement [id]
		AbstractMarker [_ FctNameId] [_ current]
	where
		ListOfIDs [idInList current]
	by	
		finalIdReplacement
		
end rule


function idInList	CurrentId [id]
	match * [id]
		idFromList [id]
	where
		CurrentId [= idFromList]
end function


rule checkVariableDecl
	replace $ [ type_specifier]
		current [ type_specifier]
	
	construct msss [id]
		_ [message current]
	
	by
		current
end rule









	
%construct symbol table for globally defined variables
function symbolTableGlobalVars 	P [program]
    replace [repeat declaration]
        decl [repeat declaration]                 				
    deconstruct P
        First1 [function_definition_or_declaration] Rest1 [repeat function_definition_or_declaration] 
    construct NewProg [program]
    	Rest1
	construct newDeclList [repeat declaration]
		decl[constructdeclarationsFromDeclaration First1]
    by
      newDeclList
	  [symbolTableGlobalVars NewProg]
end function	


function constructdeclarationsFromDeclaration fctOrDecl [function_definition_or_declaration]
	replace [repeat declaration]
		listVar [repeat declaration]
	deconstruct fctOrDecl
		currentDecl [declaration]
	deconstruct currentDecl 
		DeclSpec [decl_specifiers] initDecl [list init_declarator] SemiColoumn [semi]
		
		
	construct currentVarDecl [ declaration]	
		DeclSpec initDecl SemiColoumn
		
	construct newDeclList [repeat declaration]
		listVar[addNextDecl currentVarDecl]
	by
		newDeclList
end function		
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
%construct symbol table for variables that are defined locally, in the body or the 
%head of the function that contains the target place
function constructLocalSymbolTable P [function_definition_or_declaration]
	replace [repeat declaration]
		P2 [repeat declaration]
	deconstruct * [function_definition] P
		justFunctionP [function_definition]
	construct AllIdsInit [repeat declaration]
		_ [^ justFunctionP] 
	construct AllIds [repeat declaration]
		_ [constructSeparatedDeclarationForEveyVar AllIdsInit]
	construct allIdsFunctionDeclaration [repeat argument_declaration]
		_ [^ justFunctionP] 
	%add function headers declarations!!!!
	construct justTest [repeat declaration]
		AllIds [argumentDeclToVariableDecl allIdsFunctionDeclaration]
	by
		P2 [. justTest]
end function


function constructSeparatedDeclarationForEveyVar listOfVar [repeat declaration]
	replace [repeat declaration]
		finalLstOfVar [repeat declaration]
	deconstruct listOfVar
        First1 [declaration] Rest1 [repeat declaration]
         
    construct newFinalLstOfVar [repeat declaration]
		finalLstOfVar [addNextDecl First1]
	by
		newFinalLstOfVar
	 	[constructSeparatedDeclarationForEveyVar Rest1]
end function





%(
function addNextDecl33 currentVarDecl [variableDeclaration]
	replace [repeat variableDeclaration]
		decl [repeat variableDeclaration]
	deconstruct   currentVarDecl
		specT [decl_specifiers] declT [list init_declarator] ';
    construct initialVars [repeat variableDeclaration]
    	_ [addVarIfJustDeclaration currentVarDecl] 	
    deconstruct specT
		repeatFromDecl [repeat decl_qualifier_or_type_specifier]
	construct testT [repeat decl_qualifier_or_type_specifier]
		_ [removeTypeSpecifiers repeatFromDecl]
	construct newVarDeclSpecifiers [decl_specifiers]
		testT
	construct allVars [repeat variableDeclaration]
		initialVars [allVariableDeclarationSeparedList newVarDeclSpecifiers declT ]
	by
		decl [. allVars]
end function
)%


%PROBLEM!!!
function addNextDecl currentVarDecl [declaration]
	replace [repeat declaration]
		decl [repeat declaration]
	deconstruct   currentVarDecl
		specT [decl_specifiers] declT [list init_declarator] ';
    construct initialVars [repeat declaration]
    	_  [addVarIfJustDeclaration currentVarDecl] 	
    deconstruct specT
		repeatFromDecl [repeat decl_qualifier_or_type_specifier]
	construct testT [repeat decl_qualifier_or_type_specifier]
		 repeatFromDecl %_ [removeTypeSpecifiers repeatFromDecl]
	construct newVarDeclSpecifiers [decl_specifiers]
		testT
	construct allVars [repeat declaration]
		initialVars [alldeclarationSeparedList newVarDeclSpecifiers declT ]
	by
		decl [. allVars]
end function
	
	
	

	
	
	
	
	
	
	
	
	
	
	
	
	
function addVarIfJustDeclaration	var [declaration]
	replace [repeat declaration]
		varDecl [repeat declaration]
		deconstruct   var
		specT [decl_specifiers] declT [list init_declarator] ';
		deconstruct specT
			repeatFromDecl [repeat decl_qualifier_or_type_specifier] 
		construct lengthOfRepeat [number]
			_ [length repeatFromDecl]
		construct lengthOfModifiers [number]
			lengthOfRepeat [- 1]
		construct varID [repeat decl_qualifier_or_type_specifier]
			repeatFromDecl [tail lengthOfRepeat]
		construct typesModifiers [repeat decl_qualifier_or_type_specifier]
			repeatFromDecl [head lengthOfModifiers]
		construct typesModifiersDeclSpec [decl_specifiers]
			typesModifiers
		deconstruct * [decl_qualifier_or_type_specifier] varID
			varIdEl [decl_qualifier_or_type_specifier]
		construct varStringlit [stringlit]
			_ [quote varIdEl]
		construct varIdAsID [id]
			_ [unquote varStringlit]
		construct varDeclsss [declarator]
			varIdAsID
		construct varInitDeclarator [init_declarator]
			varDeclsss
		construct varListInitDecl [list init_declarator]
			_ [, varInitDeclarator]
		construct varDeclaration [declaration]
			typesModifiersDeclSpec varListInitDecl '; 
		construct varDeclOut [stringlit]
			_ [quote varDeclaration] 
			construct checkTypes22 [declaration]
				varDeclaration [CheckAllTYPES]
		%needed for checking if not macro specifier in initial variable; otherwise it will be seen as declarator
		construct testT [repeat decl_qualifier_or_type_specifier]
			repeatFromDecl %_ [removeTypeSpecifiers repeatFromDecl]
		construct newVarDeclSpecifiers [decl_specifiers]
			testT	
		construct newVar [declaration]
			newVarDeclSpecifiers ';
	where not
		declT [hasDecl]
	where not
		newVar [checkForMacroSpecifier]
		construct declName [declaration]
			var [fput "HELLOO.out"]
			construct checkTypes [declaration]
				var [CheckAllTYPES]
	by
		varDecl [.varDeclaration]	
end function	




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
		
	construct FTT [unary_expression]
		ReturnValue

					construct mg3 [stringlit]
			finalMessage [fputs "dadada.out"]
	by
		express
end rule
	






rule checkForMacroSpecifier
	match [any]
		macroSpec [any]
	deconstruct * [macro_specifier]	macroSpec
		MSpec [macro_specifier]
end rule



%( function removeTypeSpecifiers	v1 [repeat decl_qualifier_or_type_specifier]
	replace [repeat decl_qualifier_or_type_specifier]
		varSpec [repeat decl_qualifier_or_type_specifier]
	deconstruct v1
		first [decl_qualifier_or_type_specifier] rest [repeat decl_qualifier_or_type_specifier] 

	construct finalDeclOrSpec [decl_qualifier_or_type_specifier]
		_ [addJustIfTypeSpec first]
	by
		varSpec [.finalDeclOrSpec]
		[removeTypeSpecifiers rest]
		
end function

function addJustIfTypeSpec	V1 [decl_qualifier_or_type_specifier]
	replace [decl_qualifier_or_type_specifier]
		declOrType [decl_qualifier_or_type_specifier]
	deconstruct  V1
		typeSpec [type_specifier]
	by
		V1
end function
)%


function hasDecl
	match * [list init_declarator]
		AS [init_declarator]
end function
 
	



function alldeclarationSeparedList	specifier [decl_specifiers]
											declList [list init_declarator]
	replace [repeat declaration]
		variableDeclList [repeat declaration]
	deconstruct * [init_declarator] declList
		First [init_declarator] 
	construct Rest [list init_declarator]
		declList [tail 2]	
	
	deconstruct * [declarator] First
		currentDeclarator [declarator]

	construct newVarDecl [declaration]
		specifier currentDeclarator ';
	by
		variableDeclList [. newVarDecl]
		[alldeclarationSeparedList specifier Rest]
end function
	
	
	
	
	

%(function isDeclaration
	match [function_definition_or_declaration]
		AS [declaration]
end function
	)%

%functions for adding variables from function header into declaration List	
function argumentDeclToVariableDecl argDecl [repeat argument_declaration]
	replace [repeat declaration]
		varDecl [repeat declaration]
	deconstruct argDecl
		first [argument_declaration] rest [repeat argument_declaration]	
	deconstruct first	
		declSpec [decl_specifiers] argDeclarator [opt argument_declarator]     	
	%construct declar [declaration]
		%declSpec   ';			
	%again, make this too [decl_specifiers] [list init_declarator] [semi], for easier extraction
		deconstruct declSpec
			repeatFromDecl [repeat decl_qualifier_or_type_specifier] 
		construct lengthOfRepeat [number]
			_ [length repeatFromDecl]
		construct lengthOfModifiers [number]
			lengthOfRepeat [- 1]
		construct varID [repeat decl_qualifier_or_type_specifier]
			repeatFromDecl [tail lengthOfRepeat][fput "createVarDecl.out"]
		construct typesModifiers [repeat decl_qualifier_or_type_specifier]
			repeatFromDecl [head lengthOfModifiers] [fput "createVarDecl.out"]
		construct typesModifiersDeclSpec [decl_specifiers]
			typesModifiers
		deconstruct * [decl_qualifier_or_type_specifier] varID
			varIdEl [decl_qualifier_or_type_specifier]
		construct varStringlit [stringlit]
			_ [quote varIdEl]
		construct varIdAsID [id]
			_ [unquote varStringlit]
		construct varDeclsss [declarator]
			varIdAsID
		construct varInitDeclarator [init_declarator]
			varDeclsss
		construct varListInitDecl [list init_declarator]
			_ [, varInitDeclarator]
		construct varDeclaration [declaration]
			typesModifiersDeclSpec varListInitDecl '; 	
	construct FinalDeclar [declaration]
		varDeclaration [variableFromArgWithOpt first]		
	by
		varDecl [. FinalDeclar]
		[argumentDeclToVariableDecl rest]
end function
	
	
function variableFromArgWithOpt Arg [argument_declaration]
	replace [declaration]
		var [declaration]
	deconstruct Arg	
		declSpec [decl_specifiers] argDeclarator [opt argument_declarator]
	deconstruct declSpec
		repeatFromDecl [repeat decl_qualifier_or_type_specifier]
		
	construct testT [repeat decl_qualifier_or_type_specifier]
		repeatFromDecl % _ [removeTypeSpecifiers repeatFromDecl]
		
	construct newVarDeclSpecifiers [decl_specifiers]
		testT
	deconstruct *[declarator] argDeclarator
		declForArg [declarator]
	construct initDeclForLst [init_declarator]
		declForArg
	construct declar [declaration]
		newVarDeclSpecifiers declForArg  ';
	by
		declar
end function


























































function extractNeededFunction	FctName [stringlit]
	match * [function_definition_or_declaration]
		current [function_definition_or_declaration]
	
	
	
	construct currentFct [id]
		_ [deconstructFunctionDefinition current] 
		
	construct currentFctString [stringlit]
		_ [quote currentFct]
	where
		currentFct [= FctName]
		export FunctionDefinitionHost [function_definition_or_declaration]
			current
end function


function deconstructFunctionDefinition currentFctDef [function_definition_or_declaration]
	replace [id]
		_ [id]
	deconstruct * [function_definition] currentFctDef
			justFunct [function_definition]
		deconstruct * [function_header] justFunct
			fctHeader [function_header]
		deconstruct * [opt KR_parameter_decls] justFunct
			fctKR [opt KR_parameter_decls]	
				deconstruct * [compound_statement] justFunct
			fctStatement [compound_statement]
		deconstruct * [compound_statement_body] fctStatement
			fctStatementBody [compound_statement_body]
		construct fctStatementWithoutPreprocessor [compound_statement]
			{ fctStatementBody }
		construct functionWithoutPreprocessor [function_definition]
			fctHeader fctKR fctStatementWithoutPreprocessor 
		deconstruct fctHeader
			spec [opt decl_specifiers] decl [declarator] ext[function_declarator_extension] 
		construct stringFromDecl [stringlit]
			_ [quote decl]
		construct IDFromDecl [id]
			_ [unquote stringFromDecl]
	by
		IDFromDecl
end function
