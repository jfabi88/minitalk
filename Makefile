# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pceccoli <pceccoli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/09 15:40:17 by pceccoli          #+#    #+#              #
#    Updated: 2021/06/09 17:34:24 by pceccoli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER   = server

CLIENT   = client

CC	     = gcc

FLAGS    = -Wall -Werror -Wextra

SERVER_SRC = server.c /
			utils.c /
			utils2.c /



all : $(LIBFT) $(SERVER) $(CLIENT)

$(LIBFT) : 
	@make -C libft

$(SERVER) : server.o error.o minitalk.h
	@$(CC) server.o error.o $(LIBS) -o $@

$(CLIENT) : client.o error.o minitalk.h
	@$(CC) client.o error.o $(LIBS) -o $@

%.o : %.c
	@$(CC) $(FLAGS) $< -c -I includes

clean :
	@make clean -C libft
	@rm -f *.o
	
fclean: clean
	@make fclean -C libft
	@rm -f $(SERVER) $(CLIENT)

re: fclean all