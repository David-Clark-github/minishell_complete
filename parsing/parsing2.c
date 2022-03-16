/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 10:38:17 by dclark            #+#    #+#             */
/*   Updated: 2022/03/16 15:26:43 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//EXPENSION: si variable d'environement, elle l'etend
void	parsing(t_mini *mini)
{
	int	i;

	i = 0;
	//expension(mini);
	/*
	if (mini->exp == NULL)
		return ;
		*/
	mini->tab_separ = ft_separ(mini->prompt, &mini->tab_len);
	while (mini->tab_separ[i] && mini->int_separ[i] != 1)
	{
		if (mini->int_separ[i] != 1)
		{
				if (i != 0 && (mini->int_separ[i] != 2 || diff_redir(mini->tab_separ[i - 1]) != 10))
					mini->tab_separ[i] = expension(mini->tab_separ[i]);
		}
			i++;
	}
	mini->list = tab_to_list(mini->tab_separ, mini->tab_len);
}
