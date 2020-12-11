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

typedef struct	s_dvec
{
	void		**val;
	size_t		len;
	size_t		cap;
}				t_dvec;

bool			ft_dvec_make(t_dvec *v, int cap);
void			ft_dvec_destroy(t_dvec *v, void(*destr)(void **item));
void			ft_dvec_add(t_dvec *v, void *item);
void			*ft_dvec_get(t_dvec *v, size_t i);
void			ft_dvec_del(t_dvec *v, size_t i, void(*destr)(void **item));

#endif
