/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 13:23:09 by abrabant          #+#    #+#             */
/*   Updated: 2021/03/27 14:32:36 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft/internal/array_int.h"

t_array_int	*ft_array_new(size_t capacity)
{
	t_array_int	*new;

	new = malloc(sizeof(*new));
	if (new == NULL)
		return (NULL);
	new->array = malloc(sizeof(*new->array) * capacity);
	if (new->array == NULL)
	{
		free(new);
		return (NULL);
	}
	new->length = 0;
	new->capacity = capacity;
	return (new);
}
