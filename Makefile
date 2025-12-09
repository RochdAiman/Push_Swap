NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes -Ilibft

SRCDIR = srcs
SOURCES = $(wildcard $(SRCDIR)/*.c) \
          $(wildcard $(SRCDIR)/*/*.c) \
          $(wildcard $(SRCDIR)/*/*/*.c)
OBJECTS = $(SOURCES:. c=.o)

# Debug - add these lines temporarily
$(info SOURCES: $(SOURCES))
$(info OBJECTS: $(OBJECTS))

# Libft
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(OBJECTS) $(LIBFT)
	$(CC) $(OBJECTS) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

. PHONY: all clean fclean re