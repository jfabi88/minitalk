# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pceccoli <pceccoli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/09 15:40:17 by pceccoli          #+#    #+#              #
#    Updated: 2021/06/09 17:20:58 by pceccoli         ###   ########.fr        #
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

$(SERVER) : main_server.o error.o includes/minitalk.h
	@$(CC) main_server.o error.o $(LIBS) -o $@
	@printf "\e[38;5;226m./$@ successfully build🥑\e[0m\n"

$(CLIENT) : main_client.o error.o includes/minitalk.h
	@$(CC) main_client.o error.o $(LIBS) -o $@
	@printf "\e[38;5;46m./$@ successfully build🥝\e[0m\n"

%.o : %.c
	@$(CC) $(FLAGS) $< -c -I includes

clean :
	@make clean -C libft
	@rm -f *.o
	
fclean: clean
	@make fclean -C libft
	@rm -f $(SERVER) $(CLIENT)

re: fclean all