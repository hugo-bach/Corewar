	.name "Abelt"
	.comment "L'amer noir."

	sti r1, :hji, %1

hji:	live %234
	ld %0, r3
	zjmp %:hji
    ld %1, r2
