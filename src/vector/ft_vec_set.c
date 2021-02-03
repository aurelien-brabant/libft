#include "libft/vector.h"
#include "libft/internal/vector_int.h"

void	ft_vec_set(t_vector vector, size_t index, void *elem)
{
	((t_vector_int *)vector)->items[index] = elem;
}
