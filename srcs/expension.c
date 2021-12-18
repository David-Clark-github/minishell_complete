/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expension.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <dclark@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 18:35:01 by david             #+#    #+#             */
/*   Updated: 2021/12/18 22:09:20 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*expension(char *buffer)
{
	char	*dest;
	//int		q_1;
	int		i;

	dest = NULL;
	i = 0;
	//q_1 = 0;
	while (buffer[i])
	{
		if (buffer[i] && buffer[i] != '$')
			dest = ft_strjoin(dest, &buffer[i]);
		else
		{
		}
		i++;
	}
	return (dest);
}
