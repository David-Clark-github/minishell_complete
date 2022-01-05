/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 13:28:08 by dclark            #+#    #+#             */
/*   Updated: 2022/01/05 17:46:10 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void	ft_free_tab(char **tab_separ, int tab_len)
{
	int	i;

	i = 0;
	if (tab_separ)
	{
		while (i < tab_len)
		{
			free(tab_separ[i]);
			i++;
		}
		free(tab_separ);
	}
}

int	main(int ac, char **av)
{
	t_pars	pars;

	if (ac != 1)
	{
		printf("Aucun argument besoin pour minishell\n");
		return (EXIT_SUCCESS);
	}
	while (1)
	{
		pars.prompt = readline("Minishell~ ");
		add_history(pars.prompt);
		if (check_error_quotes(pars.prompt) == 1 && ft_strlen(pars.prompt) != 0)
		{
			pars.list = parsing(&pars);
			if (pars.list == NULL)
				printf("error during parsing\n");
			else
			{
				print_lst(&pars.list);
				extract_lst(pars.list);
			}
			ft_free_tab(pars.tab_separ, pars.tab_len);
		}
	}
}
