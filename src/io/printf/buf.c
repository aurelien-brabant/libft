/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 17:42:51 by abrabant          #+#    #+#             */
/*   Updated: 2020/11/26 12:28:59 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include "libft/string.h"
#include "libft/internal/printf.h"

/*
** In my ft_printf, there's no dynamic memory allocation, everything is
** stored in a buffer on the stack, which is to be flushed to stdout when
** full or when libft/internal/printf.has finished its work.
*/

/*
** Stores the given string in the print buffer. If buffer overflow is
** encountered, prevents it and flush the buffer.
*/

void	store_in_buf(t_state *s, const char *str, size_t n)
{
	while (n--)
	{
		if (s->s_buf.len >= PRINTF_BUF)
			flush_buf(s);
		(s->s_buf.str)[s->s_buf.len++] = *str++;
	}
}

/*
** Flushes the printf buffer to stdout.
** Add the written characters to the s.written variable used to keep track
** of total output count.
** Resets the length of the printf buffer.
*/

void	flush_to_str(t_state *s)
{
	long long	*lim;
	char		**str;

	lim = &(s->s_buf.u_dst.s_strout.lim);
	str = &(s->s_buf.u_dst.s_strout.s);
	if (!str || !lim || *lim == -2 || *lim == 0)
		return ;
	if (*lim >= 0 && (long long)(s->written + s->s_buf.len) >= *lim)
	{
		ft_memcpy(*str, s->s_buf.str, (s->written + s->s_buf.len - *lim));
		*str += (s->written + s->s_buf.len - *lim);
		*lim = -2;
	}
	else
	{
		ft_memcpy(*str, s->s_buf.str, s->s_buf.len);
		*str = *str + s->s_buf.len;
	}
	**str = '\0';
}

void	flush_buf(t_state *s)
{
	if (s->s_buf.outspec == FD_OUT)
	{
		write(s->s_buf.u_dst.dfd, s->s_buf.str, s->s_buf.len);
	}
	else if (s->s_buf.outspec == STRING_OUT)
		flush_to_str(s);
	s->written += s->s_buf.len;
	s->s_buf.len = 0;
}
