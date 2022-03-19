/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 14:32:13 by seciurte          #+#    #+#             */
/*   Updated: 2022/03/19 13:47:34 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int    ft_check_exit_format(char *str)
{
    int    i;
    while (str[i] && str[i] == ' ')
        i++;
    if (str[i] && (str[i] == '+' || str[i] == '-'))
        i++;
    while (str[i])
    {
        if (ft_isdigit(str[i]) == 0)
            return (0);
        i++;
    }
    return (1);
}

void	exec_unset(t_mini *mini, t_lst *lst)
{
	(void)mini;
	char	**args;

	args = get_args(lst);
	if (args == NULL)
		exit_error(__LINE__);
	if (ft_tablen(args) > 1)
		g_err_num = ft_unset(args[1]);
	else
		g_err_num = ft_unset(NULL);
	free(args);
}

void	exec_exit(t_lst *lst)
{
	char	**args;

	args = get_args(lst);
	if (ft_tablen(args) > 2)
		exit_error(__LINE__);
	if (ft_tablen(args) == 2 && ft_check_exit_format(args[1]))
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