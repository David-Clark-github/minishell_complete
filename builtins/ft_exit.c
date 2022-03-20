/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 11:27:43 by dclark            #+#    #+#             */
/*   Updated: 2022/03/20 06:44:42 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_exit(int num)
{
	ft_free_mini(get_mini(), 0);
	write(STDERR_FILENO, "exit\n", 5);
	close(get_mini()->save_stdin);
	close(STDIN_FILENO);
	exit(num);
}
