/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_destroy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 14:54:20 by abrabant          #+#    #+#             */
/*   Updated: 2021/03/31 02:05:10 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/internal/array_int.h"

void	ft_array_destroy(t_array_int *a, void (*fn)(void *el))
{
	size_t	i;

	if (a == NULL)
		return ;
	i = 0;
	if (fn != NULL)
	{
		while (i < a->length)
			fn(a->array[i++]);
	}
	free(a->array);
	free(a);
}
