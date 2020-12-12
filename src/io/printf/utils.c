/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 23:09:51 by abrabant          #+#    #+#             */
/*   Updated: 2020/11/25 01:08:50 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/internal/printf.h"
#include "libft/types.h"

/*
** This file provides utility functions to shorten and beautify the code used
** to implement printf. This is done through functions as complex macros
** are forbidden by the norm.
*/

/*
** Check if a given flag is set for the current conversion.
*/

bool	isflag(t_state *s, t_flag f)
{
	return (s->s_conv.flags & f);
}

void	remflag(t_state *s, t_flag f)
{
	s->s_conv.flags = s->s_conv.flags & ~f;
}

bool	ishexspec(t_state *s)
{
	return (s->s_conv.spec == HEXUPR_SPEC || s->s_conv.spec == HEXLWR_SPEC
				|| s->s_conv.spec == PTR_SPEC);
}

bool	is_int_conv(t_state *s)
{
	return (s->s_conv.spec == INT_SPEC || s->s_conv.spec == UINT_SPEC ||
			s->s_conv.spec == HEXLWR_SPEC || s->s_conv.spec == HEXUPR_SPEC);
}
