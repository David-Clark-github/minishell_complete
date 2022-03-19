/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 17:52:11 by seciurte          #+#    #+#             */
/*   Updated: 2022/03/19 12:53:09 by seciurte         ###   ########.fr       */
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
		exit_error(__LINE__);
	tmp1 = my_strjoin(tmp, ": ");
	if (tmp1 == NULL)
	{
		free(tmp);
		exit_error(__LINE__);
	}
	free(tmp);
	msg = my_strjoin(tmp1, strerror(errno));
	free(tmp1);
	if (msg == NULL)
		exit_error(__LINE__);
	write(STDERR_FILENO, msg, ft_strlen(msg));
	write(STDOUT_FILENO, "\n", 1);
	free(msg);
	g_err_num = errno;
}
