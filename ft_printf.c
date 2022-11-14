/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlevilla <rlevilla@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:23:33 by rlevilla          #+#    #+#             */
/*   Updated: 2022/10/13 17:57:33 by rlevilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"
#include <stdlib.h>
#include <stdarg.h>

size_t	ft_buffer_totalsize(const char *format, char *str, va_list)
{
	size_t	i;
	size_t	lenformat;
	size_t	lenargs;
	va_list	args;

	i = 0;
	lenformat = ft_strlen(format);
	lenargs = 0;

	va_start(args, format);
	while (
	va_end(args);
}
int	ft_printf(const char *format, ...)
{
	size_t	i;
	char	*str;
	char	*buffer;
	va_list args;

	str = (char *)format;
	buffer = malloc(sizeof((*buffer) * (ft_buffer_totalsize * 2)));
	i = 0;
	va_start(args, format);
	

	va_end(args);
}
