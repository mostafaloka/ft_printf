/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptrnmb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelgham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 13:20:48 by moelgham          #+#    #+#             */
/*   Updated: 2024/11/21 13:20:54 by moelgham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	len_ptr(uintptr_t nb)
{
	int	len;

	len = 0;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		len++;
		nb = nb / 16;
	}
	return (len);
}

void	ft_print_ptr(uintptr_t b)
{
	if (b >= 16)
	{
		ft_print_ptr(b / 16);
		ft_print_ptr(b % 16);
	}
	else
	{
		if (b <= 9)
			ft_putchar(b + '0');
		else
			ft_putchar(b - 10 + 'a');
	}
}

int	ft_ptr(uintptr_t nb)
{
	int	p;

	p = 0;
	p += write(1, "0x", 2);
	if (nb == 0)
		p += write(1, "0", 1);
	else
	{
		ft_print_ptr(nb);
		p += len_ptr(nb);
	}
	return (p);
}
