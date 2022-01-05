/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 14:42:45 by dclark            #+#    #+#             */
/*   Updated: 2022/01/04 14:59:41 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void	init(char *buf, size_t size)
{
	while (size--)
		buf[size] = 0;
}


int	ft_pwd(void)
{
	char	*buf;
	char	*res_getcwd;
	size_t	size;

	size = 512;
	buf = malloc(sizeof(char) * size);
	if (buf == NULL)
	{
		printf("malloc of ft_pwd failed :(\n");
		return (EXIT_FAILURE);
	}
	init(buf, size);
	res_getcwd = getcwd(buf, size);
	if (res_getcwd == NULL)
		return (EXIT_FAILURE);
	printf("pwd = %s\n", buf);
	free(buf);
	return (EXIT_SUCCESS);

}
