/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <dclark@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 12:54:00 by david             #+#    #+#             */
/*   Updated: 2022/03/11 13:28:28 by dclark           ###   ########.fr       */
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
	return (ft_freetab(tab_env), dest);
}

int	ft_export(char *name, char *data, char ***tab_env)
{
	printf("name = %s\n", name);
	printf("data = %s\n", data);
	if (look_name(name, *tab_env) == -1)
	{	
		printf("add_env()\n");
		*tab_env = add_env(name, data, *tab_env);
	}
	else
	{
		printf("change_env()\n");
		*tab_env = change_env(name, data, *tab_env);
	}
	return (EXIT_SUCCESS);
}
