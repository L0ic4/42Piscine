NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS_DIR = srcs
INCLUDES_DIR = includes

SRCS = ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c
OBJS = $(addprefix $(SRCS_DIR)/, $(SRCS:.c=.o))
INCLUDES = $(INCLUDES_DIR)/ft.h


$(SRCS_DIR)/%.o: $(SRCS_DIR)/%.c $(INCLUDES)
	$(CC) $(CFLAGS) -I $(INCLUDES_DIR) -o $@ -c $<

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)	

all: $(NAME)

clean :
		rm -f ${OBJS}

fclean : clean
		rm -f ${NAME}

re : fclean all
