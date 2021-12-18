# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dclark <dclark@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/28 14:52:07 by dclark            #+#    #+#              #
#    Updated: 2021/12/18 18:34:29 by david            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	srcs/add_lst_bck.c \
			srcs/print_lst.c \
			srcs/check_error_quotes.c \
			srcs/parsing.c \
			srcs/expension.c \
			main.c

HEADER	=includes/

NAME	= minishell

OBJS	= $(SRCS:.c=.o)

CFLAGS	+=	-Wall -Werror -Wextra -I $(HEADER)

CC		= gcc

#%.o: %.c
#	$(CC) -c $(CFLAGS) -o $@ $< -I $(HEADER)

all:	$(NAME)

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re:		fclean
	make

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -lreadline

.PHONY: all clean fclean re
