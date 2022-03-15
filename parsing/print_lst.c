/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 13:23:22 by dclark            #+#    #+#             */
/*   Updated: 2022/03/15 13:02:23 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_lst(t_lst **head)
{
	t_lst	*p;

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
