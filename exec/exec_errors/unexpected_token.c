/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unexpected_token.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 17:34:49 by seciurte          #+#    #+#             */
/*   Updated: 2022/03/18 18:13:31 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	error_unexpected_token(char *token)
{
	char 	*tmp;
	char	*msg;

	tmp = my_strjoin(UNEXPECTED_TOKEN, token);
	if (tmp == NULL)
		exit_error(__LINE__);
	msg = my_strjoin(tmp, "'\n");
	free(tmp);
	if (msg == NULL)
		exit_error(__LINE__);
	write(STDERR_FILENO, msg, ft_strlen(msg));
	free(msg);
	g_err_num = 2;
}