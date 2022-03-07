/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mini.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <dclark@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 12:36:28 by david             #+#    #+#             */
/*   Updated: 2022/03/07 16:31:37 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_mini(t_mini *mini)
{
	if (mini->cp_ev != NULL)
		ft_freetab(mini->cp_ev);
	if (mini->prompt != NULL) {
		free(mini->prompt);
		mini->prompt = NULL;
	}
	if (mini->exp != NULL) {
		free(mini->exp);
		mini->exp = NULL;
	}
	if (mini->tab_separ != NULL)
		ft_freetab(mini->tab_separ);
	if (mini->list != NULL)
		return ;
}
