/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unexpected_token.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 17:34:49 by seciurte          #+#    #+#             */
/*   Updated: 2022/03/13 05:58:57 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*msg_join(char *s1, char *s2, int size)
{
	
}

void	error_unexpected_token(t_mini *mini, char *token)
{
	char 	*tmp;
	char	*msg;

	tmp = ft_strljoin(UNEXPECTED_TOKEN, token,
			ft_strlen(UNEXPECTED_TOKEN) + ft_strlen(token));
	if (tmp == NULL)
		exit_error(__LINE__);
	msg = ft_strljoin(tmp, "'\n", ft_strlen(tmp) + 2);
	free(tmp);
	if (msg == NULL)
		exit_error(__LINE__);
	write(STDERR_FILENO, msg, ft_strlen(msg));
	free(msg);
	mini->er_num = 2;
}