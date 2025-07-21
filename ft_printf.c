/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irmarqui <irmarqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 17:30:05 by irmarqui          #+#    #+#             */
/*   Updated: 2025/07/21 17:22:17 by irmarqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
//#include "ft_printf_utils.c"

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
		else if (format[i] == '%' && format[i + 1] == 's')
		{
			count = count + ft_putstr(va_arg(args, char *));
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

/*int	main(void)
{
	char	*str = "Hello World";
	char	c = 'v';
	char	d = 'x';

	printf("\n%i", printf("Hello %c %% World %c %s", c, d, str));
	printf("\n");
	printf("\n%i\n", ft_printf("Hello %c %% World %c %s", c, d, str));
	return (0);
}*/
