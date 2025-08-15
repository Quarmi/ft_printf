/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irmarqui <irmarqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 16:42:59 by irmarqui          #+#    #+#             */
/*   Updated: 2025/08/15 17:09:46 by colonelolrik     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (write(1, "(null)", 6));
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr(int n)
{
	int	icount;

	icount = 0;
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	else
	{
		if (n < 0)
		{
			icount += ft_putchar('-');
			n *= -1;
		}
		if (n > 9)
		{
			icount += ft_putnbr(n / 10);
			icount += ft_putnbr(n % 10);
		}
		else
			icount += ft_putchar(n + 48);
	}
	return (icount);
}

int	ft_putunbr(unsigned int u)
{
	int	ucount;

	ucount = 0;
	if (u > 9)
	{
		ucount += ft_putunbr(u / 10);
		ucount += ft_putunbr(u % 10);
	}
	else
		ucount += ft_putchar(u + 48);
	return (ucount);
}
