/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 10:38:17 by dclark            #+#    #+#             */
/*   Updated: 2021/12/26 13:14:00 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*parsing(char *prompt, int *error_num)
{
	t_lst	*list;
	/*
	int	i;

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
	/*
	for (int i = 0; separ[i] != 0; i++)
		printf("%s\n", separ[i]);
	*/
	list = tab_to_list(separ);
	print_lst(&list);
	if (separ != NULL)
		free(separ);
	return (exp);
}
