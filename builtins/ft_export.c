/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <dclark@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 12:54:00 by david             #+#    #+#             */
/*   Updated: 2022/01/09 13:25:51 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	tab_len(char **tab_env)
{
	int	res;

	res = 0;
	while (tab_env[res])
		res++;
	return (res);
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
		iter++;
	}
	return (-1);
}
/*
static char	**change_env(char **tab_env, char *name, char *data)
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
	i = 0;
	while (tab_env[i])
	{
		free(tab_env[i]);
		i++;
	}
	free(tab_env[i]);
	return (dest);
}
*/

static char	**add_env(char *name, char *data, char **tab_env)
{
	char	**dest;
	int		i;

	i = tab_len(tab_env);
	/*
	dest = malloc(sizeof(char *) * (tab_len(tab_env) + 2));
	if (dest == NULL)
		return (NULL);
	while (tab_env[i])
	{
		dest[i] = tab_env[i];
		i++;
	}
	*/
	dest = ft_copy_env(tab_env, 1);
	dest[i] = ft_strdup(name);
	dest[i] = ft_strljoin(dest[i], "=", 1);
	dest[i] = ft_strljoin(dest[i], data, ft_strlen(data));
	i++;
	dest[i] = 0;
	while (tab_env[++i])
		free(tab_env[i]);
	return (dest);
}

int	ft_export(char *name, char *data, char **tab_env)
{
	printf("name = %s\n", name);
	printf("data = %s\n", data);
	if (look_name(name, tab_env) == -1)
	{	
		printf("add_env()\n");
		tab_env = add_env(name, data, tab_env);
	}
	else
	{
		printf("change_env()\n");
	//	change_env(tab_env, name, data);
	}
	return (EXIT_SUCCESS);
}
