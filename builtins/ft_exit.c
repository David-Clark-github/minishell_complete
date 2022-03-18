/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 11:27:43 by dclark            #+#    #+#             */
/*   Updated: 2022/03/18 17:03:49 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_exit(int num)
{
	get_mini()->er_num = num;
	ft_free_mini(get_mini(), 0);
	write(STDERR_FILENO, "\nexit\n", 6);
	exit(get_mini()->er_num);
}
