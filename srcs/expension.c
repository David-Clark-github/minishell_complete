/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expension.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <dclark@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 18:35:01 by david             #+#    #+#             */
/*   Updated: 2021/12/19 14:39:37 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"


//find_space inclut la '\0' pour tmp_env
int	find_space(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != ' ')
		i++;
	return (i);	
}


char	*ft_getenv(char *str, int len)
{
	char	*dest;
	int		i;
	int		i_str;

	i = 0;
	i_str = 0;
	printf("ft_getenv => str = %s\n", str);
	dest = malloc(sizeof(char) * len);
	if (dest == NULL)
		printf("malloc NULL\n");
	if (str[i_str] == '$')
		i_str++;
	while (i < len - 1)
	{
		dest[i] = str[i_str];
		i++;
		i_str++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*expension(char *buffer)
{
	char	*dest;
	char	*tmp_env;
	char	*env;
	int		q;
	int		i;
	int		env_len;

	dest = NULL;
	i = 0;
	q = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\'' && q == 0)
			q = 1;
		else if (buffer[i] == '\'' && q == 1)
			q = 0;
		else if (buffer[i] && buffer[i] != '$' && q == 0)
			dest = ft_strjoin(dest, &buffer[i]);
		else if (buffer[i] == '$' && q == 0)
		{
			env_len = find_space(&buffer[i]);
			tmp_env = ft_getenv(&buffer[i], env_len);
		//	printf("getenv(tmp_env) = %s\n", getenv(tmp_env));
			env = getenv(tmp_env);
			printf("");
			dest = ft_strjoin(dest, env);
			i += env_len;
			free(tmp_env);
		}
		i++;
	}
	return (dest);
}
