/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <dclark@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 12:54:00 by david             #+#    #+#             */
/*   Updated: 2022/01/18 12:31:44 by dclark           ###   ########.fr       */
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
	printf("i = %d\n", i);
	//printf("i = %d\n", i);
	dest = ft_copy_env(tab_env, 1);
	dest[i] = ft_strljoin(dest[i], name, ft_strlen(name));
	dest[i] = ft_strljoin(dest[i], "=", 1);
	dest[i] = ft_strljoin(dest[i], data, ft_strlen(data));
	printf("tablen = %d\n", ft_tablen(dest));
//	printf("dest[i] = %s\n", dest[i]);
	return (dest);
}

int	ft_export(char *name, char *data, char **tab_env)
{
	//printf("name = %s\n", name);
	//printf("data = %s\n", data);
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
