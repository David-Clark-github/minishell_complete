/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 12:54:00 by david             #+#    #+#             */
/*   Updated: 2022/03/15 19:17:31 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//return -1 if not found
static int	look_name(char *name, char **tab_env)
{
	int	iter;

	iter = 0;
	if (!name || name == NULL)
		return (-1);
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

static void	split_data(char **name, char **data, char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '=')
	{
		*name = ft_strljoin(*name, &str[i], 1);
		i++;
	}
	if (str[i] && str[i] == '=')
		i++;
	while (str[i])
	{
		*data = ft_strljoin(*data, &str[i], 1);
		i++;
	}
}

int	ft_export(char **str, char ***tab_env)
{
	int		i;
	char	*name;
	char	*data;

	i = 0;
	name = NULL;
	data = NULL;
	while (str[i])
	{
		printf("str[i] = %s\n", str[i]);
		split_data(&name, &data, str[i]);
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
		free(name);
		free(data);
		name = NULL;
		data = NULL;
		i++;
	}
	return (EXIT_SUCCESS);
}
