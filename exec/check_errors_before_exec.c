/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors_before_exec.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 22:33:45 by seciurte          #+#    #+#             */
/*   Updated: 2022/03/11 00:27:22 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_errors_before_exec(t_mini *mini)
{
	t_lst		*tmp;

	if (mini->list == NULL || mini->list->str == NULL)
		return (1);
	tmp = mini->list;
	while (tmp)
	{
		if (is_redir(tmp->log) && (!tmp->next || !tmp->next->str))
			return (error_unexpected_token(mini, "newline"), 2);
		else if (is_redir(tmp->log) && (!tmp->next
			|| (tmp->next->log <= 12 && tmp->next->log > 0)))
			return (error_unexpected_token(mini, "newline"), 2);
		else if (tmp->log == PIPE && (!tmp->next || !tmp->next->str))
			return (error_unexpected_token(mini, "|"), 2);
		tmp = tmp->next;
	}
	return (0);
}