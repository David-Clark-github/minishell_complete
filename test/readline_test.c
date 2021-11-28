/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 18:02:01 by dclark            #+#    #+#             */
/*   Updated: 2021/11/28 14:50:03 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>


int main(/*int ac, char **av*/)
{
	char	*prompt;
	prompt = readline("Enter input: ");
	add_history(prompt);
	printf("%s\n", prompt);
}
