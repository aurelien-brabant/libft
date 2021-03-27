/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_linsearch.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 17:08:27 by abrabant          #+#    #+#             */
/*   Updated: 2021/03/27 13:17:33 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/internal/array_int.h"

int	ft_array_linsearch(t_array_int *a, void *ref, int cmp(void *ref, void *el))
{
	size_t	i;
	void	*tmp;

	i = 0;
	while (i < a->length)
	{
		if (cmp(ref, a->array[i]) == 0)
		{
			if (i > 0)
			{
				tmp = a->array[i];
				a->array[i] = a->array[i - 1];
				a->array[i - 1] = tmp;
			}
			return (i);
		}
		++i;
	}
	return (-1);
}
