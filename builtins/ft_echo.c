/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 14:29:02 by dclark            #+#    #+#             */
/*   Updated: 2022/03/18 18:37:44 by dclark           ###   ########.fr       */
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
		res_w = write(fd, str[i], ft_strlen(str[i]));
		if (res_w == -1)
		{
			write(2, "Minishell: write error: no space left on device\n", 48);
			return (EXIT_FAILURE);
		}
		if (i != (len - 1))
			write(fd, " ", 1);
		i++;
	}
	if (arg == 0)
		write(fd, "\n", 1);
	return (EXIT_SUCCESS);
}
