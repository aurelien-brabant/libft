/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 13:39:49 by abrabant          #+#    #+#             */
/*   Updated: 2020/11/16 11:44:18 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** libft implementation of FreeBSD strnstr(3)
**
** A few important notes:
** - When needle is empty, haystack is returned. (strlen(needle) == 0)
** - No more than len characters are searched, then if strlen(needle) < len, we
** stop the search.
** - Passing NULL is undefined.
*/

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	const size_t	nlen = ft_strlen(needle);

	if (nlen == 0)
		return ((char *)haystack);
	while (*haystack && len-- >= nlen)
	{
		if (*haystack == *needle && ft_strncmp(haystack, needle, nlen) == 0)
			return ((char *)haystack);
		++haystack;
	}
	return (0);
}
