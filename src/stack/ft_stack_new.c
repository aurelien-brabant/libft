/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 16:23:40 by abrabant          #+#    #+#             */
/*   Updated: 2021/03/26 16:47:56 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft/internal/stack_int.h"

t_stack_int	*ft_stack_new(size_t size)
{
	t_stack_int	*stack;

	stack = malloc(sizeof (*stack));
	if (stack == NULL)
		return (NULL);
	stack->data = ft_array_new(size);
	if (stack->data == NULL)
	{
		free(stack);
		return (NULL);
	}
	stack->top = -1;
	return (stack);
}
