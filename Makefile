# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgeiger- <mgeiger-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/22 14:29:42 by mgeiger-          #+#    #+#              #
#    Updated: 2023/12/15 15:08:40 by mgeiger-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT = client
SERVER = server

NAME   = $(CLIENT) $(SERVER)

CC = cc
FLAGS = -Wall -Wextra -Werror
RM = rm -f
INC		= libft/*.a

RED		=	\e[0;91m
BLUE	=	\e[0;94m
GREEN	=	\e[0;92m
YELLOW	=	\e[0;33m
WHITE	=	\e[0;97m
BOLD	=	\e[1m
U_LINE	=	\e[4m
RESET	=	\e[0m

SRC_S = server.c
OBJ_S = $(SRC_S:.c=.o)

SRC_C = client.c
OBJ_C = $(SRC_C:.c=.o)

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

server: libft $(OBJ_S)
	@echo "$(YELLOW)Compliling server$(RESET)"
	@$(CC) $(FLAGS) -o $(SERVER) $(OBJ_S) $(INC)
	@echo "$(GREEN)Server built$(RESET)"

client: libft $(OBJ_C)
	@echo "$(YELLOW)Compliling client$(RESET)"
	@$(CC) $(FLAGS) -o $(CLIENT) $(OBJ_C) $(INC)
	@echo "$(GREEN)Client built$(RESET)"

libft:
	@echo "$(YELLOW)Compliling libft$(RESET)"
	@make -C libft/ > /dev/null 2>&1
	@echo "$(GREEN)Made libft$(RESET)"

clean:
	@$(RM) $(OBJ_S) $(OBJ_C)
	@make -C libft/ clean > /dev/null 2>&1
	@echo "$(RED)Removed .o files$(RESET)"

fclean: clean
	@$(RM) $(SERVER) $(CLIENT)
	@make -C libft/ fclean > /dev/null 2>&1
	@echo "$(RED)All files cleaned$(RESET)"

re: fclean all
	@make -C libft/ fclean > /dev/null 2>&1
	@echo "$(GREEN)Successfully cleaned and rebuilt library$(RESET)"

gitpush:
	@make fclean > /dev/null 2>&1
	@git add * > /dev/null 2>&1
	@echo "$(YELLOW)Added all files$(RESET)"
	@git commit -m "minitalk" > /dev/null 2>&1
	@echo "$(YELLOW)Commited files$(RESET)"
	@git push > /dev/null 2>&1
	@echo "$(GREEN)Files pushed$(RESET)"
	@git status
	
.PHONY: all clean fclean re client server libft gitpush
