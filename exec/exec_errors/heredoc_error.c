/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 14:42:23 by seciurte          #+#    #+#             */
/*   Updated: 2022/03/19 14:52:30 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	heredoc_EOF_error(char *token)
{
	char	*tmp;
	char	*tmp1;

	tmp = my_strjoin(HEREDOC_EOF, token);
	if (tmp == NULL)
		exit_error(__LINE__);
	tmp1 = my_strjoin(tmp, "')\n");
	if (tmp1 == NULL)
	{
		free(tmp);
		exit_error(__LINE__);
	}
	free(tmp);
	write(STDERR_FILENO, tmp1, ft_strlen(tmp1));
	// write(STDOUT_FILENO, "\n", 1);
	g_err_num = 1;
	free(tmp1);
}