/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louislaparre <louislaparre@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 17:32:34 by lolaparr          #+#    #+#             */
/*   Updated: 2023/04/19 19:33:18 by louislaparr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "ft_printf.h"
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

void	process(char **env, int *pfd, char **av, pid_t pid);
void	child_process(char **env, char **av, char **cmd_arg, int *pfd);
char	*check_access(char **env, char **cmd_arg);
char	*real_path(char *cmd,char *path, char c);

#endif
