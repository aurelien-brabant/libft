/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dvec_make.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 23:39:18 by abrabant          #+#    #+#             */
/*   Updated: 2020/11/23 16:49:55 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/vector.h"
#include <stdlib.h>

/*
** Initialize or make a new t_dvec object.
**
** @param	v	=> the vector to initalize (allocated before).
** @param	cap	=> the number of elements the vector will be able to
** hold before getting resized automatically. Cap is an important choice to
** make: do not make it too large, or you'll waste memory, but do not make
** it to small because resizing a vector is a costly operation.
** Any non-greater-than-zero value is interpreted as no value, and cap will
** be fixed to the VECTOR_DEFAULT_CAP constant defined in libft/vector.h
**
** @return	a boolean value which indicates whether or not the initialization
** has been successful. A return value of false is a sign of a malloc failure.
*/

bool	ft_dvec_make(t_dvec *v, int cap)
{
	if (cap <= 0)
		cap = VECTOR_DEFAULT_CAP;
	v->val = malloc(sizeof(void *) * cap);
	if (!v->val)
		return (false);
	v->cap = cap;
	v->len = 0;
	return (true);
}
