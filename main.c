/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 13:28:08 by dclark            #+#    #+#             */
/*   Updated: 2022/03/20 06:29:14 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_err_num = 0;

static int	is_all_whitespace(char *str)
{
	int		i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t')
			return (0);
		i++;
	}
	return (1);
}

static void	norme1(t_mini *mini)
{
	if (mini->prompt == NULL)
		ft_exit(g_err_num);
	if (ft_strlen(mini->prompt) != 0 && !is_all_whitespace(mini->prompt))
	{
		add_history(mini->prompt);
		if (check_error_quotes(mini->prompt))
			ft_putstr_fd("Minishell: Quotes error\n", STDERR_FILENO);
	}
}

int	main(int ac, char **av, char **ev)
{
	t_mini	*mini;

	(void)ac;
	(void)av;
	mini = get_mini();
	init_mini(mini);
	mini->cp_ev = ft_copy_env(ev, 0);
	mini->save_stdin = dup(STDIN_FILENO);
	custom_sig();
	while (1)
	{
		mini->prompt = readline("Minishell~ ");
		norme1(mini);
		if (!check_error_quotes(mini->prompt)
			&& !is_all_whitespace(mini->prompt))
		{
			parsing(mini);
			exec_instructions(mini);
		}
		ft_free_mini(mini, 1);
	}
}
