/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeiger- <mgeiger-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:23:40 by mgeiger-          #+#    #+#             */
/*   Updated: 2023/12/03 12:30:34 by mgeiger-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

int	ft_putstr(const char *str)
{
	int	count;

	count = 0;
	if (str == NULL)
	{
		ft_putstr("(null)");
		count += 6;
	}
	else
	{
		while (*str)
		{
			count += ft_putchar(*str);
			str++;
		}
	}
	return (count);
}
/*
int	main(void)
{
	char	*str;

	str = "Heinke";
	ft_putstr(str);
	printf("\n");
	printf("%s\n", str);
	return (0);
}
*/