/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolaparr <lolaparr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 14:50:46 by lolaparr          #+#    #+#             */
/*   Updated: 2023/01/21 15:46:34 by lolaparr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_free_stash(t_list *stash)
{
	t_list	*current;
	t_list	*next;

	current = stash;
	while (current)
	{
		free(current->content);
		next = current->next;
		free(current);
		current = next;
	}
}

t_list	*ft_lst_get_last(t_list *stash)
{
	t_list	*last;

	last = stash;
	while (last->next && last)
		last = last->next;
	return (last);
}

int	ft_new_line(t_list *stash)
{
	int		i;
	t_list	*current;

	i = 0;
	if (stash == NULL)
		return (0);
	current = ft_lst_get_last(stash);
	while (current->content[i])
	{
		if (current->content[i] == '\n')
			return (1);
		++i;
	}
	return (0);
}

void	ft_line_to_return(t_list *stash, char **line)
{
	int	i;
	int	len;

	len = 0;
	while (stash)
	{
		i = 0;
		while (stash->content[i])
		{
			if (stash->content[i] == '\n')
			{
				++len;
				break ;
			}
			++i;
			++len;
		}
		stash = stash->next;
	}
	*line = malloc(sizeof(char) * (len + 1));
	if (!line)
		return ;
}

int	ft_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}
