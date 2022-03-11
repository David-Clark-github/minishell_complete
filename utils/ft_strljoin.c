/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strljoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 13:38:28 by dclark            #+#    #+#             */
/*   Updated: 2022/03/11 18:04:37 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*start(char *dest, char *s1, int s2_len)
{
	if (s2_len == 0)
		return (NULL);
	dest = malloc(sizeof(char) * (ft_strlen(s1) + s2_len + 1));
	if (dest == NULL)
		return (free(dest), NULL);
	return (dest);
}

char	*ft_strljoin(char *s1, char *s2, int s2_len)
{
	char	*dest;
	int		i_s;
	int		i_d;

	dest = NULL;
	dest = start(dest, s1, s2_len);
	if (dest == NULL)
		return (NULL);
	i_s = -1;
	i_d = 0;
	while (s1 && s1[++i_s])
	{
		dest[i_d] = s1[i_s];
		i_d++;
	}
	i_s = -1;
	while (s2[++i_s] && s2_len-- > 0)
	{
		dest[i_d] = s2[i_s];
		i_d++;
	}
	dest[i_d] = '\0';
	if (s1 != NULL)
		free(s1);
	return (dest);
}
