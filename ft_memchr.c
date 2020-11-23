/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 21:19:26 by abrabant          #+#    #+#             */
/*   Updated: 2020/08/31 21:31:10 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** libft implementation of memchr(3)
*/

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*sc = (const unsigned char *)s;
	unsigned char		ch;

	ch = (unsigned char)c;
	while (n--)
	{
		if (*sc == ch)
			return ((void *)sc);
		++sc;
	}
	return (NULL);
}
