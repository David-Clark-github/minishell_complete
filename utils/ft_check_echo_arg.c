/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_echo_arg.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:43:26 by dclark            #+#    #+#             */
/*   Updated: 2022/03/14 18:21:13 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_check_echo_arg(char **cmd)
{
	int	res;
	int	i;

	res = 0;
	i = 2;
	if (cmd && cmd[0])
	{
		if (ft_strncmp("-n", cmd[1], 2) == 0)
		{
			while (cmd[1][i])
			{
				if (cmd[1][i] == 'n')
					i++;
				else
					return (0);
			}
			res = 1;
		}
	}
	return (res);
}
