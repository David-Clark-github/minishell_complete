/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_signal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 15:55:39 by dclark            #+#    #+#             */
/*   Updated: 2022/01/24 11:56:31 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	toto(int sig)
{
	if (sig == SIGINT) {
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	/*
	if (sig == SIGQUIT) {
		printf("totot est la\n");
		printf("en cours de développement :)");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		exit(EXIT_SUCCESS);
	}
	*/
}

void	take_signal(void)
{
	//signal(SIGQUIT, toto);
	signal(SIGINT, toto);
}
