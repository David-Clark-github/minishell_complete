/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_to_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <dclark@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 12:31:48 by david             #+#    #+#             */
/*   Updated: 2022/01/27 13:53:24 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_lst	*tab_to_list(char **tabx)
{
	t_lst	*list;
	int		i_tab;
	int		cmd_f;
	
	list = NULL;
	i_tab = 0;
	cmd_f = 0;
	if (!tabx[i_tab])
		return (NULL);
	else
	{
		while (tabx[i_tab])
		{
			if (cmd_f == 0 && diff_cmd(tabx[i_tab]) != 0)
			{
				cmd_f = diff_cmd(tabx[i_tab]);
				add_lst_back(&list, tabx[i_tab], cmd_f, i_tab);
			}
			else if (cmd_f != 0 && diff_redir(tabx[i_tab]) == 12)
			{
				add_lst_back(&list, tabx[i_tab], 12, i_tab);
				cmd_f = 0;
			}
			else
			{
				add_lst_back(&list, tabx[i_tab], diff_redir(tabx[i_tab]), i_tab);
			}
			i_tab++;
		}
	}
	return (list);
}
