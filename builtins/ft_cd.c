/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <dclark@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 12:26:49 by david             #+#    #+#             */
/*   Updated: 2022/03/13 16:12:46 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	only_home(void)
{
	char	*tmp;

	tmp = ft_getenv("HOME", get_mini()->cp_ev);
	if (ft_tablen(get_mini()->cp_ev) == 0 || tmp == NULL)
	{
		free(tmp);
		printf("HOME not found");
		return (EXIT_FAILURE);
	}
	if (chdir(tmp) == 0)
	{
		free(tmp);
		return (EXIT_SUCCESS);
	}
	else
	{
		free(tmp);
		printf("cd: no such file or directory: %s\n", tmp);
		return (EXIT_FAILURE);
	}

}

int	ft_cd(char *path)
{
	char	*tmp;

	tmp = ft_strdup(path);
	if (0/*Regarder si il y a plus de 2 arguments apres cd*/)
	{
		printf("Too much argument for cd\n");
		get_mini()->er_num = 1;
		return (EXIT_FAILURE);
	}
	//pas besoin de check is tab_separ[1] existe puisque je le fais precedement
	if (get_mini()->tab_separ[1] && ft_strcmp(get_mini()->tab_separ[1], "~") == 0)
		return (only_home());
	if (get_mini()->tab_separ[1] && strncmp(get_mini()->tab_separ[1], "~", 1) == 0 && ft_strlen(get_mini()->tab_separ[1]) > 1)
		tmp = ft_strljoin(ft_getenv("HOME", get_mini()->cp_ev), &tmp[1], ft_strlen(&tmp[1]));
	printf("tmp = %s\n", tmp);
	if (chdir(tmp) == 0)
	{
		free(tmp);
		return (EXIT_SUCCESS);
	}
	else
	{
		printf("cd: no such file or directory: %s\n", path);
		return (EXIT_FAILURE);
	}
}
