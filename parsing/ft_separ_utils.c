/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_separ_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 12:08:47 by dclark            #+#    #+#             */
/*   Updated: 2022/03/17 12:14:38 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	simple_q(int *i_str, int *i_dest, char *str, char **dest)
{
	*i_str = *i_str + 1;
	while (str[*i_str] && str[*i_str] != '\'')
	{
		dest[*i_dest] = ft_strljoin(dest[*i_dest], &str[*i_str], 1);
		*i_str = *i_str + 1;
	}
	if (str[*i_str] == '\'')
		*i_str = *i_str + 1;
	if (str[*i_str] && ft_checkcara(str[*i_str], " <>|") == 1)
		*i_dest = *i_dest + 1;
}

void	double_q(int *i_str, int *i_dest, char *str, char **dest)
{
	*i_str = *i_str + 1;
	while (str[*i_str] && str[*i_str] != '\"')
	{
		dest[*i_dest] = ft_strljoin(dest[*i_dest], &str[*i_str], 1);
		*i_str = *i_str + 1;
	}
	if (str[*i_str] == '\"')
		*i_str = *i_str + 1;
	if (str[*i_str] && ft_checkcara(str[*i_str], " <>|") == 1)
		*i_dest = *i_dest + 1;
}

void	zero_cara(int *i_str, int *i_dest, char *str, char **dest)
{
	while (str[*i_str] && ft_checkcara(str[*i_str], " <>|\'\"") == 0)
	{
		dest[*i_dest] = ft_strljoin(dest[*i_dest], &str[*i_str], 1);
		*i_str = *i_str + 1;
	}
	if (str[*i_str] && ft_checkcara(str[*i_str], " <>|") == 1)
		*i_dest = *i_dest + 1;
}

void	one_cara(int *i_str, int *i_dest, char *str, char **dest)
{
	dest[*i_dest] = ft_strljoin(dest[*i_dest], &str[*i_str], 1);
	*i_str = *i_str + 1;
	if (str[*i_str] && (str[*i_str] == str[*i_str - 1]))
	{
		dest[*i_dest] = ft_strljoin(dest[*i_dest], &str[*i_str], 1);
		*i_str = *i_str + 1;
	}
	*i_dest = *i_dest + 1;
}

void	one_pipe(int *i_str, int *i_dest, char *str, char **dest)
{
	dest[*i_dest] = ft_strljoin(dest[*i_dest], &str[*i_str], 1);
	*i_str = *i_str + 1;
	*i_dest = *i_dest + 1;
}
