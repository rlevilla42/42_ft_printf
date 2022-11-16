/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlevilla <rlevilla@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:23:33 by rlevilla          #+#    #+#             */
/*   Updated: 2022/11/16 16:30:42 by rlevilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

int	printf_conv(const char *format, int i, va_list args)
{
	char	*base;

	base = "0123456789abcdef";
	if (format[i + 1] == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	else if (format[i + 1] == 'c')
		return (ft_printf_char((char)va_arg(args, int)));
	else if (format[i + 1] == 's')
		return (ft_printf_s((char *)va_arg(args, char *)));
	else if (format[i + 1] == 'd' || format[i + 1] == 'i')
		return (ft_printf_int((int)va_arg(args, int)));
	else if (format[i + 1] == 'u')
		return (ft_printf_u(va_arg(args, unsigned int)));
	else if (format[i + 1] == 'x')
		return (ft_printf_x(va_arg(args, unsigned int), base));
	else if (format [i + 1] == 'X')
		return (ft_printf_majx(va_arg(args, unsigned int), "0123456789ABCDEF"));
	else if (format[i + 1] == 'p')
		return (ft_printf_p((unsigned long)va_arg(args, void *), base));
	else
		return (0);
}

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
			count += printf_conv(format, i, args);
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
/*
int main(void)
{
	char		c = 'X';
	char		str[] = "";
	int		n = -2147483648;
	unsigned int	n1 = 4294967295;
	unsigned int x = 4294967295;
	unsigned int X = 2147483647;
	unsigned long np = 4294967295;
	void *		p = &np;
	printf("\n%d\n", printf("V1:\n %% c = %c, s = %s, d 
	et i = %d, u = %u, x = %x, X = %X 
	et p = %p\n\n", c, str, n, n1, x, X, p));
	printf("\n%d\n", printf("V1:\n %% c = %c, s = %s, d 
	et i = %d, u = %u, x = %x, X = %X 
	et p = %p\n\n", c, str, n, n1, x, X, p));
	//printf("\n%d\n", printf("V1:\ts = %s\n", str));
	//printf("\n%d\n", ft_printf("V2:\ts = %s\n", str));
}*/
