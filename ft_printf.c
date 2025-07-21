/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irmarqui <irmarqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 17:30:05 by irmarqui          #+#    #+#             */
/*   Updated: 2025/07/21 18:15:53 by irmarqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
//#include "ft_printf_utils.c"

int	ft_check_type(va_list args, char c)
{
	int	count;

	count = 0;
	if (c == '%')
	{
		ft_putchar('%');
		count++;
	}
	else if (c == 'c')
	{
		ft_putchar(va_arg(args, int));
		count++;
	}
	else if (c == 's')
		count = ft_putstr(va_arg(args, char *));
	else if (c == 'i')
		count = ft_putnbr(va_arg(args, int));
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int	i;
	int	count;
	va_list	args;

	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			count = count + ft_check_type(args, format[i + 1]);
			i = i + 2;
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
