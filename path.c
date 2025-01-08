#include "pipex.h"

char	*ft_error(char *mensaje)
{
	perror(mensaje);
	exit(1);
}

char	*find_path(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
		{
			*env = ft_strdup(env[i]);
			return (ft_strchr(env[i], '/'));
		}
		i++;
	}
	return (NULL);
}

char	*find_cmd(char *path, char *cmd)
{
	char	**temp;
	int		i;

	i = 0;
	temp = ft_split(path, ':');
	while (temp && temp[i])
	{
		temp[i] = ft_strjoin(temp[i], "/");
		temp[i] = ft_strjoin(temp[i], cmd);
		if (access(temp[i], X_OK) == 0)
			return (temp[i]);
		i++;
	}
	if (access(cmd, X_OK) == 0)
		return (cmd);
	return (NULL);
}

char	**relative_path(char *av, char **env)
{
	char	*path;
	char	*cmd;
	char	**command;

	path = find_path(env);
	if (av)
	{
		command = ft_split(av, ' ');
		if (!command && !command[0])
			return (NULL);
	}
	cmd = find_cmd(path, command[0]);
	if (!cmd)
		ft_error("Comando no encontrado");
	if (access(cmd, X_OK) == 0)
		return (command);
	return (NULL);
}