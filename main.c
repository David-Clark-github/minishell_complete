/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 13:28:08 by dclark            #+#    #+#             */
/*   Updated: 2022/01/05 13:08:27 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int main()
{
	t_pars	pars;
	while (1)
	{
		pars.prompt = readline("Minishell~ ");
		add_history(pars.prompt);
		if (check_error_quotes(pars.prompt) == 1 && ft_strlen(pars.prompt) != 0)
		{
			pars.list = parsing(pars.prompt, &pars.error_num);
			if (pars.list == NULL)
				printf("error during parsing\n");
			else
			{
				print_lst(&pars.list);
				extract_lst(pars.list);
			}
		}
	}
}
