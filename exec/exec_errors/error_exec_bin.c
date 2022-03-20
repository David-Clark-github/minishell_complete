/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exec_bin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 13:41:13 by seciurte          #+#    #+#             */
/*   Updated: 2022/03/20 03:13:38 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_for_script(char *str)
{
	int		i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == '/')
			return (1);
		i++;
	}
	return (0);
}

static void	print_cmd_not_found(char *token)
{
	char	*tmp;
	char	*tmp1;
	char	*msg;

	if (ft_strlen(token) > 0)
		tmp = my_strjoin("Minishell: ", token);
	else
		tmp = my_strjoin("Minishell: ", "");
	if (tmp == NULL)
		fatal_error();
	tmp1 = my_strjoin(tmp, ": ");
	if (tmp1 == NULL)
	{
		free(tmp);
		fatal_error();
	}
	free(tmp);
	msg = my_strjoin(tmp1, "command not found\n");
	free(tmp1);
	if (msg == NULL)
		fatal_error();
	write(STDERR_FILENO, msg, ft_strlen(msg));
	free(msg);
	g_err_num = 127;
}

static void	print_exec_bin(char *token)
{
	char	*tmp;

	if (ft_strlen(token) > 0)
		tmp = my_strjoin("Minishell: ", token);
	else
		tmp = my_strjoin("Minishell: ", "");
	if (tmp == NULL)
		fatal_error();
	perror(tmp);
	free(tmp);
	g_err_num = errno;
}

void	error_exec_bin(char *token)
{
	if (!check_for_script(token) && errno == 2)
		print_cmd_not_found(token);
	else
		print_exec_bin(token);
}
