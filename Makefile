# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/28 14:52:07 by dclark            #+#    #+#              #
#    Updated: 2022/03/19 13:40:58 by dclark           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	parsing/add_lst_bck2.c \
			parsing/print_lst.c \
			parsing/check_error_quotes.c \
			parsing/parsing2.c \
			parsing/check_tab.c \
			parsing/check_cmd.c \
			parsing/diff_cmd_redir.c \
			parsing/check_syntax.c \
			parsing/expension.c \
			parsing/tab_to_list.c \
			parsing/ft_separ2.c \
			parsing/ft_separ_utils.c \
			parsing/init_token.c \
			parsing/num_of_element.c \
			parsing/extract_lst.c \
			parsing/ft_getenv.c \
			utils/ft_copy_env.c \
			utils/ft_strjoin.c \
			utils/ft_strljoin.c \
			utils/ft_strdup.c \
			utils/ft_strlen.c \
			utils/ft_tablen.c \
			utils/ft_isalpha.c \
			utils/ft_isdigit.c \
			utils/ft_itoa.c \
			utils/ft_strncmp.c \
			utils/ft_strcmp.c \
			utils/ft_freetab.c \
			utils/init_mini.c \
			utils/ft_free_mini.c \
			utils/get_mini.c \
			utils/ft_checkredir.c \
			utils/ft_checkquote.c \
			utils/ft_checkcara.c \
			utils/ft_check_echo_arg.c\
			utils/ft_check_exit_format.c \
			utils/ft_split.c \
			utils/ft_memset.c \
			utils/ft_strlcpy.c \
			utils/ft_memcpy.c \
			utils/my_strjoin.c \
			utils/ft_putnbr_fd.c \
			utils/ft_putstr_fd.c \
			utils/ft_putchar_fd.c \
			utils/ft_atoi.c \
			builtins/ft_echo.c \
			builtins/ft_pwd.c \
			builtins/ft_cd.c \
			builtins/ft_env.c \
			builtins/ft_export.c \
			builtins/take_data_name.c \
			builtins/ft_check_export_format.c \
			builtins/ft_unset.c \
			builtins/ft_exit.c \
			exec/cmd_path.c \
			exec/pipeline.c \
			exec/here_doc.c \
			exec/redir.c \
			exec/pipe.c \
			exec/redir_utils.c \
			exec/pids.c \
			exec/get_instruct_type1.c \
			exec/get_instruct_type2.c \
			exec/exec_utils.c \
			exec/exec_builtin1.c \
			exec/exec_builtin2.c \
			exec/exec_bin.c \
			exec/exec.c \
			exec/check_errors_before_exec.c \
			exec/exec_errors/unexpected_token.c \
			exec/exec_errors/redir_error.c \
			signal/take_signal.c \
			main.c

HEADER	=includes/

NAME	= minishell

OBJS	= $(SRCS:.c=.o)

CFLAGS	+=	-Wall -Werror -Wextra -I $(HEADER) -g -fsanitize=address

CC		= gcc

all:	$(NAME)

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re:		fclean
	@make

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -lreadline

.PHONY: all clean fclean re
