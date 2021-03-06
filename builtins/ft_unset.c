/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:12:26 by dclark            #+#    #+#             */
/*   Updated: 2022/03/20 00:40:18 by dclark           ###   ########.fr       */
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
		{
			return (i);
		}
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
		fatal_error();
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
	dest[y] = '\0';
	ft_freetab(tab_env);
	return (dest);
}

int	ft_unset(char **name)
{
	int		i;
	int		loop;
	char	***env_t;

	loop = 0;
	env_t = &get_mini()->cp_ev;
	if (name == NULL)
		return (EXIT_SUCCESS);
	while (name[loop])
	{
		i = look_name(name[loop]);
		if (i != -1)
			*env_t = unset(i, *env_t);
		loop++;
	}
	env_t = NULL;
	return (EXIT_SUCCESS);
}
