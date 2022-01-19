/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diff_cmd_redir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:21:10 by dclark            #+#    #+#             */
/*   Updated: 2022/01/19 16:15:39 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	diff_cmd(char *str)
{
	if (ft_strcmp(str, "echo") == 0)
		return (1);
	else if (ft_strcmp(str, "cd") == 0)
		return (2);
	else if (ft_strcmp(str, "pwd") == 0)
		return (3);
	else if (ft_strcmp(str, "export") == 0)
		return (4);
	else if (ft_strcmp(str, "unset") == 0)
		return (5);
	else if (ft_strcmp(str, "env") == 0)
		return (6);
	else if (ft_strcmp(str, "exit") == 0)
		return (7);
	return (0);
}

static int	diff_redir(char *str)
{
	if (ft_strcmp(str, "<") == 0)
		return (8);
	if (ft_strcmp(str, ">") == 0)
		return (9);
	if (ft_strcmp(str, "<<") == 0)
		return (10);
	if (ft_strcmp(str, ">>") == 0)
		return (11);
	if (ft_strcmp(str, "|") == 0)
		return (12);
	return (0);
}

int	diff_cmd_redir(char *str)
{
	if (diff_cmd(str) != 0)
		return (diff_cmd(str));
	if (diff_redir(str) != 0)
		return (diff_redir(str));
	return (0);
}
