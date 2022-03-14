/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 14:29:02 by dclark            #+#    #+#             */
/*   Updated: 2022/03/14 11:59:53 by dclark           ###   ########.fr       */
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

	i = 0;
	len = ft_tablen(str);
	while (str[i])
	{
		write(fd, str[i], ft_strlen(str[i]));
		if (i != (len - 1))
			write(fd, " ", 1);
		i++;
	}
	if (arg == 0)
		write(fd, "\n", 1);
	return (EXIT_SUCCESS);
}
