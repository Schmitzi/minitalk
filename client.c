/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeiger- <mgeiger-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:40:12 by mgeiger-          #+#    #+#             */
/*   Updated: 2023/12/04 09:34:52 by mgeiger-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_signal(int pid, unsigned char character)
{
	int				i;
	unsigned char	temp;

	i = 8;
	temp = character;
	while (i > 0)
	{
		i--;
		temp = character >> i;
		if (temp % 2 == 0)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(350);
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*send;
	int		i;

	if (argc != 3)
	{
		ft_putendl_fd("Usage: ./client \"PID\" \"message\"\n", 1);
		return (0);
	}
	pid = ft_atoi(argv[1]);
	send = argv[2];
	i = 0;
	while (send[i])
	{
		send_signal(pid, (unsigned)send[i]);
		i++;
	}
	send_signal(pid, '\n');
	send_signal(pid, '\n');
	ft_printf("Message sent\n%i characters sent\n", i);
	return (0);
}
