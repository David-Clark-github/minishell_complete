/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <dclark@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:39:38 by david             #+#    #+#             */
/*   Updated: 2022/01/06 17:51:19 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_env(char **tab_env, int fd)
{
	int	i;

	i = 0;
	while (tab_env[i])
	{
		write(fd, tab_env[i], strlen(tab_env[i]));
		i++;
	}
	return (EXIT_SUCCESS);
}
