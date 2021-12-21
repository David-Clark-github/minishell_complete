/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 12:59:08 by dclark            #+#    #+#             */
/*   Updated: 2021/12/21 09:59:47 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

//[readline] [rl_clear_history] [rl_on_new_line] [rl_replace_line]
//[rl_redisplay] [add_history]
# include <readline/readline.h>
# include <readline/history.h>

//[strerror]
# include <string.h>

//[printf] [perror]
# include <stdio.h>

//[malloc] [free] [getenv]
# include <stdlib.h>

//[ioctl] 
# include <sys/ioctl.h>

//[write] [access] [read] [close] [exit] [getcwd] [chdir] [unlink] [execve]
//[dup] [dup2] [pipe] [isatty] [ttyname] [ttyslot] [tcgetattr]
# include <unistd.h>
# include <termios.h>

//[open] [fork] [waitpid] [wait3/4] [siganl] [stat] [lstat] [fstat]
//[kill] [opendir] [readdir] [closedir]
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <signal.h>
# include <dirent.h>
# include <sys/time.h>
# include <sys/resource.h>
# include <sys/wait.h>

//[tgetent] [tgetflag] [tgetnum] [tgetstr] [tgoto] [tputs]
# include <curses.h>
# include <term.h>

typedef struct s_lst	t_lst;

//log:
//	1 = COMMAND
//	2 = redirection
//	3 = string

struct s_lst {
	t_lst	*next;
	int		log;
	char	*str;
};

//	check_error_quotes return 1 on success(did not find an error*) 0 if error
int		check_error_quotes(char *prompt);
void	add_lst_back(t_lst **head, char *str, int log);
void	print_lst(t_lst **head);
char	*parsing(char *prompt, int *error_num);
char	*expension(char *buffer, int *error_num);
char	*ft_strjoin(char *str_1, char *str_2);
char	**ft_separ(char *str, char c);
int		ft_strlen(char *str);
int		ft_echo(char *str, int argument);

#endif
