# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbonini- <fbonini-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/27 16:20:03 by fbonini           #+#    #+#              #
#    Updated: 2021/10/05 15:34:08 by fbonini-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a
CC			= clang
RM			= rm -f
FLAGS		= -Wall -Wextra -Werror -g
LIBS		= libft.h
INCLUDES	=./
OBJ			= ft_memset.o ft_bzero.o \
		ft_memcpy.o ft_memccpy.o \
		ft_memmove.o ft_memchr.o \
		ft_memcmp.o ft_strlen.o \
		ft_strlcpy.o ft_strlcat.o \
		ft_strchr.o ft_strrchr.o \
		ft_strnstr.o ft_strncmp.o \
		ft_atoi.o ft_isalpha.o \
		ft_isdigit.o ft_isalnum.o \
		ft_isascii.o ft_isprint.o \
		ft_toupper.o ft_tolower.o \
		ft_calloc.o ft_strdup.o \
		ft_substr.o ft_strjoin.o \
		ft_strtrim.o ft_split.o \
		ft_itoa.o ft_strmapi.o \
		ft_putchar_fd.o ft_putstr_fd.o \
		ft_putendl_fd.o ft_putnbr_fd.o

BONUS		= ft_lstnew.o ft_lstadd_front.o ft_lstsize.o \
			  ft_lstlast.o ft_lstadd_back.o ft_lstdelone.o \
			  ft_lstclear.o ft_lstiter.o ft_lstmap.o

all: $(NAME) $(BONUS)

$(NAME): $(OBJ)
	ar rcs $@ $^

%.o: %.c $(LIBS)
	$(CC) $(FLAGS) -I$(INCLUDES) $< -c -o $@

clean:
	$(RM) $(OBJ) $(BONUS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

bonus: $(OBJ) $(BONUS)
	ar rsc $(NAME) $^

.PHONY: all clean fclean re