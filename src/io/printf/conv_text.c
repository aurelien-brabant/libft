/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_text.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 19:23:21 by abrabant          #+#    #+#             */
/*   Updated: 2020/11/23 20:57:31 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft/internal/printf.h"
#include "libft/unicode.h"
#include "libft/string.h"

/*
** Bufferize in utf-8 format: support for %lc && %ls.
*/

void	buf_utf8(t_state *s)
{
	int			prec;
	t_rune		*r;
	size_t		i;
	t_byte		buf[5];

	prec = s->conv.prec;
	if (s->conv.spec == CHAR_SPEC)
	{
		ft_buf_utf8(buf, va_arg(*s->alst, t_rune));
		store_in_buf(s, (char *)buf, ft_strlen((char *)buf));
		return ;
	}
	r = va_arg(*s->alst, t_rune *);
	while (*r && prec)
	{
		ft_buf_utf8(buf, *r++);
		i = 0;
		while (buf[i] && prec)
		{
			store_in_buf(s, (char *)&buf[i++], 1);
			--prec;
		}
	}
}

void	buf_char(t_state *s)
{
	char	c;

	c = (unsigned char)va_arg(*s->alst, int);
	store_in_buf(s, &c, 1);
}

void	buf_str(t_state *s)
{
	char	*str;

	str = va_arg(*s->alst, char *);
	if (s->conv.prec >= 0)
		store_in_buf(s, str, s->conv.prec);
	else
		store_in_buf(s, str, ft_strlen(str));
}

/*
** Select the buffering function which is appropriated depending on the
** specifier, lenspec... + apply width.
*/

void	conv_text(t_state *s)
{
	const size_t flen = get_field_len(s);

	if (!isflag(s, REV_PAD_FLAG))
		buf_field_width(s, flen);
	if (s->conv.lenspec == L_LENSPEC)
		buf_utf8(s);
	else if (s->conv.spec == CHAR_SPEC)
		buf_char(s);
	else
		buf_str(s);
	if (isflag(s, REV_PAD_FLAG))
		buf_field_width(s, flen);
}
