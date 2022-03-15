/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_to_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <dclark@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 12:31:48 by david             #+#    #+#             */
/*   Updated: 2022/03/14 19:15:33 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	algo1(int *tk_len, int *i_tab, int *flag)
{
	*tk_len = *tk_len - 1;
	*i_tab = *i_tab + 1;
	*flag = 1;
}

static void	algo2(int *cmd_f, char **tabx, int *i_tab, t_lst **list)
{
	*cmd_f = diff_cmd(tabx[*i_tab]);
	add_lst_back(&*list, tabx[*i_tab], *cmd_f, *i_tab);
}

static void	algo3(int *cmd_f, char **tabx, int *i_tab, t_lst **list)
{
	add_lst_back(&*list, tabx[*i_tab], 12, *i_tab);
	*cmd_f = 0;
}

int	*g_flag(void)
{
	static int	flag;

	return (&flag);
}

t_lst	*tab_to_list(char **tabx, int tk_len)
{
	t_lst	*list;
	int		i_tab;
	int		cmd_f;

	list = NULL;
	i_tab = 0;
	cmd_f = 0;
	if (tabx[i_tab] == NULL)
		return (NULL);
	while (i_tab < tk_len)
	{
		*g_flag() = 0;
		if (tabx[i_tab] == NULL)
			algo1(&tk_len, &i_tab, g_flag());
		if (cmd_f == 0 && diff_cmd(tabx[i_tab]) != 0 && *g_flag() == 0)
			algo2(&cmd_f, tabx, &i_tab, &list);
		else if (cmd_f != 0 && diff_redir(tabx[i_tab]) == 12 && *g_flag() == 0)
			algo3(&cmd_f, tabx, &i_tab, &list);
		else if (*g_flag() == 0)
			add_lst_back(&list, tabx[i_tab], diff_redir(tabx[i_tab]), i_tab);
		if (*g_flag() == 0)
			i_tab++;
	}
	return (list);
}
