/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 14:51:03 by dclark            #+#    #+#             */
/*   Updated: 2022/01/19 17:55:38 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_pipe(char **tab_separ, int i)
{
	if (tab_separ[i + 1] == 0)
		return (0);
	if (diff_cmd_redir(tab_separ[i + 1]) < 1)
		return (0);
	if (diff_cmd_redir(tab_separ[i + 1]) > 7)
		return (0);
	return (1);
}

int	check_tab(char **tab_separ)
{
	int	i;

	i = 0;
	while (tab_separ[i])
	{
		if (diff_cmd_redir(tab_separ[i]) == 12)
			if (check_pipe(tab_separ, i) == 0)
				return (0);
		i++;
	}
	return (1);
}
