/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irmarqui <irmarqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 16:50:26 by irmarqui          #+#    #+#             */
/*   Updated: 2025/08/11 18:24:21 by irmarqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
//#include "ft_printf.c"

int	main(void)
{
	char	*str = "Bonjour";
	char	c = 'v';
	int	r = 42;
	unsigned int	u = 735;
	int	h = 30;
	int	H = 30;

	printf("\nCOUNT POINTEUR : %i\n", printf("PR POINTEUR : %p", &str));
	printf("\nPRINTF COUNT : %i", printf("Hello %c %% World %s %d %u %x %X", c, str, r, u, h, H));
	printf("\n");
	printf("\nFT_PRINTF COUNT : %i", ft_printf("Hello %c %% World %s %d %u %x %X", c, str, r, u, h, H));
	ft_printf("\nCOUNT FTPOINTEUR : %i\n", ft_printf("FT POINTEUR : %p", &str));
	return (0);
}
