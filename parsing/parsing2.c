/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 10:38:17 by dclark            #+#    #+#             */
/*   Updated: 2022/02/15 16:26:59 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//EXPENSION: si variable d'environement, elle l'etend
void	parsing(t_mini *mini)
{
	mini->exp = expension(mini->prompt, &mini->er_num, mini->cp_ev);
	if (mini->exp == NULL)
		return;
	mini->tab_separ = ft_separ(mini->exp, &mini->tab_len);
	if (check_cmd(mini->tab_separ) == -1)
	{
		//printf("command not found: %s\n", mini->tab_separ[0]);
		mini->er_num = 56;
		return;
	}
	if (check_tab(mini->tab_separ) == 0)
		return;
	mini->list = tab_to_list(mini->tab_separ, mini->tab_len);
}
