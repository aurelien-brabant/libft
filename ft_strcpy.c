/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 15:34:41 by abrabant          #+#    #+#             */
/*   Updated: 2020/09/30 22:10:01 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** libft implementation of strcpy(3)
*/

char	*ft_strcpy(char *dest, const char *src)
{
	char	*dst_ptr;

	dst_ptr = dest;
	while ((*dest++ = *src++))
		;
	return (dst_ptr);
}
