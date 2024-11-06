# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/18 14:56:45 by pgrellie          #+#    #+#              #
#    Updated: 2024/11/06 15:23:30 by acarpent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#$(shell find $(SRCS_DIR) -name '*.c')
#########################################################
# TERMINAL COLORS OP ##

NORMAL = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m
EPIX_WHITE = \033[5;97m
EPIX_GREEN = \033[5;92m
EPIX_RED = \033[5;91m

##########################################################
##### FOLDERS PATH ####

SRCS_DIR = ./srcs_mandatory/
SRCS_BONUS_DIR = ./srcs_bonus/
OBJS_DIR = ./Objs/
LIBS_DIR = ./Libraries/
BIN_DIR = ./bin/
HEADER_DIR = ./Includes/

#########################################################
###### ARGUMENTS ######

NAME = $(BIN_DIR)minishell
CFLAGS = -Wall -Werror -Wextra -g -g3
LDFLAGS = -lpedro_lib -lreadline
COMP = cc
RM = rm -rf
MKDIR = mkdir -p

##########################################################
### LIBRARIES PATH ####

LIBFT_DOSS = $(LIBS_DIR)pedro_lib/
LIBFT_MAKE_COMMAND = make -s -C $(LIBFT_DOSS) --no-print-directory
LIBFT_PATH = $(LIBFT_DOSS)pedro_lib.a

##########################################################
###### INCLUDES  ######

INCLUDES = -I $(LIBFT_PATH)
PATH_OF_THE_LIBS = -L $(LIBFT_DOSS)

##########################################################
######  SOURCES  ######
SRCS_FILES = Builtins/builtins.c\
				Builtins/cd.c\
				Builtins/echo.c\
				Builtins/env.c\
				Builtins/exitt.c\
				Builtins/export_utils2.c\
				Builtins/export_utils.c\
				Builtins/export.c\
				Builtins/pwd.c\
				Builtins/unset.c\
				Environnement/env_utils.c\
				Environnement/Initialisation.c\
				Environnement/the_env.c\
				Environnement/create_env.c\
				Exec/the_exec/cmd_exec_in_child.c\
				Exec/the_exec/cmd_path.c\
				Exec/the_exec/execution_utils2.c\
				Exec/the_exec/execution_utils.c\
				Exec/the_exec/execution.c\
				Exec/the_exec/file_opener_utils.c\
				Exec/the_exec/file_opener.c\
				Exec/the_parsing/ch_list_cmdline.c\
				Exec/the_parsing/ch_list_redirs.c\
				Exec/the_parsing/init_n_assign.c\
				Exec/the_parsing/parsing_utils.c\
				Exec/the_parsing/parsing.c\
				Expands/dr_kron.c\
				Expands/expands_functions.c\
				Expands/expands_utils.c\
				Expands/malloc_calculator.c\
				Expands/the_expander.c\
				Here_doc/here_doc_utils3.c\
				Here_doc/here_doc_utils_2d.c\
				Here_doc/here_doc_utils.c\
				Here_doc/here_doc.c\
				Lexer/lexing.c\
				Lexer/token_chlist_functions.c\
				Lexer/token_type_settings.c\
				Lexer/token_utils.c\
				Pre_parser/forbiden_chars_checker.c\
				Pre_parser/full_checker.c\
				Pre_parser/quote_checker.c\
				Pre_parser/shit_checker_1.c\
				Pre_parser/token_checker.c\
				Signals/ctrl_backslash.c\
				Signals/ctrl_c.c\
				Zmain_functions/minishell.c\
				Zmain_functions/the_programm.c\

SRCS = $(addprefix $(SRCS_DIR), $(SRCS_FILES))			

##########################################################
######  OBJECTS  ######

OBJS_FILES = $(patsubst $(SRCS_DIR)%.c, $(OBJS_DIR)%.o, $(SRCS))

##########################################################
######   RULES   ######

all: $(NAME)
	
$(NAME) : $(OBJS_DIR) $(OBJS_FILES)
	@echo "$(GREEN)\n<<< Done >>>\n$(NORMAL)"
	@echo "$(YELLOW)\nBuilding project ...\n$(NORMAL)"
	@$(MKDIR) $(BIN_DIR)
	@$(LIBFT_MAKE_COMMAND)
	@$(COMP) $(CFLAGS) $(OBJS_FILES) -o $(NAME) $(PATH_OF_THE_LIBS) $(LDFLAGS)
	@echo "$(GREEN)\n<<< [MINISHELL] has been compiled >>>\n" 
	@echo "$(EPIX_WHITE)                   /!\/!\/!\/!\/!\/!\ \n$(NORMAL)" 
	@echo "$(WHITE) Use this command : ./bin/minishell\n$(NORMAL)"
	
#Creer le repertoire 'Objs' et compiles C source files into object files
$(OBJS_DIR):
	@echo "$(RED)=================================================================================================================$(NORMAL)"
	@echo "$(EPIX_RED)// // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // //$(NORMAL)"
	@echo "$(RED)=================================================================================================================$(NORMAL)"
	@echo "$(EPIX_GREEN)⠀⢀⣠⣤⣤⣄⡀⠀$(GREEN)	   _____    ___  _______    ___   _________  ___ ___ ___________ ____      ____     	$(EPIX_GREEN)⠀⢀⣠⣤⣤⣄⡀⠀$(NORMAL)"
	@echo "$(EPIX_GREEN)⣴⣿⣿⣿⣿⣿⣿⣦$(GREEN)	  /     \  |   | \      \  |   | /   _____/ /   |   \\_   _____/ |    |    |    |    	$(EPIX_GREEN)⣴⣿⣿⣿⣿⣿⣿⣦$(NORMAL)"
	@echo "$(EPIX_GREEN)⣿⣿⣿⣿⣿⣿⣿⣿$(GREEN)	 /  \ /  \ |   | /   |   \ |   | \_____  \ /    ^    \|    __)  |    |    |    |    	$(EPIX_GREEN)⣿⣿⣿⣿⣿⣿⣿⣿$(NORMAL)"
	@echo "$(EPIX_GREEN)⣇⠈⠉⡿⢿⠉⠁⢸$(GREEN139)	/    Y    \|   |/    |    \|   | /        \\     Y    /|        \|    |___ |    |___ 	$(EPIX_GREEN)⣇⠈⠉⡿⢿⠉⠁⢸$(NORMAL)"
	@echo "$(EPIX_GREEN)⠙⠛⢻⣷⣾⡟⠛⠋$(GREEN)	\____|__  /|___|\____|__  /|___|/_______  / \___|_  //_______  /|_______ \|_______ \	$(EPIX_GREEN)⠙⠛⢻⣷⣾⡟⠛⠋$(NORMAL)"
	@echo "$(EPIX_GREEN)⠀⠀⠀⠈⠁⠀⠀⠀$(GREEN)	        \/              \/              \/        \/         \/         \/        \/	$(EPIX_GREEN)⠀⠀⠀⠈⠁⠀⠀⠀$(NORMAL)"
	@echo "$(RED)=================================================================================================================$(NORMAL)"
	@echo "$(EPIX_RED)// // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // //$(NORMAL)"
	@echo "$(RED)=================================================================================================================$(NORMAL)"
	@echo "$(YELLOW)\nProcessing c files into o files ...\n$(NORMAL)"
	@$(MKDIR) $(OBJS_DIR)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@$(MKDIR) $(dir $@)
	@$(COMP) $(CFLAGS) -I $(HEADER_DIR) -c $< -o $@

#Clean objects files and dependencies
clean:
	@$(RM) $(OBJS_DIR) $(OBJS_BONUS_DIR)
	@make clean -C $(LIBFT_DOSS) --no-print-directory
	@echo "$(MAGENTA)\n<<< Object files have been removed >>>\n$(NORMAL)"

#Cleans everething generated by the Makefile
fclean: clean
	@$(RM) $(NAME) $(BIN_DIR) $(OBJS_DIR)
	@make fclean -C $(LIBFT_DOSS) --no-print-directory
	@echo "$(MAGENTA)\n<<< Executable files, object files and Directories have been removed >>>\n$(NORMAL)"

#Remake	
re: fclean all

.PHONY: all clean fclean re libpedro_lib