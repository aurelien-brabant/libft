/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_inter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 01:00:20 by abrabant          #+#    #+#             */
/*   Updated: 2021/03/23 01:06:28 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/internal/array_int.h"
#include "libft/array.h"

t_array	ft_array_inter(t_array a1, t_array a2, int (*cmp)(void *, void *))
{
	t_array_int	*new;
	int			i;

	new = (t_array_int *)ft_array_new(((t_array_int *)a1)->size);
	if (new == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (i < ((t_array_int *)a1)->length)
	{
		if (ft_array_linsearch(a2, ((t_array_int *)a1)->array[i], cmp) != -1)
		{
			((t_array_int *)new)->array[new->length++]
				= ((t_array_int *)a1)->array[i];
		}
		++i;
	}
	return (new);

}
