/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 14:29:02 by dclark            #+#    #+#             */
/*   Updated: 2022/03/19 20:01:51 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 * if arg == 0
 * write an '\n' at the end of the string
 *
 * =======================================
 *
 * if arg == 1
 * there will be no \n at the end
 */

static int	end_echo(int fd, int arg)
{
	int	res_w;

	if (arg == 0)
		res_w = write(fd, "\n", 1);
	if (res_w == -1)
	{
		write(2, "Minishell: echo: "WRITE_ERR"\n", 54);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	ft_echo(char **str, int arg, int fd)
{
	int	i;
	int	len;
	int	res_w;

	i = 0;
	res_w = 0;
	len = ft_tablen(str);
	while (str[i])
	{
		if (ft_strlen(str[i]) == 0)
			res_w = write(fd, " ", 1);
		else
			res_w = write(fd, str[i], ft_strlen(str[i]));
		if (res_w == -1)
			return (end_echo(fd, arg));
		if (i != (len - 1))
			write(fd, " ", 1);
		i++;
	}
	return (end_echo(fd, arg));
}
