/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 12:19:03 by abrabant          #+#    #+#             */
/*   Updated: 2020/09/30 22:23:47 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** libft implementation of memset(3)
*/

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*byte_set;

	byte_set = (unsigned char *)s;
	while (n--)
	{
		*byte_set++ = c;
	}
	return (s);
}
