/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putundec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeiger- <mgeiger-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 17:43:08 by mgeiger-          #+#    #+#             */
/*   Updated: 2023/12/03 12:30:39 by mgeiger-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

int	ft_putundec(unsigned int nb)
{
	int	count;

	count = 0;
	if (nb >= 10)
	{
		count += ft_putundec(nb / 10);
		nb = nb % 10;
	}
	if (nb < 10)
	{
		ft_putchar(nb + '0');
		count++;
	}
	return (count);
}
/*
int	main(void)
{
	unsigned int	nb;

	nb = -1234;
	ft_putundec(nb);
	printf("\n");
	printf("%d\n", nb);
	return (0);
}
*/