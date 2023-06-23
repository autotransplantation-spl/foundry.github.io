tokens
	water "<#(>)*>"
	%water2 "\(#(\))*\)"
	recursion_mark "\(R\)"
end tokens



%"begin commenting.#(end commenting.)*end comment"


define program
	[repeat function_entry]
end define

%"<"[^>]*>

define function_entry
	[id]'(') [opt water] [opt recursion_in_called_fct] [opt recursion_mark] [opt ':]
end define

% (recursive: see 72)

define recursion_in_called_fct
	'( [id] ': [id] [number]    ')
end define

function main
	match [program]
		P [program]
	
	deconstruct P
		list_of_function_entries [repeat function_entry]
	
	construct list_of_ids [repeat id]
		_ [construct_list_of_id list_of_function_entries] [print] [write "FUNCTIONFINALLIST.out"]

end function


function construct_list_of_id	P [repeat function_entry]
	replace [repeat id]
		currentList [repeat id]
	deconstruct P
		first [function_entry] rest [repeat function_entry]	
	
	deconstruct * [id] first
		currentID [id]
		
	
	by
		currentList [. currentID]
		[construct_list_of_id rest]	
end function

