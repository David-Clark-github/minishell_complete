/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 13:28:08 by dclark            #+#    #+#             */
/*   Updated: 2022/01/20 16:25:04 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **ev)
{
	(void)av;
	t_mini	mini;

	mini.cp_ev = ft_copy_env(ev, 0);
	mini.er_num = 0;
	if (ac != 1)
	{
		printf("Aucun argument nécessaire pour minishell.\n");
		return (EXIT_FAILURE);
	}
	//take_signal();
	while (1)
	{
		mini.prompt = readline("Minishell~ ");
		if (ft_strlen(mini.prompt) != 0)
			add_history(mini.prompt);
		if (ft_strlen(mini.prompt) != 0)
		{
			check_error_quotes(mini.prompt, &mini.er_num);
			if (mini.er_num != 0)
				printf("er_num = %d error de quotes\n", mini.er_num);
			if (mini.er_num == 0)
				mini.list = parsing(&mini);
			/*
			if (mini.list == NULL)
				printf("error during parsing\n");
			//
			else if (extract_lst(mini.list))
				print_lst(&mini.list);
			//
			//ft_free_tab(mini.tab_separ, mini.tab_len);
			ft_freetab(mini.tab_separ);
			if (mini.list != NULL) {
				if (mini.list->log == 6)
					ft_env(mini.cp_ev, 1);
				else if (mini.list->log == 4)
					ft_export("TUTU", "tata", &mini.cp_ev);
				else if (mini.list->log == 5)
					ft_unset("TUTU", &mini.cp_ev);
				else if (mini.list->log == 3)
					ft_pwd(1);
				else if (mini.list->log == 2)
					ft_cd("../");
			}
			*/
		}
	}
}
