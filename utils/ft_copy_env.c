/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <dclark@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 11:27:06 by david             #+#    #+#             */
/*   Updated: 2022/01/18 14:11:08 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_copy_env(char **tab_env, size_t add)
{
	int		i;
	char	**dest;

	i = 0;
	if (!tab_env)
		return (NULL);
	dest = malloc(sizeof(char *) * (ft_tablen(tab_env) + 1 + add));
	while (i < ft_tablen(tab_env))
	{
		dest[i] = strdup(tab_env[i]);
		i++;
	}
	while (add-- > 0)
	{
		printf("add = %ld\n", add);
		dest[i] = 0;
		i++;
	}
	dest[i] = 0;
	return (dest);
}
