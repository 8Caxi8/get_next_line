#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main ()
{
	int fd = open("test.txt", O_RDONLY);
	int	i = 1;
	char *linha;

	linha = get_next_line(fd);
	while (linha)
	{
		printf("linha [%d] :%s", i, linha);
		linha = get_next_line(fd);
		i++;
	}

	free(linha);
	close (fd);
	return (0);
}