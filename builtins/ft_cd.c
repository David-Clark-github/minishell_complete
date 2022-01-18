/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <dclark@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 12:26:49 by david             #+#    #+#             */
/*   Updated: 2022/01/18 17:15:15 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_cd(char *path)
{
	printf("\"path\" = %s\n", path);
	if (chdir(path) == 0)
	{	
		printf("OK !");
		return (EXIT_SUCCESS);
	}
	else
	{
		return (EXIT_FAILURE);
		printf("KO !");
	}
}
