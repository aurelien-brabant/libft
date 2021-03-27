/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_insert.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 15:13:39 by abrabant          #+#    #+#             */
/*   Updated: 2021/03/27 15:10:13 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft/cstring.h"
#include "libft/internal/array_int.h"

void	ft_array_insert(t_array_int *a, void *el, size_t index)
{
	size_t	i;

	if (a->length == a->capacity)
		ft_array_int_resize(a);
	i = a->length;
	while (i > index)
	{
		a->array[i] = a->array[i - 1];
		--i;
	}
	a->array[index] = el;
	++a->length;
}
