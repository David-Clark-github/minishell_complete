/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 10:45:48 by dclark            #+#    #+#             */
/*   Updated: 2022/03/11 13:25:48 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*env_var(char *name, char **cp_ev)
{
	char	*data;
	int		i_ev;
	int		i_d;
	int		iter;

	i_ev = 0;
	i_d = 0;
	iter = 0;
	while (cp_ev[i_ev] && iter == 0)
	{
		if (ft_strncmp(name, cp_ev[i_ev], ft_strlen(name)) == 0)
			if (cp_ev[i_ev][ft_strlen(name)] == '=')
				iter = ft_strlen(name) + 1;
		if (iter == 0)
			i_ev++;
	}
	if (iter != 0)
	{
		data = malloc(sizeof(char) * (ft_strlen(&cp_ev[i_ev][iter]) + 1));
		while (cp_ev[i_ev][iter])
		{
			data[i_d] = cp_ev[i_ev][iter];
			iter++;
			i_d++;
		}
		data[i_d] = 0;
		return (data);
	}
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
	return dest;
}

char	*ft_getenv(char *name, char **cp_ev)
{
	if (ft_strlen(name) == 0)
		return (zero_name());
	if (ft_strcmp(name, "?") == 0)
		return (ft_itoa(get_mini()->er_num));
	else
		return (env_var(name, cp_ev));
}
