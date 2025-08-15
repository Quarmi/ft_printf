/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irmarqui <irmarqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 16:58:56 by colonelolrik      #+#    #+#             */
/*   Updated: 2025/08/15 17:20:25 by colonelolrik     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	int		pcount;
	char	*base;

	pcount = 0;
	base = "0123456789abcdef";
	if (!p)
		return (write(1, "(nil)", 5));
	else
	{
		pcount += ft_putstr("0x");
		pcount += ft_converthex((unsigned long) p, base);
	}
	return (pcount);
}
