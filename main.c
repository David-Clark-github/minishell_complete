/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 13:28:08 by dclark            #+#    #+#             */
/*   Updated: 2021/12/19 13:48:50 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int main()
{
	char	*prompt;
	char	*buffer;
	while (1)
	{
		prompt = readline("Minishell> ");
		add_history(prompt);
		if (check_error_quotes(prompt) == 1)
		{
			buffer = parsing(prompt);
			printf("%s\n", buffer);
			free(buffer);
		}
	}
}
