#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

// getpid -> retorna el id;
//getppid -> retorna el id del proceso padre;


int main(int argc, char *argv[])
{
	pid_t	pid;

	pid = fork();
	if (pid == 0) //si es 0 estamos en el hijo;
	{
		printf("soy el hijo %d, hijo de %d\n", getpid(), getppid());
	}
	else //estamos en el padre;
	{
		printf("soy el padre %d, hijo de %d\n", getpid(), getppid());
	}
}
