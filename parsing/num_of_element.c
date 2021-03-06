/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_of_element.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:33:16 by dclark            #+#    #+#             */
/*   Updated: 2022/03/20 03:22:14 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	simple_quotes(int *res, int *i, char *str)
{
	if (ft_strlen(&str[*i]) > 0)
		*res = *res + 1;
	*i = *i + 1;
	while (str[*i] && str[*i] != '\'')
		*i = *i + 1;
	*i = *i + 1;
}

static void	double_quotes(int *res, int *i, char *str)
{
	if (ft_strlen(&str[*i]) > 0)
		*res = *res + 1;
	if (str[*i] == '\"')
		*i = *i + 1;
	while (str[*i] && str[*i] != '\"')
		*i = *i + 1;
	if (str[*i] && str[*i] == '\"')
		*i = *i + 1;
}

static void	algo1(int *res, int *i, char *str)
{
	if (ft_strlen(&str[*i]) > 0)
		*res = *res + 1;
	while (str[*i] && ft_checkcara(str[*i], " <>|\'\"\t") == 0)
		*i = *i + 1 ;
}

static void	algo2(int *res, int *i, char *str)
{
	if (ft_strlen(&str[*i]) > 0)
		*res = *res + 1;
	*i = *i + 1;
	if (str[*i] && str[*i] == str[*i - 1])
		*i = *i + 1 ;
}

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
			simple_quotes(&res, &i, str);
		else if (str[i] == '\"')
			double_quotes(&res, &i, str);
		else if (ft_checkcara(str[i], "<>|") == 0)
			algo1(&res, &i, str);
		else if (ft_checkcara(str[i], "<>") == 1)
			algo2(&res, &i, str);
		else if (ft_checkcara(str[i], "|") == 1)
		{
			res++;
			i++;
		}
	}
	return (res);
}
