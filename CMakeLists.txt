cmake_minimum_required(VERSION 3.17)
project(fractol_unix C)

set(CMAKE_C_STANDARD 99)
include_directories(minilibx)
include_directories(includes)
include_directories(libft)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -lX11 -lXext -pthread -lm")

add_executable(fractol_unix main.c includes/fractol.h srcs/keyboard.c includes/keyboard.h srcs/errors_usage.c srcs/reader.c srcs/cleaner.c srcs/algebraic_init.c srcs/complex.c libft/ft_fabs.c srcs/move.c srcs/koch.c libft/ft_min.c libft/ft_max.c includes/graphics_base.h srcs/draw_line.c srcs/geometric_init.c srcs/mlx_create.c srcs/fractol_init.c srcs/color_g.c srcs/help.c srcs/fractols.c srcs/point_init.c srcs/put_img_and_background.c srcs/zoom.c srcs/color_a.c srcs/thread_draw.c includes/colors.h srcs/buddah.c includes/vector.h)
target_link_libraries(fractol_unix
        ~/CLionProjects/fractol_unix/minilibx/libmlx.a
        ~/CLionProjects/fractol_unix/libft/libft.a)
