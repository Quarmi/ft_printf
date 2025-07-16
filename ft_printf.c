/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irmarqui <irmarqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 17:30:05 by irmarqui          #+#    #+#             */
/*   Updated: 2025/07/16 18:26:03 by irmarqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libftprintf.h"

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int	i;
	int	count;

	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] == '%')
		{
			ft_putchar(format[i + 1]);
			i = i + 2;
			count++;
		}
		else if (format[i] == '%' && format[i + 1] == 'c')
		{
			ft_putchar(va_arg(args, int));
			i = i + 2;
			count++;
		}
		else
		{
			ft_putchar(format[i]);
			i++;
			count++;
		}
	}
	va_end(args);
	return (count);
}

int	main(void)
{
//	char	*str = "Hello world";
	char	c = 'v';
	char	d = 'x';

	printf("\n%i", printf("Hello %c World %c", c, d));
	printf("\n");
	printf("\n%i\n", ft_printf("Hello %c World %c", c, d));
	return (0);
}
