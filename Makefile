# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jalbiser <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/25 14:50:01 by jalbiser          #+#    #+#              #
#    Updated: 2023/12/01 05:22:45 by jalbiser         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = 				libftprintf.a
CC = 				gcc
CFLAGS = 			-Wall -Wextra -Werror
MAKEFLAGS +=		--silent
PRINTF_SRC_DIR = 	srcs

SRC_PRINTF = 		ft_printf.c\

OBJ_PRINTF =		$(addprefix $(PRINTF_SRC_DIR)/, $(SRC_PRINTF:.c=.o))


all: 				$(NAME)

$(NAME): 			$(OBJ_PRINTF)
					@echo "\n🕒 Compilation en cours de $(NAME)...\n"
					ar rcs $(NAME) $(OBJ_PRINTF)
					@echo "\n✅ \033[0;32mCompilation de $(NAME) effectué\033[0m\n"

clean:
					rm -f $(PRINTF_SRC_DIR)/*.o

fclean: 			clean
					rm -f $(NAME)

re: 				fclean all

.PHONY: 			all clean fclean re
