/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 18:27:29 by abrabant          #+#    #+#             */
/*   Updated: 2021/03/26 18:28:44 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/internal/stack_int.h"

size_t	ft_stack_size(t_stack_int *stack)
{
	return (ft_array_get_length(stack->data));
}
