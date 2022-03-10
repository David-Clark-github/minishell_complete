/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 14:50:01 by dclark            #+#    #+#             */
/*   Updated: 2022/03/10 11:20:55 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	malloc_len(long nb)
{
	int	res;

	res = 1;
	if (nb == 0)
		return (2);
	if (nb < 0)
	{
		res++;
		nb *= -1;
	}
	while (nb)
	{
		nb /= 10;
		res++;
	}
	return (res);
}

static char	*alloc_dest(char *dest, long nb, int len)
{
	if (nb == 0)
		dest[0] = '0';
	if (nb < 0)
	{
		nb *= -1;
		dest[0] = '-';
	}
	while (nb)
	{
		dest[len] = (nb % 10) + '0';
		nb /= 10;
		len--;
	}
	return (dest);
}

char	*ft_itoa(int n)
{
	long	nb;
	int		m_len;
	char	*dest;

	nb = (long)n;
	m_len = malloc_len(nb);
	dest = malloc(sizeof(char) * m_len);
	if (dest == NULL)
		return (NULL);
	dest[m_len - 1] = '\0';
	dest = alloc_dest(dest, nb, m_len - 2);
	return (dest);
}
