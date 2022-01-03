/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_to_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <dclark@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 12:31:48 by david             #+#    #+#             */
/*   Updated: 2022/01/03 16:55:10 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

int	diff_cmd(char *str)
{
	int	flag;

	flag = 0;
	if (ft_strncmp(str, "echo", ft_strlen("echo")) == 0)
		flag = 1;
	if (ft_strncmp(str, "cd", ft_strlen("cd")) == 0)
		flag = 2;
	if (ft_strncmp(str, "pwd", ft_strlen("pwd")) == 0)
		flag = 3;
	if (ft_strncmp(str, "export", ft_strlen("export")) == 0)
		flag = 4;
	if (ft_strncmp(str, "unset", ft_strlen("unset")) == 0)
		flag = 5;
	if (ft_strncmp(str, "env", ft_strlen("env")) == 0)
		flag = 6;
	if (ft_strncmp(str, "exit", ft_strlen("exit")) == 0)
		flag = 7;
	return (flag);
}

t_lst	*tab_to_list(char **tabx)
{
	t_lst	*list;
	int		i_tab;
	
	list = NULL;
	i_tab = 0;
	if (tabx[i_tab] && diff_cmd(tabx[i_tab]) == 0)
		return (NULL);
	else
	{
		add_lst_back(&list, tabx[i_tab], diff_cmd(tabx[i_tab]));
		i_tab++;
		while (tabx[i_tab])
		{
			add_lst_back(&list, tabx[i_tab], 0);
			i_tab++;
		}
	}
	return (list);
}
