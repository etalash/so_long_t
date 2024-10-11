# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address

# Executable name
NAME = so_long

# Directories
SRC_DIR = src
MLX_DIR = lib/minilibx-linux
LIBFT_DIR = lib/libft

# Sources and Objects
SRCS = $(SRC_DIR)/main.c $(SRC_DIR)/check.c $(SRC_DIR)/draw.c \
       $(SRC_DIR)/errors.c $(SRC_DIR)/frees.c $(SRC_DIR)/ft_strjoinfree.c \
       $(SRC_DIR)/key_hook.c $(SRC_DIR)/map_validity.c $(SRC_DIR)/window.c \
       $(SRC_DIR)/xpms_into_image.c
OBJ = $(SRCS:.c=.o)

# Libraries
MLX_LIB = $(MLX_DIR)/libmlx.a
MLX_HEADER = $(MLX_DIR)
LIBFT = $(LIBFT_DIR)/libft.a

# Linking flags (for X11, pthread, and math library)
LDFLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lbsd -I$(MLX_HEADER)

# Default target
all: $(NAME)

# Build rule for object files
$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -I $(MLX_HEADER) -c $< -o $@

# Build rule for the executable
$(NAME): $(OBJ) $(LIBFT) $(MLX_LIB)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(LDFLAGS) -o $(NAME)

# Build libft if necessary
$(LIBFT):
	make -C $(LIBFT_DIR)

# Build the minilibx-linux library
$(MLX_LIB):
	git clone git@github.com:42Paris/minilibx-linux.git $(MLX_DIR)
	make -C $(MLX_DIR)

# Clean object files and minilibx-linux
clean:
	rm -f $(OBJ)
	make clean -C $(LIBFT_DIR)
	make clean -C $(MLX_DIR)

# Full cleanup (objects and executable)
fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re
