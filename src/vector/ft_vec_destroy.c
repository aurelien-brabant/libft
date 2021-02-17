/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_destroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 23:21:05 by abrabant          #+#    #+#             */
/*   Updated: 2021/02/17 02:03:49 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft/internal/vector_int.h"
#include "libft/vector.h"

void	ft_vec_destroy(t_vector vector,  void (*cleanup)(void *))
{
	size_t			i;
	t_vector_int	*vec;

	vec = (t_vector_int *)vector;
	if (cleanup)
	{
		i = 0;
		while (i < vec->len)
			cleanup(vec->items[i++]);
	}
	free(vec->items);
	free(vec);
}
