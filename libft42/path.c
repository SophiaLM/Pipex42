#include <stdio.h>
#include <stddef.h>
#include "libft.h"

//Funcion para encontrar el path dentro del **env y convertirlo en *str;

char	*find_path(char **env)
{
	char	*path;
	int	i;

	i = 0;
	if (!env) // Si **env no existe falla;
		return (NULL);
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

char	*command(char *path, char *cmd)
{
	if (!path || !cmd)
		return (NULL);
	while (path[i])
	{
		path[i] = ft_split(path[i], ";");
		path[i] = ft_strjoin(path[i], *cmd)
		i++;
	}
}

int	main(int ac, char **av, char **env)
{
	char	*path = find_path(env);
	printf("%s\n", path);
	execve
}
