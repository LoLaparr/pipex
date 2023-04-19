/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louislaparre <louislaparre@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 17:26:06 by lolaparr          #+#    #+#             */
/*   Updated: 2023/04/19 19:30:51 by louislaparr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*real_path(char *cmd,char *path, char c)
{
	int	i;
	int	j;
	char *real_path;

	i = -1;
	j = -1;
	real_path = malloc(sizeof(char) * (ft_strlen(path) + ft_strlen(cmd) + 1))
		if (!real_path)
			return (NULL);
	while (path[++i])
		real_path[i] = path[i];
	real_path[i] = c;
	while (cmd[++j])
		real_path[++i] = cmd[i];
	real_path[i] = '\0';
	return (real_path);
}

char	*check_access(char **env, char **cmd_arg)
{
	int	i;
	char **path;

	i = 0;
	while (env[i] && ft_strncmp("PATH=", env[i], 5) != 0)
		++i;
	if (env[i] == NULL)
		exit (EXIT_FAILURE);
	path = ft_split(env[i], ':');
	if (!path)
		exit (EXIT_FAILURE);
	i = 0;
	while (path[i])
	{
		path = real_path(cmd_arg[0], path[i], '/');
		if (path == NULL)
			return (NULL);
		if (access(path[i], F_OK) == 0)
			return (path[i]);
		free(path);
		++i;
	}
	return (NULL);
}
