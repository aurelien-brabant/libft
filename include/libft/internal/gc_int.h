/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_int.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 18:42:54 by abrabant          #+#    #+#             */
/*   Updated: 2021/03/28 18:50:36 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/array.h"

/*
** Garbage collector ADT internals
*/

#ifndef GC_INT_H
#define GC_INT_H

/*
** collector contains addresses that points to something that needs to be
** freed at some point. HOW it is freed must be specified by a given function
** which address is stored at the same index in the trigger arrays.
**
** A trigger function will be called like that: trigger(collected_address);
*/

typedef struct s_gc_int
{
	t_array	collector;
	t_array	triggers;
}	t_gc_int;

#endif
