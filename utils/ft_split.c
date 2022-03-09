/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 08:50:55 by seciurte          #+#    #+#             */
/*   Updated: 2022/02/02 08:52:18 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	*free_all(char **split)
{
	int		i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (NULL);
}

static size_t	cnt_wrds(char const *s, char c)
{
	int	swt;
	int	cnt;

	swt = 0;
	cnt = 0;
	while (s != NULL && *s)
	{
		if (*s == c)
			swt = 0;
		else if (swt == 0)
		{
			swt = 1;
			cnt++;
		}
		s++;
	}
	return (cnt);
}

static size_t	wrdlen(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (*s && *s++ != c)
		len++;
	return (len);
}

static char	**set_all(char const *s, char c)
{
	char	**split;
	int		i;

	i = cnt_wrds(s, c);
	split = malloc(sizeof(char **) * (i + 1));
	if (split == NULL)
		return (NULL);
	while (i >= 0)
	{
		split[i] = NULL;
		i--;
	}
	return (split);
}

char	**ft_split(char *s, char c)
{
	int		i;
	int		j;
	char	**split;

	split = set_all(s, c);
	if (split == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s != NULL && s[i])
	{
		if (s[i] != c)
		{
			split[j] = malloc(sizeof(char *) * wrdlen(&s[i], c) + 1);
			if (split[j] == NULL)
				return (free_all(split));
			ft_strlcpy(split[j], &s[i], wrdlen(&s[i], c) + 1);
			i += wrdlen(&s[i], c);
			j++;
		}
		else
			i++;
	}
	return (split);
}