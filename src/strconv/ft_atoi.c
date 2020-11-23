/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 09:49:00 by abrabant          #+#    #+#             */
/*   Updated: 2020/11/23 16:47:17 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdbool.h>
#include <stdint.h>
#include "libft/ctype.h"
#include "libft/string.h"

static bool	iswspace(char c)
{
	const char	*set = " \n\v\r\t\f";

	return (ft_strchr(set, c) != 0);
}

/*
** libft implementation of atoi(3)
**
** underflow / overflow is handled, even if it is normally undefined.
*/

int			ft_atoi(const char *nptr)
{
	int		nb;
	bool	isneg;
	uint8_t	n;

	nb = 0;
	isneg = false;
	while (iswspace(*nptr))
		++nptr;
	if (*nptr == '+' || *nptr == '-')
		if (*nptr++ == '-')
			isneg = true;
	while (ft_isdigit(*nptr))
	{
		n = *nptr++ - 48;
		if ((uint32_t)nb * 10 + n > ((uint32_t)INT_MAX + isneg))
			break ;
		nb = nb * 10 + n;
	}
	if (isneg)
		return (-nb);
	return (nb);
}
