# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ratavare <ratavare@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/14 13:29:27 by ratavare          #+#    #+#              #
#    Updated: 2023/02/15 11:19:54 by ratavare         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=		libftprintf.a
LIBFT	=		./libft/libft.a	

CC		=		cc

CFLAGS	=		-Wall -Wextra -Werror

RM		=		rm -f

SRC 	=		srcs/ft_printf.c srcs/ft_printf_utils.c 	

OBJ		=		$(SRC:.c=.o)

all:			$(NAME)

$(NAME):		$(OBJ) $(LIBFT)
		ar rcs	$(NAME) $(OBJ)

$(LIBFT):
				make -C ./libft
				cp ./libft/libft.a $(NAME)


clean:			
				make clean -C ./libft
				$(RM) $(OBJ) $(BOBJ)

fclean: clean
				make fclean -C ./libft
				$(RM) $(NAME)

re:		fclean	$(NAME)