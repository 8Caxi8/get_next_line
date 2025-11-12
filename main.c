#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main ()
{
	int fd1 = open("test.txt", O_RDONLY);
	int fd2 = open("test2.txt", O_RDONLY);
	int fd3 = 0;
	int	i = 0;
	char	*line;

	line = get_next_line(5);
	printf("linha [%d] :%s", ++i, line);
	free(line);

	line = get_next_line(fd2);
	printf("linha [%d] :%s", ++i, line);
	free(line);

	line = get_next_line(fd2);
	printf("linha [%d] :%s", ++i, line);
	free(line);

	close (fd1);
	close (fd2);
	return (0);
}