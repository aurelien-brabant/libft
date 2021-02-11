/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 23:10:30 by abrabant          #+#    #+#             */
/*   Updated: 2021/02/11 01:38:38 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/core.h"
#include "libft/string.h"

void	ft_bsort(void *addr, size_t len
			, size_t size, int (*cmp)(void *, void *))
{
	void	*start;
	void	*last;
	void	*tmp;

	start = addr;
	tmp = ft_calloc(1, size);
	if (tmp == NULL)
		return ;
	last = addr + (len * size) - size;
	while (addr < last)
	{
		if (cmp(addr, addr + size) > 0)
		{
			ft_memcpy(tmp, addr, size);
			ft_memcpy(addr, addr + size, size);
			ft_memcpy(addr + size, tmp, size);
			addr = start;
		}
		else
			addr += size;
	}
}
