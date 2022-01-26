/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mini.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <dclark@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 12:36:28 by david             #+#    #+#             */
/*   Updated: 2022/01/26 12:38:31 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_mini(t_mini *mini)
{
	if (mini->cp_ev != NULL)
		ft_freetab(mini->cp_ev);
	if (mini->prompt != NULL)
	if (mini->exp != NULL)
	if (mini->tab_separ != NULL)
	if (mini->list != NULL)
}
