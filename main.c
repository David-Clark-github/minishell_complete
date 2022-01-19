/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 13:28:08 by dclark            #+#    #+#             */
/*   Updated: 2022/01/19 14:48:54 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
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
*/

int	main(int ac, char **av, char **tab_env)
{
	(void)av;
	t_pars	pars;

	char	**cp_tab_env;
	cp_tab_env = ft_copy_env(tab_env, 0);
	if (ac != 1)
	{
		printf("Aucun argument nécessaire pour minishell.\n");
		return (EXIT_FAILURE);
	}
	take_signal();
	while (1)
	{
		pars.prompt = readline("Minishell~ ");
		add_history(pars.prompt);
		if (check_error_quotes(pars.prompt) == 1 && ft_strlen(pars.prompt) != 0)
		{
			pars.list = parsing(&pars);
			if (pars.list == NULL)
				printf("error during parsing or syntax error\n");
			///*
			else if (extract_lst(pars.list))
				print_lst(&pars.list);
			//*/
			//ft_free_tab(pars.tab_separ, pars.tab_len);
			ft_freetab(pars.tab_separ);
			if (pars.list->log == 6)
				ft_env(cp_tab_env, 1);
			else if (pars.list->log == 4)
				ft_export("TUTU", "tata", &cp_tab_env);
			else if (pars.list->log == 5)
				ft_unset("TUTU", &cp_tab_env);
			else if (pars.list->log == 3)
				ft_pwd(1);
			else if (pars.list->log == 2)
				ft_cd("../");
		}
	}
}
