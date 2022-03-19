/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <dclark@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:39:38 by david             #+#    #+#             */
/*   Updated: 2022/03/19 15:33:43 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_env(char **tab_env, int fd)
{
	int	i;
	int	res_w;

	i = 0;
	while (tab_env[i])
	{
		res_w = write(fd, tab_env[i], strlen(tab_env[i]));
		if (res_w == -1)
		{
			write(2, "env: write error: No space left on device\n", 42);
			return (125);
		}
		res_w = write(fd, "\n", 1);
		if (res_w == -1)
		{
			write(2, "env: write error: No space left on device\n", 42);
			return (125);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}
