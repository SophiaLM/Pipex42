#include "pipex.h"

char	*find_path(char **env)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	if (!env)
		return (NULL);
	while (env[y][x])
	{
		if (ft_strncmp(env[x], "PATH=", 5) == 0)
			return (ft_strdup(env[x + 5]));
		y++;
	}
	return (NULL);
}

int	main(char **env)
{
	char	*path = find_path(*env);
	printf("%s\n", path);
}
