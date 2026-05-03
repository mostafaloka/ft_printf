/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelgham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 13:32:31 by moelgham          #+#    #+#             */
/*   Updated: 2024/11/21 13:32:34 by moelgham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

void		ft_printhex(unsigned int num, const char txt);
void		ft_print_ptr(uintptr_t b);
int			ft_len(int n);
int			hex_len(unsigned int num);
int			len_ptr(uintptr_t nb);
int			ft_ulen(unsigned int nb);
int			ft_putchar(int c);
int			ft_putstr(char *str);
int			ft_putnbr(int n);
int			ft_puthex(unsigned int num, const char format);
int			ft_ptr(uintptr_t nb);
int			ft_unsigned(unsigned int nb);
int			ft_printf(const char *format, ...);
char		*ft_char(char *s, unsigned int num, int len);
char		*ft_itoa(int n);
char		*ft_tchen(unsigned int nb);

#endif
