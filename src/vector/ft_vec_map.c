#include "libft/vector.h"
#include "libft/internal/vector_int.h"

void	ft_vec_map(t_vector vector, void (*func)(void **, size_t index))
{
	t_vector_int	*vec;
	size_t			index;

	vec = (t_vector_int *)vector;
	index = 0;
	while (index < vec->len)
	{
		func(&vec->items[index], index);
		++index;
	}
}
