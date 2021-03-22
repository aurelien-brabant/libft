/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_shift.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 14:09:41 by abrabant          #+#    #+#             */
/*   Updated: 2021/03/22 15:10:15 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/internal/array_int.h"

static void	left_shift(t_array_int *a, int offset)
{
	int	i;

	i = offset;
	while (i < a->length)
	{
		a->array[i - offset] = a->array[i];
		++i;
	}
	i -= offset;
	while (i < a->length)
	{
		a->array[i++] = 0;
	}
}

static void	right_shift(t_array_int *a, int offset)
{
	int	i;

	i = a->length - 1;
	while (i >= offset)
	{
		a->array[i] = a->array[i - offset];
		--i;
	}
	while (i >= 0)
	{
		a->array[i--] = 0;
	}
}

void	ft_array_shift(t_array_int *a, char shiftdir, int offset)
{
	if (shiftdir == -1)
	{
		left_shift(a, offset);
	}
	else if (shiftdir == 1)
	{
		right_shift(a, offset);
	}
}
