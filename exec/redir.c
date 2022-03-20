/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 13:29:52 by seciurte          #+#    #+#             */
/*   Updated: 2022/03/20 05:09:19 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	redirect_heredoc(t_mini *mini, t_lst *lst)
{
	char	*name;

	lst = lst->next;
	if (lst->str == NULL)
		name = "";
	else
		name = lst->str;
	if (mini->io_fds_redir[0] != -42)
	{
		close(mini->io_fds_redir[0]);
		mini->io_fds_redir[0] = -42;
	}
	mini->save_stdin = dup(STDIN_FILENO);
	signal(SIGINT, heredoc_sig);
	heredoc(mini, lst);
	dup2(get_mini()->save_stdin, STDIN_FILENO);
	if (mini->io_fds_redir[0] < 0)
		redir_error(name);
}

void	redirect_input(t_mini *mini, t_lst *lst)
{
	char	*name;

	lst = lst->next;
	if (lst->str == NULL)
		name = "";
	else
		name = lst->str;
	if (mini->io_fds_redir[0] != -42)
	{
		close(mini->io_fds_redir[0]);
		mini->io_fds_redir[0] = -42;
	}
	mini->io_fds_redir[0] = open(name, O_RDONLY);
	if (mini->io_fds_redir[0] < 0)
		redir_error(name);
}

void	redirect_stdout(t_mini *mini, t_lst *lst)
{
	int		log;
	char	*name;

	log = lst->log;
	lst = lst->next;
	if (lst->str == NULL)
		name = "";
	else
		name = lst->str;
	if (mini->io_fds_redir[1] != -42)
	{
		close(mini->io_fds_redir[1]);
		mini->io_fds_redir[1] = -42;
	}
	if (log == TRUNC)
		mini->io_fds_redir[1] = open(name, \
			O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR, 0644);
	else
		mini->io_fds_redir[1] = open(name, \
			O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR, 0644);
	if (mini->io_fds_redir[1] < 0)
		redir_error(name);
}
