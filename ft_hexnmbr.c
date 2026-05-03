/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexnmbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelgham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 13:19:59 by moelgham          #+#    #+#             */
/*   Updated: 2024/11/21 13:20:12 by moelgham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	hex_len(unsigned int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len ++;
		num = num / 16;
	}
	return (len);
}

void	ft_printhex(unsigned int num, const char txt)
{
	if (num >= 16)
	{
		ft_printhex(num / 16, txt);
		ft_printhex(num % 16, txt);
	}
	else
	{
		if (num <= 9)
			ft_putchar((num + '0'));
		else
		{
			if (txt == 'x')
				ft_putchar((num - 10 + 'a'));
			if (txt == 'X')
				ft_putchar((num - 10 + 'A'));
		}
	}
}

int	ft_puthex(unsigned int num, const char txt)
{
	if (num == 0)
		return (write(1, "0", 1));
	else
		ft_printhex(num, txt);
	return (hex_len(num));
}
