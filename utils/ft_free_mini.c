/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_mini.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <dclark@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 12:36:28 by david             #+#    #+#             */
/*   Updated: 2022/03/14 13:52:05 by dclark           ###   ########.fr       */
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

static void	rest(t_mini *mini)
{
	if (mini->prompt != NULL)
	{
		free(mini->prompt);
		mini->prompt = NULL;
	}
	if (mini->exp != NULL)
	{
		free(mini->exp);
		mini->exp = NULL;
	}
	if (mini->list != NULL)
	{
		ft_freelst(&mini->list);
		mini->list = NULL;
	}
	if (mini->tab_separ != NULL)
	{
		ft_freetab(mini->tab_separ);
		mini->tab_separ = NULL;
	}
}

void	ft_free_mini(t_mini *mini, int i)
{
	if (i == 0)
	{
		if (mini->cp_ev != NULL)
		{
			ft_freetab(mini->cp_ev);
			mini->cp_ev = NULL;
		}
	}
	rest(mini);
}
