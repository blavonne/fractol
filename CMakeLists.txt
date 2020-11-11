cmake_minimum_required(VERSION 3.17)
project(fractol_unix C)

set(CMAKE_C_STANDARD 99)
include_directories(minilibx)
include_directories(includes)
include_directories(libft)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -lX11 -lXext -pthread -lm -fsanitize=leak")

add_executable(fractol_unix
        includes/fractol.h
        includes/keyboard.h
        includes/graphics_base.h
        includes/colors.h
        main.c
        srcs/algebraic_init.c
        srcs/cleaner.c
        srcs/color_a.c
        srcs/color_g.c
        srcs/complex_math.c
        srcs/complex_trig.c
        srcs/draw_line.c
        srcs/fractol_init.c
        srcs/fractols_ac.c
        srcs/fractols_buddha.c
        srcs/fractols_gr.c
        srcs/fractols_koch.c
        srcs/fractols_main.c
        srcs/fractols_pifagor.c
        srcs/fractols_snow.c
        srcs/fractols_tree.c
        srcs/fractols_tw.c
        srcs/geometric_init.c
        srcs/help_a.c
        srcs/help_g.c
        srcs/keyboard.c
        srcs/mlx_color.c
        srcs/mlx_create.c
        srcs/move.c
        srcs/point_handler.c
        srcs/put_images.c
        srcs/put_usage.c
        srcs/reader.c
        srcs/thread_draw.c
        srcs/type_change.c
        srcs/zoom.c)
target_link_libraries(fractol_unix
        ~/CLionProjects/fractol/minilibx/libmlx.a
        ~/CLionProjects/fractol/libft/libft.a)
