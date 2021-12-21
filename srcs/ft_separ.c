/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_separ.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <dclark@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 10:00:55 by david             #+#    #+#             */
/*   Updated: 2021/12/21 19:20:57 by david            ###   ########.fr       */
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
	char	**dest;
	int		q_1;
	int		q_2;
	int		i_dest;
	int		i_str;
	int		num_ele;
	
	num_ele = num_of_element(str, ' ');
	dest = (char **)malloc(sizeof(char *) * num_ele + 1);
	i_dest = 0;
	i_str = 0;
	q_1 = 0;
	q_2 = 0;
	while (str[i] == ' ')
		i++;
	while (str[i])
	{
		if (str[i] == '\"' && q_1 == 0)
		{
			if (q_2 == 0)
				q_2 = 1;
			else if(q_2 == 1)
				q_2 == 0;
			i++;
		}
		else if (str[i] == '\'' && q_2 == 0)
		{
			if (q_1 == 0)
				q_1 == 1;
			else if (q_1 == 1)
				q_1 = 0;
			i++;
		}

	}
	dest[i_dest] = NULL;
	return (dest);
}
