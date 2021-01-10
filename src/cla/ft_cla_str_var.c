/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cla_str_var.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 22:29:40 by abrabant          #+#    #+#             */
/*   Updated: 2021/01/10 00:06:07 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/cla.h"
#include "libft/internal/cla_int.h"

void	ft_cla_str_var(void *cla, char **var, const char *key, const char *dflt)
{
	t_cla	*cla_ptr;
	size_t	i;

	cla_ptr = (t_cla *) cla;
	i = 0;
	while (cla_ptr->strs[i].key != NULL)
		++i;
	cla_ptr->strs[i].key = key;
	cla_ptr->strs[i].dflt = dflt;
	cla_ptr->strs[i].ptr = var;
}
