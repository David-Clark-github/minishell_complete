/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_signal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 15:55:39 by dclark            #+#    #+#             */
/*   Updated: 2022/03/10 17:15:18 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	toto(int sig)
{
	dprintf(2, "Signal = %d\n", sig);
	if (sig == SIGINT) {
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

static void	tutu(int sig)
{
	if (sig == SIGQUIT)
	{
		printf("HELLO !\n");
		exit(EXIT_SUCCESS);
	}
}

void	take_signal(void)
{
	signal(SIGQUIT, tutu);
	signal(SIGINT, toto);
}
