#include "includes/minishell.h"

int main(int ac, char **av)
{
	printf("%s\n%d\n", av[1], ft_check_export_format(av[1]));
}
