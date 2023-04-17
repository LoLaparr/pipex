/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolaparr <lolaparr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:21:09 by lolaparr          #+#    #+#             */
/*   Updated: 2023/02/10 11:12:37 by lolaparr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	cpy(char *dst, char const *src, int n)
{
	while (n--)
		*dst++ = *src++;
	*dst = '\0';
}

static int	allocate(char const *s, char **list, int word_length, int index)
{
	char	*word;

	word = (char *)malloc(sizeof(char) * (word_length + 1));
	if (!word)
	{
		while (index >= 0)
			free(list[index--]);
		free(list);
		return (0);
	}
	cpy(word, (s - word_length), word_length);
	list[index++] = word;
	return (1);
}

static int	create_word(char const *s, char c, char **list, int words)
{
	int	word_length;
	int	index;

	index = 0;
	while (*s != '\0')
	{
		word_length = 0;
		if (*s != c)
		{
			while (index != words)
			{
				if (*s == c || *s == '\0')
				{
					if (!allocate(s, list, word_length, index))
						return (0);
					index++;
					break ;
				}
				word_length++;
				s++;
			}
		}
		s++;
	}
	return (index);
}

static int	count_words(char const *str, char c)
{
	int	words;

	words = 0;
	while (*str)
	{
		if (*str != c && (*(str + 1) == c || *(str + 1) == '\0'))
			words++;
		str++;
	}
	return (words);
}

char	**ft_split(char *s, char c)
{
	int		words;
	char	**list;
	int		index;

	if (s == 0 || !s)
		return (0);
	words = count_words(s, c);
	list = malloc(sizeof(char *) * (words + 1));
	if (!list)
		return (NULL);
	index = create_word(s, c, list, words);
	if (!list)
		return (NULL);
	list[index] = NULL;
	return (list);
}

// static size_t	ft_separator(char s, char c)
// {
// 	if (s == c || s == '\0')
// 		return (1);
// 	return (0);
// }

// static size_t	ft_count(char *s, char c)
// {
// 	size_t	lenword;
// 	size_t	i;

// 	i = 0;
// 	lenword = 0;
// 	while (ft_separator(s[i], c) == 1)
// 		++i;
// 	while (ft_separator(s[i], c) == 0)
// 	{
// 		++i;
// 		++lenword;
// 	}
// 	return (lenword);
// }

// static size_t	ft_make(char **str, int count, char *s, char c)
// {
// 	size_t	i;
// 	size_t	o;
// 	size_t	lenword;

// 	i = 0;
// 	o = 0;
// 	lenword = ft_count(s, c);
// 	str[count] = malloc(sizeof(char) * lenword + 1);
// 	if (!str[count])
// 		return (0);
// 	while (s[i])
// 	{
// 		if (ft_separator(s[i], c) == 0)
// 			break ;
// 		++i;
// 	}
// 	while (ft_separator(s[i], c) == 0)
// 	{
// 		str[count][o] = s[i];
// 		++o;
// 		++i;
// 	}
// 	str[count][o] = '\0';
// 	return (i);
// }

// char	**ft_split(char const *s, char c)
// {
// 	size_t	i;
// 	size_t	count;
// 	size_t	wordcount;
// 	char	**str;

// 	i = 0;
// 	wordcount = 0;
// 	while (s[i])
// 	{
// 		if (s[i] != c && ((s[i + 1] == c) || (s[i + 1] == '\0')))
// 			++wordcount;
// 		++i;
// 	}
// 	i = 0;
// 	count = 0;
// 	str = malloc(sizeof(char *) * (wordcount + 1));
// 	if (!str)
// 		return (NULL);
// 	while (count < wordcount)
// 	{
// 		i = i + ft_make(str, count, &((char *)s)[i], c);
// 		++count;
// 	}
// 	str[count] = (NULL);
// 	return (str);
// }
