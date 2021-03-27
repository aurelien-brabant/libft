/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_merge.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 19:54:15 by abrabant          #+#    #+#             */
/*   Updated: 2021/03/27 14:32:05 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/array.h"
#include "libft/internal/array_int.h"

static	t_array	get_new_array(t_array a1, t_array a2)
{
	t_array_int	*new;

	new = (t_array_int *)ft_array_new(((t_array_int *)a1)->capacity
			+ ((t_array_int *)a2)->capacity);
	if (new == NULL)
	{
		return (NULL);
	}
	new->length = ((t_array_int *)a1)->length + ((t_array_int *)a2)->length;
	return (new);
}

t_array	ft_array_merge(t_array a1, t_array a2,
		int (*cmp)(void *el1, void *el2))
{
	t_array_int	*new;
	size_t		i;
	size_t		j;
	size_t		k;

	i = 0;
	j = 0;
	k = 0;
	new = get_new_array(a1, a2);
	while (i < ((t_array_int *)a1)->length && j < ((t_array_int *)a2)->length)
	{
		if (cmp(((t_array_int *)a1)->array[i],
				((t_array_int *)a2)->array[j]) > 0)
			new->array[k++] = ((t_array_int *)a2)->array[j++];
		else
			new->array[k++] = ((t_array_int *)a1)->array[i++];
	}
	while (i < ((t_array_int *)a1)->length)
		new->array[k++] = ((t_array_int *)a1)->array[i++];
	while (j < ((t_array_int *)a2)->length)
		new->array[k++] = ((t_array_int *)a2)->array[j++];
	return (new);
}
