#ifndef KEYBOARD_H
# define KEYBOARD_H
# ifdef __linux__
# define ESC				65307
# define MOUSE_SCROLL_UP	5
# define MOUSE_SCROLL_DOWN	4
# define ARROW_UP			65362
# define ARROW_DOWN			65364
# define ARROW_LEFT			65361
# define ARROW_RIGHT		65363
# define SPACE				32

# define NUM_PLUS			65451
# define NUM_MINUS			65453

# define MAIN_PLUS			61
# define MAIN_MINUS			45

# define MAIN_B				98 //b
# define MAIN_R				114 //r
# define MAIN_G				103 //g
# define MAIN_T				116 //t
# define MAIN_I				105 //i
# define MAIN_P				112 //p
# define MAIN_C				99 //c

# define ONE				49
# define TWO				50
# define THREE				51
# define FOUR				52
# define FIVE				53
# define SIX				54
# define SEVEN				55
# define EIGHT				56
# define NINE				57
# define NUM_ONE			65436
# define NUM_EIGHT			65431
# define NUM_NINE			65434

# else
# define ESC				53
# define MOUSE_SCROLL_UP	4
# define MOUSE_SCROLL_DOWN	5
# define ARROW_UP			126
# define ARROW_DOWN			125
# define ARROW_LEFT			123
# define ARROW_RIGHT		124
# define SPACE				49

# define NUM_PLUS		69
# define NUM_MINUS		78

# define MAIN_PAD_C			8
# define MAIN_PAD_H			4
# define MAIN_PLUS		24
# define MAIN_MINUS		27

# define MAIN_B				11 //b
# define MAIN_R				15 //r
# define MAIN_G				5 //g
# define MAIN_T				17 //t
# define MAIN_I				34 //i

# define ONE				18
# define TWO				19
# define THREE				20

# endif
#endif
