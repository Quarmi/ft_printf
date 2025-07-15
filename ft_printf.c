/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irmarqui <irmarqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 17:30:05 by irmarqui          #+#    #+#             */
/*   Updated: 2025/07/15 17:55:59 by irmarqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libftprintf.h"

#include <stdio.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_printf(const char *format, ...)
{
/*	va_list	args;

	va_start(args, format);

	va_end(args);*/
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == "%" && format[i + 1] != "c");
		{
		}
		else
		{
			ft_putchar(format[i]);
			i++;
			count++;
		}
	}
	return (count);
}

int	main(void)
{
	char	*str = "Hello world";

	printf("\n%i", printf("%s", str));
	printf("\n");
	printf("\n%i", ft_printf(str));
	return (0);
}
