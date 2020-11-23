/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 22:30:35 by abrabant          #+#    #+#             */
/*   Updated: 2020/11/16 12:03:31 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Create a new string that is a substring of s, starting from index start,
** ending at index (start + len). Bounds included.
**
** @param	s		=> the base string.
** @param	start	=> the index of string the substring starts at.
**
** @return	the malloc-allocated substring, or NULL in case malloc failed.
*/

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t			i;
	char			*substr;

	i = 0;
	if (start >= ft_strlen(s))
		len = 0;
	substr = ft_calloc(len + 1, sizeof(char));
	if (!substr)
		return (NULL);
	while (len-- && s[start])
		substr[i++] = s[start++];
	return (substr);
}
