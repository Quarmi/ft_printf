/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irmarqui <irmarqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 16:50:26 by irmarqui          #+#    #+#             */
/*   Updated: 2025/07/28 17:58:05 by irmarqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libftprintf.h"
//#include "ft_printf.c"

int	main(void)
{
	char	*str = "Bonjour";
	char	c = 'v';
	int	r = 42;
	unsigned int	u = 1;
	int	h = 0x;

//	printf("PRINTF POINTEUR : %p\n", &str);
	printf("\nPRINTF COUNT : %i", printf("Hello %c %% World %s %d %u %x", c, str, r, u, h));
	printf("\n");
	printf("\nFT_PRINTF COUNT : %i", ft_printf("Hello %c %% World %s %d %u", c, str, r, u));
	return (0);
}
