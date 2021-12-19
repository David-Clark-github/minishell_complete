/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <dclark@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 21:42:28 by david             #+#    #+#             */
/*   Updated: 2021/12/19 20:01:37 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*ft_strjoin(char *str_1, char *str_2)
{
	char	*dest;
	int		i_dest;
	int		i_str;

	i_dest = 0;
	i_str = 0;
	dest = (char *)malloc(sizeof(char) * ((ft_strlen(str_1) + 1) + 1));
	if (dest == NULL)
		return (NULL);
	while (str_1 != NULL && str_1[i_str])
	{
		dest[i_dest] = str_1[i_str];
		i_str++;
		i_dest++;
	}
	i_str = 0;
	if (str_2[i_str] != '\0')
	{
		dest[i_dest] = str_2[i_str];
		i_dest++;
	}
	dest[i_dest] = '\0';
	if (str_1 != NULL)
		free(str_1);
	return (dest);
}
