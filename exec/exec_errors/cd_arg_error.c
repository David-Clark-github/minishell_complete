/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_arg_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 15:10:10 by seciurte          #+#    #+#             */
/*   Updated: 2022/03/19 15:11:22 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cd_arg_error(void)
{
	write(STDERR_FILENO, "Minishell: cd: too many arguments\n", 34);
	g_err_num = 1;
}