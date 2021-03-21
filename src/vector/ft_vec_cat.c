/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_cat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 11:09:55 by abrabant          #+#    #+#             */
/*   Updated: 2021/02/04 22:16:02 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/cstring.h"
#include "libft/vector.h"
#include "libft/internal/vector_int.h"

static float	max_gfac(float fac1, float fac2)
{
	if (fac1 >= fac2)
		return (fac1);
	return (fac2);
}

t_vector	ft_vec_cat(t_vector vector1, t_vector vector2)
{
	t_vector_int	*vec1;
	t_vector_int	*vec2;
	t_vector_int	*new_vec;
	float			new_gfac;
	void			**items;

	vec1 = (t_vector_int *) vector1;
	vec2 = (t_vector_int *) vector2;
	new_gfac = max_gfac(vec1->gfac, vec2->gfac);
	new_vec = ft_vec_new((size_t)((float)(vec1->len + vec2->len) *new_gfac),
			new_gfac);
	if (!new_vec)
		return (NULL);
	items = new_vec->items;
	ft_memcpy(items, vec1->items, sizeof (void *) * vec1->len);
	items += vec1->len;
	new_vec->len += vec1->len;
	ft_memcpy(items, vec2->items, sizeof (void *) * vec2->len);
	new_vec->len += vec2->len;
	return (new_vec);
}
