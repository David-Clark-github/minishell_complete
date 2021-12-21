/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_separ.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <dclark@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 10:00:55 by david             #+#    #+#             */
/*   Updated: 2021/12/21 10:19:37 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	num_of_element(char *str, char c)
{
	int	res;
	int	i;

	res = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			i++;
		else if (str[i] == '\'')
		{
			res++;
			i++;
			while (str[i] && str[i] != '\'')
				i++;
			i++;
		}
		else if (str[i] == '\"')
		{
			res++;
			i++;
			while (str[i] && str[i] != '\"')
				i++;
			i++;
		}
		else if (isalpha(str[i]))
		{
			res++;
			i++;
			while (str[i] && isalpha(str[i]))
				i++;
		}
	}
	return (res);
}

char	**ft_separ(char *str, char c)
{
	printf("c = %c\n", c);
	int	res = num_of_element(str, ' ');
	printf("res = %d\n", res);
	return (NULL);
}
