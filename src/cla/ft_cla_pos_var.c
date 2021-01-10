/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cla_pos_var.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 14:27:04 by abrabant          #+#    #+#             */
/*   Updated: 2021/01/10 15:18:10 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "libft/string.h"
#include "libft/io.h"

#include "libft/internal/cla_int.h"

void	ft_cla_pos_var(void *cla, char **var, int index, const char *dflt)
{
	t_cla	*cla_ptr;
	size_t	i;

	cla_ptr = (t_cla *) cla;
	i = 0;
	while (cla_ptr->pos[i].index != -1)
		++i;
	if (i >= MAX_POS)
	{
		ft_dprintf(STDERR_FILENO, "CLA error: reached POS_MAX.\n");
		return ;
	}
	cla_ptr->pos[i].index = index;
	cla_ptr->pos[i].dflt = dflt;
	cla_ptr->pos[i].ptr = var;
}

