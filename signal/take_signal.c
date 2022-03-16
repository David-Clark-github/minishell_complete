/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_signal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 15:55:39 by dclark            #+#    #+#             */
/*   Updated: 2022/03/16 16:39:47 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <signal.h>

void	default_sig(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
}

void	heredoc_sig(void)
{
	
}

static void	custom_sigint(int sig)
{
	if (sig == SIGINT)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		get_mini()->er_num = 130;
	}
}

void	custom_sig(void)
{
	signal(SIGINT, custom_sigint);
	signal(SIGQUIT, SIG_IGN);
}
