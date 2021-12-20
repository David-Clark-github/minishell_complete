/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <dclark@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 17:45:00 by david             #+#    #+#             */
/*   Updated: 2021/12/20 17:51:26 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

//1 = retour de ligne implémenté
//0 = retour de ligne non implémenter

//le retour de int est pour le retour d'une commande et si elle a bien
// été excuter ou si il y a eu une erreur
// utile pour [echo $?] par exemple

int	ft_echo(char *str, int argument)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	if (argument)
		write(1, "\n", 1);
	return (0);
}
