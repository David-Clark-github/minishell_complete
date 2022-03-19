/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_bin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 14:42:15 by seciurte          #+#    #+#             */
/*   Updated: 2022/03/19 21:10:59 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

static void	free_and_close_on_error(char **cmd, t_pids *pid)
{
	if (get_mini()->io_fds_redir[0] != -42)
		close(STDIN_FILENO);
	if (get_mini()->io_fds_redir[1] != -42)
		close(STDOUT_FILENO);
	free(cmd[0]);
	free(cmd);
	free_in_exec();
	free(pid);
	ft_free_mini(get_mini(), 0);
}

void	exec_bin(t_mini *mini, t_lst *lst, t_pids *pid)
{
	char		**cmd;

	cmd = get_args(lst);
	cmd[0] = get_cmd_path(mini->path, cmd[0]);
	pid->pid = fork();
	if (pid->pid < 0)
		fatal_error();
	if (pid->pid == 0)
	{
		default_sig();
		dup_and_close_in_fork(mini);
		execve(cmd[0], cmd, mini->cp_ev);
		error_exec_bin(lst->str);
		free_and_close_on_error(cmd, pid);
		exit(g_err_num);
	}
	else
	{
		free(cmd[0]);
		free(cmd);
		close_out_fork(mini);
	}
}
