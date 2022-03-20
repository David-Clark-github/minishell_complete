/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_separ2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 10:00:55 by david             #+#    #+#             */
/*   Updated: 2022/03/20 02:43:55 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	init_elem(int *i_dest, int *i_str, int *tk_len, char *str)
{
	*tk_len = num_of_element(str);
	*i_dest = 0;
	*i_str = 0;
}

char	**ft_separ(char *str, int *tk_len)
{
	char	**dest;
	int		i_dest;
	int		i_str;

	init_elem(&i_dest, &i_str, tk_len, str);
	dest = (char **)malloc(sizeof(char *) * (*tk_len + 1));
	init_token(dest, *tk_len + 1);
	while (str[i_str] == ' ')
		i_str++;
	while (str[i_str])
	{
		while (str[i_str] && str[i_str] == ' ')
			i_str++;
		if (str[i_str] && str[i_str] == '\'')
			simple_q(&i_str, &i_dest, str, dest);
		else if (str[i_str] && str[i_str] == '\"')
			double_q(&i_str, &i_dest, str, dest);
		else if (str[i_str] && ft_checkcara(str[i_str], " <>|\'\"") == 0)
			zero_cara(&i_str, &i_dest, str, dest);
		else if (str[i_str] && ft_checkcara(str[i_str], "<>") == 1)
			one_cara(&i_str, &i_dest, str, dest);
		else if (str[i_str] && ft_checkcara(str[i_str], "|") == 1)
			one_pipe(&i_str, &i_dest, str, dest);
	}
	return (dest);
}
