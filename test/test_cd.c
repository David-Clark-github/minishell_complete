#include <unistd.h>
#include <stdio.h>

int main(int ac, char **av)
{
	while (1) {
		if (chdir(av[1]) == 0)
			return (0);
		else
			printf("wrong PATH\n");
	}
}
