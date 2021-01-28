/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 19:14:42 by abrabant          #+#    #+#             */
/*   Updated: 2021/01/28 22:38:33 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/core.h"
#include "libft/vector.h"
#include "libft/internal/vector_int.h"


t_vector	ft_vec_new(size_t cap, float growth_factor)
{
	t_vector_int	*vec;

	if (cap == 0)
		cap = VECTOR_DEFAULT_CAP;
	if ((size_t)((float)cap * growth_factor) <= cap)
		growth_factor = VECTOR_DEFAULT_GROWTH_FACTOR;
	vec = malloc(sizeof (*vec));
	if (vec == NULL)
		return (NULL);
	vec->items = (void **)ft_calloc(cap, sizeof (void *));
	if (vec->items == NULL)
		return (NULL);
	vec->cap = cap;
	vec->gfac = growth_factor;
	vec->len = 0;
	return ((t_vector)vec);
}
