/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_count_strings.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 15:05:45 by dclark            #+#    #+#             */
/*   Updated: 2021/12/13 16:42:33 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

void	init_value(int *a, int *b, int *c)
{
	*a = 0;
	*b = 0;
	*c = 0;
}

int	check_error_quotes(char *prompt)
{
	int	qt_1;
	int	qt_2;
	int	index;

	init_value(&qt_1, &qt_2, &index);
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

int main(int ac, char **av)
{
	char	*prompt;
	int	quotes = 1;

	prompt = "1";
	while (strlen(prompt) && quotes == 1) {
		prompt = readline("Minishell: ");
		add_history(prompt);
		quotes = check_error_quotes(prompt);
		printf("quotes = %d\n", quotes);
	}
	rl_clear_history();
	free(prompt);
}
