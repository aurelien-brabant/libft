/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 11:53:28 by abrabant          #+#    #+#             */
/*   Updated: 2020/11/06 16:08:21 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

/*
** Put a single character on a given fd.
**
** @param	c	=> the single character to output.
** @param	fd	=> the fd to output on.
*/

void	ft_putchar_fd(char c, int fd)
{
	c = (unsigned char)c;
	write(fd, &c, 1);
}
