/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 16:44:01 by seciurte          #+#    #+#             */
/*   Updated: 2022/03/09 17:03:59 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	file_not_exist(t_mini *mini, t_lst *lst)
{
	char	*error;
	char	*tmp;

	tmp = ft_strljoin("Minishell: ", lst->str, ft_strlen(lst->str));
	if (tmp == NULL)

}