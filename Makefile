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
RED_B = \033[1;31m
BLUE = \033[1;34m
RESET = \033[0m

FT_LS 		= ft_ls
CFLAGS		= -Wall -Wextra -Werror
INC			= -I include
FT_PF 		= ./lib/ft_printf/
SRC_DIR		= ./src/
OBJ_DIR 	= ./temp/
PF_A		= ./lib/ft_printf/libftprintf.a
HEADER		= ft_ls.h
PF_H		= ft_printf.h
PF_INC		= -I ./lib/ft_printf/include

SRC_FT_LS		= ft_ls.c \

SRC_LS	= $(addprefix $(SRC_DIR), $(SRC_FT_LS))
OBJ_LS	= $(addprefix $(OBJ_DIR), $(patsubst %.c, %.o, $(SRC_FT_LS)))

all: $(FT_LS)

$(FT_LS):: pf
$(FT_LS):: $(OBJ_DIR) $(OBJ_LS) $(SRC_LS)
	@echo "$(BLUE)ft_ls:     $(GREEN)Compiling$(RESET)"
	@gcc $(CFLAGS) $(OBJ_LS) -o $(FT_LS) $(INC) $(PF_INC) $(PF_A)
	@echo "$(BLUE)ft_ls:     $(GREEN)ft_ls has been created$(RESET)"


$(OBJ_DIR): 
	@mkdir -p $(OBJ_DIR)
	@gcc $(CFLAGS) -c $(SRC_LS) -o $(OBJ_LS) $(INC) $(PF_INC)

# $(OBJ_DIR)%.o: %.c $(HEADER)
# 	gcc $(CFLAGS) -c $(SRC_LS) -o $(OBJ_LS) $(INC) $(PF_INC)

pf: 
	@echo "$(BLUE)ft_printf: $(GREEN)Compiling $(RESET)"	
	@make -C ./lib/ft_printf/

clean:
	@make -C ./lib/ft_printf clean
	@echo "$(RED_B)ft_ls:     $(RED)object files have been deleted$(RESET)"
	@rm -rf $(OBJ_DIR)

fclean:
	@rm -rf $(OBJ_DIR)
	@rm -rf $(FT_LS)
	@make -C ./lib/ft_printf fclean
	@echo "$(RED_B)ft_ls:    $(RED) ft_ls have been deleted$(RESET)" 

re: fclean all