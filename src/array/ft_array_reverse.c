/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_reverse.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 13:47:31 by abrabant          #+#    #+#             */
/*   Updated: 2021/03/22 13:50:44 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/internal/array_int.h"

void	ft_array_reverse(t_array_int *a)
{
	int		i;
	int		j;
	void	*tmp;

	i = 0;
	j = a->length - 1;
	while (i < j)
	{
		tmp = a->array[i];
		a->array[i++] = a->array[j];
		a->array[j--] = tmp;
	}
}
