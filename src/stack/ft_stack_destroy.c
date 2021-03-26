/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_destroy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 16:51:13 by abrabant          #+#    #+#             */
/*   Updated: 2021/03/26 16:52:52 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft/array.h"
#include "libft/internal/stack_int.h"

void	ft_stack_destroy(t_stack_int *stack, void (*fn)(void *))
{
	ft_array_destroy(stack->data, fn);
	free(stack);
}
