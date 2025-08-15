/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irmarqui <irmarqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 16:42:59 by irmarqui          #+#    #+#             */
/*   Updated: 2025/08/15 16:40:42 by colonelolrik     ###   ########.fr       */
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

/*int	ft_puthexlow(unsigned int hl)
{
	char	*base;
	int	hlcount;

	hlcount = 0;
	base = "0123456789abcdef";
	if (hl > 15)
	{
		hlcount += ft_puthexlow(hl / 16);
		hlcount += ft_puthexlow(hl % 16);
	}
	else
		hlcount += ft_putchar(base[hl % 16]);
	return (hlcount);
}

int	ft_puthexup(unsigned int hu)
{
	char	*base;
	int	hucount;

	hucount = 0;
	base = "0123456789ABCDEF";
	if (hu > 15)
	{
		hucount += ft_puthexup(hu / 16);
		hucount += ft_puthexup(hu % 16);
	}
	else
		hucount += ft_putchar(base[hu % 16]);
	return (hucount);
}

int	ft_putpoint(void *p)
{
	char	*base;
	int	pcount;

	pcount = 0;
	base = "0123456789abcdef";
	if (!p)
		return (write(1, "(nil)", 5));
//	else
//		pcount += ft_putstr("0x");
	else
	{
		if (p > 15)
		{
			pcount += ft_putpoint(p / 16);
			pcount += ft_putpoint(p % 16);
		}
		else
			pcount += ft_putchar(base[p % 16]);
	}

	return (pcount);
}*/

int	ft_converthex(unsigned long nb, char *base)
{
	int	count;

	count = 0;
	if (nb > 15)
	{
		count += ft_converthex(nb / 16, base);
		count += ft_converthex(nb % 16, base);
	}
	else
		count += ft_putchar(base[nb % 16]);
	return (count);
}

int	ft_puthex(unsigned int h, char c)
{
	char	*base;

	if (c == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	return (ft_converthex(h, base));
}

int	ft_putpoint(void *p)
{
	int	pcount;
	char	*base;

	base = "0123456789abcdef";
	pcount = 0;
	if (!p)
		return (write(1, "(nil)", 5));
	else
	{
		pcount += ft_putstr("0x");
		pcount += ft_converthex((unsigned long) p, base);
	}
	return (pcount);
}
