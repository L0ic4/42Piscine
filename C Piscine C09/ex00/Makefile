NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS_DIR = srcs
OBJS_DIR = objs
INCLUDES_DIR = includes

SRCS = ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c
OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))
INCLUDES = $(INCLUDES_DIR)/ft.h

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "$(NAME) created successfully!"

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(INCLUDES)
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) -I$(INCLUDES_DIR) -o $@ -c $<
	@echo "Compiled $<"

clean:
	@rm -rf $(OBJS_DIR)
	@echo "Cleaned up object files"

fclean: clean
	@rm -f $(NAME)
	@echo "Cleaned up $(NAME)"

re: fclean all

.PHONY: all clean fclean re
