/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dvec_del.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 10:50:17 by abrabant          #+#    #+#             */
/*   Updated: 2020/12/11 11:08:52 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/dvector.h"

/*
** Delete an element in the vector, do cleanup if necessary, and reorganize
** the vector items.
**
** @param	v		=> a pointer to the vector.
** @param	i		=> the index of the element to delete.
** @param	destr	=> a pointer to the function that'll do the required
**                     cleanup.
**                     Can be NULL, to mean that nothing needs to be done.
*/

void	ft_dvec_del(t_dvec *v, size_t i, void (*destr)(void **item))
{
	size_t	it;

	if (i < 0 || i >= v->len)
		return ;
	it = i;
	if (destr)
		destr(&(v->val[it]));
	while (it < v->len - 1)
	{
		v->val[it] = v->val[it + 1];
		it++;
	}
	v->len--;
}