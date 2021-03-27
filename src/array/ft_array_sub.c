/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_sub.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 11:54:47 by abrabant          #+#    #+#             */
/*   Updated: 2021/03/27 14:34:22 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/internal/array_int.h"
#include "libft/array.h"

t_array	ft_array_sub(t_array a1, t_array a2, int (*cmp)(void *, void *))
{
	t_array_int	*new;
	size_t		i;

	new = (t_array_int *)ft_array_new(((t_array_int *)a1)->capacity);
	if (new == NULL)
		return (NULL);
	i = 0;
	while (i < ((t_array_int *)a1)->length)
	{
		if (ft_array_linsearch(a2, ((t_array_int *)a1)->array[i], cmp) == -1)
			new->array[new->length++] = ((t_array_int *)a1)->array[i];
		++i;
	}
	return (new);
}
