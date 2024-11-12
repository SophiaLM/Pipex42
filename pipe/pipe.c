#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int	main()
{
	int	fd[2];
	char	buffer[20];
	pid_t pid;

	pipe(fd); //se crea el pipe
	pid = fork(); //creamos el proceso hijo

	if (pid == -1)
	{
		printf("Ha fallado al crear el hijo\n");
		return (0);
	}
	if (pid == 0)
	{
		close(fd[0]); //cerramos el extremo de lectura
		printf("El hijo escribio\n");
		write(fd[1], "Hola Mundo\n", 11);
		return (0);
	}
	else
	{
		close(fd[1]); //cerramos el extre escritura
		//wait(NULL); //finalizamos el hijo
		printf("El padre lee\n");
		read(fd[0], buffer, 11);
		printf("\tmensaje leido -> %s", buffer);
	}
}
