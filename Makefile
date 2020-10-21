NAME = fractol
SRC_DIR = ./srcs/
SRCS = main.c\
		keyboard.c\
		$(SRC_DIR)check.c\
		$(SRC_DIR)cleaner.c\
		$(SRC_DIR)errors_usage.c\
		$(SRC_DIR)fractol_init.c\
		$(SRC_DIR)mandelbrot.c\
		reader.c
OBJ = $(SRCS:%.c=%.o)
MLX_DIR = ./minilibx/
MLX = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
LIBFT_DIR = ./libft/
LIBFT = -L$(LIBFT_DIR) -lft
FLAGS = -Wall -Werror -Wextra
INC = ./includes/
I_FLAGS = -I $(INC) -I $(MLX_DIR) -I $(LIBFT_DIR)
all: $(NAME)

$(NAME): $(OBJ)
	gcc $(OBJ) -o $(NAME) $(FLAGS) $(I_FLAGS) $(MLX) $(LIBFT)
%.o: %.c $(INC)fractol.h $(INC)keyboard.h
	gcc -c $< -o $@ $(I_FLAGS) $(FLAGS)
clean:
	rm -rf $(OBJ)
