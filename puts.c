/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puts.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kscordel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:40:04 by kscordel          #+#    #+#             */
/*   Updated: 2023/01/03 20:51:32 by kscordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	if (!str)
		return (0);
	return (write(1, str, ft_strlen(str)));
}

int	ft_putnbr_base(int nbr, char *base, int b)
{
	long	nb;
	int	count;

	nb = nbr;
	count = 0;
	if (nb < 0)
	{
		count += write(1, '-', 1);
		nb = nb * -1;
	}
	if (nb >= b)
		count += ft_putnbr_base(nb / b, base);
	count += ft_putchar(base[nb % b]);
	return (count);
}

int	ft_putnbru(unsigned long nbr)
{
	int	count;

	count = 0;
	if (nbr > 9)
		count += ft_putnbru(nbr / 10);
	count += ft_putchar(nbr % 10 + 48);
	return (count);
}
