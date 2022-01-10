/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tablen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <dclark@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 15:53:33 by david             #+#    #+#             */
/*   Updated: 2022/01/10 15:58:51 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// I use [tableau] because the name [tab] canot be used with term.h

int	ft_tablen(char **tableau)
{
	int	i;

	i = 0;
	if (!tableau)
		return (i);
	while(tableau[i])
		i++;
	return (i);
}
