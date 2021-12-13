#include <stdlib.h>
#include <stdio.h>

int main(int ac, char **av)
{
	char *str;
	str = getenv(av[1]);
	if (str == NULL) {
		printf("env not found\n");
		return 0;
	}
	printf("%s\n", str);
	return 1;
	/*
	Conclusion :
		Le nom de la variable doit être au caractère prêt.
		AUCUNE interpretation de minuscule ou majuscule est faite
	*/
}
