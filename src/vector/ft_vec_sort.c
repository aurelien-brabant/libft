/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 23:07:18 by abrabant          #+#    #+#             */
/*   Updated: 2021/02/17 00:57:00 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/internal/vector_int.h"
#include "libft/core.h"

void	ft_vec_sort(t_vector_int *vec, void (*sort)
				(void *, size_t, size_t, int (*cmp)(void *, void *)),
				int (*cmp)(void *, void *))
{
	sort(vec->items, vec->len, sizeof (void *), cmp);
}
