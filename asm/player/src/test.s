.name "zork"
.comment "I'M ALIIIIVE"

l2:		sti r1, %:live, %1
        ldi m3, %4, r1

live:	live %1
        ld 1, r4
		zjmp %:live
