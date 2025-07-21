/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irmarqui <irmarqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 16:42:59 by irmarqui          #+#    #+#             */
/*   Updated: 2025/07/21 18:32:24 by irmarqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '\0')
		return (0);
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
		return(ft_putstr("-2147483648"));
	else
	{
		if (n < 0)
		{
			ft_putchar('-');
			ft_putnbr(-n);
			count++;
		}
		else if (n > 9)
		{
			ft_putnbr(n / 10);
			ft_putnbr(n % 10);
//			count++;
		}
		else
		{
			ft_putchar(n + 48);
			count++;
		}
	}
	return (count);
}
