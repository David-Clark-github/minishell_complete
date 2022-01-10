/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <dclark@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 11:27:06 by david             #+#    #+#             */
/*   Updated: 2022/01/09 13:23:40 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	tab_len(char **tab_env)
{
	int	i;

	i = 0;
	while (tab_env && tab_env[i])
		i++;
	return (i);
}

char	**ft_copy_env(char **tab_env, int add)
{
	int	i;
	char	**dest;

	i = 0;
	if (!tab_env)
		return (NULL);
	dest = malloc(sizeof(char *) * (tab_len(tab_env) + 1 + add));
	while (i < tab_len(tab_env))
	{
		dest[i] = strdup(tab_env[i]);
		i++;
	}
	while (add--)
	{
		dest[i] = 0;
		i++;
	}
	dest[i] = 0;
	return (dest);
}
