/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_to_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <dclark@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 12:31:48 by david             #+#    #+#             */
/*   Updated: 2022/01/06 14:03:07 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	diff_cmd_redir(char *str)
{
	int	flag;

	flag = 0;
	if (ft_strncmp(str, "echo", ft_strlen("echo")) == 0)
		flag = 1;
	else if (ft_strncmp(str, "cd", ft_strlen("cd")) == 0)
		flag = 2;
	else if (ft_strncmp(str, "pwd", ft_strlen("pwd")) == 0)
		flag = 3;
	else if (ft_strncmp(str, "export", ft_strlen("export")) == 0)
		flag = 4;
	else if (ft_strncmp(str, "unset", ft_strlen("unset")) == 0)
		flag = 5;
	else if (ft_strncmp(str, "env", ft_strlen("env")) == 0)
		flag = 6;
	else if (ft_strncmp(str, "exit", ft_strlen("exit")) == 0)
		flag = 7;
	else if (ft_strncmp(str, ">", ft_strlen(">")) == 0)
		flag = 8;
	else if (ft_strncmp(str, "<", ft_strlen("<")) == 0)
		flag = 9;
	else if (ft_strncmp(str, ">>", ft_strlen(">>")) == 0)
		flag = 10;
	else if (ft_strncmp(str, "<<", ft_strlen("<<")) == 0)
		flag = 11;
	else if (ft_strncmp(str, "|", ft_strlen("|")) == 0)
		flag = 12;
	return (flag);
}

t_lst	*tab_to_list(char **tabx)
{
	t_lst	*list;
	int		i_tab;
	
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
