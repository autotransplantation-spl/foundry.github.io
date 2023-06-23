


%redefine upper_macro_name
%   [upperlowerid] 
%end redefine


%redefine label
%	[EX] [label_id] ': [IN] 
%    |   [EX][SP][SP] 'case [constant_expression] ': [IN] 
%    |   [EX][SP][SP] 'default ': [IN] 
%#ifdef GNU
%    |   [EX][SP][SP] 'case [constant_expression] [SP] '... [SP] [constant_expression] ': [IN]    
%#endif
%end redefine



%include "CNoComments.grm"

include "cOriginal.grm"




function main
    replace [program]
        P [program]
        
        
   %construct tP [program]
    %	P [CheckAllTYPES]
    
    %import TXLargs [repeat stringlit]
    
    %deconstruct * [stringlit] TXLargs
    %	programPath [stringlit]
    	
    %construct newP [program]
    	%_ [removeIFDefs programPath "/home/alex/Development/GenTransRepo/feature-transplant/ResearchProject/GenTransTXLSourceCode/ifdef.x"]
    
    %construct newProg [program]
    	%P [CheckAllTYPES]
    
   construct outputNewP [program]
    	P 
    
    
    %construct NewP [program]
        %P [replaceSimpleStatement]
    by
       P %newProg
end function 



rule compoundStmAddBracketsAtOnlyOneStm
	replace $ [sub_statement]
		stn [statement]
	construct newCompoundStmBody [compound_statement_body]
		stn
	construct newCompoundStm [compound_statement]
		{ newCompoundStmBody }
	construct newCompSubStm [sub_statement]
		newCompoundStm
	by
		newCompSubStm
end rule


function removeIFDefs	ProgramPath [stringlit]
						fixIfDefProg [stringlit]
	
	replace [program]
		P [program]
	construct nonIfDefsOutput [stringlit]
		ProgramPath [+ "NON"]					
	construct commandForNonIf [stringlit]
		_ [+ fixIfDefProg] [+ " "] [+ ProgramPath] [+ " "] [+ ProgramPath]  [+ " "]  [+ nonIfDefsOutput]
	construct CallCommand2 [id]
    	_ [system commandForNonIf]
	construct outputFileCompleteName [stringlit]
		_ [+ nonIfDefsOutput]
	construct ProgramSource [program]
		_ [read outputFileCompleteName]
		
	by
		ProgramSource
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




%(

rule replaceSimpleStatement
	replace $ [function_definition]
		myF [function_definition]

    deconstruct myF
    	header [function_header] paramDecls [opt KR_parameter_decls] statementComp [compound_statement]
    	
   	deconstruct * [compound_statement_body] statementComp
        body [compound_statement_body] 
    
    deconstruct * [declaration_or_statement] body
        myGraft [addGraft] 
    
    deconstruct body
    	listFromBody [repeat declaration_or_statement]
    
    construct newStatementBody [repeat declaration_or_statement]
     	%null initially
    construct finalVersionHope [repeat declaration_or_statement]
     	newStatementBody [removeAddGraftLine listFromBody]
     	
     construct finalCompund [compound_statement_body]
     	finalVersionHope
     
     construct finalCompStatement [compound_statement]
     	'{ finalCompund '}
        
        
    construct finalFctDef [function_definition]
    	header paramDecls finalCompStatement
        
	by
		finalFctDef
end rule


function removeAddGraftLine V1[repeat declaration_or_statement]
	
	replace [repeat declaration_or_statement]
        returnValue [repeat declaration_or_statement]
	deconstruct V1
        First1 [declaration_or_statement] Rest1 [repeat declaration_or_statement]
        
   construct newFirst [repeat declaration_or_statement]
     	%null initially
	construct finalFirst [repeat declaration_or_statement]
		newFirst [addDeclOrState2 First1] [addFinallyTheGraft First1]

    by
      returnValue [. finalFirst]
	  returnValue [removeAddGraftLine Rest1]
end function


function addFinallyTheGraft decl [declaration_or_statement]
	replace [repeat  declaration_or_statement]
		_[repeat  declaration_or_statement]
		
	construct something [stringlit]
		"/Users/margineanalexandru/Documents/workspace/Transplants/input/stringLength.c"

    construct P2 [program]
               _[read something]
               
   % construct normalizedP2 [program]
    %	P2 [normalize]
               
    deconstruct P2
        fct_body [function_definition]
        
    deconstruct fct_body
        headerG [function_header] paramDeclsG [opt KR_parameter_decls] statementCompG [compound_statement]
        
    deconstruct * [compound_statement_body] statementCompG
        body [compound_statement_body] 
    
    deconstruct body
    	listFromBody [repeat declaration_or_statement] 

   construct  listWithoutReturn [repeat declaration_or_statement]
   		listFromBody [removeReturn]
    	
		
	
	where
		decl [containsAGraft]
	by 
		listWithoutReturn
end function

rule normalize
	replace [id] 
		Id [id]
	deconstruct not Id
		'x
	by
		'x
end rule

function removeReturn
    replace * [jump_statement]
		_ [jump_statement]
    by
          
end function


function addDeclOrState2 decl [declaration_or_statement]
	replace [repeat declaration_or_statement]
		_[repeat declaration_or_statement]
	where not
		decl [containsAGraft]
	by
		decl
end function

function containsAGraft
    match [declaration_or_statement]
        AS [addGraft]
end function
)%

