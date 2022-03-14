/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 10:38:17 by dclark            #+#    #+#             */
/*   Updated: 2022/03/14 18:28:54 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//EXPENSION: si variable d'environement, elle l'etend
void	parsing(t_mini *mini)
{
	mini->exp = expension(mini);
	if (mini->exp == NULL)
		return;
	mini->tab_separ = ft_separ(mini->exp, &mini->tab_len);
	/*
	if (check_tab(mini->tab_separ) == 0)
		return;
	*/
	mini->list = tab_to_list(mini->tab_separ, mini->tab_len);
}
