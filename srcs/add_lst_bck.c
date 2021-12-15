/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_lst_bck.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 11:59:54 by dclark            #+#    #+#             */
/*   Updated: 2021/12/15 13:33:48 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	add_lst_back(t_lst **head_lst, char *str, int log)
{
	t_lst	*dest;
	t_lst	*p;

	p = *head_lst;
	dest = malloc(sizeof(t_lst));
	if (dest)
	{
		dest->str = str;
		dest->log = log;
		dest->next = NULL;
	}
	while (p->next)
		p = p->next;
	p->next = dest;
}
