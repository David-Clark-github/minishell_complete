/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fatal_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 16:01:53 by seciurte          #+#    #+#             */
/*   Updated: 2022/03/20 00:54:41 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	fatal_error(void)
{
	dprintf(2, "fatal error\n");
	ft_free_mini(get_mini(), 0);
	perror("Minishell: ");
	exit(-42);
}
