/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolaparr <lolaparr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 13:01:33 by lolaparr          #+#    #+#             */
/*   Updated: 2023/02/09 14:48:55 by lolaparr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long int	ft_atoi(const char *nptr)
{
	long long int	i;
	long long int	nb;
	long long int	count;

	i = 0;
	nb = 0;
	count = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || (nptr[i] == ' '))
		++i;
	if ((nptr[i] == '-') || (nptr[i] == '+'))
	{
		if (nptr[i] == '-')
			count *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nb = nb * 10 + (nptr[i] - '0');
		++i;
	}
	return (nb * count);
}
