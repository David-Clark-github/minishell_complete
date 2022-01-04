/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_separ2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <dclark@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 10:00:55 by david             #+#    #+#             */
/*   Updated: 2022/01/04 17:29:40 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	num_of_element(char *str)
{
	int	res;
	int	i;

	res = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		if (str[i] == '\'')
		{
			res++;
			i++;
			while (str[i] && str[i] != '\'')
				i++;
			i++;
		}
		else if (str[i] == '\"')
		{
			res++;
			if (str[i] == '\"')
				i++;
			while (str[i] && str[i] != '\"')
				i++;
			if (str[i] && str[i] == '\"')
				i++;
		}
		else
		{
			res++;
			//i++;
			while (str[i] && str[i] != '\'' && str[i] != '\"' && str[i] != ' ')
				i++;
		}
	}
	return (res);
}

static void	init_token(char **token, int len)
{
	int	i;

	i = 0;
	while (len-- > 0)
	{
		token[i] = 0;
		i++;
	}
}

char	**ft_separ(char *str, int *tk_len)
{
	char	**dest;
	int		i_dest;
	int		i_str;
	
	*tk_len = num_of_element(str);
	i_dest = 0;
	i_str = 0;
	//printf("number of element = %d\n", *tk_len);
	dest = (char **)malloc(sizeof(char *) * (*tk_len + 1));
	init_token(dest, *tk_len + 1);
	while (str[i_str] == ' ')
		i_str++;
	while (str[i_str])
	{
		while (str[i_str] && str[i_str] == ' ')
			i_str++;
		if (str[i_str] && str[i_str] == '\'')
		{
			i_str++;
			if (str[i_str] == '\'')
			{
				dest[i_dest] = ft_strljoin(dest[i_dest], NULL, 0);
				i_dest++;
				i_str++;
			}
			else
			{
				while (str[i_str] && str[i_str] != '\'')
				{
					dest[i_dest] = ft_strljoin(dest[i_dest], &str[i_str], 1);
					i_str++;
				}
				if (str[i_str] == '\'')
					i_str++;
				if (str[i_str] != '\"' && str[i_str] != '\'')
					i_dest++;
			}
		}
		else if (str[i_str] && str[i_str] == '\"')
		{
			i_str++;
			if (str[i_str] == '\"')
			{
				dest[i_dest] = ft_strljoin(dest[i_dest], NULL, 0);
				i_dest++;
				i_str++;
			}
			else
			{
				while (str[i_str] && str[i_str] != '\"')
				{
					dest[i_dest] = ft_strljoin(dest[i_dest], &str[i_str], 1);
					i_str++;
				}
				if (str[i_str] == '\"')
					i_str++;
				if (str[i_str] != '\"' && str[i_str] != '\'')
					i_dest++;
			}
		}
		else
		{
			while (str[i_str] && str[i_str] != ' ' && str[i_str] != '\'' && str[i_str] != '\"')
			{
				dest[i_dest] = ft_strljoin(dest[i_dest], &str[i_str], 1);
				i_str++;
			}
			if (str[i_str] && (str[i_str] != '\'' && str[i_str] != '\"'))
				i_dest++;
		}
	}
	return (dest);
}
