# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lucavall <lucavall@student.42firenze.it    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/06 13:21:29 by lucavall          #+#    #+#              #
#    Updated: 2023/12/05 14:08:43 by lucavall         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# --VARIABLES--
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
LIBC		= ar -rcs
NAME		= libftprintf.a
RM			= rm -rf
SRC			= ft_printf.c ft_utils.c
SRC_OBJ		= $(SRC:.c=.o)

# --RULES--
%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

all: $(NAME)

$(NAME): $(SRC_OBJ)
	$(LIBC) $(NAME) $(SRC_OBJ)

clean:
	$(RM) *.o

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
