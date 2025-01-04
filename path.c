#include "pipex.h"

//Funcion para encontrar el path dentro del **env y convertirlo en *str;

char	*find_path(char **env)
{
	int	i;

	if (!env) // Si **env no existe falla;
		return (NULL);
	i = 0;
	while (env[i]) //Recorremos el **env;
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0) //Buscar el path;
		{
			*env = ft_strdup(env[i]); //subcadena con el path;
			return (ft_strchr(env[i], '/'));//*str final sin la palabra
			//"path" (solo necesitamos las direcciones);
		}
		i++;
	}
	return (NULL); //Si no encontramos el path falla;
}

//Funcion para encontrar el directorio del comando y devolverlo;

char	*find_cmd(char *path, char *cmd)
{
	char	**temp; //temp para no sobreescribir el path
	int	i;

	i = 0;
	temp = ft_split(path, ':');
	while (temp && temp[i])
	{
		temp[i] = ft_strjoin(temp[i], "/");
		temp[i] = ft_strjoin(temp[i], cmd);
		if (access(temp[i], X_OK) == 0) //funcion para confirmar que es ejecutable
			return(temp[i]);
		i++;
	}
	return (NULL);
}

//Para ejecutar las anteriores, tiene que devolver array por el execve

char	**relative_path(char *av, char **env)
{
	char	*path;
	char	*cmd;
	char	**command;

	path = find_path(env);
	cmd = find_cmd(path, av);
	if (cmd)
		command = ft_split(cmd, ' ');
	else
		command = NULL;
	return (command);
}

/*
int	main(int ac, char **av, char **env)
{
	char	*path = find_path(env);
	printf("paso 1:\n%s\n\n", path);

	char	*comandos = find_cmd(path, av[1]);
	printf("paso 2:\n%s\n", comandos); //recuerda pasarle el argumento del cmd!!
}
*/
