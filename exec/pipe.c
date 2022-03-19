/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 13:33:51 by seciurte          #+#    #+#             */
/*   Updated: 2022/03/19 17:18:25 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	redirect_pipe_stdin(t_mini *mini, int **pipeline, int *pipe_index)
{
	int			nb_of_pipes;

	nb_of_pipes = get_nb_of_pipes(mini->list);
	if (nb_of_pipes > 0 && (*pipe_index) > 0)
	{
		mini->io_fds_redir[0] = pipeline[(*pipe_index) - 1][0];
	}
}

void	redirect_pipe_stdout(t_mini *mini, int **pipeline, int *pipe_index)
{
	int			nb_of_pipes;

	nb_of_pipes = get_nb_of_pipes(mini->list);
	if (nb_of_pipes > 0 && (*pipe_index) < nb_of_pipes)
	{
		if (pipe(pipeline[(*pipe_index)]) < 0)
			fatal_error();
		if ((*pipe_index) < nb_of_pipes)
		{
			mini->io_fds_redir[1] = pipeline[(*pipe_index)][1];
			mini->unused_fds[0] = pipeline[(*pipe_index)][0];
		}
		(*pipe_index)++;
	}
}
