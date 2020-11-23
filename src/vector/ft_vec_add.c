/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 00:10:30 by abrabant          #+#    #+#             */
/*   Updated: 2020/11/23 01:14:13 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/core.h"
#include "libft/vector.h"

static void	resize_vec(t_vec *v, size_t ncap)
{
	v->val = ft_realloc(v->val, v->cap * sizeof(void *), ncap * sizeof(void *));
	v->cap = ncap;
}

void		ft_vec_add(t_vec *v, void *item)
{
	if (v->len == v->cap)
		resize_vec(v, v->cap * 2);
	v->val[v->len++] = item;
}
