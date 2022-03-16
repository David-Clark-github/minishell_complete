#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main()
{
	int		fd;
	char	buff[32];
	char	test[32];

	fd = open(".", __O_TMPFILE);
	read(STDIN_FILENO, buff, 32);
	write(fd, buff, 32);
	read(fd, test, 32);
	write(STDOUT_FILENO, test, 32);
	close(fd);
}