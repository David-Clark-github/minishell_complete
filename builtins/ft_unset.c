/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:12:26 by dclark            #+#    #+#             */
/*   Updated: 2022/03/15 18:15:18 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	look_name(char *name, char **tab_env)
{
	int	i;

	i = 0;
	while (tab_env[i])
	{
		if (ft_strncmp(name, tab_env[i], ft_strlen(name)) == 0)
			return (i);
		i++;
	}
	return (-1);
}

static char	**unset(int i, char **tab_env)
{
	char	**dest;
	int		y;

	dest = malloc(sizeof(char *) * ft_tablen(tab_env));
	if (dest == NULL)
		return (NULL);
	y = 0;
	while (y < (ft_tablen(tab_env) - 1))
	{
		if (i != y)
			dest[y] = strdup(tab_env[y]);
		y++;
	}
	dest[y] = 0;
	ft_freetab(tab_env);
	return (dest);
}

int	ft_unset(char *name, char ***tab_env)
{
	int	i;

	i = look_name(name, *tab_env);
	if (i != -1)
	{
		*tab_env = unset(i, *tab_env);
		if (tab_env == NULL)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
