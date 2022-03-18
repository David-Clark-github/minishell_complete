/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 14:18:22 by seciurte          #+#    #+#             */
/*   Updated: 2022/03/18 15:48:32 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_cd(t_mini *mini, t_lst *lst)
{
	(void)mini;
	char	**args;

	args = get_args(lst);
	if (args == NULL)
		exit_error(__LINE__);
	if (args[0] == NULL)
		g_err_num = ft_cd(NULL);
	if (ft_tablen(args) > 2)
		exit_error(__LINE__);
	else
		g_err_num = ft_cd(args[1]);
	free(args);
}

void	exec_echo(t_mini *mini, t_lst *lst)
{
	char	**args;
	int		opt;

	args = get_args(lst);
	if (args == NULL)
		exit_error(__LINE__);
	opt = 0;
	if (ft_check_echo_arg(args))
		opt = 1;
	if (mini->io_fds_redir[1] != -42)
		g_err_num = ft_echo(&args[1 + opt], opt, mini->io_fds_redir[1]);
	else
		g_err_num = ft_echo(&args[1 + opt], opt, STDOUT_FILENO);
	free(args);
}

void	exec_env(t_mini *mini)
{
	if (mini->io_fds_redir[1] != -42)
		g_err_num = ft_env(mini->cp_ev, mini->io_fds_redir[1]);
	else
		g_err_num = ft_env(mini->cp_ev, STDOUT_FILENO);
}

void	exec_export(t_mini *mini, t_lst *lst)
{
	(void)mini;
	(void)lst;
	// char	**args;

	// args = get_args(lst);
	// if (args == NULL)
	// 	exit_error(__LINE__);
	// if (ft_check_export_format(args[0]))
	// 	exit_error(__LINE__);
	// if (args[0] == NULL)
	// 	g_err_num = ft_cd(NULL);
	// if (ft_tablen(args) > 2)
	// 	exit_error(__LINE__);
	// else
	// 	g_err_num = ft_cd(args[1]);
}

void	exec_pwd(t_mini *mini)
{
	if (mini->io_fds_redir[1] != -42)
		g_err_num = ft_pwd(mini->io_fds_redir[1]);
	else
		g_err_num = ft_pwd(STDOUT_FILENO);
}