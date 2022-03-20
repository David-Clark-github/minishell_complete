/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_signal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 15:55:39 by dclark            #+#    #+#             */
/*   Updated: 2022/03/20 05:15:31 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <signal.h>

void	error_code_fork(void)
{
	if (WIFEXITED(g_err_num))
	{
		g_err_num = WEXITSTATUS(g_err_num);
	}
	else if (WIFSIGNALED(g_err_num))
	{
		g_err_num = WTERMSIG(g_err_num);
		g_err_num += 128;
		if (g_err_num == 131)
			write(STDERR_FILENO, CORE_DUMP, ft_strlen(CORE_DUMP));
	}
}

void	default_sig(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
}

void	heredoc_sig(int sig)
{
	if (sig == SIGINT)
	{
		get_mini()->heredoc_sigint = 1;
		close(STDIN_FILENO);
		ft_putstr_fd("\n", STDOUT_FILENO);
		custom_sig();
		g_err_num = 130;
	}
}

static void	custom_sigint(int sig)
{
	if (sig == SIGINT)
	{
		ft_putchar_fd('\n', STDOUT_FILENO);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		g_err_num = 130;
	}
}

void	custom_sig(void)
{
	signal(SIGINT, custom_sigint);
	signal(SIGQUIT, SIG_IGN);
}
