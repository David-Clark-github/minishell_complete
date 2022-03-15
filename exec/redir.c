/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 13:29:52 by seciurte          #+#    #+#             */
/*   Updated: 2022/03/15 14:09:16 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	redirect_heredoc(t_mini *mini, t_lst *lst)
{
	if (mini->io_fds_redir[0] != -42)
	{
		close(mini->io_fds_redir[0]);
		mini->io_fds_redir[0]= -42;
	}
	heredoc(mini, lst);
	if (mini->io_fds_redir[0] < 0)
		exit_error(__LINE__);
}

void	redirect_input(t_mini *mini, t_lst *lst)
{
	if (mini->io_fds_redir[0] != -42)
	{
		close(mini->io_fds_redir[0]);
		mini->io_fds_redir[0]= -42;
	}
	mini->io_fds_redir[0] = open(lst->next->str, O_RDONLY);
	if (mini->io_fds_redir[0] < 0)
		exit_error(__LINE__);
}

void	redirect_stdout(t_mini *mini, t_lst *lst)
{
	int		log;
	// printf("%s\n", lst->str);
	log = lst->log;
	lst = lst->next;
	// printf("%s\n", lst->str);
	if (mini->io_fds_redir[1] != -42)
	{
		close(mini->io_fds_redir[1]);
		mini->io_fds_redir[1] = -42;
	}
	if (log == TRUNC)
		mini->io_fds_redir[1] = open(lst->str, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	else
		mini->io_fds_redir[1] = open(lst->str, O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
	if (mini->io_fds_redir[1] < 0)
		exit_error(__LINE__);
	// printf("%s\n", lst->str);
}