/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 15:34:05 by abrabant          #+#    #+#             */
/*   Updated: 2020/11/22 22:30:19 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** libft implementation of isspace(3)
*/

unsigned char	ft_isspace(char c)
{
	const char	*charset = "\n\t\r\f\v ";

	while (*charset)
		if (*charset++ == c)
			return (1);
	return (0);
}
