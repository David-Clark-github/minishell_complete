/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 12:49:32 by dclark            #+#    #+#             */
/*   Updated: 2022/01/24 16:43:47 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_cmd(char **tab_separ)
{
	int	res;

	res = diff_cmd_redir(tab_separ[0]);
	if (res < 1 || res > 7)
		return (-1);
	return (1);
}
