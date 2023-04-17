/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_nbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolaparr <lolaparr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 19:58:08 by louislaparr       #+#    #+#             */
/*   Updated: 2023/01/09 18:46:41 by lolaparr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_nbr(int n, int *count)
{
	long long int	nbr;

	nbr = n;
	if (nbr < 0)
	{
		*count += write(1, "-", 1);
		nbr *= -1;
	}
	if (nbr > 9)
		ft_put_nbr(nbr / 10, count);
	ft_putchar(nbr % 10 + '0');
	return (*count += 1);
}

unsigned int	ft_put_unsigned_nbr(unsigned int n, int *count)
{
	if (n > 9)
		ft_put_unsigned_nbr(n / 10, count);
	ft_putchar(n % 10 + '0');
	return (*count += 1);
}

unsigned long int	ft_print_hexa(unsigned long int n, int c, int *count)
{
	if (n >= 16)
		ft_print_hexa(n / 16, c, count);
	ft_putchar(ALPHABET[n % 16 + c * 16]);
	return (*count += 1);
}
