/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 18:59:13 by abrabant          #+#    #+#             */
/*   Updated: 2021/01/28 23:41:00 by abrabant         ###   ########.fr       */
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
** Initialize and allocate memory for a new vector data structure.
**
** @PARAM cap			=> the amount of items the vector can hold 
** before having to be resized. If it is found to be zero, the default
** value is used instead.
**
** @PARAM growth_factor	=> the factor used to increase the vector's
** total capacity when it is full. The factor must increase the cap
** by at least one. A quick check is performed to ensure that's the case;
** if that's not the default growth_factor is used.
**
** These two parameters can omitted by specifying obviously
** wrong values. For example, the following call:
** t_vector vec = ft_vec_new(0, 0)
** will simply create a vector with the defaults parameters
** (defined in libft/internal/vector_int.h).
**
** @RETURN				=> a t_vector element holding the 
** vector's memory address.
*/

t_vector	ft_vec_new(size_t cap, float growth_factor);

/*
** Add a new element at the end of a vector.
**
** @PARAM	vector	=> the targeted vector instance.
**
** @PARAM	element	=> the address of the element to add.
**
** @RETURN			=> the address of the added element, or NULL if something
** went wrong. In the last case, the error is related to the vector's
** resizing.
*/

void		*ft_vec_add(t_vector vector, void *element);

/*
** Delete an element of the vector at a specific index.
**
** @PARAM vector	=> the targeted vector instance.
**
** @PARAM index		=> the index of the element to remove.
**
** @PARAM cleanup	=> a function to apply on the element
** before it gets deleted from the vector. Used to perform some cleanup.
** A NULL pointer means no cleanup.
**
** @RETURN			=> the index of the deleted element if deletion was
** successful, -1 otherwise.
*/

int			ft_vec_del(t_vector vector, size_t index
						, void (*cleanup)(void *));

/*
** Return the number of elements held by the vector.
**
** @PARAM vector	=> the targeted vector instance.
**
** @RETURN			=> the length of the vector.
*/

size_t		ft_vec_len(t_vector vector);

/*
** Return the maximum number of elements that the vector can hold before
** it needs to trigger a resize operation.
**
** @PARAM vector	=> the targeted vector instance.
**
** @RETURN			=> the cap of the vector.
*/

size_t		ft_vec_cap(t_vector vector);

/*
** Iterate over vector's elements.
**
** @PARAM vector	=> the targeted vector instance.
**
** @PARAM func		=> a pointer to a function that is applied on each
** element of the vector. Passing a NULL pointer results in undefined
** behaviour.
*/

void	ft_vec_foreach(t_vector vector, void (*func)(void *));

/*
** Get an element of the vector using its index.
**
** @PARAM vector	=> the targeted vector instance.
**
** @PARAM index		=> the index of the element to retrieve.
**
** @RETURN			=> the element requested if index is in bounds, NULL
** otherwise.
*/

void	*ft_vec_get(t_vector vector, size_t index);

/*
** Destroy the vector, freeing all the memory allocated for it.
**
** @PARAM vector	=> the targeted vector instance.
**
** @PARAM cleanup	=> a pointer to a function that is applied on each
** element of the vector. Used to do some important cleanup. NULL value is
** interpreted as no cleanup.
*/

void		ft_vec_destroy(t_vector vector, void (*cleanup)(void *));

#endif
