NAME = fractol

# Compiler
CC := gcc

# Compiler flags
CFLAGS := -Wall -Wextra -Werror -g

# Linker flags
#LDFLAGS := -lglfw -framework Cocoa -framework OpenGL -framework IOKit -LMLX42/build -lmlx42
LDFLAGS := -lglfw -framework Cocoa -framework OpenGL -framework IOKit -L/Users/aantonie/Desktop/projects/P06.fractol/mlx_practice/MLX42/build -lmlx42

# Directories
SRC_DIR 	:= src
INC_DIR 	:= include
LIB_DIR 	:= MLX42
LIBFT_DIR 	:= libft

# Source and header files
SRCS 	:= calculate_mandelbrot.c draw_fractal.c main.c calculate_julia.c init_fractol.c mouse.c
OBJS 	:= $(SRCS:.c=.o)
HEADERS := -I $(INC_DIR) -I $(LIB_DIR)/include -I $(LIBFT_DIR)/include

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

# Library
LIBMLX 	:= $(LIB_DIR)/build/libmlx42.a
LIBFT 	:= $(LIBFT_DIR)/libft.a

# Executable name
TARGET := fractol

# Default target
all: $(TARGET)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(TARGET): $(LIBFT) $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(TARGET)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re