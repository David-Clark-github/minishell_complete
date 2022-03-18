/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_data_name.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 14:17:02 by dclark            #+#    #+#             */
/*   Updated: 2022/03/18 15:11:39 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*take_name(char *str)
{
	char	*dest;
	int		i;

	i = 0;
	dest = NULL;
	while (str[i] && str[i] != '=')
	{
		dest = ft_strljoin(dest, &str[i], 1);
		i++;
	}
	return (dest);
}

static char	*taka_data(char *str)
{
	char	*dest;
	int		i;

	i = 0;
	dest = NULL;
	while (str[i] && str[i] != '=')
		i++;
	i++;
	while (str[i])
	{
		dest = ft_strljoin(dest, &str[i], 1);
		i++;
	}
	return (dest);
}

void	take_data_name(char **name, char **data, char *str)
{
	*name = take_name(str);
	*data = taka_data(str);
	(void)name;
	(void)data;
}
