# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ratavare <ratavare@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/24 12:56:01 by ratavare          #+#    #+#              #
#    Updated: 2023/06/14 15:24:18 by ratavare         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAMECL	=	client

NAMESV 	=	server

CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror

INCLUDES	=	-I$(HEADERS_DIRECTORY)

HEADERS_DIRECTORY = ./includes/
HEADERS_LIST = minitalk.h\

RM		=	rm -f

LIBFT	=	./libft/libft.a

FT_PRINTF = ./ft_printf/libftprintf.a

SRCCL		=	srcs/client.c

SRCSV		=	srcs/server.c

all:			$(NAMECL) $(NAMESV)

$(NAMECL):		$(LIBFT) $(FT_PRINTF) $(SRCCL)
				$(CC) $(CFLAGS) $(SRCCL) $(FT_PRINTF) $(LIBFT) $(INCLUDES) -o $(NAMECL)
				
$(NAMESV):		$(LIBFT) $(FT_PRINTF) $(SRCSV)
				$(CC) $(CFLAGS) $(SRCSV) $(FT_PRINTF) $(LIBFT) $(INCLUDES) -o $(NAMESV)

$(LIBFT):
				make -C ./libft
$(FT_PRINTF):
				make -C ./ft_printf

clean:			
				make clean -C ./libft
				make clean -C ./ft_printf
				$(RM)

fclean: clean
				make fclean -C ./libft
				make fclean -C ./ft_printf
				$(RM) $(NAMECL) $(NAMESV)

re:		fclean	$(NAMECL) $(NAMESV)