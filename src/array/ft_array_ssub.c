/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_ssub.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 12:16:45 by abrabant          #+#    #+#             */
/*   Updated: 2021/03/27 14:34:17 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/array.h"
#include "libft/internal/array_int.h"
#include "libft/cstring.h"

/*
** NOTE: To be clear, the way this code is organized is ugly and I know it.
** I did not find any other suitable way to code that function without
** infringing 42's norm. That's stupid code, but at least it works.
** Rework of this function without the norm restrictions is planned.
*/

static	t_array	get_new_array(t_array a1, t_array a2)
{
	t_array_int	*new;

	new = (t_array_int *)ft_array_new(((t_array_int *)a1)->capacity
			+ ((t_array_int *)a2)->capacity);
	if (new == NULL)
	{
		return (NULL);
	}
	return (new);
}

/*
** Again, for norm sake...
*/

static void	handle_ret_zero(size_t *iter)
{
	++iter[0];
	++iter[1];
}

t_array	ft_array_ssub(t_array a1, t_array a2,
		int (*cmp)(void *el1, void *el2))
{
	size_t			iter[2];
	t_array_int		*arrs[3];
	int				ret;

	ft_memset(iter, 0, sizeof(iter));
	arrs[0] = (t_array_int *)a1;
	arrs[1] = (t_array_int *)a2;
	arrs[2] = get_new_array(a1, a2);
	if (arrs[2] == NULL)
		return (NULL);
	while (iter[0] < arrs[0]->length && iter[1] < arrs[1]->length)
	{
		ret = cmp(arrs[0]->array[iter[0]], arrs[1]->array[iter[1]]);
		if (ret > 0)
			iter[1]++;
		else if (ret == 0)
			handle_ret_zero(iter);
		else
			arrs[2]->array[arrs[2]->length++] = arrs[0]->array[iter[0]++];
	}
	while (iter[0] < arrs[0]->length)
		arrs[2]->array[arrs[2]->length++] = arrs[0]->array[iter[0]++];
	return (arrs[2]);
}
