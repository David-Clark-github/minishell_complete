/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <dclark@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:39:38 by david             #+#    #+#             */
/*   Updated: 2022/01/25 12:34:38 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_env(char **tab_env, int fd)
{
	int	i;

	i = 0;
	while (tab_env[i])
	{
		write(fd, tab_env[i], strlen(tab_env[i]));
		write(fd, "\n", 1);
		i++;
	}
	return (EXIT_SUCCESS);
}
