/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 12:26:49 by david             #+#    #+#             */
/*   Updated: 2022/03/19 18:34:34 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	only_home(void)
{
	char	*tmp;

	tmp = ft_getenv("HOME", get_mini()->cp_ev);
	if (chdir(tmp) == 0)
	{
		free(tmp);
		return (EXIT_SUCCESS);
	}
	else
	{
		if (tmp == NULL)
			write(STDERR_FILENO, "Minishell: cd: HOME not set\n", 28);
		else
			arg_error(tmp);
		free(tmp);
		return (EXIT_FAILURE);
	}
}

static int	ft_chdir(char *path)
{
	if (chdir(path) == 0)
	{
		if (path != NULL)
			free(path);
		return (EXIT_SUCCESS);
	}
	else
	{
		arg_error(path);
		if (path != NULL)
			free(path);
		return (errno);
	}
}

int	ft_cd(char *path)
{
	char	*tmp;

	tmp = NULL;
	if (path == NULL || !path)
	{
		if (tmp != NULL)
			free(tmp);
		return (only_home());
	}
	tmp = ft_strdup(path);
	if (tmp && ft_strcmp(tmp, "~") == 0)
	{
		if (tmp != NULL)
			free(tmp);
		return (only_home());
	}
	if (tmp && ft_strncmp(tmp, "~", 1) == 0 && ft_strlen(tmp) > 1)
		tmp = ft_strljoin(ft_getenv("HOME", get_mini()->cp_ev), \
		&tmp[1], ft_strlen(&tmp[1]));
	return (ft_chdir(tmp));
}
