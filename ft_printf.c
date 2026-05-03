/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelgham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 13:17:26 by moelgham          #+#    #+#             */
/*   Updated: 2024/11/21 13:17:54 by moelgham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

static int	handle_conversion(va_list vl, char format)
{
	if (format == 'c')
		return (ft_putchar(va_arg(vl, int)));
	else if (format == 's')
		return (ft_putstr(va_arg(vl, char *)));
	else if (format == 'p')
		return (ft_ptr(va_arg(vl, uintptr_t)));
	else if (format == 'd' || format == 'i')
		return (ft_putnbr(va_arg(vl, int)));
	else if (format == 'u')
		return (ft_unsigned(va_arg(vl, unsigned int)));
	else if (format == 'x' || format == 'X')
		return (ft_puthex(va_arg(vl, unsigned int), format));
	else if (format == '%')
		return (ft_putchar('%'));
	return (-1);
}

static int	process_format(va_list vl, const char *format, int *i)
{
	int	res;

	res = 0;
	if (format[*i] == '%')
	{
		res = handle_conversion(vl, format[*i + 1]);
		if (res == -1)
			return (-1);
		(*i)++;
	}
	else
		res = ft_putchar(format[*i]);
	return (res);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		p;
	int		res;
	va_list	vl;

	i = 0;
	p = 0;
	va_start(vl, format);
	if (!format || write(1, 0, 0) == -1)
	{
		return (-1);
	}
	while (format[i])
	{
		res = process_format(vl, format, &i);
		if (res == -1)
		{
			va_end(vl);
			return (-1);
		}
		p += res;
		i++;
	}
	va_end(vl);
	return (p);
}
