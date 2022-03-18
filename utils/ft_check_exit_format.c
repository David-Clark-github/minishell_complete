/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_exit_format.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 17:54:10 by dclark            #+#    #+#             */
/*   Updated: 2022/03/18 17:54:58 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_check_exit_format(char *str)
{
	int	i;
	while (str[i] && str[i] == ' ')
		i++;
	if (str[i] && (str[i] == '+' || str[i] == '-'))
		i++;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}
