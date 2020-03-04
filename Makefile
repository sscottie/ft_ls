# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sscottie <sscottie@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/13 18:35:13 by sscottie          #+#    #+#              #
#    Updated: 2020/03/03 11:45:19 by sscottie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

# COLORS

GREEN = \033[0;32m
RED = \033[0;31m
RED_B = \033[1;4;31m
BLUE = \033[1;4;34m
RESET = \033[0m

FT_LS 		= ft_ls
CFLAGS		= -Wall -Wextra -Werror
INC			= -I include
FT_PF 		= ./lib/ft_printf/
SRC_DIR		= ./src/
OBJ_DIR 	= obj/
PF_A		= ./lib/ft_printf/libftprintf.a
HEADER		= ft_ls.h
PF_H		= ft_printf.h
PF_INC		= -I ./lib/ft_printf/include

SRC_FT_LS		= ft_ls.c \

SRC_LS	= $(addprefix $(SRC_DIR), $(SRC_FT_LS))

all: pf $(FT_LS)

$(FT_LS):: pf $(SRC_LS)
	gcc $(CFLAGS) $(SRC_LS) -o $(FT_LS) $(INC) $(PF_INC) $(PF_A)

pf: 
	make -C ./lib/ft_printf/

clean:
	@make -C ./lib/ft_printf clean

fclean: clean
	@rm -rf $(P_S)
	@rm -rf $(CH)
	@make -C ./lib/ft_printf fclean
	@rm -rf $(PR)

re: fclean all