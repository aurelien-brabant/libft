/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_int.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 12:32:39 by abrabant          #+#    #+#             */
/*   Updated: 2021/03/27 14:30:06 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_INT_H
# define ARRAY_INT_H
# include <stddef.h>
# define ARRAY_SIZE_DEFAULT 10

/*
** This how the array ADT is represented internally.
** The members of this structure are not meant to be accessed directly, but
** through the use of the various helper functions provided by libft/array.h.
**
** NOTE: Array's size is not fixed and will increase if more elements need
** to be stored. This capability is handled internally by ft_array_int_resize
** and needs to be used by any function that will mutate the array's content.
**
** An array of void pointers is used to store any type of element.
*/

typedef struct s_array
{
	size_t	capacity;
	size_t	length;
	void	**array;
}	t_array_int;

/*
** Perform array resizing operation when it is needed. The function doesn't
** check if it is, but double the size of the array directly by allocation
** a brand new array and copying the old content in the new one.
*/

void	ft_array_int_resize(t_array_int *a);

#endif
