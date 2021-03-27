/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_foreach.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 14:36:53 by abrabant          #+#    #+#             */
/*   Updated: 2021/03/27 13:16:55 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/internal/array_int.h"

int	ft_array_foreach(t_array_int *a, int (*fn)(), void *data)
{
	size_t	i;
	size_t	ret;

	i = 0;
	while (i < a->length)
	{
		ret = fn(a->array[i], i, data);
		if (ret != 0)
			return (ret);
		++i;
	}
	return (0);
}
