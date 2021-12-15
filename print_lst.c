/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 13:23:22 by dclark            #+#    #+#             */
/*   Updated: 2021/12/15 13:25:36 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	print_lst(t_lst **head)
{
	t_lst *p;
	int	i;

	p = *head;
	i = 0;
	while (p)
	{
		printf("i = %d\n");
		printf("string = %s", p->str);
		printf("log = %d\n", p->log);
		p = p->next;
	}
}
