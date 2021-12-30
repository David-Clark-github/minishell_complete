# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dclark <dclark@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/28 14:52:07 by dclark            #+#    #+#              #
#    Updated: 2021/12/30 12:46:32 by dclark           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	srcs/add_lst_bck.c \
			srcs/print_lst.c \
			srcs/check_error_quotes.c \
			srcs/parsing2.c \
			srcs/expension.c \
			srcs/tab_to_list.c \
			srcs/ft_strjoin.c \
			srcs/ft_separ.c \
			srcs/ft_strlen.c \
			srcs/ft_isalpha.c \
			srcs/ft_echo.c \
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
