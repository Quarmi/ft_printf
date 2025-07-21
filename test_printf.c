/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irmarqui <irmarqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 16:50:26 by irmarqui          #+#    #+#             */
/*   Updated: 2025/07/21 17:23:12 by irmarqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libftprintf.h"
//#include "ft_printf.c"

int	main(void)
{
	char	*str = "Hello World";
	char	c = 'v';
	char	d = 'x';

	printf("\n%i", printf("Hello %c %% World %c %s", c, d, str));
	printf("\n");
	printf("\n%i", ft_printf("Hello %c %% World %c %s", c, d, str));
	return (0);
}
