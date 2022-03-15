/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:12:26 by dclark            #+#    #+#             */
/*   Updated: 2022/03/15 18:39:04 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	look_name(char *name)
{
	int	i;

	i = 0;
	while (get_mini()->cp_ev[i])
	{
		if (ft_strncmp(name, get_mini()->cp_ev[i], ft_strlen(name)) == 0)
			return (i);
		i++;
	}
	return (-1);
}

static char	**unset(int i)
{
	char	**dest;
	int		y;
	int		t;

	dest = malloc(sizeof(char *) * ft_tablen(get_mini()->cp_ev));
	if (dest == NULL)
		return (NULL);
	y = 0;
	t = 0;
	while (t < (ft_tablen(get_mini()->cp_ev)))
	{
		if (y != i)
		{
			dest[y] = strdup(get_mini()->cp_ev[t]);
			y++;
		}
		t++;
	}
	dest[y] = 0;
	ft_freetab(get_mini()->cp_ev);
	return (dest);
}

int	ft_unset(char **name)
{
	int	i;
	int	loop;

	loop = 0;
	while (name[loop])
	{
		i = look_name(name[loop]);
		if (i != -1)
		{
			get_mini()->cp_ev = unset(i);
			if (get_mini()->cp_ev == NULL)
				return (EXIT_FAILURE);
		}
		loop++;
	}
	return (EXIT_SUCCESS);
}
