/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolaparr <lolaparr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 14:10:08 by lolaparr          #+#    #+#             */
/*   Updated: 2023/01/21 14:10:50 by lolaparr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;
	int		k;

	i = ft_strlen(s1);
	j = ft_strlen(s2);
	k = -1;
	str = malloc(sizeof(char) * i + j + 1);
	if (!str)
		return (NULL);
	i = -1;
	while (s1[++k])
		str[++i] = s1[k];
	k = -1;
	while (s2[++k])
		str[++i] = s2[k];
	str[i + 1] = '\0';
	return (str);
}
