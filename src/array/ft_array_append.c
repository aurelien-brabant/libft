/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_append.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 13:17:38 by abrabant          #+#    #+#             */
/*   Updated: 2021/03/21 18:00:13 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft/internal/array_int.h"
#include "libft/cstring.h"

void	ft_array_append(t_array_int *a, void *el)
{
	if (a->length == a->size)
	{
		ft_array_int_resize(a);
	}
	a->array[a->length++] = el;
}
