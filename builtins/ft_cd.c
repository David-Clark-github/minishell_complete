/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <dclark@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 12:26:49 by david             #+#    #+#             */
/*   Updated: 2022/03/13 17:54:52 by david            ###   ########.fr       */
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
		printf("HOME not found");
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
		printf("cd: no such file or directory: %s\n", tmp);
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
		tmp = ft_strljoin(ft_getenv("HOME", get_mini()->cp_ev), &tmp[1], ft_strlen(&tmp[1]));
	printf("tmp = %s\n", tmp);
	if (chdir(tmp) == 0)
	{
		printf("chdir successfull !\n");
		free(tmp);
		return (EXIT_SUCCESS);
	}
	else
	{
		printf("cd: no such file or directory: %s\n", tmp);
		free(tmp);
		return (EXIT_FAILURE);
	}
}
