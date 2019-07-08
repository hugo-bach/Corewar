##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile of my project lemin
##

MAIN 			= 	main

NAME			=	corewar

ROOT			=	.

INCLUDE			= 	include

INSTRUCTIONS	=	instructions
UTILS			= 	utils
SINGLETON		=	singleton

CC				= 	gcc
RM 				= 	rm
FIND			=	find

TYPE 			=	.c
TYPE_VALGRIND	=	vgcore.
WILD_CARD		=	*

SRC_DIR			=	$(addprefix $(ROOT)/, sources)

BUILD			=	$(ROOT)/build

SRC_PREFIX 		= 	$(addprefix $(SRC_DIR)/, $(SRC_FILES))
SRC				= 	$(addsuffix $(TYPE), $(SRC_PREFIX))
OBJS			=	$(patsubst $(SRC_DIR)/%.c, $(BUILD)/%.o, $(SRC))

SRC_FILES		=	find_dump								\
					nb_prog									\
					number_allready_used					\
					parsing									\
					convert_base							\
					hex_dump								\
					display_dump							\
					open_file								\
					name_finder								\
					display_help							\
					virtual_machine							\
					op										\
					mem_operations							\
					get_params_value						\
					win										\
					get_prog_infos							\
					struct_sorter							\
					find_parsing_values						\
					display_ncurse							\
					free_mem								\
					registre								\
					pc_sorting								\
					$(UTILS)/my_strcmp						\
					$(UTILS)/my_strdup						\
					$(UTILS)/write_error					\
					$(UTILS)/my_str_endwith					\
					$(UTILS)/my_strlen						\
					$(UTILS)/my_atoi						\
					$(UTILS)/my_put_nbr						\
					$(UTILS)/my_putstr						\
					$(SINGLETON)/singleton_prog				\
					$(INSTRUCTIONS)/launch_instruction		\
					$(INSTRUCTIONS)/ldi_instruction			\
					$(INSTRUCTIONS)/st_instruction			\
					$(INSTRUCTIONS)/sti_instruction			\
					$(INSTRUCTIONS)/ld_instruction			\
					$(INSTRUCTIONS)/live_instruction		\
					$(INSTRUCTIONS)/zjmp_instruction		\
					$(INSTRUCTIONS)/lld_instruction			\
					$(INSTRUCTIONS)/lldi_instruction		\
					$(INSTRUCTIONS)/add_instruction			\
					$(INSTRUCTIONS)/sub_instruction			\
					$(INSTRUCTIONS)/and_instruction			\
					$(INSTRUCTIONS)/or_instruction			\
					$(INSTRUCTIONS)/xor_instruction			\
					$(INSTRUCTIONS)/aff_instruction			\
					$(INSTRUCTIONS)/create_instruction		\
					$(INSTRUCTIONS)/check_instruction		\
					$(INSTRUCTIONS)/get_instruction_nbr		\
					$(INSTRUCTIONS)/special_instruction		\
					$(INSTRUCTIONS)/fork_instructions		\
					$(MAIN)

WARN			=	-W -Wall -Wpedantic $(WERROR)

WERROR			= 	-Werror

LDFLAGS 		=	-g3 -lncurses -lpthread

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

create_folder:		
					$(DEBUG)mkdir -p $(BUILD)
					$(DEBUG)mkdir -p $(BUILD)/$(INSTRUCTIONS)
					$(DEBUG)mkdir -p $(BUILD)/$(UTILS)
					$(DEBUG)mkdir -p $(BUILD)/$(SINGLETON)

echo_start:			create_folder
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
