/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 13:11:24 by seciurte          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/03/09 18:47:51 by seciurte         ###   ########.fr       */
=======
/*   Updated: 2022/03/14 12:39:59 by seciurte         ###   ########.fr       */
>>>>>>> master
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
	if (ft_strncmp("PATH", env[i], 4) != 0)
		return (NULL);
	path = ft_split(&env[i][5], ':');
	if (path == NULL)
		exit_error(__LINE__);
	i = 0;
	while (path[i])
	{
		tmp = ft_strljoin(path[i], "/", ft_strlen(path[i]) + 1);
		if (tmp == NULL)
		{
			free_path(path);
			exit_error(__LINE__);
		}
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
		tmp = ft_strljoin(path[i], cmd, ft_strlen(path[i]) + ft_strlen(cmd));
		if (tmp == NULL)
			exit_error(__LINE__);
		if (access(tmp, X_OK) == 0)
			return (tmp);
		free(tmp);
		i++;
	}
	return (cmd);
}
