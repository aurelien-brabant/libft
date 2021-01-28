/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 18:59:13 by abrabant          #+#    #+#             */
/*   Updated: 2021/01/28 19:06:36 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** This header provides all the required type definitions and prototypes
** to make use of vectors.
** All the internal details (how the vectors are managed in memory, helper
** functions and so on) are kept private in <libft/internal/vector_int.h>.
*/

#ifndef VECTOR_H
# define VECTOR_H

# include <stddef.h>

/*
** The address of a t_vector_int object.
** Abstracted for the sake of encapsulation.
*/
typedef void *t_vector;

/*
** Functions used to manipulate and get informations
** about a vector.
*/
t_vector	*ft_vec_new(size_t cap);
void		*ft_vec_add(t_vector *vector, void *element, size_t index);
int			ft_vec_del(t_vector *vector, size_t index
						, void (*cleanup)(void *));
size_t		ft_vec_len(t_vector *vector);
size_t		ft_vec_cap(t_vector *vector);
int			ft_vec_destroy(t_vector *vector, void (*cleanup)(void *));

#endif
