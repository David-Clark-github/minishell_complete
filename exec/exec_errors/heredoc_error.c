/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 14:42:23 by seciurte          #+#    #+#             */
/*   Updated: 2022/03/19 17:23:05 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	heredoc_eof_error(char *token)
{
	char	*tmp;
	char	*tmp1;

	tmp = my_strjoin(HEREDOC_EOF, token);
	if (tmp == NULL)
		fatal_error();
	tmp1 = my_strjoin(tmp, "')\n");
	if (tmp1 == NULL)
	{
		free(tmp);
		fatal_error();
	}
	free(tmp);
	write(STDERR_FILENO, tmp1, ft_strlen(tmp1));
	g_err_num = 1;
	free(tmp1);
}
