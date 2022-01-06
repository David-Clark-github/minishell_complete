/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <dclark@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 12:54:00 by david             #+#    #+#             */
/*   Updated: 2022/01/06 17:54:55 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	tab_len(char **tab)
{
	int	res;

	res = 0;
	while (tab[res])
		res++;
	return (res)
}

//return -1 if not found
static int	look_name(char *name, char **tab_env)
{
	int	iter;

	iter = 0;
	while (tab_env[iter])
	{
		if (ft_strncmp(name, tab_env[iter], ft_strlen(name)) == 0)
			return (iter);
	}
	return (-1);
}

char	**add_env(char **tab_env, char *name, char *data)
{
	char	**dest;
	int		i;

	i = 0;
	dest = malloc(sizeof(char *) * (tab_len(tab_env) + 2));
	while (tab_env[i])
	{
		dest[i] = ft_strdup(tab_env[i]);
		i++;
	}
	dest[i] = ft_strjoin(dest[i], name);
	dest[i] = ft_strjoin(dest[i], "=");
	dest[i] = ft_strjoin(dest[i], data);
	dest[++i] = 0;
	return (dest);
}

int	ft_export(char *name, char *data, char **tab_env)
{
	if (look_name(name, tab_env) == -1)
		add_env(tab_env, name, data);
	else
	{
		tab_env[look_name(name, tab_env)] = ft_strdup(data);
		tab_env[look_name(name, tab_env)] = ft_strjoin(tab_env[look_name(name, tab_env)], "=");
		tab_env[look_name(name, tab_env)] = ft_strjoin(tab_env[look_name(name, tab_env)], data);
	}
	return (EXIT_SUCCESS);
}
