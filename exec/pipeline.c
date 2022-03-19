/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 13:14:31 by seciurte          #+#    #+#             */
/*   Updated: 2022/03/19 17:08:59 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_pipeline(int **pipeline)
{
	int		i;

	if (pipeline == NULL)
		return ;
	i = 0;
	while (pipeline[i])
	{
		free(pipeline[i]);
		i++;
	}
	free(pipeline);
}

int	get_nb_of_pipes(t_lst *lst)
{
	int		i;

	i = 0;
	if (lst == NULL)
		return (i);
	while (lst)
	{
		if (lst->log == PIPE)
			i++;
		lst = lst->next;
	}
	return (i);
}

int	**create_pipeline(t_lst *lst)
{
	int		i;
	int		nb_pipes;
	int		**pipeline;

	nb_pipes = get_nb_of_pipes(lst);
	if (nb_pipes == 0)
		return (NULL);
	pipeline = malloc(sizeof(int *) * (nb_pipes + 1));
	if (pipeline == NULL)
		fatal_error();
	ft_memset(pipeline, 0, nb_pipes);
	i = 0;
	while (i < nb_pipes)
	{
		pipeline[i] = malloc(sizeof(int) * 2);
		if (pipeline[i] == NULL)
		{
			free_pipeline(pipeline);
			fatal_error();
		}
		ft_memset(pipeline[i], -42, 2);
		i++;
	}
	pipeline[i] = NULL;
	return (pipeline);
}
