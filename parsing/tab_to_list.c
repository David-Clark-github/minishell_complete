/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_to_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <dclark@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 12:31:48 by david             #+#    #+#             */
/*   Updated: 2022/03/11 18:20:50 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_lst	*tab_to_list(char **tabx, int tk_len)
{
	t_lst	*list;
	int		i_tab;
	int		cmd_f;
	int		flag;
	
	list = NULL;
	i_tab = 0;
	cmd_f = 0;
	flag = 0;
	if (tabx[i_tab] == NULL)
		return (NULL);
	while (i_tab < tk_len)
	{
		flag = 0;
		if (tabx[i_tab] == NULL) {
			tk_len--;
			i_tab++;
			flag = 1;
		}
		if (cmd_f == 0 && diff_cmd(tabx[i_tab]) != 0 && flag == 0)
		{
			cmd_f = diff_cmd(tabx[i_tab]);
			add_lst_back(&list, tabx[i_tab], cmd_f, i_tab);
		}
		else if (cmd_f != 0 && diff_redir(tabx[i_tab]) == 12 && flag == 0)
		{
			add_lst_back(&list, tabx[i_tab], 12, i_tab);
			cmd_f = 0;
		}
		else if (flag == 0)
		{
			add_lst_back(&list, tabx[i_tab], diff_redir(tabx[i_tab]), i_tab);
		}
		if (flag == 0)
			i_tab++;
	}
	return (list);
}
