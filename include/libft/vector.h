/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 22:50:06 by abrabant          #+#    #+#             */
/*   Updated: 2020/11/23 12:02:31 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H
# include "libft/types.h"

# define VECTOR_DEFAULT_CAP 4

typedef struct	s_vec
{
	void		**val;
	size_t		len;
	size_t		cap;
}				t_vec;

bool			ft_vec_make(t_vec *v, int cap);
void			ft_vec_destroy(t_vec *v, void(*destr)(void **item));
void			ft_vec_add(t_vec *v, void *item);
void			*ft_vec_get(t_vec *v, size_t i);
void			ft_vec_del(t_vec *v, size_t i, void(*destr)(void **item));

#endif
