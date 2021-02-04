/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_del.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 23:41:45 by abrabant          #+#    #+#             */
/*   Updated: 2021/01/28 23:49:00 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/vector.h"
#include "libft/internal/vector_int.h"

int	ft_vec_del(t_vector vector, size_t index, void (*cleanup)(void *))
{
	t_vector_int	*vec;
	size_t			it;

	vec = (t_vector_int *)vector;
	if (index < 0 && index >= vec->len)
		return (-1);
	if (cleanup)
		cleanup(vec->items[index]);
	it = index;
	while (it < vec->len - 1)
	{
		vec->items[it] = vec->items[it + 1];
		++it;
	}
	--vec->len;
	return (index);
}
