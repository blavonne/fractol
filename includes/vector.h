//#ifndef ECTOR_H
//# define VECTOR_H
//# include <stdlib.h>
//
//typedef struct		s_vector
//{
//	void	*data;
//	size_t	current;
//	size_t	size;
//}					t_vector;
//
//
//void	push_in_vector(t_vector *vector, void *data, size_t size)
//{
//	char		*dest;
//	char		*src;
//	size_t		new_max;
//	size_t		i;
//
//	i = 0;
//	if (vector->current + size > vector->size)
//		resize_vector(vector);
//	dest = vector->data;
//	src = data;
//	new_max = vector->current + size;
//	while (vector->current < new_max)
//		dest[vector->current++] = src[i++];
//}
//
//void
//
//#endif
