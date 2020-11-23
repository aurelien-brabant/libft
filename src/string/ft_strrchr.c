/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 13:24:30 by abrabant          #+#    #+#             */
/*   Updated: 2020/11/07 15:22:59 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** libft implementation of strrchr(3)
**
** Behaves like my libft strnstr(3) implementation, except that we search the
** last occurence of a single character and that if this character is null,
** the terminator is returned. It is indeed returned, so performing a cat -e
** on the output should display a "^@" character, which is the representation
** of a non printable null byte.
*/

char	*ft_strrchr(const char *s, int c)
{
	char *last;

	last = 0;
	while (*s)
	{
		if (*s == c)
			last = (char *)s;
		++s;
	}
	return (c == '\0' ? (char *)s : last);
}
