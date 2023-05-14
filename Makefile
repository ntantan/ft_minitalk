# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ntan <ntan@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/01 10:20:34 by ntan              #+#    #+#              #
#    Updated: 2022/03/11 12:25:44 by ntan             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER_SRCS			=	server_src/server.c

CLIENT_SRCS			=	client_src/client.c

SERVER_OBJS			= 	$(SERVER_SRCS:.c=.o)

CLIENT_OBJS			=	$(CLIENT_SRCS:.c=.o)

CC					= 	gcc
RM					= 	rm -f
CFLAGS				= 	-Wall -Wextra -Werror -fsanitize=address

all:				libftprintf server client

server:				$(SERVER_OBJS)
					$(CC) $(CFLAGS) -I. $(SERVER_SRCS) -o server -L./ft_printf -lftprintf

client:				$(CLIENT_OBJS)
					$(CC) $(CFLAGS) -I. $(CLIENT_SRCS) -o client -L./ft_printf -lftprintf

libftprintf:
					make -C ft_printf

clean:
					$(RM) $(SERVER_OBJS)
					$(RM) $(CLIENT_OBJS)
					make clean -C ft_printf

fclean:			
					$(RM) $(SERVER_OBJS)
					$(RM) server
					$(RM) $(CLIENT_OBJS)
					$(RM) client
					make fclean -C ft_printf

re:					fclean all

.PHONY:				all clean fclean re