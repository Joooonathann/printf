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
MAKE_LIBFT =		@make -C $(LIBFT_DIR)/

SRC_LIBFT = 		ft_atoi.c\
					ft_isascii.c\
					ft_lstadd_front_bonus.c\
					ft_lstmap_bonus.c\
					ft_memcpy.c\
					ft_putnbr_fd.c\
					ft_striteri.c\
					ft_strmapi.c\
					ft_substr.c\
					ft_bzero.c\
					ft_isdigit.c\
					ft_lstclear_bonus.c\
					ft_lstnew_bonus.c\
					ft_memmove.c\
					ft_putstr_fd.c\
					ft_strjoin.c\
					ft_strncmp.c\
					ft_tolower.c\
					ft_calloc.c\
					ft_isprint.c\
					ft_lstdelone_bonus.c\
					ft_lstsize_bonus.c\
					ft_memset.c\
					ft_split.c\
					ft_strlcat.c\
					ft_strnstr.c\
					ft_toupper.c\
					ft_isalnum.c\
					ft_itoa.c\
					ft_lstiter_bonus.c\
					ft_memchr.c\
					ft_putchar_fd.c\
					ft_strchr.c\
					ft_strlcpy.c\
					ft_strrchr.c\
					ft_isalpha.c\
					ft_lstadd_back_bonus.c\
					ft_lstlast_bonus.c\
					ft_memcmp.c\
					ft_putendl_fd.c\
					ft_strdup.c\
					ft_strlen.c\
					ft_strtrim.c

SRC_PRINTF = 		ft_flags.c\
					ft_printchar.c\
					ft_printf.c\
					ft_printhexadecimal.c\
					ft_printint.c\
					ft_printptr.c\
					ft_printstr.c\
					ft_printunsigned.c

OBJ_LIBFT = 		$(addprefix $(LIBFT_DIR)/, $(SRC_LIBFT:.c=.o))
OBJ_PRINTF =		$(addprefix $(PRINTF_SRC_DIR)/, $(SRC_PRINTF:.c=.o))


all: 				$(NAME)

$(NAME): 			$(OBJ_LIBFT) $(OBJ_PRINTF)
					ar crs $@ $^

clean:
					rm -f $(PRINTF_SRC_DIR)/*.o
					$(MAKE_LIBFT) clean

fclean: 			clean
					rm -f $(NAME)
					$(MAKE_LIBFT) fclean

re: 				fclean all
					$(MAKE_LIBFT) re

.PHONY: 			all clean fclean re
