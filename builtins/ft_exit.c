/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 11:27:43 by dclark            #+#    #+#             */
/*   Updated: 2022/03/18 12:21:36 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_exit(int num, int print, int fd)
{
	get_mini()->er_num = num;
	ft_free_mini(get_mini(), 0);
	if (print == 1)
		write(fd, "exit", ft_strlen("exit"));
	exit(get_mini()->er_num);
}
