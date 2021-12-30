/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_exp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 13:33:29 by dclark            #+#    #+#             */
/*   Updated: 2021/12/30 15:31:53 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*quotes_exp(char *str)
{
	int		i;
	char	*dest;

	i = 0;
	dest = NULL;
	while (str[i])
	{
		if (str[i] != '\'' && str[i] != '\"')
			dest = ft_strljoin(dest, &str[i], 1);
		i++;
	}

	free(str);
	return (dest);
}
