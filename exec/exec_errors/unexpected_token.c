/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unexpected_token.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 17:34:49 by seciurte          #+#    #+#             */
/*   Updated: 2022/03/14 12:48:36 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	error_unexpected_token(t_mini *mini, char *token)
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
	mini->er_num = 2;
}