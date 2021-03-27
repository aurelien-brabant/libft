/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_delete.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 15:55:15 by abrabant          #+#    #+#             */
/*   Updated: 2021/03/27 15:11:05 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/internal/array_int.h"

void	ft_array_delete(t_array_int *a, size_t index, void (*fn)(void *el))
{
	size_t	i;

	i = a->length - 1;
	if (fn != NULL)
		fn(a->array[index]);
	while (index < i)
	{
		a->array[index] = a->array[index + 1];
		++index;
	}
	--a->length;
}
