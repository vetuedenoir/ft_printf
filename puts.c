/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puts.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kscordel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:40:04 by kscordel          #+#    #+#             */
/*   Updated: 2022/12/27 17:58:10 by kscordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_putstr(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = ft_strlen(str);
	write(1, str, i);
	return (i);
}

int	ft_putnbr_base(int nbr, char *base, int b)
{
	long	nb;

	nb = nbr;
	if (nb < 0)
	{
		write(1, '-', 1);
		nb = nb * -1;
	}
	if (nb >= b)
		ft_putnbr_base(nb / b, base);
	ft_putchar_fd(base[nb % b], 1);
	return (ft_nbrlen(nbr, b));
}

int	ft_putnbru(unsigned long nbr)
{
	if (nbr > 9)
		ft_putnbru(nbr / 10);
	ft_putchar_fd(nbr % 10 + 48, fd);
	return (ft_nbrulen(nbr));
}

static int	ft_nbrlen(int nbr, int b)
{
	int	i;

	i = 0;
	if (nbr == 0)
		return (1);
	while (nbr != 0)
	{
		nbr /= b;
		i++;
	}
	return (i);
}

static int	ft_nbulen(unsigned long nbr)
{
	int	i;

	i = 0;
	if (nbr == 0)
		return (1);
	while (nbr != 0)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}
