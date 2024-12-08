#include <stdio.h>
#include <stddef.h>
#include "libft.h"

char	*find_path(char **env)
{
	char	*path;
	int	i;

	i = 0;
	if (!env)
		return (NULL);
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			return (ft_strdup(env[i + 5]));
		i++;
	}
	return (NULL);
}

int	main(int ac, char **av, char **env)
{
	char	*path = find_path(env);
	printf("%s\n", path);
}
