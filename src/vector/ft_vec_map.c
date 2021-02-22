/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 19:59:32 by abrabant          #+#    #+#             */
/*   Updated: 2021/02/16 21:45:44 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/vector.h"
#include "libft/internal/vector_int.h"

void	ft_vec_map(t_vector vector,
		void (*func)(void **, size_t index, void *), void *data)
{
	t_vector_int	*vec;
	size_t			index;

	vec = (t_vector_int *)vector;
	index = 0;
	while (index < vec->len)
	{
		func(&vec->items[index], index, data);
		++index;
	}
}