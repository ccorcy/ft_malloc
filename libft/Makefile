# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccorcy <ccorcy@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/20 15:48:39 by ccorcy            #+#    #+#              #
#    Updated: 2018/05/06 17:42:00 by ccorcy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCS = ./ft_abs.c \
		./ft_atoi.c \
		./ft_atol.c \
		./ft_strappend.c \
		./ft_bzero.c \
		./ft_isalnum.c \
		./ft_isalpha.c \
		./ft_isascii.c \
		./ft_isdigit.c \
		./ft_isprint.c \
		./ft_isspace.c \
		./ft_itoa.c \
		./ft_lstadd.c \
		./ft_lstdel.c \
		./ft_lstdelone.c \
		./ft_lstiter.c \
		./ft_lstlen.c \
		./ft_lstmap.c \
		./ft_lstnew.c \
		./ft_memalloc.c \
		./ft_memccpy.c \
		./ft_memchr.c \
		./ft_memcmp.c \
		./ft_memcpy.c \
		./ft_memdel.c \
		./ft_memmove.c \
		./ft_memset.c \
		./ft_print_err.c \
		./ft_putchar.c \
		./ft_putchar_fd.c \
		./ft_putendl.c \
		./ft_putendl_fd.c \
		./ft_putnbr.c \
		./ft_putnbr_fd.c \
		./ft_putstr.c \
		./ft_putstr_fd.c \
		./ft_strcat.c \
		./ft_strchr.c \
		./ft_strclr.c \
		./ft_strcmp.c \
		./ft_strcpy.c \
		./ft_strdel.c \
		./ft_strdup.c \
		./ft_strequ.c \
		./ft_striter.c \
		./ft_striteri.c \
		./ft_strjoin.c \
		./ft_strlcat.c \
		./ft_strlen.c \
		./ft_str_arr_length.c \
		./ft_strmap.c \
		./ft_strmapi.c \
		./ft_strncat.c \
		./ft_strncmp.c \
		./ft_strncpy.c \
		./ft_strnequ.c \
		./ft_strnew.c \
		./ft_strnstr.c \
		./ft_strrchr.c \
		./ft_strsplit.c \
		./ft_strstr.c \
		./ft_strsub.c \
		./ft_strtrim.c \
		./ft_free_split.c \
		./ft_tolower.c \
		./ft_toupper.c \
		./get_next_line.c
OBJS = $(SRCS:.c=.o)
FLAGS = -Wall -Werror -Wextra
all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "\x1B[34mLib compiled\x1B[0m"

.c.o:
	@echo "\x1B[34mCompiling\x1B[0m" $< "\x1B[34m->\x1B[0m" $@ "\x1B[0m"
	@gcc -c $< -o $@ $(FLAGS)

clean:
	@rm -f $(OBJS)
	@echo "\x1B[31mCleaning...\x1B[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\x1B[31mMinishell deleted\x1B[0m"

re: fclean all

.PHONY: all clean fclean re
