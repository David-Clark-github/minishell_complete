/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 12:59:08 by dclark            #+#    #+#             */
/*   Updated: 2022/01/06 13:19:18 by david            ###   ########.fr       */
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

//log:
//	1 = COMMAND
//	2 = redirection
//	3 = string


typedef struct s_lst {
	struct s_lst	*next;
	char			*str;
	int				log;
	int				iter;
}t_lst;

typedef struct	s_parsing {
	char	*prompt;
	char	*exp;
	char	**tab_separ;
	int		tab_len;
	t_lst	*list;
	int		error_num;
}				t_pars;

//	check_error_quotes return 1 on success(did not find an error*) 0 if error
t_lst	*parsing(t_pars *pars);
char	*expension(char *prompt, int *error_num);
char	*quotes_exp(char *str);
int		check_error_quotes(char *prompt);
void	add_lst_back(t_lst **head, char *str, int log, int iter);
void	print_lst(t_lst **head);
char	*ft_strjoin(char *str_1, char *str_2);
char	*ft_strljoin(char *s1, char *s2, int s2_len);
char	**ft_separ(char *str, int *tk_len);
int		ft_strlen(char *str);
int		ft_isalpha(int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		extract_lst(t_lst *list);

//BUILTINS
int		ft_echo(char *str, int arg);
int		ft_pwd(int fd);

//DO NOT USE [tab] FOR PARAMETER NAME
//term.h USES IT

t_lst	*tab_to_list(char **tabx);
#endif
