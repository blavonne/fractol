NAME = fractol
#-------------------------------------------------------------------------------
SRC_DIR = ./srcs/
INC_DIR = ./includes/
#-------------------------------------------------------------------------------
LIBFT = ./libft/libft.a
L_ROOT = ./libft/
L_LIB = -L $(L_ROOT) -lft
#-------------------------------------------------------------------------------
MLX = ./minilibx/libmlx.a
MLX_ROOT = ./minilibx/
MLX_LIB = -L $(MLX_ROOT) -lmlx
#-------------------------------------------------------------------------------
SRC = main.c\
	$(SRC_DIR)keyboard.c\
	$(SRC_DIR)errors_usage.c\
	$(SRC_DIR)reader.c\
	$(SRC_DIR)cleaner.c\
	$(SRC_DIR)algebraic_init.c\
	$(SRC_DIR)complex.c\
	$(SRC_DIR)move.c\
	$(SRC_DIR)koch.c\
	$(SRC_DIR)draw_line.c\
	$(SRC_DIR)geometric_init.c\
	$(SRC_DIR)mlx_create.c\
	$(SRC_DIR)fractol_init.c\
	$(SRC_DIR)change_color.c\
	$(SRC_DIR)help.c\
	$(SRC_DIR)fractols.c\
	$(SRC_DIR)point_init.c\
	$(SRC_DIR)put_img_and_background.c\
	$(SRC_DIR)zoom.c\
	$(SRC_DIR)color.c\
	$(SRC_DIR)thread_draw.c\
OBJ = $(SRC:%.c=%.o)
# flags-------------------------------------------------------------------------
FLAGS = -Wall -Werror -Wextra
I_FLAGS = -I $(INC_DIR) -I $(MLX_ROOT) -I $(L_ROOT)
# libs--------------------------------------------------------------------------
LIBS = -lX11 -lXext -pthread -lm
#-------------------------------------------------------------------------------
# builder-----------------------------------------------------------------------
#-------------------------------------------------------------------------------
all: $(LIBFT) $(MLX) $(NAME)
# build external libraries------------------------------------------------------
$(LIBFT):
	$(MAKE) -C $(L_ROOT)
$(MLX):
	$(MAKE) -C $(MLX)

# build checker-----------------------------------------------------------------
$(NAME): $(LIBFT) $(MLX) $(OBJ)
	gcc $(OBJ) -o $(NAME) $(I_FLAGS) $(FLAGS) $(L_LIB) $(MLX_LIB) $(LIBS)
%.o: %.c $(INC_DIR)fractol.h $(INC_DIR)keyboard.h $(INC_DIR)graphics_base.h
	gcc -c $< -o $@ $(I_FLAGS) $(FLAGS)

# clean section-----------------------------------------------------------------
clean:
	$(MAKE) -C $(L_ROOT) clean
	$(MAKE) -C $(MLX_ROOT) clean
	rm -rf $(OBJ)
fclean: clean
	$(MAKE) -C $(L_ROOT) fclean
	$(MAKE) -C $(MLX_ROOT) fclean
	rm -rf $(NAME)
re: fclean all

.PHONY: all clean fclean re