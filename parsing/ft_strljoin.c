/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strljoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 13:38:28 by dclark            #+#    #+#             */
/*   Updated: 2022/01/04 17:29:09 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static char	*zero_len(void)
{
	char	*dest;

	dest = malloc(sizeof(char *));
	dest[0] = '\0';
	return (dest);
}

char	*ft_strljoin(char *s1, char *s2, int s2_len)
{
	char	*dest;
	int		i_s;
	int		i_d;

	i_s = 0;
	i_d = 0;
	if (s2_len == 0)
		return (zero_len());
	dest = malloc(sizeof(char) * (ft_strlen(s1) + s2_len + 1));
	if (dest == NULL)
		return (NULL);
	while (s1 && s1[i_s])
	{
		dest[i_d] = s1[i_s];
		i_s++;
		i_d++;
	}
	i_s = 0;
	while (s2[i_s] && s2_len-- > 0)
	{
		dest[i_d] = s2[i_s];
		i_d++;
		i_s++;
	}
	dest[i_d] = '\0';
	return (dest);
}
