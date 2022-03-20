/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expension.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <dclark@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 18:35:01 by david             #+#    #+#             */
/*   Updated: 2022/03/20 04:02:15 by dclark           ###   ########.fr       */
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
	if (str[i] && str[i] == '?')
	{
		res++;
		return (res);
	}
	while (str[i] && (ft_isalnum(str[i]) || str[i] == '_'))
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
		fatal_error();
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
	if (prompt != NULL)
		free(prompt);
	return (dest);
}

static void	algo(t_mini *mini, int *i, int *flag)
{
	int		env_len;
	char	*name_env;
	char	*env;

	name_env = NULL;
	env = NULL;
	env_len = found_env_len(&mini->prompt[*i]);
	name_env = ft_getname(&mini->prompt[*i], env_len);
	env = ft_getenv(name_env, mini->cp_ev);
	mini->exp = ft_strjoin_env(mini->exp, env);
	while (env_len-- > 0)
		*i = *i + 1;
	*i = *i + 1;
	*flag = 1;
	free(name_env);
	free(env);
}

void	expension(t_mini *mini)
{
	int		q;
	int		i;
	int		flag;

	i = 0;
	q = 0;
	flag = 0;
	while (mini->prompt[i])
	{
		flag = 0;
		if (mini->prompt[i] == '\'' && q == 0)
			q = 1;
		else if (mini->prompt[i] == '\'' && q == 1)
			q = 0;
		else if (mini->prompt[i] == '$' && q == 0)
			algo(mini, &i, &flag);
		if (flag == 0)
			mini->exp = ft_strjoin(mini->exp, &mini->prompt[i]);
		if (mini->prompt[i] && flag == 0)
			i++;
	}
}
