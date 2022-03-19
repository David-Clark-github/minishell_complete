/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_format_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 17:33:07 by seciurte          #+#    #+#             */
/*   Updated: 2022/03/19 18:40:06 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	arg_format_error(char *token)
{
	char	*tmp;
	char	*tmp1;

	tmp = my_strjoin("Minishell: exit: ", token);
	if (tmp == NULL)
		fatal_error();
	tmp1 = my_strjoin(tmp, ": numeric argument required\n");
	if (tmp1 == NULL)
	{
		free(tmp);
		fatal_error();
	}
	free(tmp);
	write(STDERR_FILENO, tmp1, ft_strlen(tmp1));
	g_err_num = 2;
}