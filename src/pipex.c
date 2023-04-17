/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolaparr <lolaparr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 17:26:06 by lolaparr          #+#    #+#             */
/*   Updated: 2023/04/17 19:58:14 by lolaparr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	process(char **env, int *pfd, char **av, pid_t pid)
{
	char **cmd_arg;
	pid = fork();

	if (pid == 0)
	{
		cmd_arg = ft_split(av[2], ' ');
			if (!cmd_arg[0])
				exit (EXIT_FAILURE);
		child_process();
	}
	else
	{
		cmd_arg = ft_split(av[3], ' ');
			if (!cmd_arg[0])
				exit (EXIT_FAILURE);
				whaitpid(pid, NULL, WNOHANG);
		parent_process();
	}
}

int	main(int ac, char **av, char **env)
{
	int	pfd[2];
	pid_t pid;

	if (ac != 5 | !env | !env[0])
		exit(EXIT_FAILURE);
	process(env, pfd, av, pid);
	return (0);
}
