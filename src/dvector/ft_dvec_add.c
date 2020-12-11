/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dvec_add.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 10:50:48 by abrabant          #+#    #+#             */
/*   Updated: 2020/12/11 10:50:51 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/core.h"
#include "libft/vector.h"

static void	resize_vec(t_dvec *v, size_t ncap)
{
	v->val = ft_realloc(v->val, v->cap * sizeof(void *), ncap * sizeof(void *));
	v->cap = ncap;
}

/*
** Add an element to the vector, resizing it if needed.
**
** @param	v		=> a pointer to a t_dvec struct.
** @param	item	=> the actual item to add.
*/

void		ft_dvec_add(t_dvec *v, void *item)
{
	if (v->len == v->cap)
		resize_vec(v, v->cap * 2);
	v->val[v->len++] = item;
}
