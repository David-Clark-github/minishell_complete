/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 14:29:02 by dclark            #+#    #+#             */
/*   Updated: 2022/01/07 18:19:37 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/*
 * if arg == 0
 * write an '\n' at the end of the string
 */

int	ft_echo(char *str, int arg, int fd)
{
	write(fd, str, ft_strlen(str));
	if (arg == 0)
	{
		write(fd, "\n", 1);
	}
	return (EXIT_SUCCESS);
}
