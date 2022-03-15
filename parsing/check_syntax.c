/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 18:25:46 by dclark            #+#    #+#             */
/*   Updated: 2022/03/15 12:45:40 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	simple_syntax(char **tab_separ)
{
	int	i;

	i = -1;
	while (tab_separ[++i])
	{
		if (tab_separ[i + 1])
		{
			if (diff_redir(tab_separ[i]) != 0)
				if (diff_redir(tab_separ[i + 1]) != 0)
					return (1);
		}
	}
	return (0);
}

int	check_syntax(t_mini *mini)
{
	if (simple_syntax(mini->tab_separ) != 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
