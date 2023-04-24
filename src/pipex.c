/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolaparr <lolaparr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 17:26:06 by lolaparr          #+#    #+#             */
/*   Updated: 2023/04/24 18:19:43 by lolaparr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(char **env, char **av, char **cmd_arg, int *pfd)
{
	int		infile;
	char	*good_path;

	good_path = check_access(env, cmd_arg);
	ft_printf("I am child %s; %s\n", good_path, cmd_arg[1]);
	if (good_path == NULL)
		exit(EXIT_FAILURE);
	infile = open(av[1], O_RDONLY);
	if (dup2(infile, STDIN_FILENO) < 0)
		exit(EXIT_FAILURE);
	if (dup2(pfd[1], STDOUT_FILENO) < 0)
	{
		perror("pfd");
		exit(EXIT_FAILURE);
	}
	close(infile);
	close(pfd[0]);
	close(pfd[1]);
	execve(good_path, cmd_arg, env);
	free(good_path);
}

void	parent_process(char **env, char **av, char **cmd_arg, int *pfd)
{
	int		outfile;
	char	*good_path;

	good_path = check_access(env, cmd_arg);
	ft_printf("I am parent %s\n", good_path);
	if (good_path == NULL)
		exit(EXIT_FAILURE);
	outfile = open(av[4], O_RDWR | O_TRUNC | O_CREAT, 0777);
	if (outfile == -1)
		exit(EXIT_FAILURE);
	if (dup2(pfd[0], STDIN_FILENO) < 0)
		exit(EXIT_FAILURE);
	if (dup2(outfile, STDOUT_FILENO) < 0)
		exit(EXIT_FAILURE);
	close(outfile);
	close(pfd[0]);
	close(pfd[1]);
	execve(good_path, cmd_arg, env);
	free(good_path);
}

void	process(char **env, int *pfd, char **av, pid_t pid)
{
	char	**cmd_arg;

	pid = fork();
	if (pid == 0)
	{
		cmd_arg = ft_split(av[2], ' ');
		if (!cmd_arg[0])
			exit(EXIT_FAILURE);
		child_process(env, av, cmd_arg, pfd);
	}
	else
	{
		cmd_arg = ft_split(av[3], ' ');
		if (!cmd_arg[0])
			exit(EXIT_FAILURE);
		waitpid(pid, NULL, WNOHANG);
		parent_process(env, av, cmd_arg, pfd);
	}
}

int	main(int ac, char **av, char **env)
{
	int		pfd[2];
	pid_t	pid;

	pid = 0;
	if (ac != 5 || !env || !env[0])
		exit(EXIT_FAILURE);
	pipe(pfd);
	process(env, pfd, av, pid);
	return (0);
}
