/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 14:55:31 by seciurte          #+#    #+#             */
/*   Updated: 2022/03/09 19:37:37 by seciurte         ###   ########.fr       */
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

void	exec_bin(t_mini *mini, t_lst *lst, pid_t *pid)
{
	char		**cmd;

	cmd = ft_split(lst->str, ' ');
	cmd[0] = get_cmd_path(mini->path, cmd[0]);
	*pid = fork();
	if (*pid < 0)
		exit_error(__LINE__);
	if (*pid == 0)
	{
		// dprintf(2, "cmd = %s | pid = %d\n", cmd[0], getpid());
		dup_and_close_in_fork(mini);
		execve(cmd[0], cmd, mini->cp_ev);
		exit_error(__LINE__);
	}
	else
	{
		free_cmd(cmd);
		close_out_fork(mini);
	}
}

void	exec_echo(t_mini *mini, t_lst *lst)
{
	if (mini->io_fds_redir[1] != -42)
		mini->er_num = ft_echo();
}

void	exec_builtin(t_mini *mini, t_lst *lst)
{
	if (lst->log == BECHO)
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
	while(lst && lst->str)
	{
		redirections(mini, lst, pipeline, &pipe_index);
		if (lst && is_cmd(lst->log))
			exec(mini, lst);
		if (lst && is_redir(lst->log))
			lst = skip_redir(lst);
		else if (lst && lst->next && is_redir(lst->next->log))
			lst = skip_redir(lst->next);
		else if (lst)
			lst = lst->next;
	}
	wait_for_forks(mini);
	free_pipeline(pipeline);
	free_pids(&(mini->pids));
}
