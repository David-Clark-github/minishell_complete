/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <dclark@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 21:42:28 by david             #+#    #+#             */
/*   Updated: 2022/03/14 14:17:25 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	algo(char *dest, char *s1, char *s2)
{
	int	i_d;
	int	i_s;

	i_d = 0;
	i_s = 0;
	while (s1 != NULL && s1[i_s])
	{
		dest[i_d] = s1[i_s];
		i_s++;
		i_d++;
	}
	i_s = 0;
	if (s2[i_s] && s2[i_s] != '\0')
	{
		dest[i_d] = s2[i_s];
		i_d++;
	}
	dest[i_d] = '\0';
	if (s1 != NULL)
	{
		free(s1);
		s1 = NULL;
	}
}

char	*ft_strjoin(char *str_1, char *str_2)
{
	char	*dest;

	dest = (char *)malloc(sizeof(char) * ((ft_strlen(str_1) + 1) + 1));
	if (dest == NULL)
		return (NULL);
	algo(dest, str_1, str_2);
	return (dest);
}
