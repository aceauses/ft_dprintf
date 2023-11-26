# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aceauses <aceauses@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/17 09:47:04 by aceauses          #+#    #+#              #
#    Updated: 2023/07/29 12:53:35 by aceauses         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:
NAME = libftprintf.a
CC = cc
FLAGS = -Wall -Werror -Wextra
AR= ar rcs
SRC= ft_printf.c \
	 ft_putchar.c \
	 ft_putstr.c \
	 ft_print_hex.c \
	 ft_put_ptr.c \
	 ft_putnmbr.c \
	 ft_putnmbr_un.c \

BOLD    := \033[1m./SRC/
RED     := \033[31;1m
GREEN   := \033[32;1m
YELLOW  := \033[33;1m
BLUE    := \033[34;1m
MAGENTA := \033[35;1m
CYAN    := \033[36;1m
WHITE   := \033[37;1m
RESET	= \x1b[0m

OBJS=$(SRC:.c=.o)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

$(OBJS):
	$(CC) -c $(FLAGS) $(SRC)

all: $(NAME)
	@echo "$(CYAN)[Printf] $(GREEN)Library Compiled$(RESET)"

clean:
	rm -f $(OBJS)
	@echo "$(CYAN)[Printf] $(RED)Objects Cleaned$(RESET)"

fclean:
	rm -f $(NAME) $(OBJS)
	@echo "$(CYAN)[Printf] $(RED)Library, Objects Cleaned$(RESET)"

re: fclean all

.PHONY: libft all clean fclean re
