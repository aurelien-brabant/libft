/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_dup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 18:23:16 by abrabant          #+#    #+#             */
/*   Updated: 2021/04/13 16:19:19 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft/cstring.h"
#include "libft/array.h"
#include "libft/internal/array_int.h"

t_array	ft_array_dup(t_array a)
{
	t_array_int	*new;

	new = (t_array_int *)ft_array_new(((t_array_int *)a)->capacity);
	if (new == NULL)
	{
		return (NULL);
	}
	new->length = ((t_array_int *)a)->length;
	ft_memcpy(new->array, ((t_array_int *)a)->array,
		sizeof(*new->array) * new->length);
	return (new);
}
