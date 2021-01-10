/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cla_int_var.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 23:06:59 by abrabant          #+#    #+#             */
/*   Updated: 2021/01/10 00:06:24 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/cla.h"
#include "libft/internal/cla_int.h"

void	ft_cla_int_var(void *cla, long long int *var, const char *key
						, long long int dflt)
{
	t_cla	*cla_ptr;
	size_t	i;

	cla_ptr = (t_cla *) cla;
	i = 0;
	while (cla_ptr->ints[i].key != NULL)
		++i;
	cla_ptr->ints[i].key = key;
	cla_ptr->ints[i].dflt = dflt;
	cla_ptr->ints[i].ptr = var;
}
