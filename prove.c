#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	//av1 (la info que leemos) av2 (donde escribimos esa info)
	int	fd1;
	int	fd2;
	char	buffer[1024];
	int	bytes;

	fd1 = open(av[1], O_RDONLY); //abrimos para leer;
	fd2 = open(av[2], O_WRONLY | O_CREAT | O_TRUNC, 0777); //abrimos para escribir, crear y truncar

	while (bytes > 0)
	{
		bytes = read(fd1, &buffer, sizeof(char));
		write(fd2, &buffer, bytes);
	}

	close(fd1);
	close(fd2);
}
