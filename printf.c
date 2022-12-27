/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kscordel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:38:36 by kscordel          #+#    #+#             */
/*   Updated: 2022/12/27 18:06:18 by kscordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_putp(unsigned long p)
{
	if (!p)
	{
		write(1, "nil", 3);
		return (3);
	}
	else
	{
		write(1, "0x", 2);
		return (2 + ft_putnbr_base(p, "0123456789abcdef", 16));
	}
}

int	ft_instruct(char *pindex, int *len, va_list ap)
{
	if (pindex[i] == 'c')
	{
		write(1, va_arg(ap, char), 1);
		*len = *len + 1;
	}
	else if (pindex[i] == 's')
		*len = *len + ft_putstr(va_arg(ap, char));
	else if (pindex[i] == 'p')
		*len = *len + ft_putp(va_arg(ap, char *));
	else if (pindex[i] == 'd' || pindex[i] == 'i')
		*len = *len + ft_putnbr_base(va_arg(ap, int), "0123456789", 10);
	else if (pindex[i] == 'u')
		*len = *len + ft_putnbru(va_arg(ap, unsigned int));
	else if (pindex[i] == 'x')
		*len = *len + ft_putnbr_base(va_arg(ap, int), "0123456789abcdef", 16);
	else if (pindex[i] == 'X')
		*len = *len + ft_putnbr_base(va_arg(ap, int), "01234567789ABCDEF", 16);
	else if (pindex[i] == '%')
	{
		write(1, '%', 1);
		*len = *len + 1;
	}
	return (i);
}

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	int			i;
	int			len;

	va_start(ap, format);
	if (!format)
		return (0);
	while (format[i])
	{
		if (format[i] == '%')
			i += ft_instruct(&format[i], &len, ap);
		ft_putchar_fd(format[i], 1);
		i++;
	}
	va_end(ap);
	return (len);
}
