/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_get.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 22:27:29 by abrabant          #+#    #+#             */
/*   Updated: 2021/01/28 22:30:00 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/vector.h"
#include "libft/internal/vector_int.h"

void	*ft_vec_get(t_vector vector, size_t index)
{
	t_vector_int	*vec;

	vec = (t_vector_int *)vector;
	if (index < 0 || index >= vec->len)
		return (NULL);
	return (vec->items[index]);
}
