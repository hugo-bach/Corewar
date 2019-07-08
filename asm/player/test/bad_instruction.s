.name "zork"
.comment "I'M ALIIIIVE"

l2:		sti r1, %:live, %0
        ldi 3, %4, r1
        mov r2, %0, r3

live:	live %1
		zjmp %:live
