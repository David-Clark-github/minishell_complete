/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freetab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 14:18:41 by dclark            #+#    #+#             */
/*   Updated: 2022/01/18 14:25:05 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_freetab(char **tabx)
{
	int	tab_len;
	int	i;

	tab_len = ft_tablen(tabx);
	i = 0;
	while (i <= tab_len)
	{
		free(tabx[i]);
		i++;
	}
	free(tabx);
}
