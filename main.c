/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 13:28:08 by dclark            #+#    #+#             */
/*   Updated: 2022/01/04 18:08:33 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int main()
{
	t_lst	*list;
	char	*prompt;
	int		error_num;
	while (1)
	{
		prompt = readline("Minishell~ ");
		add_history(prompt);
		if (check_error_quotes(prompt) == 1 && ft_strlen(prompt) != 0)
		{
			list = parsing(prompt, &error_num);
			if (list == NULL)
			{
				printf("env not found\n");
			}
			else
			{
				extract_lst(list);
			}
		}
	}
}
