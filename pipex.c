/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soluna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 23:36:03 by soluna            #+#    #+#             */
/*   Updated: 2025/01/08 23:36:18 by soluna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	*first_child(char **av, int *fd, char **env)
{
	int		infile;
	char	**command;
	char	*path;

	path = find_path(env);
	infile = open(av[1], O_RDONLY);
	if (infile == -1)
		ft_error("Error al abrir el infile");
	if (dup2(infile, STDIN_FILENO) == -1)
		ft_error("Dup2 error");
	close(infile);
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		ft_error("Dup2 error");
	close(fd[0]);
	close(fd[1]);
	command = relative_path(av[2], env);
	execve(find_cmd(path, command[0]), command, env);
	exit(127);
}

void	*second_child(char **av, int *fd, char **env)
{
	int		outfile;
	char	**command;
	char	*path;

	path = find_path(env);
	outfile = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile == -1)
		ft_error("error al abrir el outfile");
	if (dup2(outfile, STDOUT_FILENO) == -1)
		ft_error("Dup2 error");
	close(outfile);
	if (dup2(fd[0], STDIN_FILENO) == -1)
		ft_error("Dup2 error");
	close(fd[0]);
	close(fd[1]);
	command = relative_path(av[3], env);
	execve(find_cmd(path, command[0]), command, env);
	exit(127);
}

int	main(int ac, char **av, char **env)
{
	pid_t	pid1;
	pid_t	pid2;
	int		fd[2];
	int		status;

	if (ac != 5)
	{
		ft_error("Numero de argumentos invalido");
		return (-1);
	}
	pipe(fd);
	pid1 = fork();
	if (pid1 == -1)
		ft_error("No ha podido crear el primer hijo");
	if (pid1 == 0)
		first_child(av, fd, env);
	pid2 = fork();
	if (pid2 == -1)
		ft_error("No a podido crear el segundo hijo");
	if (pid2 == 0)
		second_child(av, fd, env);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, &status, 0);
	waitpid(pid2, &status, 0);
	return (WEXITSTATUS(status));
}
