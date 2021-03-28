/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gc_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 19:17:35 by abrabant          #+#    #+#             */
/*   Updated: 2021/03/28 19:43:28 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft/internal/gc_int.h"
#include "libft/gc.h"

void	ft_gc_destroy(t_gc gc)
{
	ft_gc_wipe((t_gc_int *)gc);
	ft_array_destroy(((t_gc_int *)gc)->collector, NULL);
	ft_array_destroy(((t_gc_int *)gc)->triggers, NULL);
	free(gc);
}
