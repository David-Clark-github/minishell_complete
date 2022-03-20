/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 13:11:24 by seciurte          #+#    #+#             */
/*   Updated: 2022/03/20 00:55:50 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_path(char **path)
{
	int		i;

	i = 0;
	if (!path)
		return ;
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
		fatal_error();
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
	if (ft_strncmp("./", cmd, 2) == 0 || ft_strncmp("/", cmd, 1) == 0)
		return (ft_strdup(cmd));
	while (path && path[i] && ft_strlen(cmd) > 0)
	{
		tmp = my_strjoin(path[i], cmd);
		if (tmp == NULL)
			fatal_error();
		if (access(tmp, X_OK) == 0)
			return (tmp);
		free(tmp);
		i++;
	}
	return (ft_strdup(cmd));
}
