/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 13:45:36 by abrabant          #+#    #+#             */
/*   Updated: 2020/11/07 15:35:14 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/*
** libft implementation of ft_memcpy(3)
*/

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*destc;
	const unsigned char	*srcc;

	destc = (unsigned char *)dest;
	srcc = (const unsigned char *)src;
	if (!dest && !src)
		return (0);
	while (n--)
	{
		*destc++ = *srcc++;
	}
	return (dest);
}
