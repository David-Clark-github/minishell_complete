/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 13:23:22 by dclark            #+#    #+#             */
/*   Updated: 2022/01/03 17:15:11 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	print_lst(t_lst **head)
{
	t_lst *p;

	p = *head;
	while (p)
	{
		if (p->log < 8 && p->log > 0)
			printf("CMD = %s\n", p->str);
		else if (p->log > 7 && p->log < 13)
			printf("Redirection = %s\n", p->str);
		else
			printf("String = %s\n", p->str);
		printf("log = %d\n\n", p->log);
		p = p->next;
	}
}
