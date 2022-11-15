/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlevilla <rlevilla@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:23:33 by rlevilla          #+#    #+#             */
/*   Updated: 2022/11/15 23:21:18 by rlevilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	va_list	args;

	count = 0;
	i = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '%')
			{
				write(1, "%", 1);
				count++;
			}
			else if (format[i + 1] == 'c')
			{
				count += ft_printf_char((char)va_arg(args, int));
			}
			else if (format[i + 1] == 's')
			{
				count += ft_printf_s((char *)va_arg(args, char *));
			}
			else if (format[i + 1] == 'd' || format[i + 1] == 'i')
			{
				count += ft_printf_int((int)va_arg(args, int));
			}
			else if (format[i + 1] == 'u')
			{
				count += ft_printf_u(va_arg(args, unsigned int));
			}
			else if (format[i + 1] == 'x')
			{
				count += ft_printf_x(va_arg(args, unsigned int), "0123456789abcdef");
			}
			else if (format [i + 1] == 'X')
			{
				count += ft_printf_majx(va_arg(args, unsigned int), "0123456789ABCDEF");
			}
			else if (format[i + 1] == 'p')
			{
				count += ft_printf_p((unsigned long)va_arg(args, void *), "0123456789abcdef");
			}
			else
			{
				return (0);
			}
			i += 2;

		}
		else
		{
			write(1, &format[i++], 1);
			count++;
		}
	}
	return (count);
}

int main(void)
{
	char		c = 'X';
	char		str[] = "GHB";
	int		n = 93270;
	unsigned int	n1 = 66799;
	unsigned int x = 4294967295;
	unsigned int X = 2147483647;
	unsigned long np = 4294967295;
	void *		p = &np;
	printf("\n%d\n", printf("V1:\n %% c = %c, s = %s, d et i = %d, u = %u, x = %x, X = %X et p = %p\n\n", c, str, n, n1, x, X, p));
	printf("\n%d\n", ft_printf("V2:\n %% c = %c, s = %s, d et i = %d, u = %u, x = %x, X = %X et p = %p\n\n", c, str, n, n1, x, X, p));
}
