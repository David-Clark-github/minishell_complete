/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 18:02:01 by dclark            #+#    #+#             */
/*   Updated: 2021/11/29 15:15:54 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


static unsigned int	ft_strlen(char *str)
{
	unsigned int	res = 0;
	if (!str)
		return 0;
	for (; str[res]; res++)
		;
	return (res);
}

int main(/*int ac, char **av*/)
{
	char	*prompt = "u";
	int		fd_history = open("/mnt/nfs/homes/dclark/.history", O_RDONLY);
	char	*buf;
	size_t	n = 1;
	using_history();
	if (fd_history < 0) {
		printf("fail to execute open(): %d\n", fd_history);
		return 2;
	}
	while (ft_strlen(prompt) != 0) {
		prompt = readline("Enter input: ");
		add_history(prompt);
		if (ft_strlen(prompt) != 0)
			printf("%s\n", prompt);
		printf("%d\n", where_history());
	}
	while (getline(&buf, &n, &fd_history))
		printf("%c", *buf);
	/*
	if (ft_strlen(prompt) == 0) {
		printf("Empty line\n");
	}
	else {
		for (int i = 0; prompt[i]; i++)
			printf("[%c]\n", prompt[i]);
	}
	*/
}
