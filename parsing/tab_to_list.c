/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_to_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <dclark@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 12:31:48 by david             #+#    #+#             */
/*   Updated: 2022/01/19 16:15:40 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
/*
int	diff_cmd(char *str)
{
	int	flag;

	flag = 0;
	if (ft_strcmp(str, "echo") == 0)
		flag = 1;
	else if (ft_strcmp(str, "cd") == 0)
		flag = 2;
	else if (ft_strcmp(str, "pwd") == 0)
		flag = 3;
	else if (ft_strcmp(str, "export") == 0)
		flag = 4;
	else if (ft_strcmp(str, "unset") == 0)
		flag = 5;
	else if (ft_strcmp(str, "env") == 0)
		flag = 6;
	else if (ft_strcmp(str, "exit") == 0)
		flag = 7;
	else if (ft_strcmp(str, ">>") == 0)
		flag = 8;
	else if (ft_strcmp(str, "<<") == 0)
		flag = 9;
	else if (ft_strcmp(str, ">") == 0)
		flag = 10;
	else if (ft_strcmp(str, "<") == 0)
		flag = 11;
	else if (ft_strcmp(str, "|") == 0)
		flag = 12;
	return (flag);
}
*/
t_lst	*tab_to_list(char **tabx)
{
	t_lst	*list;
	int		i_tab;
	//int		lst_log;
	
	list = NULL;
	i_tab = 0;
	if (!tabx[i_tab])
		return (NULL);
	else
	{
		while (tabx[i_tab])
		{
			add_lst_back(&list, tabx[i_tab], diff_cmd_redir(tabx[i_tab]), i_tab);
			i_tab++;
		}
	}
	return (list);
}
