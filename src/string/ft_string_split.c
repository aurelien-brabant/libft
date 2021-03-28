/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_split.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 21:16:16 by abrabant          #+#    #+#             */
/*   Updated: 2021/03/29 01:23:04 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/internal/string_int.h"
#include "libft/string.h"
#include "libft/array.h"
#include "libft/cstring.h"

static bool	add_to_split(t_array split, t_string subset)
{
	if (subset == NULL)
	{
		ft_array_destroy(split, (void (*)(void *))ft_string_destroy);
		return (false);
	}
	ft_array_append(split, subset);
	return (true);
}

t_array	ft_string_split(t_string str, const char *sep)
{
	t_string_int	*str_int;
	t_string		new;
	t_array			split;
	size_t			i;
	size_t			beg;

	str_int = (t_string_int *)str;
	split = ft_array_new(str_int->length / 2 + 1);
	if (split == NULL)
		return (NULL);
	i = 0;
	while (i < str_int->length)
	{
		while (i < str_int->length && ft_strchr(sep, str_int->chrs[i]) != NULL)
			++i;
		beg = i;
		while (i < str_int->length && ft_strchr(sep, str_int->chrs[i]) == NULL)
			++i;
		if (beg == i)
			break ;
		new = ft_string_subset(str, beg, i);
		if (!add_to_split(split, new))
			return (NULL);
	}
	return (split);
}
