/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 13:54:16 by abrabant          #+#    #+#             */
/*   Updated: 2020/11/06 14:47:18 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** libft implementation of memccpy(3)
*/

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s = (unsigned char *)src;

	if (!n)
		return (NULL);
	d = (unsigned char *)dest;
	*d = *s++;
	while (*d++ != (unsigned char)c && --n)
		*d = *s++;
	if (*(d - 1) == (unsigned char)c)
		return ((void *)d);
	return (NULL);
}
