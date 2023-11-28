# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jalbiser <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/25 14:50:01 by jalbiser          #+#    #+#              #
#    Updated: 2023/11/25 14:50:05 by jalbiser         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = 				libftprintf.a
CC = 				gcc
CFLAGS = 			-Wall -Wextra -Werror

LIBFT_DIR = 		libft
PRINTF_SRC_DIR = 	src
MAKE_LIBFT =		@make -C $(LIBFT_DIR)

SRC_PRINTF = 		ft_flags.c\
					ft_printchar.c\
					ft_printf.c\
					ft_printhexadecimal.c\
					ft_printint.c\
					ft_printptr.c\
					ft_printstr.c\
					ft_printunsigned.c

OBJ_PRINTF =		$(addprefix $(PRINTF_SRC_DIR)/, $(SRC_PRINTF:.c=.o))


all: 				$(NAME)

$(NAME): 			$(OBJ_PRINTF)
					$(MAKE_LIBFT) all
					ar crs $@ $(LIBFT_DIR)/libft.a $^

clean:
					rm -f $(PRINTF_SRC_DIR)/*.o
					$(MAKE_LIBFT) clean

fclean: 			clean
					rm -f $(NAME)
					$(MAKE_LIBFT) fclean

re: 				fclean all
					$(MAKE_LIBFT) re

.PHONY: 			all clean fclean re