tokens
	%commentIn	"/\*[(\\\n)(\"#[\"\n]*\")(/\*#[(\*/)]*\*/)#n]*\*/"
	%anything	"[(\\\n)(\"#[\"\n]*\")(/\*#[(\*/)]*\*/)#n]*"
	commentIn 	"/\*#(\*/)*\*/"
end tokens







define program
	[repeat commentIn]
end define


function main
	match [program]
		P [program]
end function
