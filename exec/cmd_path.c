/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 13:11:24 by seciurte          #+#    #+#             */
/*   Updated: 2022/03/13 11:27:53 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_path(char **path)
{
	int		i;

	i = 0;
	while (path[i])
	{
		free(path[i]);
		i++;
	}
	free(path);
}

char	**get_path(char **env)
{
	int		i;
	char	**path;
	char	*tmp;

	i = 0;
	while (env[i] != NULL && ft_strncmp("PATH", env[i], 4) != 0)
		i++;
	if (env[i] == NULL)
		return (NULL);
	path = ft_split(&env[i][5], ':');
	if (path == NULL)
		exit_error(__LINE__);
	i = 0;
	while (path[i])
	{
		tmp = my_strjoin(path[i], "/");
		if (tmp == NULL)
			return (free_path(path), NULL);
		free(path[i]);
		path[i] = tmp;
		i++;
	}
	return (path);
}

char	*get_cmd_path(char **path, char *cmd)
{
	int		i;
	char	*tmp;

	i = 0;
	while (path && path[i])
	{
		tmp = my_strjoin(path[i], cmd);
		if (tmp == NULL)
			exit_error(__LINE__);
		if (access(tmp, X_OK) == 0)
		{
			free(cmd);
			return (tmp);
		}
		free(tmp);
		i++;
	}
	return (cmd);
}
