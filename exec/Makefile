# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/24 15:09:38 by seciurte          #+#    #+#              #
#    Updated: 2022/03/09 18:12:10 by seciurte         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	cmd_path.c \
			pipeline.c \
			here_doc.c \
			redir.c \
			pipe.c \
			redir_utils.c \
			pids.c \
			get_instruct_type.c \
			exec.c \
			../utils/ft_strdup.c \
			../utils/ft_strlen.c \
			../utils/ft_strcmp.c \
			../parsing/add_lst_bck2.c \
			../parsing/diff_cmd_redir.c \
			../parsing/print_lst.c \
			../utils/ft_strlcpy.c \
			../utils/ft_split.c \
			../utils/ft_memset.c \
			../utils/ft_strncmp.c \
			../utils/ft_strljoin.c \
			../utils/ft_isalpha.c \

HEADER	= ../includes/

NAME	= macroshell

OBJS	= $(SRCS:.c=.o)

CFLAGS	+=	-Wall -Werror -Wextra -I $(HEADER) -g -fsanitize=undefined
CC		= clang

all:	$(NAME)

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re:		fclean
	make

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -lreadline

.PHONY: all clean fclean re