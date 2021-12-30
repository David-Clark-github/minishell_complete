/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 13:28:08 by dclark            #+#    #+#             */
/*   Updated: 2021/12/30 11:19:35 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int main()
{
	char	*prompt;
	char	*buffer;
	int		error_num;
	while (1)
	{
		prompt = readline("Minishell~ ");
		add_history(prompt);
		if (check_error_quotes(prompt) == 1 && ft_strlen(prompt) != 0)
		{
			buffer = parsing(prompt, &error_num);
			if (buffer == NULL)
			{
				printf("env not found\n");
			}
			else
			{
				free(buffer);
			}
		}
	}
}
