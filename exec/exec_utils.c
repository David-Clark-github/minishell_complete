/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 14:36:00 by seciurte          #+#    #+#             */
/*   Updated: 2022/03/19 20:28:02 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_nb_of_args(t_lst *lst)
{
	int		nb_args;

	nb_args = 0;
	while (lst && lst->log != PIPE)
	{
		if (lst->log == 0 || is_builtin(lst->log))
			nb_args++;
		if (is_redir(lst->log))
			lst = lst->next->next;
		else
			lst = lst->next;
	}
	return (nb_args);
}

char	**get_args(t_lst *lst)
{
	char	**cmd;
	int		i;
	int		nb_args;

	i = 0;
	nb_args = get_nb_of_args(lst);
	cmd = malloc(sizeof(char *) * (nb_args + 1));
	if (cmd == NULL)
		return (NULL);
	while (lst && lst->log != PIPE)
	{
		if (lst->log == 0 || is_builtin(lst->log))
		{
			if (ft_strlen(lst->str) == 0)
				cmd[i] = "";
			else
				cmd[i] = lst->str;
			i++;
			lst = lst->next;
		}
		else
			lst = lst->next->next;
	}
	cmd[i] = NULL;
	return (cmd);
}
