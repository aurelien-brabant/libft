/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cla_bool_var.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 21:26:30 by abrabant          #+#    #+#             */
/*   Updated: 2021/01/09 23:47:24 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/cla.h"
#include "libft/internal/cla_int.h"

void	ft_cla_bool_var(void *cla, bool *var, const char *key, const bool *dflt)
{
	t_cla	*cla_ptr;
	size_t	i;

	cla_ptr = (t_cla *)cla;
	i = 0;
	while (cla_ptr->bools[i].key != NULL)
		++i;
	cla_ptr->bools[i].key = key;
	cla_ptr->bools[i].dflt = dflt;
	cla_ptr->bools[i].ptr = var;
}
