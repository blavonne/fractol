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

# define BLUE				98 //b
# define RED				114 //r
# define GREEN				103 //g
# define ALPHA				116 //t
# define HELP				105 //i
# define PAUSE				112 //p

# define ONE				49
# define TWO				50
# define THREE				51
# define FOUR				52
# define FIVE				53
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

# define BLUE				11 //b
# define RED				15 //r
# define GREEN				5 //g
# define ALPHA				17 //t
# define HELP				34 //i

# define ONE				18
# define TWO				19
# define THREE				20
# endif
#endif
