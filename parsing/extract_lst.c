/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 18:10:35 by dclark            #+#    #+#             */
/*   Updated: 2022/01/10 15:12:11 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//log 0 : String
//log 1<->7 CMD
//log 8<->12 Redirection

int	extract_lst(t_lst *list)
{
	if (list->log > 0 && list->log < 8)
		return (1);
	else
	{
		printf("%s commande introuvable\n", list->str);
		return (0);
	}

}
