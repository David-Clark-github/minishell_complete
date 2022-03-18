/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors_before_exec.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 22:33:45 by seciurte          #+#    #+#             */
/*   Updated: 2022/03/18 18:13:56 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_errors_before_exec(t_mini *mini)
{
	t_lst		*tmp;
	t_lst		*prev;

	if (mini->list == NULL || mini->list->str == NULL)
		return (1);
	tmp = mini->list;
	prev = NULL;
	while (tmp)
	{
		if (is_redir(tmp->log) && !tmp->next)
			return (error_unexpected_token("newline"), 2);
		else if (is_redir(tmp->log) && (!tmp->next
				|| (tmp->next->log <= 12 && tmp->next->log > 0)))
			return (error_unexpected_token("newline"), 2);
		else if (tmp->log == PIPE && (!tmp->next || tmp->next->log == PIPE
				|| prev == NULL))
			return (error_unexpected_token("|"), 2);
		prev = tmp;
		tmp = tmp->next;
	}
	return (0);
}
