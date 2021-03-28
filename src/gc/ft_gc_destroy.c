/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gc_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 19:17:35 by abrabant          #+#    #+#             */
/*   Updated: 2021/03/28 19:21:17 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/internal/gc_int.h"

void	ft_gc_destroy(t_gc_int *gc)
{
	//ft_gc_wipe(gc);
	ft_array_destroy(gc->collector, NULL);
	ft_array_destroy(gc->triggers, NULL);
	free(gc);
}
