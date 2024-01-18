/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeiger- <mgeiger-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 17:43:08 by mgeiger-          #+#    #+#             */
/*   Updated: 2023/12/03 12:30:26 by mgeiger-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

int	ft_putptr(void *ptr)
{
	unsigned long	hex;
	char			buffer[16];
	int				result;
	int				i;
	int				remainder;

	i = 0;
	if (ptr == NULL)
		return (write(1, "(nil)", 5));
	hex = (unsigned long)ptr;
	result = write(1, "0x", 2);
	while (hex > 0)
	{
		remainder = hex % 16;
		if (remainder < 10)
			buffer[i++] = remainder + '0';
		else
			buffer[i++] = remainder - 10 + 'a';
		hex = hex / 16;
	}
	while (i > 0)
		result += write(1, &buffer[--i], 1);
	return (result);
}
/*
int	main(void)
{
	int	nb = 3741239533;

	ft_putptr(&nb);
	printf("\n");
	printf("%p\n", &nb);
}
*/