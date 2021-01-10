/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cla_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 21:12:50 by abrabant          #+#    #+#             */
/*   Updated: 2021/01/10 15:40:56 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/core.h"
#include "libft/cla.h"
#include "libft/internal/cla_int.h"

static void	init_pos_index(t_cla_pos *pos)
{
	size_t	i;

	i = 0;
	while (i < MAX_POS)
		pos[i++].index = -1;
}

void	*ft_cla_init(int ac, char **av)
{
	t_cla	*cla;
	
	cla = ft_calloc(1, sizeof (t_cla));
	if (cla != NULL)
	{
		cla->ac = ac - 1;
		cla->av = av + 1;
		init_pos_index(cla->pos);
	}
	return (cla);
}
