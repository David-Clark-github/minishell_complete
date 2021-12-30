/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 10:38:17 by dclark            #+#    #+#             */
/*   Updated: 2021/12/30 12:53:28 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*parsing(char *prompt, int *error_num)
{
	t_lst	*list;
	t_pars	pars;

	pars.exp = expension(prompt, error_num);
	printf("exp = %s\n", pars.exp);
	if (pars.exp == NULL)
		return (NULL);
	pars.token_lst = ft_separ(pars.exp, &pars.tk_len);
	printf("apres separ\n");
	printf("\ntab:\n");
	for (int i = 0; pars.token_lst[i] != 0; i++)
		printf("%s\n", pars.token_lst[i]);
	printf("\n");
	list = tab_to_list(pars.token_lst);
	print_lst(&list);
	if (pars.token_lst != NULL)
		free(pars.token_lst);
	return (pars.exp);
}
