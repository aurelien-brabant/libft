/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 14:51:12 by abrabant          #+#    #+#             */
/*   Updated: 2020/11/28 11:04:40 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/internal/printf.h"
#include "libft/unicode.h"
#include "libft/string.h"
#include "libft/ctype.h"
#include <stdio.h>

/*
** @UTIL
**
** Bufferize a modified string conversion, i.e %ls, in the ft_printf global
** buffer.
**
** @param	s	=> a pointer to the ft_printf global state.
*/

static void		buf_lstr(t_state *s)
{
	const t_byte	*nstr = (t_byte *)"(null)";
	t_byte			buf[5];
	t_rune			*ra;
	int				prec;
	size_t			i;

	prec = s->conv.prec;
	ra = va_arg(*s->alst, t_rune *);
	if (!ra)
		while (*nstr && prec-- != 0)
			store_in_buf(s, (char *)nstr++, 1);
	while (prec != 0 && ra && *ra)
	{
		ft_buf_utf8(buf, *ra++);
		i = 0;
		while (buf[i] && prec != 0)
		{
			if (!(!ft_isprint(buf[i]) && prec == 1))
				store_in_buf(s, (char *)&buf[i++], 1);
			--prec;
		}
	}
}

/*
** @UTIL
**
** Bufferize a standard string conversion, i.e %s, in the ft_printf global
** buffer.
**
** @param	s	=> a pointer to the ft_printf global state.
*/

static void		buf_str(t_state *s)
{
	const t_byte	*nstr = (t_byte *)"(null)";
	t_byte			*str;
	int				prec;

	str = va_arg(*s->alst, t_byte *);
	prec = s->conv.prec;
	if (!str)
		str = (t_byte *)nstr;
	while (prec-- != 0 && str && *str)
		store_in_buf(s, (char *)str++, 1);
}

/*
** @UTIL
**
** Get the field length of a string conversion modified by the l length
** specifier, i.e %ls. This conversion must handle UTF-8 encoding, and
** is therefore dealing with a t_rune array (custom alias for uint32_t)
**
** @param	s	=> a pointer to the ft_printf global state.
**
** @return	the field length.
*/

static size_t	get_lflen(t_state *s)
{
	va_list	clst;
	size_t	flen;
	size_t	prec;
	size_t	tmp;
	t_rune	*ra;

	va_copy(clst, *s->alst);
	prec = s->conv.prec;
	flen = 0;
	ra = va_arg(clst, t_rune *);
	if (!ra && (prec < 0 || prec >= 6))
		flen = 6;
	else if (!ra)
		flen = prec;
	else if (ra)
		while (prec != 0 && *ra)
		{
			tmp = ft_runelen(*ra++);
			while (prec != 0 && tmp-- > 0 && ++flen)
				--prec;
		}
	va_end(clst);
	return (flen);
}

/*
** @UTIL
**
** Get the field length of a standard string conversion, i.e %s.
** This is done by copying the list and extracting the string to evaluate
** its length, while handling the NULL pointer undefined (but expected ?) case.
**
** @param	s	=> a pointer to the ft_printf global state.
**
** @return	the field length.
*/

static size_t	get_flen(t_state *s)
{
	va_list	clst;
	size_t	flen;
	t_byte	*bs;
	int		prec;

	prec = s->conv.prec;
	flen = 0;
	va_copy(clst, *s->alst);
	bs = va_arg(clst, t_byte *);
	if (!bs)
		bs = (t_byte *)"(null)";
	while (*bs++ && prec-- != 0)
		++flen;
	va_end(clst);
	return (flen);
}

/*
** @EXPORTED
**
** The conversion function used to convert %s.
**
** @param	s	=> a pointer to the ft_printf global state.
*/

void			conv_str(t_state *s)
{
	const bool	isutf8 = s->conv.lenspec == L_LENSPEC;
	size_t		flen;

	if (isutf8)
		flen = get_lflen(s);
	else
		flen = get_flen(s);
	if (!isflag(s, REV_PAD_FLAG))
		buf_field_width(s, flen);
	if (isutf8)
		buf_lstr(s);
	else
		buf_str(s);
	if (isflag(s, REV_PAD_FLAG))
		buf_field_width(s, flen);
}
