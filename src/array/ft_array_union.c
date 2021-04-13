/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_union.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 21:57:12 by abrabant          #+#    #+#             */
/*   Updated: 2021/04/13 16:19:47 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/array.h"
#include "libft/internal/array_int.h"
#include "libft/cstring.h"

t_array	ft_array_union(t_array a1, t_array a2, int (*cmp)(void *, void *))
{
	t_array_int	*new;
	size_t		i;

	new = (t_array_int *)ft_array_new(((t_array_int *)a1)->capacity
			+ ((t_array_int *)a2)->capacity);
	if (new == NULL)
		return (NULL);
	ft_memcpy(new->array, ((t_array_int *)a1)->array,
		sizeof(*new->array) * ((t_array_int *)a1)->length);
	new->length = ((t_array_int *)a1)->length;
	i = 0;
	while (i < ((t_array_int *)a2)->length)
	{
		if (ft_array_linsearch(a1, ((t_array_int *)a2)->array[i], cmp) == -1)
		{
			((t_array_int *)new)->array[new->length++]
				= ((t_array_int *)a2)->array[i];
		}
		++i;
	}
	return (new);
}
