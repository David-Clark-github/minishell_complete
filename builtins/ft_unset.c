/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:12:26 by dclark            #+#    #+#             */
/*   Updated: 2022/03/19 18:22:33 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	look_name(char *name)
{
	int	i;

	i = 0;
	while (get_mini()->cp_ev[i])
	{
		if (ft_strncmp(name, get_mini()->cp_ev[i], ft_strlen(name)) == 0 && \
			get_mini()->cp_ev[i][ft_strlen(name)] == '=')
			return (i);
		i++;
	}
	return (-1);
}

static char	**unset(int i, char **tab_env)
{
	char	**dest;
	int		y;
	int		t;

	dest = malloc(sizeof(char *) * ft_tablen(tab_env));
	if (dest == NULL)
		return (NULL);
	y = 0;
	t = 0;
	while (t < (ft_tablen(tab_env)))
	{
		if (t != i)
		{
			dest[y] = strdup(tab_env[t]);
			y++;
		}
		t++;
	}
	dest[y] = 0;
	ft_freetab(tab_env);
	return (dest);
}

int	ft_unset(char **name)
{
	int		i;
	int		loop;
	char	***cp_env;

	loop = 0;
	if (name == NULL)
		return (EXIT_SUCCESS);
	cp_env = &get_mini()->cp_ev;
	while (name[loop])
	{
		i = look_name(name[loop]);
		if (i != -1)
			*cp_env = unset(i, *cp_env);
		loop++;
	}
	cp_env = NULL;
	return (EXIT_SUCCESS);
}
