/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 14:32:13 by seciurte          #+#    #+#             */
/*   Updated: 2022/03/16 14:36:11 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
}

void	exec_builtin(t_mini *mini, t_lst *lst)
{
	// printf("lst->log = %d\n", lst->log);
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
	close_out_fork(mini);
}