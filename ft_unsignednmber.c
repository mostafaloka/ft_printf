/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsignednmber.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelgham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 13:21:20 by moelgham          #+#    #+#             */
/*   Updated: 2024/11/21 13:32:07 by moelgham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_ulen(unsigned int nb)
{
	int	len;

	len = 0;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		len++;
		nb /= 10;
	}
	return (len);
}

char	*ft_tchen(unsigned int nb)
{
	char	*str;
	int		len;

	len = ft_ulen(nb);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len > 0)
	{
		str[len - 1] = (nb % 10) + '0';
		nb /= 10;
		len--;
	}
	return (str);
}

int	ft_unsigned(unsigned int nb)
{
	char	*str;
	int		printed_chars;

	if (nb == 0)
		return (write(1, "0", 1));
	str = ft_tchen(nb);
	if (!str)
		return (-1);
	printed_chars = ft_putstr(str);
	free(str);
	return (printed_chars);
}
