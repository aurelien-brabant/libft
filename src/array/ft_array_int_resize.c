/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_int_resize.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 12:58:53 by abrabant          #+#    #+#             */
/*   Updated: 2021/03/21 13:05:00 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft/internal/array_int.h"

#include "libft/cstring.h"

void	ft_array_int_resize(t_array_int *a)
{
	void	**new_arr;

	new_arr = malloc(sizeof(*a->array) * a->size * 2);
	ft_memcpy(new_arr, a->array, a->size * sizeof(*a->array));
	free(a->array);
	a->size *= 2;
	a->array = new_arr;
}
