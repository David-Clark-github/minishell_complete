/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 17:52:11 by seciurte          #+#    #+#             */
/*   Updated: 2022/03/19 19:37:38 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	redir_error(char *token)
{
	char	*tmp;
	char	*tmp1;

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
	perror(tmp1);
	free(tmp1);
	g_err_num = errno;
}
