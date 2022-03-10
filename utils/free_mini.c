/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mini.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <dclark@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 12:36:28 by david             #+#    #+#             */
/*   Updated: 2022/03/10 15:00:32 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_mini(t_mini *mini)
{
	if (mini->cp_ev != NULL)
		ft_freetab(mini->cp_ev);
	if (mini->prompt != NULL)
	{
		free(mini->prompt);
		mini->prompt = NULL;
	}
	if (mini->list != NULL)
		return ;
}
