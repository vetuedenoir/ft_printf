/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kscordel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:42:25 by kscordel          #+#    #+#             */
/*   Updated: 2022/12/27 18:02:40 by kscordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "libft.h"

int	ft_printf(const char *format, ...);
int	ft_instruct(char *pindex, int *len, va_list ap);
int	ft_putp(unsigned long p);
int	ft_putstr(const char *str);
int	ft_putnbr_base(int nbr, char *base, int b);
int	ft_putnbru(unsigned int nbr);

#endif
