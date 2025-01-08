/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soluna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 23:37:20 by soluna            #+#    #+#             */
/*   Updated: 2025/01/08 23:38:55 by soluna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stddef.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/wait.h>
# include <stdlib.h>
# include "./libft42/libft.h"

void	*first_child(char **av, int *fd, char **env);
void	*second_child(char **av, int *fd, char **env);
char	*ft_error(char *mensaje);
char	*find_path(char **env);
char	*find_cmd(char *path, char *cmd);
char	**relative_path(char *av, char **env);

#endif
