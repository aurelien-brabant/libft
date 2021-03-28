/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gc_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 19:46:16 by abrabant          #+#    #+#             */
/*   Updated: 2021/03/28 19:49:34 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/array.h"
#include "libft/internal/gc_int.h"

void	*ft_gc_add(t_gc_int *gc, void *el, void (*trigger)())
{
	ft_array_append(gc->collector, el);
	ft_array_append(gc->triggers, trigger);
	return (el);
}
