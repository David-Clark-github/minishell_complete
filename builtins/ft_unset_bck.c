/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:12:26 by dclark            #+#    #+#             */
/*   Updated: 2022/03/15 15:24:13 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	look_name(char *name, char **tab_env)
{
	int	i;

	i = 0;
	while (tab_env[i] && tab_env[i] != NULL)
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

int	ft_unset(char **name, char ***tab_env)
{
	int	i;
	int	loop;
	(void)tab_env;

	loop = 0;
	while (name[loop])
	{
		i = look_name(name[loop], get_mini()->cp_ev);
		if (i != -1)
		{	
			get_mini()->cp_ev = unset(i, get_mini()->cp_ev);
			if (get_mini()->cp_ev == NULL)
				return (EXIT_FAILURE);
		}
		loop++;
	}
	return (EXIT_SUCCESS);
}
