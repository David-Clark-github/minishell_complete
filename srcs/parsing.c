/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 10:38:17 by dclark            #+#    #+#             */
/*   Updated: 2021/12/22 19:06:09 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*parsing(char *prompt, int *error_num)
{
	/*
	int	i;
	t_lst	*list;

	list = NULL;
	i = 0;
	while (prompt[i] == ' ')
		i++;
	add_lst_back(&list, "toto", 5);
	add_lst_back(&list, "tutu", 4);
	add_lst_back(&list, "tata", 2);
	print_lst(&list);
	return (prompt);
	*/
	char	*exp;
	char	**separ;
	exp = expension(prompt, error_num);
	if (exp == NULL)
		return (NULL);
	separ = ft_separ(exp);
	if (separ != NULL)
		free(separ);
	return (exp);
}
