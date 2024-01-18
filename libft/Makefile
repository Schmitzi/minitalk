# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgeiger- <mgeiger-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/22 14:29:42 by mgeiger-          #+#    #+#              #
#    Updated: 2023/12/03 13:41:11 by mgeiger-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = libft.a

CC      = cc
CFLAGS   = -Wall -Wextra -Werror -g
AR		= ar -rcs
RM      = rm -f

RED     = \e[0;91m
BLUE    = \e[0;94m
GREEN   = \e[0;92m
YELLOW  = \e[0;33m
WHITE   = \e[0;97m
BOLD    = \e[1m
U_LINE  = \e[4m
RESET   = \e[0m

FILES 	=	ft_atoi \
			ft_putchar_fd \
			ft_putendl_fd \
			ft_putnbr_fd \
			ft_printf \
			ft_putchar \
			ft_putdec \
			ft_puthex_l \
			ft_puthex_s \
			ft_putptr \
			ft_putstr \
			ft_putundec \

SRCS_DIR = ./
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))

OBJS_DIR = ./
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))
	
all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $@ $^
	@echo "$(GREEN)Finished$(RESET)"

$(OBJS_DIR)%.o:	$(SRCS_DIR)%.c
	@$(CC) $(CFLAGS) -c -o $@ $<

clean:
	@$(RM) $(OBJS)
	@echo "$(RED)Deleted .o files$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)Deleted libft.a$(RESET)"

re:	fclean all

.PHONY: all clean fclean re client server
