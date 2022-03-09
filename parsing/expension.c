/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expension.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <dclark@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 18:35:01 by david             #+#    #+#             */
/*   Updated: 2022/03/09 19:35:57 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


//found_env_len inclut la '\0' pour name_env
static int	found_env_len(char *str)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	if (str[i] == '$')
		i++;
	while ((str[i] && ft_isalpha(str[i])) || (str[i] == '?'))
	{
		res++;
		i++;
	}
	return (res);	
}


static char	*ft_getname(char *str, int len)
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

static char	*ft_strjoin_env(char *prompt, char *env)
{
	char	*dest;
	int		i_d;
	int		i_be;

	i_d = 0;
	i_be = 0;
	dest = malloc(sizeof(char) * (ft_strlen(prompt) + ft_strlen(env) + 1));
	while (prompt != NULL && prompt[i_be])
	{
		dest[i_d] = prompt[i_be];
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
	if (prompt != NULL) {
		free(prompt);
		prompt = NULL;
	}
	return (dest);
}

static char	*ft_getenv(char *name, char **cp_ev)
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
		{
			if (cp_ev[i_ev][ft_strlen(name)] == '=')
				iter = ft_strlen(name) + 1;
		}
		if (iter == 0)
			i_ev++;
	}
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

char	*expension(t_mini* mini, int *error_num)
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
	while (mini->prompt[i])
	{
		if (mini->prompt[i] == '\'' && q == 0)
			q = 1;
		else if (mini->prompt[i] == '\'' && q == 1)
			q = 0;
		else if (mini->prompt[i] == '$' && q == 0)
		{
			env_len = found_env_len(&mini->prompt[i]);
			name_env = ft_getname(&mini->prompt[i], env_len);
			env = ft_getenv(name_env, mini->cp_ev);
			dest = ft_strjoin_env(dest, env);
			while (env_len--)
				i++;
			i++;
			free(name_env);
			name_env = NULL;
		}
		dest = ft_strjoin(dest, &mini->prompt[i]);
		i++;
	}
	return (dest);
}
