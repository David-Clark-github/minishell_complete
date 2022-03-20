/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 12:59:08 by dclark            #+#    #+#             */
/*   Updated: 2022/03/20 00:59:35 by seciurte         ###   ########.fr       */
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
# define HEREDOC_EOF1 "Minishell: here-document"
# define HEREDOC_EOF2 " delimited by end-of-file (wanted `"
# define CORE_DUMP "Quit (core dumped)\n"
# define WRITE_ERR "write error: no space left on device"

# define MAXUPRC 4

extern int	g_err_num;

typedef struct s_lst {
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
	int		**pipeline;
	int		heredoc_sigint;
	t_lst	*list;
}				t_mini;

//PARSING
void	parsing(t_mini *mini);
void	expension(t_mini *mini);
char	*ft_getenv(char *name, char **cp_ev);
int		check_error_quotes(char *prompt);
void	add_lst_back(t_lst **head, char *str, int log, int iter);
void	print_lst(t_lst **head);
char	**ft_separ(char *str, int *tk_len);
void	simple_q(int *i_str, int *i_dest, char *str, char **dest);
void	double_q(int *i_str, int *i_dest, char *str, char **dest);
void	zero_cara(int *i_str, int *i_dest, char *str, char **dest);
void	one_cara(int *i_str, int *i_dest, char *str, char **dest);
void	one_pipe(int *i_str, int *i_dest, char *str, char **dest);
void	init_token(char **token, int len);
int		num_of_element(char *str);
int		extract_lst(t_lst *list);
int		check_tab(char **tab_separ);
int		check_cmd(char **tab_separ);
int		check_syntax(t_mini *mini);
int		diff_cmd_redir(char *str);
int		diff_cmd(char *str);
int		diff_redir(char *str);

//BUILTINS
int		ft_echo(char **str, int arg, int fd);
int		ft_pwd(int fd);
int		ft_env(char **tab_env, int fd);
int		ft_export(char **str, char ***tab_env);
void	take_data_name(char **name, char **data, char *str);
int		ft_unset(char **name);
int		ft_cd(char *path);
int		ft_exit(int num);

//ARG_BUILTIN
void	arg_unset(char **tabx, t_mini *mini);

//UTILS
int		ft_strlen(const char *str);
int		ft_tablen(char **tableau);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
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
int		ft_check_echo_arg(char **cmd);
int		ft_check_export_format(char *str);
//int		ft_check_exit_format(char *str);
int		ft_check_export_error(char *str);
t_mini	*get_mini(void);
char	**ft_split(char *s, char c);
size_t	ft_strlcpy(char *dst, char *src, size_t size);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*my_strjoin(char *s1, char *s2);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
int		ft_atoi(const char *nptr);

//INSTRUCTION TYPES
int		is_redir_stdin(int log);
int		is_redir_stdout(int log);
int		is_cmd(int log);
int		is_redir(int log);
int		is_builtin(int log);
int		is_arg_and_redir(int log);

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
t_lst	*skip_redir_and_args(t_lst *lst);
void	redirections(t_mini *mini, t_lst *lst, int **pipeline, int *pipe_index);

//PIDS
t_pids	*create_pid(void);
void	add_pid_to_pids(t_mini *mini, t_pids *pid);
void	wait_for_forks(t_mini *mini);
void	free_pids(t_pids **pids);

//ERRORS IN EXEC
void	internal_error(t_mini *mini);

//EXEC
int		get_nb_of_args(t_lst *lst);
char	**get_args(t_lst *lst);
void	exec_cd(t_mini *mini, t_lst *lst);
void	exec_echo(t_mini *mini, t_lst *lst);
void	exec_env(t_mini *mini);
void	exec_export(t_mini *mini, t_lst *lst);
void	exec_pwd(t_mini *mini);
void	exec_unset(t_mini *mini, t_lst *lst);
void	exec_builtin(t_mini *mini, t_lst *lst);
void	exec_instructions(t_mini *mini);
void	dup_and_close_in_fork(t_mini *mini);
void	close_out_fork(t_mini *mini);
void	exec_bin(t_mini *mini, t_lst *lst, t_pids *pid);
void	free_in_exec(void);

//EXEC ERRORS
void	error_unexpected_token(char *token);
int		check_errors_before_exec(t_mini *mini);
void	redir_error(char *token);
void	error_exec_bin(char *token);
void	heredoc_eof_error(char *token);
void	error_code_fork(void);
void	nb_arg_error(char *token);
void	fatal_error(void);
void	arg_error(char *token);
void	arg_format_error(char *token);

//DO NOT USE THE NAME "tab" FOR PARAMETER NAME
//term.h USES IT

t_lst	*tab_to_list(char **tabx, int tk_len);

//SIGNAL
void	default_sig(void);
void	custom_sig(void);
void	heredoc_sig(int sig);
#endif
