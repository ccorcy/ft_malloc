# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccorcy <ccorcy@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/07 13:04:16 by ccorcy            #+#    #+#              #
#    Updated: 2018/05/09 23:06:56 by ccorcy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifeq ($(HOSTTYPE), )
	HOSTTYPE :=  $(shell uname -m)_$(shell uname -s)
endif

SRCDIR = srcs
OBJDIR = objs

MALLOC_NAME = libft_malloc_$(HOSTTYPE).so
NAME = main
SRCS = $(SRCDIR)/main.c $(SRCDIR)/free.c $(SRCDIR)/init_page.c \
		$(SRCDIR)/malloc.c $(SRCDIR)/page_size.c $(SRCDIR)/realloc.c \
		$(SRCDIR)/utils.c
OBJS = $(patsubst $(SRCDIR)/%, $(OBJDIR)/%, $(SRCS:.c=.o))
FLAGS = -Wall -Werror -Wextra

all: $(NAME)

main: $(OBJS)
	@make -C libft/
	@gcc $(FLAGS) $(OBJS) -Llibft/ -lft -I includes -o main
	@gcc $(FLAGS) $(OBJS) -shared -Llibft -lft -I includes -o $(MALLOC_NAME)
	@echo "sources compiled"

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	@gcc $(FLAGS) -c $< -o $@ 
	@echo $< " -> " $@
clean:
	@make -C libft/ clean
	@rm -f $(OBJS)
	@rm -rf $(OBJDIR)
	@echo "cleaning"

fclean: clean
	@make -C libft/ fclean
	rm -f main
	@echo "main deleted"

re: fclean all

.PHONY: all clean fclean re
