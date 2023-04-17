/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolaparr <lolaparr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:22:58 by louislaparr       #+#    #+#             */
/*   Updated: 2023/01/09 18:35:56 by lolaparr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_len_ptr(unsigned long int ptr)
{
	int	len;

	len = 0;
	while (ptr != 0)
	{
		ptr /= 16;
		++len;
	}
	return (len);
}

void	ft_make_ptr(unsigned long int ptr)
{
	if (ptr >= 16)
	{
		ft_make_ptr(ptr / 16);
		ft_make_ptr(ptr % 16);
	}
	else
	{
		if (ptr <= 9)
			ft_putchar(ptr + '0');
		else
			ft_putchar(ptr - 10 + 'a');
	}
}

int	ft_put_address(void *ptr)
{
	unsigned long int	pttr;
	int					len;

	pttr = (unsigned long int)ptr;
	len = 0;
	if (pttr == 0)
		len += (int)write(1, "(nil)", 5);
	else
	{
		len += write(1, "0x", 2);
		ft_make_ptr(pttr);
		len += ft_len_ptr(pttr);
	}
	return (len);
}
