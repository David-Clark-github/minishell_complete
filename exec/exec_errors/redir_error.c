/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 17:52:11 by seciurte          #+#    #+#             */
/*   Updated: 2022/03/19 17:23:13 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	redir_error(char *token)
{
	char	*tmp;
	char	*tmp1;
	char	*msg;

	tmp = my_strjoin("Minishell: ", token);
	if (tmp == NULL)
		fatal_error();
	tmp1 = my_strjoin(tmp, ": ");
	if (tmp1 == NULL)
	{
		free(tmp);
		fatal_error();
	}
	free(tmp);
	msg = my_strjoin(tmp1, strerror(errno));
	free(tmp1);
	if (msg == NULL)
		fatal_error();
	write(STDERR_FILENO, msg, ft_strlen(msg));
	free(msg);
	g_err_num = 1;
}
