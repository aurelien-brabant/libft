/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_binsearch.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 19:43:40 by abrabant          #+#    #+#             */
/*   Updated: 2021/03/21 19:55:33 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/internal/array_int.h"

int	ft_array_binsearch(t_array_int *a, void *ref, int cmp(void *ref, void *el))
{
	int	high;
	int	low;
	int	mid;
	int	ret;

	low = 0;
	high = a->length - 1;
	while (low <= high)
	{
		mid = (low + high) / 2;
		ret = cmp(ref, a->array[mid]);
		if (ret == 0)
		{
			return (mid);
		}
		if (ret > 0)
		{
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
	}
	return (-1);
}
