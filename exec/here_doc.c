/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 13:17:01 by seciurte          #+#    #+#             */
/*   Updated: 2022/03/20 05:07:27 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_heredoc_end(char *buffer, char *limiter)
{
	if (ft_strlen(limiter) == 0 && ft_strlen(buffer) > 0)
		return (0);
	else if (buffer && ft_strncmp(buffer, limiter, ft_strlen(limiter)) == 0)
		return (1);
	return (0);
}

static char	*get_var_value(t_mini *mini, char *var, int var_len)
{
	int			env_index;

	env_index = 0;
	while (mini->cp_ev[env_index])
	{
		if (ft_strncmp(mini->cp_ev[env_index], var, var_len - 1) == 0)
			return (mini->cp_ev[env_index]);
		env_index++;
	}
	return (NULL);
}

static void	expand(t_mini *mini, int fd, char *buffer, int *buff_index)
{
	int		var_len;
	char	*var_value;

	var_len = 1;
	if (ft_strncmp(&buffer[(*buff_index)], "$?", 2) == 0)
	{
		ft_putnbr_fd(g_err_num, fd);
		(*buff_index)++;
	}
	else if (buffer[(*buff_index) + var_len]
		&& buffer[(*buff_index) + var_len] != '$')
	{
		while (buffer[(*buff_index) + var_len]
			&& ft_isalpha(buffer[(*buff_index) + var_len]))
			var_len++;
		var_value = get_var_value(mini, &buffer[(*buff_index) + 1], var_len);
		if (var_value != NULL)
			write(fd, &var_value[var_len], ft_strlen(&var_value[var_len]));
		(*buff_index) += var_len - 1;
	}
	else
		write(fd, &buffer[(*buff_index)], 1);
}

static void	write_with_expansion(t_mini *mini, int fd, char *buffer)
{
	int		buff_index;

	buff_index = 0;
	while (buffer && buffer[buff_index])
	{
		if (buffer[buff_index] == '$')
			expand(mini, fd, buffer, &buff_index);
		else
			write(fd, &buffer[buff_index], 1);
		buff_index++;
	}
	write(fd, "\n", 1);
}

void	heredoc(t_mini *mini, t_lst *lst)
{
	char	*limiter;
	int		hd_fd[2];
	int		flag;

	limiter = lst->str;
	if (pipe(hd_fd) < 0)
		return ;
	flag = 1;
	while (flag && mini->heredoc_sigint == 0)
	{
		mini->buffer = readline("> ");
		if (mini->buffer == NULL && mini->heredoc_sigint == 0)
		{
			heredoc_eof_error(limiter);
			flag = 0;
		}
		else if (check_heredoc_end(mini->buffer, limiter))
			flag = 0;
		else
			write_with_expansion(mini, hd_fd[1], mini->buffer);
		free(mini->buffer);
		mini->buffer = NULL;
	}
	close(hd_fd[1]);
	mini->io_fds_redir[0] = hd_fd[0];
}
