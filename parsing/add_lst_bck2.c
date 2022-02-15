/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_lst_bck2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 11:59:54 by dclark            #+#    #+#             */
/*   Updated: 2022/02/15 16:33:46 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	add_lst_back(t_lst **head_lst, char *str, int log, int iter)
{
	t_lst	*dest;
	t_lst	*pointeur;

	pointeur = *head_lst;
	dest = malloc(sizeof(t_lst));
	if (dest != NULL)
	{
		if (str == 0)
			dest->str = 0;
		else
			dest->str = str;
		dest->log = log;
		dest->iter = iter;
		dest->next = NULL;
	}
	if (pointeur == NULL)
	{
		*head_lst = dest;
		return;
	}
	while (pointeur->next)
		pointeur = pointeur->next;
	pointeur->next = dest;
}
