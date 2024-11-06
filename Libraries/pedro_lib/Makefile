# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pgrellie <pgrellie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/14 12:20:45 by apintus           #+#    #+#              #
#    Updated: 2024/10/31 18:43:06 by pgrellie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	ft_isalpha.c\
		ft_issigns.c\
		ft_isdigit.c\
		ft_isspace.c\
		ft_isalnum.c\
		ft_isascii.c\
		ft_isprint.c\
		ft_issigns.c\
		ft_tolower.c\
		ft_toupper.c\
		ft_strlen.c\
		ft_memset.c\
		ft_bzero.c\
		ft_memcpy.c\
		ft_memmove.c\
		ft_strlcpy.c\
		ft_strcat.c\
		ft_strlcat.c\
		ft_toupper.c\
		ft_tolower.c\
		ft_strchr.c\
		ft_strrchr.c\
		ft_strcmp.c\
		ft_strncmp.c\
		ft_memchr.c\
		ft_memcmp.c\
		ft_strnstr.c\
		ft_atoi.c\
		ft_atol.c\
		ft_calloc.c\
		ft_realloc.c\
		ft_strcpy.c\
		ft_strdup.c\
		ft_substr.c\
		ft_strjoin.c\
		ft_strtrim.c\
		ft_split.c\
		ft_itoa.c\
		ft_strmapi.c\
		ft_striteri.c\
		ft_putchar_fd.c\
		ft_putstr_fd.c\
		ft_putendl_fd.c\
		ft_putnbr_fd.c\

BONUS =	ft_lstnew.c\
		ft_lstadd_front.c\
		ft_lstsize.c\
		ft_lstlast.c\
		ft_lstadd_back.c\
		ft_lstdelone.c\
		ft_lstclear.c\
		ft_lstiter.c\
		ft_lstmap.c\
		
GNL = get_next_line.c\
		get_next_line_utils.c\
		
PRINTF = ft_printf.c\
		ft_putptr.c\
		ft_putunbr.c\
		ft_utils.c\

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(BONUS:.c=.o)

OBJS_GNL = $(GNL:.c=.o)

OBJS_PRINTF = $(PRINTF:.c=.o)

CC = gcc
RM = rm -rf
AR = ar rc
RN = ranlib
CFLAGS = -Wall -Wextra -Werror

NAME = libpedro_lib.a

all : $(NAME)

$(NAME) :
	$(CC) $(CFLAGS) -c $(SRCS) $(GNL) $(PRINTF)
	$(AR) $(NAME) $(OBJS) $(OBJS_GNL) $(OBJS_PRINTF)
	$(RN) $(NAME)

bonus : $(OBJS_BONUS)
		$(AR) $(NAME) $(OBJS_BONUS)

clean :
	@$(RM) $(OBJS) $(OBJS_BONUS) $(OBJS_GNL) $(OBJS_PRINTF)

fclean : clean
	@$(RM) $(NAME)

re : fclean all

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRCS) $(BONUS) &(GNL) &(PRINTF)
	gcc -nostartfiles -shared -o libft.so $(OBJS) $(OBJS_BONUS) &(OBJS_GNL) &(OBJS_PRINTF)
	
.PHONY: all fclean clean re
