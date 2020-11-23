/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 13:15:41 by abrabant          #+#    #+#             */
/*   Updated: 2020/11/11 23:24:37 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 ** libft implementation of strdup(3)
*/

char	*ft_strdup(const char *s)
{
	const size_t	len = ft_strlen(s) + 1;
	char			*dup;

	dup = malloc(sizeof(char) * len);
	if (!dup)
		return (NULL);
	ft_strlcpy(dup, s, len);
	return (dup);
}
