# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pgrellie <pgrellie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/18 14:56:45 by pgrellie          #+#    #+#              #
#    Updated: 2024/09/12 15:59:25 by pgrellie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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
SRCS_FILES = $(shell find $(SRCS_DIR) -name '*.c')

SRCS = $(addprefix $(SRCS_DIR), $(SRCS_FILES))			

##########################################################
######  OBJECTS  ######

OBJS_FILES = $(patsubst $(SRCS_DIR)%.c, $(OBJS_DIR)%.o, $(SRCS_FILES))
OBJS = $(addprefix $(OBJS_DIR), $(OBJS_FILES))

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
	@echo "$(EPIX_GREEN)⣇⠈⠉⡿⢿⠉⠁⢸$(GREEN)	/    Y    \|   |/    |    \|   | /        \\     Y    /|        \|    |___ |    |___ 	$(EPIX_GREEN)⣇⠈⠉⡿⢿⠉⠁⢸$(NORMAL)"
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