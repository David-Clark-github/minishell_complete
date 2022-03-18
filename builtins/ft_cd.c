/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <dclark@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 12:26:49 by david             #+#    #+#             */
/*   Updated: 2022/03/18 18:58:48 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	only_home(void)
{
	char	*tmp;

	tmp = ft_getenv("HOME", get_mini()->cp_ev);
	if (ft_tablen(get_mini()->cp_ev) == 0 || tmp == NULL)
	{
		free(tmp);
		printf("HOME not set\n");
		return (EXIT_FAILURE);
	}
	if (chdir(tmp) == 0)
	{
		free(tmp);
		return (EXIT_SUCCESS);
	}
	else
	{
		free(tmp);
		write(2, "Minishell: cd: no such file or directory: ", 42);
		write(2, tmp, ft_strlen(tmp));
		write(2, "\n", 1);
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
		write(2, "Minishell: cd: no such file or directory: ", 42);
		write(2, path, ft_strlen(path));
		write(2, "\n", 1);
		if (path != NULL)
			free(path);
		return (EXIT_FAILURE);
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
