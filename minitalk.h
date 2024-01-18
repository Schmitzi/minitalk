/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeiger- <mgeiger-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 12:37:42 by mgeiger-          #+#    #+#             */
/*   Updated: 2023/12/07 16:40:29 by mgeiger-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# define BUFFER_SIZE 1024

# include <signal.h>
# include <unistd.h>
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <string.h>
# include <stdint.h>
# include "./libft/libft.h"

void	handle_signal(int signal);
void	send_signal(int pid, unsigned char character);

#endif
