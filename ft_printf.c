/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kscordel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:38:36 by kscordel          #+#    #+#             */
/*   Updated: 2023/01/06 12:21:31 by kscordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putp(unsigned long p)
{
	if (!p)
		return (write(1, "(nil)", 5));
	else
	{
		write(1, "0x", 2);
		return (2 + ft_putnbru_base(p, MINUSCULE));
	}
}

int	ft_instruct(const char *pindex, int *len, va_list ap)
{
	if (pindex[1] == 'c')
		*len = *len + ft_putchar(va_arg(ap, int));
	else if (pindex[1] == 's')
		*len = *len + ft_putstr(va_arg(ap, char *));
	else if (pindex[1] == 'p')
		*len = *len + ft_putp(va_arg(ap, long unsigned int));
	else if (pindex[1] == 'd' || pindex[1] == 'i')
		*len = *len + ft_putnbr(va_arg(ap, int));
	else if (pindex[1] == 'u')
		*len = *len + ft_putnbru(va_arg(ap, unsigned int));
	else if (pindex[1] == 'x')
		*len = *len + ft_putnbru_base(va_arg(ap, unsigned int), MINUSCULE);
	else if (pindex[1] == 'X')
		*len = *len + ft_putnbru_base(va_arg(ap, unsigned int), MAJUSCULE);
	else if (pindex[1] == '%')
		*len = *len + ft_putchar('%');
	return (2);
}

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	int			i;
	int			len;

	i = 0;
	len = 0;
	va_start(ap, format);
	if (!format)
		return (0);
	while (format[i])
	{
		if (format[i] == '%')
			i += ft_instruct(&format[i], &len, ap);
		else
		{
			ft_putchar(format[i]);
			i++;
			len++;
		}
	}
	va_end(ap);
	return (len);
}
