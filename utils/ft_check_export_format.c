/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_export_format.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:58:26 by dclark            #+#    #+#             */
/*   Updated: 2022/03/14 17:09:16 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_check_export_format(char *str)
{
	int	i;
	int	flag;

	i = -1;
	flag = 0;
	if (str == NULL)
		return (0);
	while (str[++i] && flag == 0)
		if (str[i] == '=')
			flag = 1;
	if (flag == 0)
		return (0);
	i = 0;
	while (str[i] && str[i] != '=')
	{
		if (ft_isalpha(str[i]))
			i++;
		else
			return (0);
	}
	return (1);
}
