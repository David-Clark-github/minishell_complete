/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_lst_bck.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 11:59:54 by dclark            #+#    #+#             */
/*   Updated: 2022/01/03 13:49:55 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
void	add_lst_back(t_lst **head_lst, char *str, int log)
{
	t_lst	*dest;
	t_lst	*pointeur;

	if (!str)
		return;
	pointeur = *head_lst;
	dest = malloc(sizeof(t_lst));
	if (dest != NULL)
	{
		dest->str = str;
		dest->log = log;
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
