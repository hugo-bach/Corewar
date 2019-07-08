##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile of my project lemin
##

MAIN 			= 	main

NAME			=	asm

ROOT			=	.

INCLUDE			= 	include

CC				= 	gcc
RM 				= 	rm
FIND			=	find

TYPE 			=	.c
TYPE_COR		=	.cor
TYPE_VALGRIND	=	vgcore.
WILD_CARD		=	*

SRC_DIR			=	$(addprefix $(ROOT)/, src)

BUILD			=	$(ROOT)/obj

SRC_PREFIX 		= 	$(addprefix $(SRC_DIR)/, $(SRC_FILES))
SRC				= 	$(addsuffix $(TYPE), $(SRC_PREFIX))
OBJS			=	$(patsubst $(SRC_DIR)/%.c, $(BUILD)/%.o, $(SRC))

SRC_FILES		=	convert_base		\
					my_strdup			\
					name				\
					delete_comment		\
					my_macro_name		\
					my_strlen			\
					open_file			\
					write_core			\
					my_strcat			\
					name_core			\
					my_strcmp			\
					my_line_startwith	\
					mnemonic_to_int		\
					header_parsing		\
					get_magic_nbr		\
					op					\
					get_nb_inst 		\
					my_word_is_present	\
					get_params_nbr		\
					get_params_type		\
					singleton_label		\
					create_label		\
					write_error			\
					endswith			\
					my_str_to_tab		\
					my_atoi				\
					label_tools			\
					it_end_by_i			\
					instruction			\
					get_type 			\
					get_params 			\
					get_value_bytes		\
					value_bytes_tools	\
					instruction_invalid	\
					check_params		\
					get_typesnbr		\
					my_str_endwith		\
					calc_prog_size		\
					get_label_index		\
					my_strlen_array		\
					check_word			\
					write_on_byte		\
					skip_tools			\
					get_value_instr		\
					$(MAIN)

WARN			=	-W -Wall -Wpedantic $(WERROR)

WERROR			= 	-Werror

LDFLAGS 		=	-g3

CFLAGS			=	-I $(ROOT)/$(INCLUDE) $(WARN)

DEBUG 			= 	@


#COLORS

GREEN 			=	\e[1;32m
WHITE			=	\e[0m
ORANGE			=	\e[1;33m
RED				=	\e[1;31m
BLUE			=	\e[1;34m
YELLOW			=	\e[1;93m


all:				$(NAME)

$(NAME):			echo_start $(BUILD)/$(NAME)
					$(DEBUG)cp $(BUILD)/$(NAME) $(ROOT)
					$(DEBUG)printf "$(GREEN)Successful to copy binary into root directory.\n$(WHITE)"

$(BUILD)/$(NAME):	$(OBJS)
					$(DEBUG)printf "$(ORANGE)Compile sources.$(WHITE)\n"
					$(DEBUG)$(CC) -o $(BUILD)/$(NAME) $(OBJS) $(LDFLAGS)
					$(DEBUG)printf "$(ORANGE)Start link obj and libraries.$(WHITE)\n"

$(BUILD)/%.o:		$(SRC_DIR)/%.c
					$(DEBUG)printf "$(ORANGE)Compiling$(WHITE)[$(YELLOW)$(notdir $<)$(WHITE)]$(RED)->$(WHITE)[$(YELLOW)$(notdir $@)$(WHITE)]\n"
					$(DEBUG)$(CC) -o $@ -c $< $(CFLAGS) $(LDFLAGS)

echo_start:
					$(DEBUG)mkdir -p $(BUILD)
					$(DEBUG)printf "$(RED)Start the compilation:\n$(WHITE)"

clean:
					$(DEBUG)$(RM) -rf $(OBJS)
					$(DEBUG)$(RM) -rf $(BUILD)
					$(DEBUG)$(RM) -rf $(TYPE_VALGRIND)$(WILD_CARD)
					$(DEBUG)printf "$(ORANGE)Delete all valgrind files.$(WHITE)\n"
					$(DEBUG)printf "$(ORANGE)Delete object files.$(WHITE)\n"

fclean:	clean
					$(DEBUG)$(RM) -f $(BUILD)/$(NAME)
					$(DEBUG)$(RM) -f $(ROOT)/$(NAME)
					$(DEBUG)printf "$(ORANGE)Removing binary file.$(WHITE)\n"

re:					fclean
					$(DEBUG)make --no-print-directory all

.PHONY: clean fclean all re echo_start
