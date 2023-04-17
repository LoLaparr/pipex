/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolaparr <lolaparr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 23:10:07 by lolaparr          #+#    #+#             */
/*   Updated: 2023/01/21 15:46:20 by lolaparr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}					t_list;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char				*get_next_line(int fd);
void				ft_clean_stash(t_list **stash);
void				ft_dup_stash(char **line, t_list *stash);
void				ft_read_to_buff(int fd, t_list **stash);
void				ft_add_to_stash(t_list **stash, char *buff, int readed);
void				ft_free_stash(t_list *stash);
t_list				*ft_lst_get_last(t_list *stash);
int					ft_new_line(t_list *stash);
void				ft_line_to_return(t_list *stash, char **line);
int					ft_len(char *str);

#endif
