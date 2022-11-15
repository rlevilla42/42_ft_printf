/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlevilla <rlevilla@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:23:33 by rlevilla          #+#    #+#             */
/*   Updated: 2022/11/15 18:16:08 by rlevilla         ###   ########.fr       */
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
			if (format[++i] == '%')
			{
				write(1, "%", 1);
				count++;
			}
			else if (format[++i] == 'c')
			{
				count += ft_printf_char((char)va_arg(args, int));
			}
			else if (format[++i] == 's')
			{
				count += ft_printf_s((char *)va_arg(args, char *));
			}
			else if (format[++i] == 'd' || format[i + 1] == 'i')
			{
				count += ft_printf_int((int)va_arg(args, int));
			}
			else if (format[++i] == 'u')
			{
				count += ft_printf_u(va_arg(args, unsigned int));
			}
			else if (format[++i] == 'x')
			{
				count += ft_printf_x(va_arg(args, unsigned int), "0123456789abcdef");
			}
			else if (format [++i] == 'X')
			{
				count += ft_printf_majx(va_arg(args, unsigned int), "0123456789ABCDEF");
			}
			else if (format[++i] == 'p')
			{
				count += ft_printf_p((unsigned long)va_arg(args, void *), "0123456789abcdef");
			}
			else
				return (0);
			i++;

		}
		else if (!(format[i] == '%'))
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
	int		n = 93720;
	unsigned int	n1 = 66799;
	unsigned int x = 4294967295;
	unsigned int X = 2147483647;
	unsigned long np = 4294967295;
	void *		p = &np;
	printf("\n%d\n", printf("Voila ce que output printf:\n c = %c, s = %s, d et i = %d, u = %u, x = %x, X = %X et p = %p\n\n ", c, str, n, n1, x, X, p));
	printf("\n%d\n", ft_printf("Voila ce que output FT_printf:\n c = %c, s = %s, d et i = %d, u = %u, x = %x, X = %X et p = %p\n\n ", c, str, n, n1, x, X, p));
}
