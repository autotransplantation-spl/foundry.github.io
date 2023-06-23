include "cOriginal.grm"




%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%This program will add the identified interface to the Host Source Code								 %	
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%GRAMMAR DEFINITIONS

define addGraft
	__ADDGRAFTHERE__JUSTHERE [NL]
	|	[not interfaceFunction] [repeat declaration_or_statement]
	|	[not interfaceFunction] [function_definition]
end define

define interfaceFunction
	__INTERFACE_FUNCTION [NL]
end define

define declaration_or_statement_markers
	[declaration_or_statement] 
	| [stringlit] [NL]
end define

redefine declaration_or_statement
	[declaration] 
    |	[statement] 
    |	[addGraft]
    |	[interfaceFunction]
#ifdef PREPROCESSOR
    |	[preprocessor]
#endif
#ifdef GNU
    |	[function_definition]  
#endif
#ifdef MACROS
    |	[macro_declaration_or_statement]
#endif
    |	[unknown_declaration_or_statement]
end redefine

redefine function_definition_or_declaration
	[function_definition]  
    |	[declaration] 
	|	[interfaceFunction]
	|	[addGraft]

#ifdef PREPROCESSOR
    |	[preprocessor]
#endif
    |	[compound_statement] [NL]	% sometimes, function headers are ifdefed out
#ifdef GNU
    |	[macro_declaration_or_statement]
#endif
    |	[unknown_declaration_or_statement]
end redefine

define decl_specifiers_and_declarator
	[decl_specifiers] [declarator]
end define

%END GRAMMAR DEFINITIONS
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%



%transformation rules
function main
    replace [program]
        P [program]
    import TXLargs [repeat stringlit]
	construct separeSign [stringlit]
		 "%"
	deconstruct  TXLargs
		 PathToGraft [stringlit] NewHostOutput [stringlit] InterfaceOutput [stringlit] InterfaceHeaderFileName [stringlit] 
	export PathToGraft
    construct P2 [program]
    	_[read PathToGraft] 
    deconstruct * [compilation_unit] P2
    	compUnit [compilation_unit]	
    deconstruct compUnit
    	functionsAndDeclFromGraft [repeat function_definition_or_declaration]
	deconstruct * [compilation_unit] P
    	compUnitHost [compilation_unit]
    deconstruct compUnitHost
    	functionsAndDeclFromHost [repeat function_definition_or_declaration]
   	construct functionsNoGraftFromDonor [repeat function_definition_or_declaration]
   		_ [returnFunctionWithNoGraftFromDonor functionsAndDeclFromGraft] [write InterfaceOutput]	
   		
    construct NewP [program]
        P [insertGraftInFunction] 
    deconstruct * [repeat function_definition_or_declaration] NewP
    	newProgDecl [repeat function_definition_or_declaration]
	construct includeMark[stringlit]
		"#include"
	%InterfaceHeaderFileName
	construct TransplantHeaderFile [stringlit]
		includeMark [+ " \""] [+ InterfaceHeaderFileName] [+ "\""]
	construct preprocLineTransplantHeader [preprocessor_line]
		_ [unquote TransplantHeaderFile]
	construct preprocTransplantHeader [preprocessor]
		preprocLineTransplantHeader
	construct TransplantHeaderDeclaration [repeat function_definition_or_declaration]
		preprocTransplantHeader    
    construct NewProgrammWithGraftInclude [repeat function_definition_or_declaration]
    	%TransplantHeaderDeclaration [.newProgDecl]	
    	_ [. newProgDecl]
    construct outputNewProg [repeat function_definition_or_declaration]
    	NewProgrammWithGraftInclude [write NewHostOutput]
   	construct outputNewProg2 [repeat function_definition_or_declaration]
    	NewProgrammWithGraftInclude %[print]
    by
        NewProgrammWithGraftInclude
end function 


function isAGraft
    match  [function_definition_or_declaration]
        AS [addGraft]
end function


function returnFunctionWithNoGraftFromDonor	V1 [repeat function_definition_or_declaration]
	replace [repeat function_definition_or_declaration]
		P[repeat function_definition_or_declaration]
	deconstruct V1 
		first [function_definition_or_declaration] rest [repeat function_definition_or_declaration]
	construct functionWithGraft [function_definition_or_declaration]
		_ [returnNonGraftFctFromGraft first]
	by
		P [. functionWithGraft]
		[returnFunctionWithNoGraftFromDonor rest]
end function


function returnNonGraftFctFromGraft	V1 [function_definition_or_declaration]
	replace [function_definition_or_declaration]
		current [function_definition_or_declaration]
	deconstruct V1
		fctDef [function_definition_or_declaration]
	where not	
		V1[containsAGraft] 
	by	
		V1
end function


function insertGraftInFunction
	replace * [addGraft]
		G [addGraft]
	%only apply this function if the graft is: __ADDGRAFTHERE__JUSTHERE
	%otherwise it was already replaced as a function
	deconstruct * G
		__ADDGRAFTHERE__JUSTHERE
	by
	 G [addTheGraftInFunction]
end function


function addTheGraftInFunction
	replace [addGraft]
		myGraft [addGraft]		
	import PathToGraft [stringlit]	
    construct P2 [program]
               _[read PathToGraft]    
    deconstruct * [compilation_unit] P2
    	compUnit [compilation_unit]
    deconstruct compUnit
    	functionsAndDeclFromGraft [repeat function_definition_or_declaration]
    
    construct functionWithG [repeat function_definition_or_declaration]
    	_ [returnFunctionWithGraftFromDonor functionsAndDeclFromGraft]
    deconstruct * [function_definition] functionWithG
    	fct_body [function_definition]    
    deconstruct fct_body
        headerG [function_header] paramDeclsG [opt KR_parameter_decls] statementCompG [compound_statement] 
    deconstruct * [compound_statement_body] statementCompG
        body [compound_statement_body] 
    deconstruct body
    	listFromBody [repeat declaration_or_statement] 
   	construct  listWithoutReturn [repeat declaration_or_statement]
   		listFromBody  [removeGraftSign]
	by 
		listWithoutReturn
end function

function removeGraftSign
    replace * [addGraft]
		_ [addGraft]
    by 
end function


function returnFunctionWithGraftFromDonor	V1 [repeat function_definition_or_declaration]
	replace [repeat function_definition_or_declaration]
		P[repeat function_definition_or_declaration]
	deconstruct V1 
		first [function_definition_or_declaration] rest [repeat function_definition_or_declaration]
	construct functionWithGraft [function_definition_or_declaration]
		_ [returnGraftPlace first]
	by
		P [. functionWithGraft]
		[returnFunctionWithGraftFromDonor rest]
end function


function returnGraftPlace	V1 [function_definition_or_declaration]
	replace [function_definition_or_declaration]
		_ [function_definition_or_declaration]
	deconstruct V1
		fctDef [function_definition_or_declaration]
	where 
		V1[containsAGraft]
	by	
		V1
end function


function containsAGraft
    match * [declaration_or_statement]
        AS [addGraft]
end function