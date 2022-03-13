/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 13:35:40 by seciurte          #+#    #+#             */
/*   Updated: 2022/03/13 08:13:16 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_lst	*skip_redir(t_lst *lst)
{
	while (lst && is_redir(lst->log))
	{
		if (is_redir(lst->log))
			lst = lst->next->next;
	}
	return (lst);
}

static void	do_redirections(t_mini *mini, t_lst *lst)
{
	// if (!(is_redir(lst->log) && lst->next && lst->str))
	// 	error_unexpected_token(mini, lst);
	while (lst && is_redir(lst->log))
	{
		if (lst->log == INPUT)
			redirect_input(mini, lst);
		else if (lst->log == HEREDOC)
			redirect_heredoc(mini, lst);
		else if (is_redir_stdout(lst->log))
			redirect_stdout(mini, lst);
		// dprintf(2, "stdin %d | stdout %d | %s\n", mini->io_fds_redir[0], mini->io_fds_redir[1], lst->next->str);
		if (is_redir(lst->log))
			lst = lst->next->next;
	}
}

// static void	do_redirections_and_args(t_mini *mini, t_lst *lst)
// {
// 	while (lst && is_redir(lst->log))
// 	{
// 		if (lst->log == INPUT)
// 			redirect_input(mini, lst);
// 		else if (lst->log == HEREDOC)
// 			redirect_heredoc(mini, lst);
// 		else if (is_redir_stdout(lst->log))
// 			redirect_stdout(mini, lst);
// 		// dprintf(2, "stdin %d | stdout %d | %s\n", mini->io_fds_redir[0], mini->io_fds_redir[1], lst->next->str);
// 		if (is_redir(lst->log))
// 			lst = lst->next->next;
// 		else
// 			lst = lst->next;
// 	}
// }

void	redirections(t_mini *mini, t_lst *lst, int **pipeline, int *pipe_index)
{
	(void) pipeline;
	(void) pipe_index;
	do_redirections(mini, lst);
	redirect_pipe_stdin(mini, pipeline, pipe_index);
	if (lst && lst->next && (is_redir(lst->next->log) || lst->next->log == PIPE))
	{
		lst = lst->next;
		do_redirections(mini, lst);
		redirect_pipe_stdout(mini, pipeline, pipe_index);
	}
}