/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <dclark@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 12:54:00 by david             #+#    #+#             */
/*   Updated: 2022/01/06 14:06:29 by david            ###   ########.fr       */
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
static int	look_name(char *varia_name, char **tab_env)
{
	int	iter;

	iter = 0;
	while (tab_env[iter])
	{
		if (ft_strncmp(varia_name, tab_env[iter], ft_strlen(varia_name)) == 0)
			return (iter);
	}
	return (-1);
}

int	ft_export(char *varia_name, char *varia_data, char **tab_env)
{
	
}
