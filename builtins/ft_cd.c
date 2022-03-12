/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <dclark@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 12:26:49 by david             #+#    #+#             */
/*   Updated: 2022/03/12 22:51:35 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_cd(char *path)
{
	if (ft_tablen(get_mini->tab_separ) > 2)
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
