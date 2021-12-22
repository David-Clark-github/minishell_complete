#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

void	print_tab(char **dest)
{
	for (int i = 0; dest[i] != 0; i++)
		printf("%s\n", dest[i]);
}

static char	*ft_strljoin(char *s1, char *s2, int len_s2)
{
	char	*dest;
	int		i_s;
	int		i_d;

	i_s = 0;
	i_d = 0;
	if (s1 == NULL && len_s2 == 0)
		return (NULL);
	dest = malloc(sizeof(char) * (strlen(s1) + len_s2 + 1));
	if (dest == NULL)
		return (NULL);
	while (s1[i_s])
	{
		dest[i_d] = s1[i_s];
		i_s++;
		i_d++;
	}
	i_s = 0;
	while (s2[i_s] && len_s2--)
	{
		dest[i_d] = s2[i_s];
		i_d++;
		i_s++;
	}
	dest[i_d] = '\0';
	return (dest);
}

static int	num_of_element(char *str, char c)
{
	int	res;
	int	i;

	res = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			i++;
		else if (str[i] == '\'')
		{
			res++;
			i++;
			while (str[i] && str[i] != '\'')
				i++;
			i++;
		}
		else if (str[i] == '\"')
		{
			res++;
			i++;
			while (str[i] && str[i] != '\"')
				i++;
			i++;
		}
		else if (isalpha(str[i]))
		{
			res++;
			i++;
			while (str[i] && isalpha(str[i]))
				i++;
		}
	}
	return (res);
}

char	*fill_dest(char *input, int *i)
{
	char	*dest = NULL;
	int	it = *i;
	int	q_1 = 0;
	int	q_2 = 0;
	int	al = 0;
	int	flag = 0;

	if (input[it] == '\'')
		q_1 = 1;
	else if (input[it] == '\"')
		q_1 = 1;
	else if (isalpha(input[it]))
		al = 1;
	if (al == 1)
	{
		while (input[it] && flag == 0)
		{
			if (input[it] != '\'' && input[it] != ' ' && input[it] != '\"')
				dest = ft_strljoin(dest, &input[it], 1);
			else
				flag = 1;
			it++;
		}
		if (flag == 1)
			it++;
	}
	else if (q_1 == 1)
	{
		it++;
		while (input[it] && input[it] != '\'')
		{
			dest = ft_strljoin(dest, &input[it], 1);
			it++;
		}
		it++;
	}
	else if (q_2 == 1)
	{
		it++;
		while (input[it] && input[it] != '\"')
		{
			dest = ft_strljoin(dest, &input[it], 1);
			it++;
		}
		it++;
	}
	*i = it;
	return (dest);
}

char **ft_separ(char *input)
{
	int	i = 0;
	int	i_tab = 0;
	int	num_elem = num_of_element(input, ' ');
	printf("num_elem = %d\n", num_elem);
	char **tab = malloc(sizeof(char *) * num_elem + 1);
	if (tab == NULL)
	{
		printf("tab get null from malloc ");
		return NULL;
	}

	while (num_elem--)
	{
		printf("num_elem = %d\n", num_elem);
		tab[i_tab] = fill_dest(input, &i);
		i_tab++;
	}
	tab[i_tab] = 0;
}

int main(int ac, char **av)
{
	char *input;
	char **tab;
	size_t	n = 0;
	ssize_t	res_gl;

	res_gl = getline(&input, &n, stdin);
	printf("input = %s", input);
	tab = ft_separ(input);
	print_tab(tab);
}
