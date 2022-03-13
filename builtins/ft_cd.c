/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <dclark@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 12:26:49 by david             #+#    #+#             */
/*   Updated: 2022/03/13 10:20:21 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_cd(char *path)
{
	if (/*ft_tablen(get_mini->tab_separ) > 2*/ /*Regarder si il y a plus de 2 arguments apres cd*/)
	{
		printf("Too much argument for cd\n");
		get_mini()->err_num = 1;
		return (EXIT_FAILURE);
	}
	if (chdir(path) == 0)
		return (EXIT_SUCCESS);
	else
	{
		printf("cd: no such file or directory: %s\n", path);
		return (EXIT_FAILURE);
	}
}
