/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mini.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <dclark@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 12:36:28 by david             #+#    #+#             */
/*   Updated: 2022/03/11 18:08:25 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_freelst(t_lst **list)
{
	t_lst	*tmp;

	while (*list)
	{
		tmp = (*list)->next;
		free(*list);
		*list = tmp;
	}
}

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
		ft_freelst(&mini->list);
}
