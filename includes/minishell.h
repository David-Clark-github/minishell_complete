/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 12:59:08 by dclark            #+#    #+#             */
/*   Updated: 2022/03/12 20:35:16 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

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
# include <errno.h>

//[tgetent] [tgetflag] [tgetnum] [tgetstr] [tgoto] [tputs]
# include <curses.h>
# include <term.h>

//RESERVED TOKENS
# define BECHO 1
# define CD 2
# define PWD 3
# define EXPORT 4
# define UNSET 5
# define ENV 6
# define EXIT 7
# define INPUT 8
# define TRUNC 9
# define HEREDOC 10
# define APPEND 11
# define PIPE 12

//BASH PARSING ERRORS
# define UNEXPECTED_TOKEN "Minishell: syntax error near unexpected token `"

typedef struct	s_lst {
	struct s_lst	*next;
	char			*str;
	int				log;
	int				iter;
}				t_lst;

typedef struct s_parsing {
	char	*prompt;
	char	*exp;
	char	**tab_separ;
	int		tab_len;
	t_lst	*list;
	int		error_num;
}				t_pars;

typedef struct s_pids
{
	pid_t				pid;
	struct s_pids		*next;
}				t_pids;

typedef struct s_minishell {
	char	**cp_ev;
	int		er_num;
	char	*prompt;
	char	*exp;
	char	**tab_separ;
	int		tab_len;
	int		io_fds_redir[2];
	int		unused_fds[2];
	t_pids	*pids;
	char	**path;
	char	*buffer;
	t_lst	*list;
}				t_mini;

//PARSING
void	parsing(t_mini *mini);
char	*expension(t_mini *mini, int *error_num);
char	*ft_getenv(char *name, char **cp_ev);
char	*quotes_exp(char *str);
int		check_error_quotes(char *prompt, int *er);
void	add_lst_back(t_lst **head, char *str, int log, int iter);
void	print_lst(t_lst **head);
char	**ft_separ(char *str, int *tk_len);
int		extract_lst(t_lst *list);
int		check_tab(char **tab_separ);
int		check_cmd(char **tab_separ);
int		check_syntax(t_mini *mini);
int		diff_cmd_redir(char *str);
int		diff_cmd(char *str);
int		diff_redir(char *str);

//BUILTINS
int		ft_echo(char *str, int arg, int fd);
int		ft_pwd(int fd);
int		ft_env(char **tab_env, int fd);
int		ft_export(char *name, char *data, char ***tab_env);
int		ft_unset(char *name, char ***tab_env);
int		ft_cd(char *path);

//ARG_BUILTIN
void	arg_export(char **tabx, t_mini *mini);
void	arg_unset(char **tabx, t_mini *mini);

//UTILS
int		ft_strlen(char *str);
int		ft_tablen(char **tableau);
int		ft_isalpha(int c);
char	*ft_strdup(char *s);
char	*ft_itoa(int n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strjoin(char *str_1, char *str_2);
char	*ft_strljoin(char *s1, char *s2, int s2_len);
char	**ft_copy_env(char **tab_env, size_t add);
void	ft_freetab(char **tabx);
void	init_mini(t_mini *mini);
void	ft_free_mini(t_mini *mini, int i);
int		ft_checkredir(char c);
int		ft_checkquote(char c);
int		ft_checkcara(char c, char *str);
t_mini	*get_mini(void);
char	**ft_split(char *s, char c);
size_t	ft_strlcpy(char *dst, char *src, size_t size);
void	*ft_memset(void *s, int c, size_t n);

//INSTRUCTION TYPES
int		is_redir_stdin(int log);
int		is_redir_stdout(int log);
int		is_cmd(int log);
int		is_redir(int log);

//GET PATH AND CMDS PATH
char	**get_path(char **env);
char	*get_cmd_path(char **path, char *cmd);
void	free_path(char **path);

//PIPELINE
void	free_pipeline(int **pipeline);
int		get_nb_of_pipes(t_lst *lst);
int		**create_pipeline(t_lst *lst);

//HEREDOC
void	heredoc(t_mini *mini, t_lst *lst);

//REDIRECTIONS
void	redirect_heredoc(t_mini *mini, t_lst *lst);
void	redirect_input(t_mini *mini, t_lst *lst);
void	redirect_stdout(t_mini *mini, t_lst *lst);

//PIPES
void	redirect_pipe_stdin(t_mini *mini, int **pipeline, int *pipe_index);
void	redirect_pipe_stdout(t_mini *mini, int **pipeline, int *pipe_index);

//REDIRECTION UTILS
t_lst	*skip_redir(t_lst *lst);
void	redirections(t_mini *mini, t_lst *lst, int **pipeline, int *pipe_index);

//PIDS
t_pids	*create_pid(void);
void	add_pid_to_pids(t_mini *mini, t_pids *pid);
void	wait_for_forks(t_mini *mini);
void	free_pids(t_pids **pids);

//TMP FUNCTIONS
void	exit_error(int line);

//ERRORS IN EXEC
void	internal_error(t_mini *mini);

//EXEC
void	exec_instructions(t_mini *mini);

//EXEC ERRORS
void	error_unexpected_token(t_mini *mini, char *token);
int		check_errors_before_exec(t_mini *mini);

//DO NOT USE THE NAME "tab" FOR PARAMETER NAME
//term.h USES IT

t_lst	*tab_to_list(char **tabx, int tk_len);

//TEST
void	take_signal(void);
#endif
