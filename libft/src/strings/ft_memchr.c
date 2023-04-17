/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolaparr <lolaparr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 13:17:32 by lolaparr          #+#    #+#             */
/*   Updated: 2023/01/21 13:17:44 by lolaparr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*tmp;

	tmp = ((char *)s);
	while (n > 0)
	{
		if (*tmp == (char)c)
			return (tmp);
		++tmp;
		--n;
	}
	return (NULL);
}
