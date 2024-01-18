/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeiger- <mgeiger-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 12:37:42 by mgeiger-          #+#    #+#             */
/*   Updated: 2023/12/03 13:10:35 by mgeiger-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <signal.h>
# include <unistd.h>
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <string.h>
# include <stdint.h>

int		ft_atoi(const char *nptr);
void	ft_putendl_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
int		ft_printf(const char *format, ...);
int		ft_putchar(char c);
int		ft_putdec(int nb);
int		ft_puthex_l(int nb);
int		ft_puthex_s(int nb);
int		ft_putptr(void *ptr);
int		ft_putstr(const char *str);
int		ft_putundec(unsigned int nb);

#endif