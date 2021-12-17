/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_V1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <dclark@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:37:17 by david             #+#    #+#             */
/*   Updated: 2021/12/17 17:06:53 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int	check_error_quotes(char *prompt)
{
	int	qt_1 = 0;
	int	qt_2 = 0;
	int	index = 0;

	//init_value(&qt_1, &qt_2, &index);
	while (prompt[index])
	{
		if (prompt[index] == '\'' && qt_2 == 0)
		{
			if (qt_1 == 1)
				qt_1 = 0;
			else if (qt_1 == 0)
				qt_1 = 1;
		}
		else if (prompt[index] == '\"' && qt_1 == 0)
		{
			if (qt_2 == 1)
				qt_2 = 0;
			else if (qt_2 == 0)
				qt_2 = 1;
		}
		index++;
	}
	if ((qt_1 != 0) || (qt_2 != 0))
		return -1;
	return 1;
}

void	parsing(char *prompt)
{
	printf("Hello !\n");
}

int main(int ac, char **av)
{
	char	*prompt;
	int		res_quotes;

	while (1)
	{
		prompt = readline("Mini-mini-shell> ");
		add_history(prompt);
		if (check_error_quotes(prompt) != -1)
		{
			parsing(prompt);
		}
	}
}
