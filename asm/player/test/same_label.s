.name "zork"
.comment "I'M ALIIIIVE"

test:		sti r1, %:test, %0
        ldi 3, %4, r1
        sti r2, %0, r3

test:	live %1
		zjmp %:test
