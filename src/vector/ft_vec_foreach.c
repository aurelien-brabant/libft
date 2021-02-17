/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_foreach.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 20:57:11 by abrabant          #+#    #+#             */
/*   Updated: 2021/02/17 01:26:56 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/internal/vector_int.h"
#include "libft/vector.h"

int		ft_vec_foreach(t_vector vector,
		int (*func)(void *, size_t, void *), void *data)
{
	t_vector_int	*vec;
	size_t			i;
	int				ret;

	vec = (t_vector_int *)vector;
	i = 0;
	while (i < vec->len)
	{
		ret = func(vec->items[i], i, data);
		if (ret != 0)
			return (ret);
		++i;
	}
	return (0);
}
