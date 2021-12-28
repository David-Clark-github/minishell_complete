/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expension.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <dclark@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 18:35:01 by david             #+#    #+#             */
/*   Updated: 2021/12/28 12:21:49 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"


//find_space inclut la '\0' pour name_env
int	find_space(char *str)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	if (str[i] == '$')
		i++;
	while (str[i] && ft_isalpha(str[i]))
	{
		res++;
		i++;
	}
	return (res);	
}


char	*ft_getenv(char *str, int len)
{
	char	*dest;
	int		i;
	int		i_str;

	i = 0;
	i_str = 0;
	dest = malloc(sizeof(char) * len + 1);
	if (dest == NULL)
		printf("malloc NULL\n");
	if (str[i_str] == '$')
		i_str++;
	while (i < len)
	{
		dest[i] = str[i_str];
		i++;
		i_str++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin_env(char *buffer, char *env)
{
	char	*dest;
	int		i_d;
	int		i_be;

	i_d = 0;
	i_be = 0;
	dest = malloc(sizeof(char) * (ft_strlen(buffer) + ft_strlen(env) + 1));
	while (buffer != NULL && buffer[i_be])
	{
		dest[i_d] = buffer[i_be];
		i_d++;
		i_be++;
	}
	i_be = 0;
	while (env != NULL && env[i_be])
	{
		dest[i_d] = env[i_be];
		i_d++;
		i_be++;
	}
	dest[i_d] = '\0';
	if (buffer != NULL)
		free(buffer);
	return (dest);
}

char	*expension(char *buffer, int *error_num)
{
	char	*dest;
	char	*name_env;
	char	*env;
	int		q;
	int		i;
	int		env_len;
	(void)error_num;
	dest = NULL;
	i = 0;
	q = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\'' && q == 0)
			q = 1;
		else if (buffer[i] == '\'' && q == 1)
			q = 0;
		else if (buffer[i] == '$' && q == 0)
		{
			env_len = find_space(&buffer[i]);
			name_env = ft_getenv(&buffer[i], env_len);
			env = getenv(name_env);
			/*
			if (env == NULL)
			{
				*error_num = 0;
				return (NULL);
			}
			*/
			dest = ft_strjoin_env(dest, env);
			while (env_len--)
				i++;
			i++;
			free(name_env);
		}
		//else if (buffer[i]/* && buffer[i] != '$' && q == 0*/)
		dest = ft_strjoin(dest, &buffer[i]);
		i++;
	}
	return (dest);
}
