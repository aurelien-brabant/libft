/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_foreach.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 20:57:11 by abrabant          #+#    #+#             */
/*   Updated: 2021/01/28 22:24:05 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/internal/vector_int.h"
#include "libft/vector.h"

void	ft_vec_foreach(t_vector vector, void (*func)(void *))
{
	t_vector_int	*vec;
	size_t	i;

	vec = (t_vector_int *)vector;
	i = 0;
	while (i < vec->len)
		func(vec->items[i++]);
}
