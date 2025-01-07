#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int	main(int ac, char **av)
{
	int	fd[2];
	int	infile;
	int	outfile;

	infile = open(av[1], O_RDONLY);
	outfile = open(av[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);

	pipe(fd);

	dup2(infile, STDIN_FILENO);
	dup2(fd[1], STDIN_FILENO);
	dup2(fd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);

	printf("Hola mundo\n");

	close(infile);
	close(outfile);
	close(fd[0]);
	close(fd[1]);
}
