/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 08:52:34 by seciurte          #+#    #+#             */
/*   Updated: 2022/02/02 08:52:43 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	ft_strlcpy(char *dst, char *src, size_t size)
{
	size_t		i;
	size_t		s_src;

	if (!dst && !src)
		return (0);
	i = 1;
	s_src = ft_strlen(src);
	while (*src && i < size)
	{
		*dst = *src;
		src++;
		dst++;
		i++;
	}
	if (size != 0)
		*dst = '\0';
	return (s_src);
}