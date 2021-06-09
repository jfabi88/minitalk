# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pceccoli <pceccoli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/09 15:40:17 by pceccoli          #+#    #+#              #
#    Updated: 2021/06/09 17:43:39 by pceccoli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER   = server

CLIENT   = client

CC	     = gcc

FLAGS    = -Wall -Werror -Wextra

SERVER_SRC = server.c /
			utils.c /
			utils2.c /

CLIENT_SRC = client.c
			error.c

all : $(SERVER) $(CLIENT)

$(SERVER) : server.o utils.o utils2.o minitalk.h
	@$(CC) server.o utils.o utils2.o -o $@ 

$(CLIENT) : client.o error.o minitalk.h
	@$(CC) client.o error.o $(LIBS) -o $@

%.o : %.c
	@$(CC) $(FLAGS) $< -c -I minitalk.h

clean :
	@rm -rf *.o

fclean: clean
	@rm -rf $(SERVER) $(CLIENT)

re: fclean all