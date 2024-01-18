/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeiger- <mgeiger-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 17:43:08 by mgeiger-          #+#    #+#             */
/*   Updated: 2023/12/03 12:30:20 by mgeiger-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

static void	ft_conv(int n, int count)
{
	if (n < 10)
	{
		ft_putchar(n + '0');
		count++;
	}
	else
	{
		ft_putchar(n - 10 + 'a');
		count++;
	}
}

int	ft_puthex_s(int nb)
{
	unsigned int	n;
	int				count;

	count = 0;
	if (nb < 0)
	{
		n = (unsigned int)(-1 * nb);
		n = (~n) + 1;
		count++;
	}
	else
	{
		n = (unsigned int)nb;
		count++;
	}
	if (n >= 16)
	{
		count += ft_puthex_s(n / 16);
		n %= 16;
	}
	ft_conv(n, count);
	return (count);
}
