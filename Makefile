# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dclark <dclark@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/28 14:52:07 by dclark            #+#    #+#              #
#    Updated: 2022/01/12 16:07:57 by dclark           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	parsing/add_lst_bck2.c \
			parsing/print_lst.c \
			parsing/check_error_quotes.c \
			parsing/parsing2.c \
			parsing/expension.c \
			parsing/quotes_exp.c \
			parsing/tab_to_list.c \
			parsing/ft_separ2.c \
			parsing/extract_lst.c \
			utils/ft_copy_env.c \
			utils/ft_strjoin.c \
			utils/ft_strljoin.c \
			utils/ft_strdup.c \
			utils/ft_strlen.c \
			utils/ft_tablen.c \
			utils/ft_isalpha.c \
			utils/ft_strncmp.c \
			utils/ft_strcmp.c \
			builtins/ft_echo.c \
			builtins/ft_pwd.c \
			builtins/ft_env.c \
			builtins/ft_export.c \
			signal/take_signal.c \
			main.c

HEADER	=includes/

NAME	= minishell

OBJS	= $(SRCS:.c=.o)

CFLAGS	+=	-Wall -Werror -Wextra -I $(HEADER) #-ggdb3

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
