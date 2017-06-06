# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myernaux <myernaux@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/15 15:25:14 by myernaux          #+#    #+#              #
#    Updated: 2017/06/06 09:34:48 by myernaux         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

INC = includes

SRC_PATH = srcs
OBJ_PATH = obj
LIBFT_PATH = libft
LIBFTA = libft.a
LIBFT = $(addprefix $(LIBFT_PATH)/,$(LIBFTA))

SRC_NAME = ft_printf.c ft_putunbr.c hexa.c parse.c \
		   parse2.c printer_i.c adresse_printer.c ft_putlunbr.c \
			ft_putlnbr.c octal.c ft_putwchar.c ft_putwstr.c \
			print_number.c double_modulo.c octalm.c printer_for_string.c \
			print_chars.c wutils.c parse1.c parse3.c parse4.c \
			adresse_printer2.c hexa2.c octal2.c ft_putwstr2.c
SRCS = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJS = $(addprefix $(OBJ_PATH)/,$(SRC_NAME:.c=.o))

GREEN = \033[0;32m
RED = \033[0;31m
NC = \033[0m

all: $(NAME)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir -p $(OBJ_PATH)
	@gcc $(FLAGS) -I $(INC) -o $@ -c $<

$(NAME): $(OBJS)
	@make -C $(LIBFT_PATH)
	@cp $(LIBFT) ./$(NAME)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "$(GREEN)--------ft_printf compiled--------$(NC)"

clean:
	@make clean -C $(LIBFT_PATH)
	@/bin/rm -rf $(OBJ_PATH)

fclean: clean
	@make fclean -C $(LIBFT_PATH)
	@/bin/rm -rf $(NAME)
	@echo "$(GREEN)---ft_printf removed completely---$(NC)"

re: fclean all
