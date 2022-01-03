/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 13:23:22 by dclark            #+#    #+#             */
/*   Updated: 2022/01/03 17:30:43 by dclark           ###   ########.fr       */
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
			printf("CMD\n[%s]\n", p->str);
		else if (p->log > 7 && p->log < 13)
			printf("Redirection\n[%s]\n", p->str);
		else
			printf("String\n[%s]\n", p->str);
		printf("log = %d\n", p->log);
		printf("iter = %d\n\n", p->iter);
		p = p->next;
	}
}
