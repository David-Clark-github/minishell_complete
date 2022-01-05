# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dclark <dclark@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/28 14:52:07 by dclark            #+#    #+#              #
#    Updated: 2022/01/05 17:43:35 by dclark           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	parsing/add_lst_bck2.c \
			parsing/print_lst.c \
			parsing/check_error_quotes.c \
			parsing/parsing2.c \
			parsing/expension.c \
			parsing/quotes_exp.c \
			parsing/tab_to_list.c \
			parsing/ft_strjoin.c \
			parsing/ft_strljoin.c \
			parsing/ft_separ2.c \
			parsing/ft_strlen.c \
			parsing/ft_isalpha.c \
			builtins/ft_echo.c \
			builtins/ft_pwd.c \
			builtins/extract_lst.c \
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
