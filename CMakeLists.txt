cmake_minimum_required(VERSION 3.17)
project(fractol_unix C)

set(CMAKE_C_STANDARD 99)
include_directories(minilibx)
include_directories(includes)
include_directories(libft)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -lX11 -lXext -pthread -lm")

add_executable(fractol_unix main.c includes/fractol.h srcs/keyboard.c
        includes/keyboard.h
        srcs/put_usage.c
        srcs/reader.c
        srcs/cleaner.c
        srcs/algebraic_init.c
        srcs/complex_math.c
        libft/ft_fabs.c
        srcs/move.c
        srcs/fractols_koch.c
        libft/ft_min.c
        libft/ft_max.c
        includes/graphics_base.h
        srcs/draw_line.c
        srcs/geometric_init.c
        srcs/mlx_create.c
        srcs/fractol_init.c
        srcs/color_g.c
        srcs/help.c
        srcs/fractols_main.c
        srcs/put_images.c
        srcs/zoom.c
        srcs/color_a.c
        srcs/thread_draw.c
        includes/colors.h
        srcs/point_handler.c
        srcs/type_change.c
        srcs/fractols_buddha.c
        srcs/complex_trig.c
        srcs/constructor.c
        srcs/fractols_al.c
        srcs/fractols_tree.c
        srcs/mlx_color.c
        srcs/fractols_pifagor.c
        srcs/fractols_rt.c)
target_link_libraries(fractol_unix
        ~/CLionProjects/fractol_unix/minilibx/libmlx.a
        ~/CLionProjects/fractol_unix/libft/libft.a)
