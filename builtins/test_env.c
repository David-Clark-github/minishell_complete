#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
static char	*zero_len(void)
{
	char	*dest;

	dest = malloc(sizeof(char *));
	dest[0] = '\0';
	return (dest);
}

char	*ft_strljoin(char *s1, char *s2, int s2_len)
{
	char	*dest;
	int		i_s;
	int		i_d;

	i_s = 0;
	i_d = 0;
	if (s2_len == 0)
		return (zero_len());
	dest = malloc(sizeof(char) * (strlen(s1) + s2_len + 1));
	if (dest == NULL)
		return (NULL);
	while (s1 && s1[i_s])
	{
		dest[i_d] = s1[i_s];
		i_s++;
		i_d++;
	}
	i_s = 0;
	while (s2[i_s] && s2_len-- > 0)
	{
		dest[i_d] = s2[i_s];
		i_d++;
		i_s++;
	}
	dest[i_d] = '\0';
	return (dest);
}
static int	tab_len(char **tab_env)
{
	int	res;

	res = 0;
	while (tab_env[res])
		res++;
	return (res);
}

//return -1 if not found
static int	look_name(char *name, char **tab_env)
{
	int	iter;

	iter = 0;
	while (tab_env[iter])
	{
		if (strncmp(name, tab_env[iter], strlen(name)) == 0)
			return (iter);
		iter++;
	}
	return (-1);
}

static char	**change_env(char **tab_env, char *name, char *data)
{
	char	**dest;
	int		i;

	i = 0;
	dest = malloc(sizeof(char *) * (tab_len(tab_env) + 2));
	while (tab_env[i])
	{
		dest[i] = strdup(tab_env[i]);
		i++;
	}
	dest[i] = ft_strljoin(dest[i], name, strlen(name));
	dest[i] = ft_strljoin(dest[i], "=", 1);
	dest[i] = ft_strljoin(dest[i], data, strlen(data));
	dest[++i] = 0;
	i = 0;
	while (tab_env[i])
	{
		free(tab_env[i]);
		i++;
	}
	free(tab_env[i]);
	return (dest);
}

static char	**add_env(char *name, char *data, char **tab_env)
{
	char	**dest;
	int		i;

	i = 0;
	printf("avant malloc");
	dest = malloc(sizeof(char *) * (tab_len(tab_env) + 2));
	printf("apres malloc");
	if (dest == NULL)
		return (NULL);
	while (tab_env[i])
	{
		dest[i] = tab_env[i];
		i++;
	}
	dest[i] = strdup(name);
	dest[i] = ft_strljoin(dest[i], "=", 1);
	dest[i] = ft_strljoin(dest[i], data, strlen(data));
	i++;
	dest[i] = 0;
	i = -1;
	while (tab_env[++i])
		free(tab_env[i]);
	free(tab_env);
	return (dest);
}

int	ft_export(char *name, char *data, char **tab_env)
{
	printf("name = %s\n", name);
	printf("data = %s\n", data);
	if (look_name(name, tab_env) == -1)
	{	
		printf("add_env()\n");
		tab_env = add_env(name, data, tab_env);
	}
	else
	{
		printf("change_env()\n");
		change_env(tab_env, name, data);
	}
	return (EXIT_SUCCESS);
}

int	ft_env(char **tab_env, int fd)
{
	int	i;

	i = 0;
	while (tab_env[i])
	{
		write(fd, tab_env[i], strlen(tab_env[i]));
		write(fd, "\n", 1);
		i++;
	}
	return (EXIT_SUCCESS);
}

char	**copy_env(char **tab_env)
{
	int	i;
	char	**dest;

	i = 0;
	dest = malloc(sizeof(char *) * (tab_len(tab_env) + 1));
	while (i < tab_len(tab_env))
	{
		dest[i] = strdup(tab_env[i]);
		i++;
	}
	dest[i] = 0;
	return (dest);
}

int main(int ac, char **av, char **tab_env)
{
	char **tmp_tab_env = copy_env(tab_env);
	//ft_env(tab_env, 1);
	ft_env(tmp_tab_env, 1);
}
