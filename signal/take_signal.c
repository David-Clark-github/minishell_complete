/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_signal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 15:55:39 by dclark            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/03/10 17:15:18 by seciurte         ###   ########.fr       */
=======
/*   Updated: 2022/03/10 17:59:31 by dclark           ###   ########.fr       */
>>>>>>> origin/err_num
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <signal.h>

static void	toto(int sig)
{
<<<<<<< HEAD
	dprintf(2, "Signal = %d\n", sig);
	if (sig == SIGINT) {
=======
	if (sig == SIGINT)
	{
>>>>>>> origin/err_num
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		get_mini()->er_num = 130;
		//printf("er_num: %d\n", get_mini()->er_num);
	}
}

/*
static void	tutu(int sig)
{
	if (sig == SIGQUIT)
	{
		//exit(get_mini()->er_num);
	}
}
*/

void	take_signal(void)
{
	//signal(SIGQUIT, tutu);
	signal(SIGINT, toto);
	signal(SIGQUIT, SIG_IGN);
}
