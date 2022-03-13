/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freetab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 14:18:41 by dclark            #+#    #+#             */
/*   Updated: 2022/03/10 14:59:26 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_freetab(char **tabx)
{
	int	tab_len;
	int	i;

	if (!tabx)
		return ;
	tab_len = ft_tablen(tabx);
	i = 0;
	while (i <= tab_len)
	{
		free(tabx[i]);
		tabx[i] = NULL;
		i++;
	}
	free(tabx);
	tabx = NULL;
}
