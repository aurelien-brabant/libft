/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_cur_written.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 11:49:15 by abrabant          #+#    #+#             */
/*   Updated: 2020/11/17 12:42:12 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/internal/printf.h"

/*
** %n conversion (supporting %ll %l %h %hh)
**
** Store in the integer pointed by the argument (assumed to be a pointer)
** the current amount of characters written (or stored in buf).
*/

void	conv_cur_written(t_state *s)
{
	const t_lenspec	lspec = s->s_conv.lenspec;
	const void		*el = va_arg(*s->alst, void *);

	if (!el)
		return ;
	if (lspec == H_LENSPEC)
		*(short *)el = s->written + s->s_buf.len;
	if (lspec == HH_LENSPEC)
		*(char *)el = s->written + s->s_buf.len;
	if (lspec == L_LENSPEC)
		*(long *)el = s->written + s->s_buf.len;
	if (lspec == LL_LENSPEC)
		*(long long *)el = s->written + s->s_buf.len;
	else
		*(int *)el = s->written + s->s_buf.len;
}
