/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 14:42:45 by dclark            #+#    #+#             */
/*   Updated: 2022/03/18 19:14:13 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	init(char *buf, size_t size)
{
	while (size--)
		buf[size] = 0;
}

static int	p2(char *buf, int size, int fd)
{
	char	*res_getcwd;
	int		res_w;

	init(buf, size);
	res_getcwd = getcwd(buf, size);
	if (res_getcwd == NULL)
	{
		free(buf);
		return (EXIT_FAILURE);
	}
	res_w = write(fd, buf, ft_strlen(buf));
	if (res_w == -1)
	{
		write(2, "Minishell: pwd: write error: No space left on device\n", 53);
		free(buf);
		return (EXIT_FAILURE);
	}
	write(fd, "\n", 1);
	free(buf);
	buf = NULL;
	return (EXIT_SUCCESS);
}

int	ft_pwd(int fd)
{
	char	*buf;
	size_t	size;

	size = 512;
	buf = malloc(sizeof(char) * size);
	if (buf == NULL)
		printf("malloc of ft_pwd failed :(\n");
	if (buf == NULL)
		return (EXIT_FAILURE);
	if (p2(buf, size, fd) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
