/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 20:37:30 by abrabant          #+#    #+#             */
/*   Updated: 2021/02/04 22:13:33 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/core.h"
#include "libft/vector.h"
#include "libft/internal/vector_int.h"

static bool	resize_vector(t_vector_int *vec)
{
	size_t	new_cap;

	new_cap = (size_t)((float)vec->cap * vec->gfac);
	vec->items = ft_realloc(vec->items, sizeof (void *) * vec->cap,
			sizeof (void *) * new_cap);
	vec->cap = new_cap;
	if (vec->items == NULL)
		return (false);
	return (true);
}

void	*ft_vec_add(t_vector vector, void *element)
{
	t_vector_int	*vec;

	vec = (t_vector_int *)vector;
	if (vec->len == vec->cap)
		if (!resize_vector(vec))
			return (NULL);
	vec->items[vec->len] = element;
	return (vec->items[vec->len++]);
}
