/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mini.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <dclark@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 12:31:21 by david             #+#    #+#             */
/*   Updated: 2022/01/26 12:33:03 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_mini(t_mini *mini)
{
	mini->cp_ev = NULL;
	mini->er_num = 0;
	mini->prompt = NULL;
	mini->exp = NULL;
	mini->tab_separ = NULL;
	mini->tab_len = 0;
	mini->list = NULL;
}
