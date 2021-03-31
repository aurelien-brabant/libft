/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant </var/mail/abrabant>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 17:14:51 by abrabant          #+#    #+#             */
/*   Updated: 2021/03/31 17:19:55 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/internal/array_int.h"

void	ft_array_sort(t_array_int *a, void (*alg)(void *, size_t, size_t,
			int (*cmp)(void *, void *)), int (*cmp)(void *, void *))
{
	alg(a->array, a->length, sizeof (void *), cmp);
}
