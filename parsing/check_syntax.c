/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 18:25:46 by dclark            #+#    #+#             */
/*   Updated: 2022/01/24 18:40:49 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	simple_syntax(char **tab_separ)
{
	int	i;

	i = 0;
	while (tab_separ[i])
	{
		if (diff_cmd_redir(tab_separ[i]) > 7 && tab_separ[i + 1] == 0)
			return (-1);
		if (diff_cmd_redir(tab_separ[i]) == 12)
			if (diff_cmd_redir(tab_separ[i + 1]) < 1 || diff_cmd_redir(tab_separ[i + 1]) > 7)
				return (-1);
		i++;
	}
	return (1);
}

int	check_syntax(t_mini *mini)
{
	if (simple_syntax(mini->tab_separ) == -1) {
		mini->er_num = 28;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
