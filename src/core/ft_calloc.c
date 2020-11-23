/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 21:49:57 by abrabant          #+#    #+#             */
/*   Updated: 2020/11/08 13:05:19 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdlib.h>
#include "libft/string.h"

/*
** libft implementation of calloc(3)
**
** The error handling is the same as the Linux implementation: if nmemb * size
** overflows an int datatype, NULL is returned.
**
** The case where nmemb or size is 0 is not handled specifically because
** malloc(3) should already do it.
*/

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*mem;
	size_t	i;

	i = 0;
	if (nmemb * size > UINT_MAX)
		return (NULL);
	mem = malloc(size * nmemb);
	if (!mem)
		return (NULL);
	return (ft_memset(mem, 0, nmemb * size));
}
