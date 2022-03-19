/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 10:45:48 by dclark            #+#    #+#             */
/*   Updated: 2022/03/19 12:40:59 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*algo1(char *data, int *i_ev, int *i_d, int *iter)
{		
	data = malloc(sizeof(char) * \
		(ft_strlen(&get_mini()->cp_ev[*i_ev][*iter]) + 1));
	while (get_mini()->cp_ev[*i_ev][*iter])
	{
		data[*i_d] = get_mini()->cp_ev[*i_ev][*iter];
		*iter = *iter + 1;
		*i_d = *i_d + 1;
	}
	data[*i_d] = 0;
	return (data);
}

static void	loop(char *name, int *i_ev, int *iter)
{
	if (ft_strncmp(name, get_mini()->cp_ev[*i_ev], ft_strlen(name)) == 0)
		if (get_mini()->cp_ev[*i_ev][ft_strlen(name)] == '=')
			*iter = ft_strlen(name) + 1;
	if (*iter == 0)
		*i_ev = *i_ev + 1;
}

static char	*env_var(char *name, char **cp_ev)
{
	char	*data;
	int		i_ev;
	int		i_d;
	int		iter;

	i_ev = 0;
	i_d = 0;
	iter = 0;
	data = NULL;
	while (cp_ev[i_ev] && iter == 0)
		loop(name, &i_ev, &iter);
	if (iter != 0)
		return (algo1(data, &i_ev, &i_d, &iter));
	else if (iter == 0)
	{
		data = malloc(sizeof(char));
		data[0] = 0;
		return (data);
	}
	return (NULL);
}

static char	*zero_name(void)
{
	char	*dest;

	dest = (char *)malloc(sizeof(char) * 2);
	if (dest == NULL)
		return (free(dest), NULL);
	dest[0] = '$';
	dest[1] = 0;
	return (dest);
}

char	*ft_getenv(char *name, char **cp_ev)
{
	if (ft_strlen(name) == 0)
		return (zero_name());
	if (ft_strcmp(name, "?") == 0)
		return (ft_itoa(g_err_num));
	else
		return (env_var(name, cp_ev));
}
