/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 18:59:13 by abrabant          #+#    #+#             */
/*   Updated: 2021/02/11 01:43:11 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** This header provides all the required type definitions and prototypes
** to make use of vectors.
**
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
** @PARAM cap:
** The amount of items the vector can hold before having to be resized. If it
** is found to be zero, the default value is used instead.
**
** @PARAM growth_factor:
** The factor used to increase the vector's total capacity when it is full.
** The factor must increase the cap by at least one. A quick check is performed
** to ensure that's the case: if that's not the default *growth_factor* is used.
**
** These two parameters can omitted by specifying obviously wrong values. For
** example, the following call:
** t_vector vec = ft_vec_new(0, 0)
** will simply create a vector with the defaults parameters (defined in 
** libft/internal/vector_int.h).
**
** @RETURN:
** A t_vector element holding the vector's memory address.
*/

t_vector	ft_vec_new(size_t cap, float growth_factor);

/*
** Add a new element at the end of a vector.
**
** @PARAM vector:
** The targeted vector instance.
**
** @PARAM element:
** The address of the element to add.
**
** @RETURN:
** The address of the added element, or NULL if something went wrong. In the
** last case, the error is related to the vector's resizing.
*/

void		*ft_vec_add(t_vector vector, void *element);

/*
** Delete an element of the vector at a specific index.
**
** @PARAM vector:
** The targeted vector instance.
**
** @PARAM index:
** The index of the element to remove.
**
** @PARAM cleanup:
** A function to apply on the element
** before it gets deleted from the vector. Used to perform some cleanup.
** A NULL pointer means no cleanup.
**
** @RETURN:
** The index of the deleted element if deletion was successful, -1 otherwise.
*/

int			ft_vec_del(t_vector vector, size_t index,
				void (*cleanup)(void *));

/*
** Return the number of elements held by the vector.
**
** @PARAM vector:
** The targeted vector instance.
**
** @RETURN:
** The length of the vector.
*/

size_t		ft_vec_len(t_vector vector);

/*
** Return the maximum number of elements that the vector can hold before
** it needs to trigger a resize operation.
**
** @PARAM vector:
** The targeted vector instance.
**
** @RETURN:
** The cap of the vector.
*/

size_t		ft_vec_cap(t_vector vector);

/*
** Iterate over vector's elements.
**
** @PARAM vector:
** The targeted vector instance.
**
** @PARAM func:
** A pointer to a function that is applied on each element of the vector.
** Passing a NULL pointer results in undefined behaviour.
*/

void		ft_vec_foreach(t_vector vector, void (*func)(void *));

/*
** Iterate over vector's elements in the perspective to modify them.
**
** @PARAM vector:
** The targeted vector instance.
**
** @PARAM func:
** A pointer to a function that is applied on each element of the vector.
**
** NOTE: as opposed to ft_vec_foreach, here the address of the element is
** given and not the element itself. This allows one to apply modifications
** to the vector item slot itself. For example, it is possible to create a new
** element with each mapped vector item and replace the old elements with
** the newly created ones. This is NOT something ft_vec_foreach can achieve.
**
** Like a standard mapping function, the index of each element is passed.
*/

void		ft_vec_map(t_vector vector, void (*func)(void **, size_t));

/*
** Get an element of the vector using its index.
**
** @PARAM vector:
** The targeted vector instance.
**
** @PARAM index:
** The index of the element to retrieve.
**
** @RETURN:
** The element requested if index is in bounds, NULL otherwise.
*/

void		*ft_vec_get(t_vector vector, size_t index);

/*
** Set a vector's existing element to another one.
** 
** @PARAM vector:
** The targeted vector instance.
**
** @PARAM index:
** The index of the element to set. An element must already exist at this
** index. If not, this is undefined behaviour. Consider using ft_vec_add
** if what you want is adding an element.
**
** @PARAM element:
** The new element to set as a replacement for the one at the specified
** index.
**
** NOTE: no operation is performed on the replaced element.
*/

void		ft_vec_set(t_vector vector, size_t index, void *elem);

/*
** Concatenate two vectors inside a new one. The vectors used
** for the concatenation are NOT destroyed.
** The biggest growth_factor is used for the new vector.
** The cap of the new vector is given by the formula below (in pseudo-code):
** cap(concat_vector) = (len(vector1) + len(vector2)) * growth_factor
**
** @PARAM vector1:
** The first vector instance.
**
** @PARAM vector2:
** The second vector instance.
**
** @RETURN:
** A new vector holding the concatenation of vector1 and vector2.
*/

t_vector	ft_vec_cat(t_vector vector1, t_vector vector2);

/*
** Destroy the vector, freeing all the memory allocated for it.
**
** @PARAM vector:
** The targeted vector instance.
**
** @PARAM cleanup:
** A pointer to a function that is applied on each element of the vector.
** Used to do some important cleanup. NULL value is interpreted as no cleanup.
*/

void		ft_vec_destroy(t_vector vector, void (*cleanup)(void *));

#endif
