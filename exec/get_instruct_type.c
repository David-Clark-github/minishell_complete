/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_instruct_type.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 13:08:01 by seciurte          #+#    #+#             */
/*   Updated: 2022/03/09 13:10:42 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_redir_stdin(int log)
{
	return (log == INPUT || log == HEREDOC);
}

int	is_redir_stdout(int log)
{
	return (log == TRUNC || log == APPEND);
}

int	is_cmd(int log)
{
	return ((log <= 7));
}

int	is_redir(int log)
{
	return (log >= 8 && log <= 11);
}