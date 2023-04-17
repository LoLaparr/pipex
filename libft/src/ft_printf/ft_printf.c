/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolaparr <lolaparr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 01:19:30 by louislaparr       #+#    #+#             */
/*   Updated: 2023/01/09 18:43:26 by lolaparr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check(char c)
{
	char	*str;
	int		i;

	i = 0;
	str = "cspdiuxX%";
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		++i;
	}
	return (0);
}

int	ft_do_it(char c, va_list args)
{
	int	i;

	i = 0;
	if (c == 'c')
		i = ft_putchar(va_arg(args, int));
	else if (c == 's')
		i = ft_print_str(va_arg(args, char *));
	else if (c == 'p')
		i = ft_put_address(va_arg(args, void *));
	else if (c == 'd' || c == 'i')
		ft_put_nbr(va_arg(args, int), &i);
	else if (c == 'u')
		ft_put_unsigned_nbr(va_arg(args, unsigned int), &i);
	else if (c == 'x' || c == 'X')
		ft_print_hexa(va_arg(args, unsigned int), (c == 'X'), &i);
	else if (c == '%')
		i = ft_putchar('%');
	return (i);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		j;
	va_list	args;

	if (!str)
		return (0);
	i = 0;
	j = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%' && ft_check(str[i + 1]) == 1)
		{
			j += ft_do_it(str[i + 1], args);
			i += 2;
		}
		else
		{
			j += ft_putchar(str[i]);
			++i;
		}
	}
	va_end(args);
	return (j);
}

//  int	main(void)
//  {
//  	char			letter;
// 	char			*str;
// 	void			*ptr;
// 	int				dec;
// 	int				i;
// 	unsigned int	ui;
// 	unsigned int	x;
// 	unsigned int	max;

// 	// test char
// 	letter = 'c';
// 	if (printf("len = %d\n", printf("char = %c\n", letter)) ==
// 		ft_printf("len = %d\n", ft_printf("char = %c\n", letter)))
// 		printf("♥‿♥\n\n");
// 	else
// 		printf("(҂◡_◡)\n\n");
// 	// test str
// 	str = NULL;
// 	if (printf("len = %d\n", printf("str = %s\n", str)) ==
// 		ft_printf("len = %d\n", ft_printf("str = %s\n", str)))
// 		printf("♥‿♥\n\n");
// 	else
// 		printf("(҂◡_◡)\n\n");
// 	// test pointer
// 	if (printf("len = %d\n", printf("ptr = %p\n", &ptr)) ==
// 		ft_printf("len = %d\n", ft_printf("ptr = %p\n", &ptr)))
// 		printf("♥‿♥\n\n");
// 	else
// 		printf("(҂◡_◡)\n\n");
// 	// nbr decimal;
// 	dec = -12;
// 	if (printf("len = %d\n", printf("dec = %d\n", dec)) ==
// 		ft_printf("len = %d\n", ft_printf("dec = %d\n", dec)))
// 		printf("♥‿♥\n\n");
// 	else
// 		printf("(҂◡_◡)\n\n");
// 	// nbr entier;
// 	i = 15;
// 	if (printf("len = %d\n", printf("entier = %i\n", i)) ==
// 		ft_printf("len = %d\n", ft_printf("entier = %i\n", i)))
// 		printf("♥‿♥\n\n");
// 	else
// 		printf("(҂◡_◡)\n\n");
// 	// unsigned int i;
// 	ui = -45678;
// 	if (printf("len = %d\n", printf("unsigned int = %u\n", ui)) ==
// 		ft_printf("len = %d\n", ft_printf("unsigned int = %u\n", ui)))
// 		printf("♥‿♥\n\n");
// 	else
// 		printf("(҂◡_◡)\n\n");
// 	// pourcentage;
// 	if (printf("len = %d\n", printf("pourcentage = %%\n")) ==
// 		ft_printf("len = %d\n", ft_printf("pourcentage = %%\n")))
// 		printf(":hearts:‿:hearts:\n\n");
// 	else
// 		printf("(҂◡_◡)\n\n");
// 	// nbr hexamin
// 	x = 278909898;
// 	if (printf("len = %d\n", printf("hexamin = %x\n", x)) ==
// 		ft_printf("len = %d\n", ft_printf("hexamin = %x\n", x)))
// 		printf(":hearts:‿:hearts:\n\n");
// 	else
// 		printf("(҂◡_◡)\n\n");
// 	// nbr hexamax
// 	max = 278909898;
// 	if (printf("len = %d\n", printf("hexamax = %X\n", max)) ==
// 		ft_printf("len = %d\n", ft_printf("hexamax = %X\n", max)))
// 		printf(":hearts:‿:hearts:\n\n");
// 	else
// 		printf("(҂◡_◡)\n\n");
// }
