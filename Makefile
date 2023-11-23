NAME = libftprintf.a

SRC_DIR = srcs
LIBFT_DIR = libft
INCLUDES_DIR = includes

SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
LIBFT_FILES = $(wildcard $(LIBFT_DIR)/*.c)

OBJ_FILES = $(SRC_FILES:$(SRC_DIR)/%.c=$(SRC_DIR)/%.o) $(LIBFT_FILES:$(LIBFT_DIR)/%.c=$(LIBFT_DIR)/%.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I $(INCLUDES_DIR) -I $(LIBFT_DIR)

all: $(NAME)

$(NAME): $(OBJ_FILES)
	ar rc $@ $^
	ranlib $@

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT_DIR)/%.o: $(LIBFT_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
