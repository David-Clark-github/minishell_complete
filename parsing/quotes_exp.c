/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_exp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 13:33:29 by dclark            #+#    #+#             */
/*   Updated: 2022/01/10 15:18:37 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*quotes_exp(char *str)
{
	int		i;
	char	*dest;
	int		quotes;

	i = 0;
	dest = NULL;
	quotes = 0;
	while (str[i])
	{
		if (str[i] != '\'' && str[i] != '\"')
			dest = ft_strljoin(dest, &str[i], 1);
		else
		{
			if (str[i] == '\'' && quotes == 0)
				quotes = 1;
			else if (str[i] == '\"' && quotes == 0)
				quotes = 2;
			dest = ft_strljoin(dest, "\n", 1);
			i++;
			if (quotes == 1)
			{
				while (str[i] != '\'')
				{
					dest = ft_strljoin(dest, &str[i], 1);
					i++;
				}
			}
			else if (quotes == 2)
			{
				while (str[i] != '\"')
				{
					dest = ft_strljoin(dest, &str[i], 1);
					i++;
				}
			}
			quotes = 0;
			dest = ft_strljoin(dest, "\n", 1);
		}
		i++;
	}
	free(str);
	return (dest);
}
