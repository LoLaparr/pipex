/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolaparr <lolaparr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 14:15:24 by lolaparr          #+#    #+#             */
/*   Updated: 2023/04/17 16:20:34 by lolaparr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_lt
{
	char		*content;
	struct s_lt	*next;
}				t_lt;

int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_tolower(int c);
int				ft_toupper(int c);
long long int	ft_atoi(const char *nptr);
void			*ft_calloc(size_t nmemb, size_t size);
char			*ft_strdup(const char *s);
void			ft_bzero(void *s, int n);
size_t			ft_strlen(const char *s);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memset(void *s, int c, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
char			*ft_strchr(const char *s, int c);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			**ft_split(char *s, char c);
char			*ft_strjoin(char const *s1, char const *s2);
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
void			ft_lstadd_back(t_lt **lst, t_lt *new);
void			ft_lstadd_front(t_lt **lst, t_lt *new);
void			ft_lstclear(t_lt **lst, void (*del)(void *));
void			ft_lstdelone(t_lt *lst, void (*del)(void *));
void			ft_lstiter(t_lt *lst, void (*f)(void *));
t_lt			*ft_lstlast(t_lt *lst);
t_lt			*ft_lstmap(t_lt *lst, void *(*f)(void *), void (*del)(void *));
t_lt			*ft_lstnew(void *content);
int				ft_lstsize(t_lt *lst);
char			*ft_strdup(const char *s);

#endif
