/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_to_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <dclark@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 12:31:48 by david             #+#    #+#             */
/*   Updated: 2021/12/24 21:08:39 by david            ###   ########.fr       */
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
		flag = 1;
	if (ft_strncmp(str, "pwd", ft_strlen("pwd")) == 0)
		flag = 1;
	if (ft_strncmp(str, "export", ft_strlen("export")) == 0)
		flag = 1;
	if (ft_strncmp(str, "unset", ft_strlen("unset")) == 0)
		flag = 1;
	if (ft_strncmp(str, "env", ft_strlen("env")) == 0)
		flag = 1;
	if (ft_strncmp(str, "exit", ft_strlen("exit")) == 0)
		flag = 1;
	return (flag);
}

t_lst	*tab_to_list(char **tab)
{
	t_lst	*list;
	int		i_tab;
	
	list = NULL;
	i_tab = 0;
	if (diff_cmd(tab[i_tab]) != 1)
	{
		//error = cmd not found;
		return (NULL);
	}
	else
	{
		while (tab[i_tab] != 0)
			add_lst_back(&list, tab[i_tab], i_tab);
	}
	return (list);
}
