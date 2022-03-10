/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 12:54:00 by david             #+#    #+#             */
/*   Updated: 2022/03/10 15:41:47 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//return -1 if not found
static int	look_name(char *name, char **tab_env)
{
	int	iter;

	iter = 0;
	while (tab_env[iter])
	{
		if (ft_strncmp(name, tab_env[iter], ft_strlen(name)) == 0)
			return (iter);
		iter++;
	}
	return (-1);
}

static char	**add_env(char *name, char *data, char **tab_env)
{
	char	**dest;
	int		i;

	i = ft_tablen(tab_env);
	dest = ft_copy_env(tab_env, 1);
	ft_freetab(tab_env);
	dest[i] = ft_strljoin(dest[i], name, ft_strlen(name));
	dest[i] = ft_strljoin(dest[i], "=", 1);
	if (ft_strlen(data) != 0)
		dest[i] = ft_strljoin(dest[i], data, ft_strlen(data));
	return (dest);
}

static char	**change_env(char *name, char *data, char **tab_env)
{
	char	**dest;
	int		i;

	dest = malloc(sizeof(char *) * (ft_tablen(tab_env) + 1));
	i = 0;
	while (i <= ft_tablen(tab_env))
	{
		dest[i] = 0;
		i++;
	}
	i = 0;
	while (i < ft_tablen(tab_env))
	{
		if (look_name(name, tab_env) == i)
		{
			dest[i] = ft_strljoin(dest[i], name, ft_strlen(name));
			dest[i] = ft_strljoin(dest[i], "=", 1);
			if (ft_strlen(data) != 0)
				dest[i] = ft_strljoin(dest[i], data, ft_strlen(data));
		}
		else
			dest[i] = strdup(tab_env[i]);
		i++;
	}
	ft_freetab(tab_env);
	return (dest);
}

int	ft_export(char *name, char *data, char ***tab_env)
{
	printf("name = %s\n", name);
	printf("data = %s\n", data);
	if (look_name(name, *tab_env) == -1)
	{
		dprintf(2, "add_env()\n");
		*tab_env = add_env(name, data, *tab_env);
	}
	else
	{
		dprintf(2, "change_env()\n");
		*tab_env = change_env(name, data, *tab_env);
	}
	return (EXIT_SUCCESS);
}
