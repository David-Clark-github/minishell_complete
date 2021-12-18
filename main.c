/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 13:28:08 by dclark            #+#    #+#             */
/*   Updated: 2021/12/18 17:48:05 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int main()
{
	char	*prompt;
	while (1)
	{
		prompt = readline("Minishell> ");
		add_history(prompt);
		if (check_error_quotes(prompt) == 1)
			parsing(prompt);
	}
}
