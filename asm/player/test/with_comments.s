# comment1
# comment2
# comment 
.name "zork"
.comment "I'M ALIIIIVE" # another comment
        #           l
# label1

l2:		sti r1, %:live, %0
        ldi 3, %4, r1 # why not
        sti r2, %0, r3
# label2

live:	live %1
		zjmp %:live

# end of the program
