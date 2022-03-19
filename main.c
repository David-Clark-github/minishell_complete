/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 13:28:08 by dclark            #+#    #+#             */
/*   Updated: 2022/03/19 14:33:00 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_err_num = 0;

int	main(int ac, char **av, char **ev)
{
	(void)av;
	t_mini	*mini;

	mini = get_mini();
	init_mini(mini);
	mini->cp_ev = ft_copy_env(ev, 0);
	// char	**name = NULL;
	// name = malloc(sizeof(char*) * 3);
	// char	**data = NULL;
	// data = malloc(sizeof(char*) * 3);
	// name[0] = strdup("toto");
	// name[1] = strdup("tutu");
	// name[2] = '\0';
	// data[0] = '\0';
	// data[1] = strdup("data");
	// data[2] = '\0';
	if (ac != 1)
	{
		printf("Aucun argument nécessaire pour minishell.\n");
		return (EXIT_FAILURE);
	}
	custom_sig();
	while (1)
	{
		//\33[2K\r
		mini->prompt = readline("Minishell~ ");
		if (mini->prompt == NULL)
			ft_exit(mini->er_num);
		if (ft_strlen(mini->prompt) != 0)
		{
			add_history(mini->prompt);
			mini->er_num = check_error_quotes(mini->prompt, &mini->er_num);
		}
		if (mini->er_num != 0)
			printf("er_num = %d error de quotes\n", mini->er_num);
		if (ft_strlen(mini->prompt) != 0 && mini->er_num == 0)
		{
			// if (mini->er_num != 0)
			// 	printf("er_num = %d error de quotes\n", mini->er_num);
			if (mini->er_num != -1)
				parsing(mini);
			// if (mini->list == NULL && mini->er_num == 0)
			// 	printf("error during parsing\n");
			// if (check_syntax(mini) == EXIT_FAILURE)
			// 	printf("syntax error\n");
			// if (mini->er_num != -1 && extract_lst(mini->list))
			// if (mini->list && mini->list->log == 4)
			// 	ft_export(name, &mini->cp_ev);
			// if (mini->list && mini->list->log == 5)
			// 	ft_unset(name);
			// if (mini->list && mini->er_num != -1 && mini->list->log == 6)
			// 	ft_env(mini->cp_ev, 1);
			// if (mini->er_num == 0 && mini->list->log == 3)
			//  	ft_pwd(1);
			// if (mini->er_num == 0 && mini->list->log == 2)
			// 	ft_cd(mini->tab_separ[1]);
			//  if (mini->er_num == 0 && mini->list->log == 6)
			//  	ft_env(mini->cp_ev, 1);
			// if (mini->er_num == 0 && mini->list->log == 4)
			// 	arg_export(mini->tab_separ, mini);
			// if (mini->er_num != 0)
			// 	printf("er_num = %d\n", mini->er_num);
			// ft_freetab(mini->tab_separ);
			// print_lst(&mini->list);
			exec_instructions(mini);
		}
		if (check_error_quotes(mini->prompt, &mini->er_num) != 0)
			mini->er_num = 0;
		ft_free_mini(mini, 1);
	}
}
