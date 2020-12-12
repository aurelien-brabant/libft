/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 15:23:23 by abrabant          #+#    #+#             */
/*   Updated: 2020/11/26 14:01:00 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft/internal/printf.h"

/*
** Initialize ft_vsprintf call. Where everything starts.
*/

int			ft_vsprintf(char *str, const char *fmt, va_list ap)
{
	t_state				s;
	va_list				alst;
	t_converter			conv[TOTAL_SPEC];

	s.fmt = fmt;
	va_copy(alst, ap);
	s.alst = &alst;
	s.written = 0;
	s.s_buf.len = 0;
	s.s_buf.outspec = STRING_OUT;
	s.s_buf.u_dst.s_strout.s = str;
	s.s_buf.u_dst.s_strout.lim = -1;
	init_conv(conv);
	while (*s.fmt)
		parse_fmt(&s, conv);
	flush_buf(&s);
	va_end(alst);
	return (s.written);
}
