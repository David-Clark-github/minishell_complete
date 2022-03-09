/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 16:58:24 by seciurte          #+#    #+#             */
/*   Updated: 2022/03/09 17:14:52 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	malloc_error(t_mini *mini)
{
	write(STDERR_FILENO, "Minishell: Out of memory\n", 25);
	exit(EXIT_FAILURE);
}