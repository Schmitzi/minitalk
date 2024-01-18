/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeiger- <mgeiger-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 17:43:08 by mgeiger-          #+#    #+#             */
/*   Updated: 2023/12/03 12:29:51 by mgeiger-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

static char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s++ == (char)c)
			return ((char *)--s);
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

static int	ft_format(va_list args, const char *format)
{
	int	count;

	count = 0;
	if (*format == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (*format == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (*format == 'p')
		count += ft_putptr(va_arg(args, void *));
	else if (*format == 'd' || *format == 'i')
		count += ft_putdec(va_arg(args, int));
	else if (*format == 'u')
		count += ft_putundec(va_arg(args, unsigned int));
	else if (*format == 'x')
		count += ft_puthex_s(va_arg(args, int));
	else if (*format == 'X')
		count += ft_puthex_l(va_arg(args, int));
	else if (*format == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, format);
	if (format == 0)
		return (-1);
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			if (ft_strchr("cspdiuxX%", *++format))
				count += ft_format(args, format);
			else
			{
				count += ft_putchar('%');
				count += ft_putchar(*format);
			}
		}
		else
			count += ft_putchar(*format);
		format++;
	}
	va_end(args);
	return (count);
}
