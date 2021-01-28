/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_int.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 19:06:56 by abrabant          #+#    #+#             */
/*   Updated: 2021/01/28 19:32:58 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Internal header responsible for handling
** all the vector pseudo-class inner logic.
**
** The elements declared in this header are not meant to be used
** by the end user.
*/

#ifndef VECTOR_INT_H
# define VECTOR_INT_H
# include <stddef.h>

# define VECTOR_DEFAULT_CAP 10
# define VECTOR_DEFAULT_GROWTH_FACTOR 2.0

typedef struct s_vector_int
{
	void	**items;
	size_t	len;
	size_t	cap;
	float	gfac;
}	t_vector_int;

#endif
