/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolaparr <lolaparr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 13:18:54 by lolaparr          #+#    #+#             */
/*   Updated: 2023/01/21 13:19:24 by lolaparr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str;
	unsigned char	*str2;
	size_t			i;

	str = ((unsigned char *)s1);
	str2 = ((unsigned char *)s2);
	i = 0;
	while (i < n)
	{
		if (str[i] != str2[i])
			return (str[i] - str2[i]);
		++i;
	}
	return (0);
}
