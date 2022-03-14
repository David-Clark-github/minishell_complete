/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 14:42:45 by dclark            #+#    #+#             */
/*   Updated: 2022/03/14 12:15:15 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	init(char *buf, size_t size)
{
	while (size--)
		buf[size] = 0;
}

int	ft_pwd(int fd)
{
	char	*buf;
	char	*res_getcwd;
	size_t	size;

	size = 512;
	buf = malloc(sizeof(char) * size);
	if (buf == NULL)
		printf("malloc of ft_pwd failed :(\n");
	if (buf == NULL)
		return (EXIT_FAILURE);
	init(buf, size);
	res_getcwd = getcwd(buf, size);
	if (res_getcwd == NULL)
		return (EXIT_FAILURE);
	write(fd, buf, ft_strlen(buf));
	write(fd, "\n", 1);
	free(buf);
	buf = NULL;
	return (EXIT_SUCCESS);
}
