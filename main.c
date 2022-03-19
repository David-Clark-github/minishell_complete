/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 13:28:08 by dclark            #+#    #+#             */
/*   Updated: 2022/03/19 14:22:55 by dclark           ###   ########.fr       */
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
	if (ac != 1)
	{
		printf("Aucun argument nécessaire pour minishell.\n");
		return (EXIT_FAILURE);
	}
	custom_sig();
	while (1)
	{
		mini->prompt = readline("Minishell~ ");
		if (mini->prompt == NULL)
			ft_exit(g_err_num);
		if (ft_strlen(mini->prompt) != 0)
		{
			add_history(mini->prompt);
			g_err_num = check_error_quotes(mini->prompt, &g_err_num);
		}
		if (g_err_num != 0)
			printf("er_num = %d error de quotes\n", g_err_num);
		if (ft_strlen(mini->prompt) != 0 && g_err_num == 0)
		{
			if (mini->er_num != -1)
				parsing(mini);
			exec_instructions(mini);
		}
		if (check_error_quotes(mini->prompt, &g_err_num) != 0)
			g_err_num = 0;
		ft_free_mini(mini, 1);
	}
}
