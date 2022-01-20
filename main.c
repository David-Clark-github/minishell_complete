/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 13:28:08 by dclark            #+#    #+#             */
/*   Updated: 2022/01/20 15:04:03 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **ev)
{
	(void)av;
	int		er;
	t_pars	pars;

	char	**cp_ev;
	er = 0;
	cp_ev = ft_copy_env(ev, 0);
	if (ac != 1)
	{
		printf("Aucun argument nécessaire pour minishell.\n");
		return (EXIT_FAILURE);
	}
	take_signal();
	while (1)
	{
		pars.prompt = readline("Minishell~ ");
		if (ft_strlen(pars.prompt) != 0)
			add_history(pars.prompt);
		if (ft_strlen(pars.prompt) != 0)
		{
			check_error_quotes(pars.prompt, &er);
			if (er == 0)
				pars.list = parsing(&pars);
			if (pars.list == NULL)
				printf("error during parsing\n");
			///*
			else if (extract_lst(pars.list))
				print_lst(&pars.list);
			//*/
			//ft_free_tab(pars.tab_separ, pars.tab_len);
			ft_freetab(pars.tab_separ);
			if (pars.list != NULL) {
				if (pars.list->log == 6)
					ft_env(cp_tab_env, 1);
				else if (pars.list->log == 4)
					ft_export("TUTU", "tata", &cp_ev);
				else if (pars.list->log == 5)
					ft_unset("TUTU", &cp_ev);
				else if (pars.list->log == 3)
					ft_pwd(1);
				else if (pars.list->log == 2)
					ft_cd("../");
			}
		}
	}
}
