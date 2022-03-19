/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nb_arg_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 15:10:10 by seciurte          #+#    #+#             */
/*   Updated: 2022/03/19 17:29:46 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	nb_arg_error(char *token)
{
	char	*tmp;
	char	*tmp1;

	tmp = my_strjoin("Minishell: ", token);
	if (tmp == NULL)
		fatal_error();
	tmp1 = my_strjoin(tmp, ": too many arguments\n");
	if (tmp1 == NULL)
	{
		free(tmp);
		fatal_error();
	}
	free(tmp);
	write(STDERR_FILENO, tmp1, ft_strlen(tmp1));
	g_err_num = 1;
}
