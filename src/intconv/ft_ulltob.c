/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltob.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 20:46:34 by abrabant          #+#    #+#             */
/*   Updated: 2020/11/08 13:40:07 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/string.h"
#include "libft/core.h"

static size_t	get_nb_len(unsigned long long nb, uint8_t base)
{
	size_t	count;

	count = 1;
	while (nb)
	{
		++count;
		nb /= base;
	}
	return (count);
}

/*
** unsigned long long to base.
**
** @param	nb		=> the base number as an unsigned long long.
** @param	base	=> the base to convert in. Accepted values are 2-16.
**
** @return	a malloc-allocated string holding the representation of nb in the
** specified base.
*/

char			*ft_ulltob(unsigned long long nb, uint8_t base)
{
	const char	*charset = "0123456789ABCDEF";
	size_t		len;
	size_t		i;
	char		*str;

	if (base < 2 || base > ft_strlen(charset))
		return (0);
	len = get_nb_len(nb, base);
	i = 0;
	if (!(str = (char *)ft_calloc((len + 1), sizeof(char))))
		return (0);
	while (nb)
	{
		str[i++] = charset[nb % base];
		nb /= base;
	}
	if (i == 0)
		str[i++] = '0';
	return (ft_strrev(str));
}
