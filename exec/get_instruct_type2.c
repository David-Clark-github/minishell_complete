/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_instruct_type2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 14:40:33 by seciurte          #+#    #+#             */
/*   Updated: 2022/03/19 17:21:08 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_arg_and_redir(int log)
{
	return (log == 0 || is_redir(log));
}
