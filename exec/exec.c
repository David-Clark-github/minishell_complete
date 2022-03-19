/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 14:55:31 by seciurte          #+#    #+#             */
/*   Updated: 2022/03/19 17:09:21 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <sys/errno.h>

void	free_in_exec(void)
{
	free_pipeline(get_mini()->pipeline);
	free_pids(&(get_mini()->pids));
	free_path(get_mini()->path);
}

static int	check_for_redir_error(t_mini *mini)
{
	if ((mini->io_fds_redir[0] < 0 && mini->io_fds_redir[0] != -42)
		|| (mini->io_fds_redir[1] < 0 && mini->io_fds_redir[1] != -42))
		return (0);
	return (1);
}

void	exec(t_mini *mini, t_lst *lst)
{
	t_pids		*pid;

	if (check_for_redir_error(mini) == 0)
	{
		if (mini->io_fds_redir[0] > 0)
		{
			close(mini->io_fds_redir[0] > 0);
			mini->io_fds_redir[0] = -42;
		}
		if (mini->io_fds_redir[1] > 0)
		{
			close(mini->io_fds_redir[1] > 0);
			mini->io_fds_redir[1] = -42;
		}
		return ;
	}
	if (lst->log == 0)
	{
		pid = create_pid();
		exec_bin(mini, lst, pid);
		add_pid_to_pids(mini, pid);
	}
	else if (is_builtin(lst->log))
		exec_builtin(mini, lst);
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
	int		pipe_index;

	g_err_num = check_errors_before_exec(mini);
	if (g_err_num != 0)
		return ;
	init_exec_utils(mini);
	lst = mini->list;
	mini->pipeline = create_pipeline(lst);
	pipe_index = 0;
	while (lst)
	{
		redirections(mini, lst, mini->pipeline, &pipe_index);
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
	free_in_exec();
}
