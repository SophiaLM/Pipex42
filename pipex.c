#include "pipex.h"

//Primer hijo, proceso uno que trabaja con el primer comando

void	*first_child(char **av, int *fd, char **env)
{
	int	infile; //para abrir nuestro fd y trabajar con el;
	char	**command; //para los cmd (array por nuestra funcion en path)

	infile = open(av[1], O_RDONLY); //abrimos solo con lectura, fd[0]

	dup2(infile, STDIN_FILENO);
	close(infile);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);

	if (ft_strchr(av[2], '/'))
		command = ft_split(av[2], ' ');
	else
		command = relative_path(av[2], env);
	if (command && command[0])
		execve(command[0], command, env);
	exit(127);
}

void	*second_child(char **av, int *fd, char **env)
{
	int	outfile;
	char	**command;

	outfile = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 666);

	dup2(outfile, STDOUT_FILENO);
	close(outfile);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	close(fd[1]);

	if (ft_strchr(av[3], '/'))
		command = ft_split(av[3], ' ');
	else
		command = relative_path(av[3], env);
	if (command && command[0])
		execve(command[0], command, env);
	exit(127);
}

int	main(int ac, char **av, char **env)
{
	pid_t	pid1;
	pid_t	pid2;
	int	fd[2];
	int	status;

	if (ac != 5)
		return (0);
	pipe(fd);

	pid1 = fork();
	if (pid1 == -1)
		return(1);
	if (pid1 == 0)
		first_child(av, fd, env);
	pid2 = fork();
	if (pid2 == -1)
		return (1);
	if (pid2 == 0)
		second_child(av, fd, env);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, &status, 0);
	waitpid(pid2, &status, 0);

	return (WEXITSTATUS(status));
}
