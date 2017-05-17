# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myernaux <myernaux@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/15 15:25:14 by myernaux          #+#    #+#              #
#    Updated: 2017/05/17 15:41:45 by myernaux         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf  
SRCS = ft_printf.c ft_putunbr.c hexa.c parse.c parse2.c printer_i.c adresse_printer.c ft_putlunbr.c ft_putlnbr.c octal.c ft_putwchar.c ft_putwstr.c
LIBRARIES = libft/libft.a libftprintf.a
OBJECTS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):
	@make -C ./libft
	@gcc -c $(SRCS)
	@ar rc libftprintf.a $(OBJECTS)
	@ranlib libftprintf.a
	@gcc main.c $(LIBRARIES) -o $(NAME)

clean:
	@rm -f $(OBJECTS) libftprintf.a main.o
	@make clean -C ./libft

fclean:	clean
	@rm -f $(NAME)
	@make fclean -C ./libft

re: fclean all
