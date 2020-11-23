/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 21:16:44 by abrabant          #+#    #+#             */
/*   Updated: 2020/11/07 15:34:46 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft/string.h"

/*
** libft implementation of memmove(3)
*/

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*src_byte = (const unsigned char *)src;
	unsigned char		*dest_byte;

	dest_byte = (unsigned char *)dest;
	if (src_byte < dest_byte)
	{
		while (n--)
			dest_byte[n] = src_byte[n];
	}
	else
	{
		ft_memcpy(dest_byte, src_byte, n);
	}
	return (dest);
}
