/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 12:45:59 by abrabant          #+#    #+#             */
/*   Updated: 2020/11/06 14:45:52 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Creates a new string holding the concatenation of s1 and s2.
**
** @param	s1	=> the first string
** @param	s2	=> the second string
**
** @return	the result of the concatenation, or NULL if malloc failed.
*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*concat;
	size_t	concat_len;

	concat_len = ft_strlen(s1) + ft_strlen(s2);
	concat = ft_calloc(concat_len + 1, sizeof(char));
	if (!concat)
		return (NULL);
	while ((*concat = *s1++))
		++concat;
	while ((*concat = *s2++))
		++concat;
	return (concat - concat_len);
}
