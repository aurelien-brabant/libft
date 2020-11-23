/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 13:06:35 by abrabant          #+#    #+#             */
/*   Updated: 2020/11/06 13:56:06 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** libft implementation of bzero(3)
*/

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
