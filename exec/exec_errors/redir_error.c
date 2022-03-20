/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 17:52:11 by seciurte          #+#    #+#             */
/*   Updated: 2022/03/20 03:51:38 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	redir_error(char *token)
{
	char	*tmp;

	if (ft_strlen(token) > 0)
		tmp = my_strjoin("Minishell: ", token);
	else
		tmp = my_strjoin("Minishell: ", "");
	if (tmp == NULL)
		fatal_error();
	perror(tmp);
	free(tmp);
	g_err_num = errno;
}
