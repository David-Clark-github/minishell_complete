/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 14:55:31 by seciurte          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/03/09 19:37:37 by seciurte         ###   ########.fr       */
=======
/*   Updated: 2022/03/15 19:31:13 by seciurte         ###   ########.fr       */
>>>>>>> master
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <sys/errno.h>

void	exit_error(int line)
{
	dprintf(2, "Error at line %d\n", line);
	dprintf(2, "%s\n", strerror(errno));
	exit(EXIT_FAILURE);
}

/*
************************************************************************************************************************************************************************************************************************************************
************************************************************************************************************************************************************************************************************************************************
************************************************************************************************************************************************************************************************************************************************
*/

int	is_builtin(int log)
{
	return (log >= BECHO && log <= EXIT);
}

<<<<<<< HEAD
void	free_cmd(char **cmd)
{
	int		i;

	i = 0;
	while (cmd[i])
	{
		free(cmd[i]);
		i++;
	}
	free(cmd);
=======
int	is_arg_and_redir(int log)
{
	return (log == 0 || is_redir(log));
>>>>>>> master
}

void	dup_and_close_in_fork(t_mini *mini)
{
	if (mini->io_fds_redir[0] != -42)
	{
		dup2(mini->io_fds_redir[0], STDIN_FILENO);
		close(mini->io_fds_redir[0]);
	}
	if (mini->io_fds_redir[1] != -42)
	{
		dup2(mini->io_fds_redir[1], STDOUT_FILENO);
		close(mini->io_fds_redir[1]);
	}
	if (mini->unused_fds[0] != -42)
		close(mini->unused_fds[0]);
	if (mini->unused_fds[1] != -42)
		close(mini->unused_fds[1]);
}

void	close_out_fork(t_mini *mini)
{
	if (mini->io_fds_redir[0] != -42)
	{
		close(mini->io_fds_redir[0]);
		mini->io_fds_redir[0] = -42;
	}
	if (mini->io_fds_redir[1] != -42)
	{
		close(mini->io_fds_redir[1]);
		mini->io_fds_redir[1] = -42;
	}
	if (mini->unused_fds[0] != -42)
		mini->unused_fds[0] = -42;
	if (mini->unused_fds[1] != -42)
		mini->unused_fds[1] = -42;
}

int	get_nb_of_args(t_lst *lst)
{
	int		nb_args;

	nb_args = 0;
	while (lst && lst->log != PIPE)
	{
		if (lst->log == 0 || is_builtin(lst->log))
			nb_args++;
		if (is_redir(lst->log))
			lst = lst->next->next;
		else
			lst = lst->next;
	}
	return (nb_args);
}

char	**get_args(t_lst *lst)
{
	char	**cmd;
	int		i;
	int		nb_args;

	i = 0;
	nb_args = get_nb_of_args(lst);
	cmd = malloc(sizeof(char *) * (nb_args + 1));
	if (cmd == NULL)
		return (NULL);
	while (lst && lst->log != PIPE)
	{
		if (lst->log == 0 || is_builtin(lst->log))
		{
			cmd[i] = lst->str;
			i++;
			lst = lst->next;
		}
		else
			lst = lst->next->next;
	}
	cmd[i] = NULL;
	return (cmd);
}

void	exec_bin(t_mini *mini, t_lst *lst, pid_t *pid)
{
	char		**cmd;

<<<<<<< HEAD
	cmd = ft_split(lst->str, ' ');
=======
	take_signal();
	cmd = get_args(lst);
>>>>>>> master
	cmd[0] = get_cmd_path(mini->path, cmd[0]);
	*pid = fork();
	if (*pid < 0)
		exit_error(__LINE__);
	if (*pid == 0)
	{
		dup_and_close_in_fork(mini);
		execve(cmd[0], cmd, mini->cp_ev);
		exit_error(__LINE__);
	}
	else
	{
		close_out_fork(mini);
	}
}

<<<<<<< HEAD
void	exec_echo(t_mini *mini, t_lst *lst)
{
	if (mini->io_fds_redir[1] != -42)
		mini->er_num = ft_echo();
=======
void	exec_cd(t_mini *mini, t_lst *lst)
{
	char	**args;

	args = get_args(lst);
	if (args == NULL)
		exit_error(__LINE__);
	if (args[0] == NULL)
		mini->er_num = ft_cd(NULL);
	else
	{
		// printf("%s\n", cmd[1]);
		mini->er_num = ft_cd(args[1]);
	}
}

void	exec_echo(t_mini *mini, t_lst *lst)
{
	char	**args;

	args = get_args(lst);
	if (args == NULL)
		exit_error(__LINE__);
	if (args[0] == NULL)
	{
		if (mini->io_fds_redir[1] != -42)
			mini->er_num = ft_echo(args, 0, mini->io_fds_redir[1]);
		else
			mini->er_num = ft_echo(args, 0, STDOUT_FILENO);
	}
	else
	{
		if (mini->io_fds_redir[1] != -42)
			mini->er_num = ft_echo(&args[1], 0, mini->io_fds_redir[1]);
		else
			mini->er_num = ft_echo(&args[1], 0, STDOUT_FILENO);
	}
}

void	exec_env(t_mini *mini)
{
	if (mini->io_fds_redir[1] != -42)
		mini->er_num = ft_env(mini->cp_ev, mini->io_fds_redir[1]);
	else
		mini->er_num = ft_env(mini->cp_ev, STDOUT_FILENO);
}

void	exec_export(t_mini *mini, t_lst *lst)
{
	(void)mini;
	(void)lst;
}

void	exec_pwd(t_mini *mini)
{
	if (mini->io_fds_redir[1] != -42)
		mini->er_num = ft_pwd(mini->io_fds_redir[1]);
	else
		mini->er_num = ft_pwd(STDOUT_FILENO);
}

void	exec_unset(t_mini *mini, t_lst *lst)
{
	char	**args;

	args = get_args(lst);
	if (args == NULL)
		exit_error(__LINE__);
	if (args[0] == NULL)
		mini->er_num = ft_unset(&args[0]);
	else
		mini->er_num = ft_unset(&args[1]);
>>>>>>> master
}

void	exec_builtin(t_mini *mini, t_lst *lst)
{
<<<<<<< HEAD
	if (lst->log == BECHO)
=======
	// printf("lst->log = %d\n", lst->log);
	if (lst->log == CD)
		exec_cd(mini, lst);
	else if (lst->log == BECHO)
>>>>>>> master
		exec_echo(mini, lst);
}

void	exec(t_mini *mini, t_lst *lst)
{
	t_pids		*pid;

	if (lst->log == 0)
	{
		pid = create_pid();
		exec_bin(mini, lst, &(pid->pid));
		add_pid_to_pids(mini, pid);
	}
	else if (is_builtin(lst->log))
	{
		exec_builtin(mini, lst);
	}
}

static void	init_exec_utils(t_mini *mini)
{
	mini->buffer = NULL;
	mini->io_fds_redir[0] = -42;
	mini->io_fds_redir[1] = -42;
	mini->unused_fds[0] = -42;
	mini->unused_fds[1] = -42;
	mini->pids = NULL;
	mini->path = get_path(mini->cp_ev);
}

void	exec_instructions(t_mini *mini)
{
	t_lst	*lst;
	int		**pipeline;
	int		pipe_index;

	init_exec_utils(mini);
	lst = mini->list;
	pipeline = create_pipeline(lst);
	pipe_index = 0;
	while(lst)
	{
		// dprintf(2, "lst->str = %s\n", lst->str);
		redirections(mini, lst, pipeline, &pipe_index);
		if (lst && is_cmd(lst->log))
			exec(mini, lst);
		if (is_redir(lst->log))
			lst = skip_redir(lst);
		else if (lst->log == 0 || is_builtin(lst->log))
			lst = skip_redir_and_args(lst);
		else
			lst = lst->next;
	}
	wait_for_forks(mini);
	free_pipeline(pipeline);
	free_pids(&(mini->pids));
}
