/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louislaparre <louislaparre@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:04:01 by lolaparr          #+#    #+#             */
/*   Updated: 2023/04/19 19:41:47 by louislaparr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
		unsigned char	*str1;
		unsigned char	*str2;
		size_t					i;

		i = 0;
		str1 = ((unsigned char *)s1);
		str2 = ((unsigned char *)s2);
		while (i < n && (str1[i] || str2[i]))
		{
			if (str1[i] != str2[i])
				return (str1[i] - str2[i]);
			++i;
		}
		return (0);
}
