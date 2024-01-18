/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeiger- <mgeiger-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:40:21 by mgeiger-          #+#    #+#             */
/*   Updated: 2023/12/08 10:21:40 by mgeiger-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_signal(int signal)
{
	static unsigned char	current_char;
	static int				i;
	char					*msg;
	int						j;

	j = 0;
	msg = malloc(sizeof(char) * BUFFER_SIZE);
	current_char |= (signal == SIGUSR1);
	i++;
	if (i == 8)
	{
		msg[j++] = current_char;
		i = 0;
		current_char = 0;
	}
	else
		current_char <<= 1;
	if (current_char == '\0')
	{
		msg[j] = '\0';
		ft_printf("%s", msg);
		j = 0;
		free(msg);
	}
}

int	main(void)
{
	ft_printf("\nYour PID: %i\n\n", getpid());
	ft_printf("--------------------PRINT--AREA-----------------------\n\n");
	signal(SIGUSR2, handle_signal);
	signal(SIGUSR1, handle_signal);
	while (1)
		pause();
	return (0);
}
