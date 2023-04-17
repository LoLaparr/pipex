/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolaparr <lolaparr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 18:35:41 by louislaparr       #+#    #+#             */
/*   Updated: 2023/01/09 18:45:00 by lolaparr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef ALPHABET
#  define ALPHABET "0123456789abcdef0123456789ABCDEF"
# endif

int					ft_printf(const char *str, ...);
int					ft_check(char c);
int					ft_do_it(char c, va_list args);
int					ft_putchar(char c);
int					ft_print_str(char *str);
int					ft_put_address(void *ptr);
void				ft_make_ptr(unsigned long int ptr);
int					ft_len_ptr(unsigned long int ptr);
int					ft_put_nbr(int n, int *count);
unsigned int		ft_put_unsigned_nbr(unsigned int n, int *count);
unsigned long int	ft_print_hexa(unsigned long int n, int c, int *count);

#endif
