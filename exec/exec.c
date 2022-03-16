/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 14:55:31 by seciurte          #+#    #+#             */
/*   Updated: 2022/03/16 16:46:30 by seciurte         ###   ########.fr       */
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
	int		**pipeline;
	int		pipe_index;

	g_err_num = check_errors_before_exec(mini);
	if (g_err_num != 0)
		return ;
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
