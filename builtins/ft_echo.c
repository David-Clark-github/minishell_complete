/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 14:29:02 by dclark            #+#    #+#             */
/*   Updated: 2022/01/04 14:40:48 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/*
 * if arg == 0
 * write an '\n' at the end of the string
 */

int	ft_echo(char *str, int arg)
{
	write(1, str, ft_strlen(str));
	if (arg == 0)
	{
		write(1, "\n", 1);
	}
	return (EXIT_SUCCESS);
}
