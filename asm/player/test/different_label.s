.name "zork"
.comment "I'M ALIIIIVE"

label1:		sti r1, %:label2, %0
        ldi 3, %4, r1
        sti r2, %0, r3

label2:	live %1
		zjmp %:label2
