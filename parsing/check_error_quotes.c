/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error_quotes.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 17:20:03 by dclark            #+#    #+#             */
/*   Updated: 2022/03/20 02:40:24 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	init_value(int *a, int *b, int *c)
{
	*a = 0;
	*b = 0;
	*c = -1;
}

static void	simple_quote(int *q)
{
	if (*q == 1)
		*q = 0;
	else if (*q == 0)
		*q = 1;
}

int	check_error_quotes(char *prompt)
{
	int	qt_1;
	int	qt_2;
	int	index;

	init_value(&qt_1, &qt_2, &index);
	while (prompt[++index])
	{
		if (prompt[index] == '\'' && qt_2 == 0)
			simple_quote(&qt_1);
		else if (prompt[index] == '\"' && qt_1 == 0)
			simple_quote(&qt_2);
	}
	if ((qt_1 != 0) || (qt_2 != 0))
		return (1);
	return (0);
}
