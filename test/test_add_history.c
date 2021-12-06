/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_add_history.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 18:02:01 by dclark            #+#    #+#             */
/*   Updated: 2021/12/06 13:49:35 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>


int main(/*int ac, char **av*/)
{
	char	*prompt = "1";
	while (strlen(prompt)) {
		prompt = readline("Minishell: ");
		add_history(prompt);
	}
	rl_clear_history();
	free(prompt);
}
