/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 21:35:00 by abrabant          #+#    #+#             */
/*   Updated: 2020/09/30 22:26:30 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** libft implementation of memcmp(3)
*/

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*mem1 = (unsigned char *)s1;
	const unsigned char *mem2 = (unsigned char *)s2;

	if (!n)
		return (0);
	while (*mem1++ == *mem2++ && --n)
		;
	return (*(--mem1) - *(--mem2));
}
