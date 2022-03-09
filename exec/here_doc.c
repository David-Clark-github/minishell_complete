/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 13:17:01 by seciurte          #+#    #+#             */
/*   Updated: 2022/03/09 13:18:06 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_heredoc_end(char *buffer, char *limiter)
{
	if (ft_strlen(limiter) == 0 && ft_strlen(buffer) > 0)
		return (0);
	else if (buffer && ft_strncmp(buffer, limiter, ft_strlen(limiter)) == 0)
	{
		write(STDIN_FILENO, "\n", 1);
		return (1);
	}
	return (0);
}

static char	*get_var_value(t_mini *mini, char *var, int var_len)
{
	int			env_index;

	env_index = 0;
	while (mini->cp_ev[env_index])
	{
		if (ft_strncmp(mini->cp_ev[env_index], var, var_len) == 0)
			return (mini->cp_ev[env_index]);
		env_index++;
	}
	return (NULL);
}

static void	write_with_expansion(t_mini *mini, int fd, char *buffer)
{
	int		buff_index;
	int		var_len;
	char	*var_value;

	buff_index = 0;
	while (buffer && buffer[buff_index])
	{
		// dprintf(2, "here\n");
		var_len = 0;
		if (buffer[buff_index] == '$' && (ft_isalpha(buffer[buff_index + 1]) || buffer[buff_index + 1] == '?'))
		{
			while (buffer[buff_index + var_len] && buffer[buff_index + var_len] != ' ')
				var_len++;
			var_value = get_var_value(mini, &buffer[buff_index + 1], var_len - 1);
			if (var_value != NULL)
			{
				write(fd, &var_value[var_len], ft_strlen(&var_value[var_len]));
				buff_index += var_len - 1;
			}
			else
				write(fd, &buffer[buff_index], 1);
		}
		else
			write(fd, &buffer[buff_index], 1);
		buff_index++;
	}
	write(fd, "\n", 1);
}

void	heredoc(t_mini *mini, t_lst *lst)
{
	char	*limiter;
	int		heredocfd;
	int		flag;

	limiter = lst->next->str;
	heredocfd = open(".heredoc", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	if (heredocfd < 0)
		return ;
	flag = 1;
	while (flag)
	{
		mini->buffer = readline("> ");
		printf("heredoc = %s\n", mini->buffer);
		if (check_heredoc_end(mini->buffer, limiter))
		{
			free(mini->buffer);
			mini->buffer = NULL;
			flag = 0;
		}
		else
			write_with_expansion(mini, heredocfd, mini->buffer);
	}
	close(heredocfd);
}