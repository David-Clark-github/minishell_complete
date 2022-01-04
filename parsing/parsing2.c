/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 10:38:17 by dclark            #+#    #+#             */
/*   Updated: 2022/01/04 18:30:39 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void	ft_free_tab(char **tab_separ, int tab_len)
{
	int	i;

	i = 0;
	while (i < tab_len)
	{
		free(tab_separ[i]);
		i++;
	}
	free(tab_separ);
}

t_lst	*parsing(char *prompt, int *error_num)
{
	t_lst	*list;
	t_pars	pars;

	pars.exp = expension(prompt, error_num);
	//printf("expension = %s\n", pars.exp);
	/*
	pars.exp = quotes_exp(pars.exp);
	printf("quotes_exp = %s\n", pars.exp);
	*/
	if (pars.exp == NULL)
		return (NULL);
	pars.tab_separ = ft_separ(pars.exp, &pars.tab_len);
	/*
	printf("\ntab:\n");
	for (int i = 0; pars.tab_separ[i] != 0; i++)
		printf("%s\n", pars.tab_separ[i]);
	printf("\n");
	*/
	list = tab_to_list(pars.tab_separ);
	//printf("\n");
	//print_lst(&list);
	if (pars.tab_separ != NULL)
		ft_free_tab(pars.tab_separ, pars.tab_len);
	return (list);
}
