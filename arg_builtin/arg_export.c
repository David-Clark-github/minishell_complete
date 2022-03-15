/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_export.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 13:12:07 by dclark            #+#    #+#             */
/*   Updated: 2022/03/15 14:49:20 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		to_equal(char *str)
{
	int	res;

	res = 0;
	while (str[res] && str[res] != '=')
		res++;
	return (res);
}

static int		after_equal(char *str)
{
	int	res;
	int	i;

	res = 0;
	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	if (str[i] == '=')
		i++;
	if (str[i] == '=')
		return (-1);
	while (str[i])
	{
		res++;
		i++;
	}
	return (res);
}

void	arg_export(char **tabx, t_mini *mini)
{
	int		it;
	int		is;
	char	*name;
	char	*data;

	it = 0;
	is = 0;
	name = NULL;
	data = NULL;
	while (tabx[it])
	{
		if (ft_strcmp(tabx[it], "export") == 0 && tabx[it + 1])
		{
			it++;
			name = ft_strljoin(name, tabx[it], to_equal(tabx[it]));
			is = to_equal(tabx[it]);
			if (is == ft_strlen(tabx[it]))
				break;
			if (after_equal(tabx[it]) != -1)
				data = ft_strljoin(data, &tabx[it][is + 1], after_equal(&tabx[it][is]));
			ft_export(&name, &data, 1, &mini->cp_ev);
			//printf("name = %s\ndata = %s\n", name, data);
		}
		it++;
	}
	free(name);
	free(data);
	mini->er_num = 0;
}
