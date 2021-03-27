/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_pop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 17:06:39 by abrabant          #+#    #+#             */
/*   Updated: 2021/03/27 14:55:54 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/array.h"
#include "libft/internal/stack_int.h"

void	*ft_stack_pop(t_stack_int *stack)
{
	int		arr_length;
	void	*el;

	arr_length = ft_array_length(stack->data);
	if (arr_length == 0)
		return (NULL);
	el = ft_array_get(stack->data, arr_length - 1);
	ft_array_delete(stack->data, arr_length - 1, NULL);
	return (el);
}
