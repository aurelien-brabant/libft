/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 15:19:49 by abrabant          #+#    #+#             */
/*   Updated: 2021/03/27 14:32:54 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/internal/array_int.h"

static void	rotate_one_left(t_array_int *a)
{
	int		i;
	int		high;
	void	*rotated;

	i = 0;
	rotated = a->array[i];
	high = a->length - 1;
	while (i < high)
	{
		a->array[i] = a->array[i + 1];
		++i;
	}
	a->array[i] = rotated;
}

static void	rotate_one_right(t_array_int *a)
{
	int		i;
	void	*rotated;

	i = a->length - 1;
	rotated = a->array[i];
	while (i > 0)
	{
		a->array[i] = a->array[i - 1];
		--i;
	}
	a->array[i] = rotated;
}

void	ft_array_rotate(t_array_int *a, char rotatedir, size_t offset)
{
	while (offset > 0)
	{
		if (rotatedir == -1)
			rotate_one_left(a);
		if (rotatedir == 1)
			rotate_one_right(a);
		--offset;
	}
}
