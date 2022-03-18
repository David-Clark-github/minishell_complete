/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 14:32:13 by seciurte          #+#    #+#             */
/*   Updated: 2022/03/18 17:40:47 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_unset(t_mini *mini, t_lst *lst)
{
	(void)mini;
	char	**args;

	args = get_args(lst);
	if (args == NULL)
		exit_error(__LINE__);
	g_err_num = ft_unset(args);
	free(args);
}

void	exec_exit(t_lst *lst)
{
	char	**args;

	args = get_args(lst);
	if (ft_tablen(args) > 2)
		exit_error(__LINE__);
	if (ft_tablen(args) == 2)
		ft_exit((ft_atoi(args[1]) % 256));
	else
		ft_exit(g_err_num);
}

void	exec_builtin(t_mini *mini, t_lst *lst)
{
	int		nb_pipes;

	nb_pipes = get_nb_of_pipes(mini->list);
	if (lst->log == CD)
		exec_cd(mini, lst);
	else if (lst->log == BECHO)
		exec_echo(mini, lst);
	else if (lst->log == ENV)
		exec_env(mini);
	else if (lst->log == EXPORT)
		exec_export(mini, lst);
	else if (lst->log == PWD)
		exec_pwd(mini);
	else if (lst->log == UNSET)
		exec_unset(mini, lst);
	else if (lst->log == EXIT && nb_pipes == 0)
		exec_exit(lst);
	close_out_fork(mini);
}