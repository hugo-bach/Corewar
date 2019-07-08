##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## makefile as root
##

ASM				=	asm
COREWAR			=	corewar

ROOT			=	.

COPY			=	cp
RM				= 	rm
FLAGS			=	-rf

FLAGS_COMPIL	=	-C
FLAGS_CLEAN		=	clean
FLAGS_FCLEAN	=	fclean
FLAGS_DEBUG		=	--no-print-directory

ALL				=	all
DEBUG			= 	@
COMPIL			=	make

#COLORS

GREEN 			=	\e[1;32m
WHITE			=	\e[0m
ORANGE			=	\e[1;33m
RED				=	\e[1;31m
BLUE			=	\e[1;34m
YELLOW			=	\e[1;93m

all:
				$(DEBUG) printf "$(YELLOW)===============================================\n"
				$(DEBUG) printf "$(ORANGE)Projet CPE_corewar_2018 binary : $(RED)$(ASM)\n$(WHITE)"
				$(DEBUG) $(COMPIL) $(FLAGS_DEBUG) $(FLAGS_COMPIL) $(ROOT)/$(ASM)
				$(DEBUG) printf "$(YELLOW)===============================================\n"
				$(DEBUG) printf "$(ORANGE)Projet CPE_corewar_2018 binary : $(RED)$(COREWAR)\n$(WHITE)"
				$(DEBUG) $(COMPIL) $(FLAGS_DEBUG) $(FLAGS_COMPIL) $(ROOT)/$(COREWAR)

clean:
				$(DEBUG) printf "$(RED)Delete binary:\n$(WHITE)"
				$(DEBUG) printf "$(BLUE)asm deleting\n"
				$(DEBUG) $(COMPIL) $(FLAGS_DEBUG) $(FLAGS_CLEAN) $(FLAGS_COMPIL) $(ROOT)/$(ASM)
				$(DEBUG) printf "$(BLUE)corewar deleting\n$(WHITE)"
				$(DEBUG) $(COMPIL) $(FLAGS_DEBUG) $(FLAGS_CLEAN) $(FLAGS_COMPIL) $(ROOT)/$(COREWAR)

fclean:
				$(DEBUG) printf "$(RED)Execute make fclean ASM\n$(WHITE)"
				$(DEBUG) $(COMPIL) $(FLAGS_DEBUG) $(FLAGS_FCLEAN) $(FLAGS_COMPIL) $(ROOT)/$(ASM)
				$(DEBUG) printf "$(RED)\nExecute make fclean COREWAR\n$(WHITE)"
				$(DEBUG) $(COMPIL) $(FLAGS_DEBUG) $(FLAGS_FCLEAN) $(FLAGS_COMPIL) $(ROOT)/$(COREWAR)

re:				fclean
				$(DEBUG) $(COMPIL) $(FLAGS_DEBUG) $(ALL)

.PHONY:	all clean fclean re
