/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_of_element.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:33:16 by dclark            #+#    #+#             */
/*   Updated: 2022/03/16 18:58:27 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	simple_quotes(int *res, int *i, char *str)
{
	*res = *res + 1;
	*i = *i + 1;
	while (str[*i] && str[*i] != '\'')
		*i = *i + 1;
	*i = *i + 1;
}
/*
static void	double_quotes(int *res, int *i, char *str)
{
//	printf("avant double\n");
	*res = *res + 1;
	if (str[*i] == '\"')
		*i = *i + 1;
	while (str[*i] && str[*i] != '\"')
		*i = *i + 1;
	if (str[*i] && str[*i] == '\"')
		*i = *i + 1;
//	printf("apres double\n");
}
*/

int	num_of_element(char *str)
{
	int	res;
	int	i;

	res = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		if (str[i] == '\'')
			simple_quotes(&res, &i, &str[i]);
		else if (str[i] == '\"')
			//double_quotes(&res, &i, &str[i]);
		{
			res++;
			if (str[i] == '\"')
				i++;
			while (str[i] && str[i] != '\"')
				i++;
			if (str[i] && str[i] == '\"')
				i++;
		}
		else if (ft_checkcara(str[i], "<>|") == 0)
		{
			res++;
			while (str[i] && ft_checkcara(str[i], " <>|\'\"\t") == 0)
				i++;
		}
		else if (ft_checkcara(str[i], "<>") == 1)
		{
			res++;
			i++;
			if (str[i] && str[i] == str[i - 1])
				i++;
		}
		else if (ft_checkcara(str[i], "|") == 1)
		{
			res++;
			i++;
		}
	}
	return (res);
}
