#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int	ft_tablen(char **tab)
{
	int	res = 0;

	while (tab && tab[res])
		res++;
	return (res);
}

char	**ft_copy_env(char **tab_env, size_t add)
{
	int		i;
	char	**dest;
	int		tab_len;

	i = 0;
	tab_len = ft_tablen(tab_env);
	if (!tab_env)
		return (NULL);
	dest = malloc(sizeof(char *) * (ft_tablen(tab_env) + 1 + add));
	while (i < tab_len)
	{
		dest[i] = strdup(tab_env[i]);
		i++;
	}
	while (add-- > 0)
	{
		dest[i] = 0;
		i++;
	}
	dest[i] = 0;
	return (dest);
}

int main(int ac, char **av, char **ev)
{
	char **ev_cp;

	ev_cp = ft_copy_env(ev, 0);
	for (int i = 0; i < ft_tablen(ev); i++)
		printf("%s\n", ev[i]);
	for (int i = 0; i < ft_tablen(ev); i++) {
		free(ev_cp[i]);
		ev_cp[i] = NULL;
	}
	free(ev_cp);
	ev_cp = NULL;
	return (0);
}
