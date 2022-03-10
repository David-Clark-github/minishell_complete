/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_separ2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <dclark@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 10:00:55 by david             #+#    #+#             */
/*   Updated: 2022/03/10 14:00:39 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
		else if (ft_checkcara(str[i], "<>|") == 0)
		{
			res++;
			while (str[i] && ft_checkcara(str[i], " <>|\'\"\t") == 0)
				i++;
		}
		else if (ft_checkcara(str[i], "<>") == 1)
		{
			res++;
			i++;
			if (str[i] && str[i] == str[i - 1])
				i++;
		}
		else if (ft_checkcara(str[i], "|") == 1)
		{
			res++;
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
	//printf("\nnum_of_element: %d\n\n", *tk_len);
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
			//printf("&str[i] == %s\n", &str[i_str]);
			i_str++;
			while (str[i_str] && str[i_str] != '\'')
			{
				dest[i_dest] = ft_strljoin(dest[i_dest], &str[i_str], 1);
				i_str++;
			}
			if (str[i_str] == '\'')
				i_str++;
			if (str[i_str] && ft_checkcara(str[i_str], "\"\'") == 0)
				i_dest++;
		}
		else if (str[i_str] && str[i_str] == '\"')
		{
			//printf("&str[i] == %s\n", &str[i_str]);
			i_str++;
			while (str[i_str] && str[i_str] != '\"')
			{
				dest[i_dest] = ft_strljoin(dest[i_dest], &str[i_str], 1);
				i_str++;
			}
			if (str[i_str] == '\"')
				i_str++;
			if (str[i_str] && ft_checkcara(str[i_str], "\"\'") == 0)
				i_dest++;
		}
		else if (str[i_str] && ft_checkcara(str[i_str], "<>|\'\"") == 0)
		{
			while (str[i_str] && ft_checkcara(str[i_str], " <>|\'\"") == 0)
			{
				dest[i_dest] = ft_strljoin(dest[i_dest], &str[i_str], 1);
				i_str++;
			}
			if (str[i_str] && ft_checkcara(str[i_str], " <>|\'\"") == 1)
				i_dest++;
		}
		else if (str[i_str] && ft_checkcara(str[i_str], "<>") == 1)
		{
			dest[i_dest] = ft_strljoin(dest[i_dest], &str[i_str], 1);
			i_str++;
			if (str[i_str] && (str[i_str] == str[i_str - 1]))
			{
				dest[i_dest] = ft_strljoin(dest[i_dest], &str[i_str], 1);
				i_str++;
			}
			i_dest++;
		}
		else if (str[i_str] && ft_checkcara(str[i_str], "|") == 1)
		{
			dest[i_dest] = ft_strljoin(dest[i_dest], &str[i_str], 1);
			i_str++;
			i_dest++;
		}
	}
	return (dest);
}
