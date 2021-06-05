/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_new.c                                     :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 13:23:09 by abrabant          #+#    #+#             */
/*   Updated: 2021/03/27 14:32:36 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft/internal/vector_int.h"

t_vector_int	*ft_vector_new(size_t capacity)
{
	t_vector_int	*new;

	new = malloc(sizeof(*new));
	if (new == NULL)
		return (NULL);
	new->vector = malloc(sizeof(*new->vector) * capacity);
	if (new->vector == NULL)
	{
		free(new);
		return (NULL);
	}
	new->length = 0;
	new->capacity = capacity;
	return (new);
}
