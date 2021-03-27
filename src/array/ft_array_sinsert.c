/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_sinsert.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 17:19:28 by abrabant          #+#    #+#             */
/*   Updated: 2021/03/27 14:34:00 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/internal/array_int.h"

void	ft_array_sinsert(t_array_int *a, void *el,
		int (*cmp)(void *el, void *el2))
{
	int	i;

	if (a->length == a->capacity)
	{
		ft_array_int_resize(a);
	}
	i = a->length;
	while (i > 0 && cmp(el, a->array[i - 1]) < 0)
	{
		a->array[i] = a->array[i - 1];
		--i;
	}
	a->array[i] = el;
	++a->length;
}
