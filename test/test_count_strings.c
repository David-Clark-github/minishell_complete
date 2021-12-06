/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_count_strings.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 15:05:45 by dclark            #+#    #+#             */
/*   Updated: 2021/12/04 17:52:34 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

typedef struct	s_quotes {
	int	sin_qt;
	int	dou_qt;
}				t_quotes;

int main(int ac, char **av)
{
	char	*prompt;
	t_string	data_st;

	prompt = "1";
	while (strlen(prompt)) {
		prompt = readline("Minishell: ");
		add_history(prompt);
	}
	rl_clear_history();
	free(prompt);
}
