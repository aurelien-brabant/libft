/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dvec_destroy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 10:51:06 by abrabant          #+#    #+#             */
/*   Updated: 2020/12/25 23:50:21 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/dvector.h"

/*
** Completely destroy a vector.
**
** @param	v		=> a pointer to the vector to destroy.
** @param	destr	=> a pointer to a function that'll take as an argument
** each item held by the vector. Use that function to do all the cleanup
** stuff you may have to do with the items. A NULL pointer is accepted,
** as a sign that you don't need any special cleanup routine.
*/

void	ft_dvec_destroy(t_dvec *v, void (*destr)(void **item))
{
	size_t	i;

	i = 0;
	if (destr)
	{
		while (i < v->len)
		{
			destr(&(v->val[i]));
			++i;
		}
	}
	free(v->val);
	v->len = 0;
	v->cap = 0;
}
