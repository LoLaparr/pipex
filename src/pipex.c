/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louislaparre <louislaparre@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 17:26:06 by lolaparr          #+#    #+#             */
/*   Updated: 2023/04/19 19:32:14 by louislaparr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(char **env, char **av, char **cmd_arg, int *pfd)
{
	int	infile;
	char	*good_path;

	good_path = check_access(env, cmd_arg);
	if (good_path == NULL)
		exit (EXIT_FAILURE);
	infile = open(av[2], O_WDONLY);
	if (dup2(infile, STDIN_FILENO) < 0)
		exit (EXIT_FAILURE);
	if (dup2(pfd[1], STDOUT_FILENO) < 0)
		exit (EXIT_FAILURE);
	execve(good_path, cmd_arg, env);
	close(infile);
	close(pfd[0]);
	close(pfd[1]);
	free(good_path);
}

void	process(char **env, int *pfd, char **av, pid_t pid)
{
	char **cmd_arg;
	pid = fork();

	if (pid == 0)
	{
		cmd_arg = ft_split(av[2], ' ');
			if (!cmd_arg[0])
				exit (EXIT_FAILURE);
		child_process(env, av, cmd_arg, pfd);
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
	pipe(pfd);
	process(env, pfd, av, pid);
	return (0);
}
