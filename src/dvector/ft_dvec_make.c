/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dvec_make.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 10:53:11 by abrabant          #+#    #+#             */
/*   Updated: 2020/12/11 11:09:24 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/dvector.h"
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
** be fixed to the VECTOR_DEFAULT_CAP constant defined in libft/dvector.h
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
