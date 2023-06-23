include "c.grm"


function main
    match [program]
        P [program]
    construct OldProg [program]
    	P

    construct CallCommand [id]
    	_ [system "./SourceContent input"]

	construct ListOfExistingSourceFiles [repeat stringlit]
		_ [read "output.out"]
        construct Message [id]
    	_ [message ListOfExistingSourceFiles]


end function 



%S1 [pipe S2]