/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolaparr <lolaparr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 00:55:32 by lolaparr          #+#    #+#             */
/*   Updated: 2023/01/23 10:42:55 by lolaparr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_add_to_stash(t_list **stash, char *buff, int readed)
{
	t_list	*new_lst;
	t_list	*last;
	int		i;

	i = 0;
	new_lst = malloc(sizeof(t_list));
	if (!new_lst)
		return ;
	new_lst->next = NULL;
	new_lst->content = malloc(sizeof(char) * (readed + 1));
	if (!new_lst->content)
		return ;
	while (buff[i] && i < readed)
	{
		new_lst->content[i] = buff[i];
		++i;
	}
	new_lst->content[i] = '\0';
	if (*stash == NULL)
	{
		*stash = new_lst;
		return ;
	}
	last = ft_lst_get_last(*stash);
	last->next = new_lst;
}

void	ft_read_to_buff(int fd, t_list **stash)
{
	char	*buff;
	int		readed;

	readed = 1;
	while (ft_new_line(*stash) == 0 && readed != 0)
	{
		buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buff)
			return ;
		readed = (int)read(fd, buff, BUFFER_SIZE);
		if ((*stash == NULL && readed == 0) || readed == -1)
		{
			free(buff);
			return ;
		}
		buff[readed] = '\0';
		ft_add_to_stash(stash, buff, readed);
		free(buff);
	}
}

void	ft_dup_stash(char **line, t_list *stash)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (stash == NULL)
		return ;
	ft_line_to_return(stash, line);
	if (*line == NULL)
		return ;
	while (stash)
	{
		i = 0;
		while (stash->content[i])
		{
			if (stash->content[i] == '\n')
			{
				(*line)[j++] = stash->content[i];
				break ;
			}
			(*line)[j++] = stash->content[i++];
		}
		stash = stash->next;
	}
	(*line)[j] = '\0';
}

void	ft_clean_stash(t_list **stash)
{
	t_list	*clean_node;
	t_list	*last;
	int		i;
	int		j;

	clean_node = malloc(sizeof(t_list));
	if (*stash == NULL || clean_node == NULL)
		return ;
	clean_node->next = NULL;
	last = ft_lst_get_last(*stash);
	i = 0;
	while (last->content[i] != '\n' && last->content[i])
		++i;
	if (last->content[i] == '\n' && last->content[i])
		i++;
	clean_node->content = malloc(sizeof(char) * ((ft_len(last->content) - i)
				+ 1));
	if (!clean_node->content)
		return ;
	j = 0;
	while (last->content[i])
		clean_node->content[j++] = last->content[i++];
	clean_node->content[j] = '\0';
	ft_free_stash(*stash);
	*stash = clean_node;
}

char	*get_next_line(int fd)
{
	static t_list	*stash = NULL;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	ft_read_to_buff(fd, &stash);
	if (stash == NULL)
		return (NULL);
	ft_dup_stash(&line, stash);
	ft_clean_stash(&stash);
	if (line == NULL || line[0] == '\0')
	{
		ft_free_stash(stash);
		stash = NULL;
		free(line);
		return (NULL);
	}
	return (line);
}

// int	main(void)
// {
// 	char	*test;
// 	int		fd;

// 	fd = open("test.txt", O_RDONLY);
// 	test = get_next_line(fd);
// 	while (test)
// 	{
// 		printf("%s", test);
// 		free(test);
// 		test = get_next_line(fd);
// 	}
// 	return (0);
// }
