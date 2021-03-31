/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 14:30:22 by abrabant          #+#    #+#             */
/*   Updated: 2021/03/31 00:46:59 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_H
# define CORE_H
# include "./types.h"

void		*ft_calloc(size_t nmemb, size_t size);
void		*ft_realloc(void *ptr, size_t osize, size_t nsize);
void		ft_bubble_sort(void *mem, size_t nb_el, size_t size_el,
				int (*cmp)(void *, void *));
void		ft_insertion_sort(void *mem, size_t nb_el, size_t size_el,
				int (*cmp)(void *, void *));

long long	ft_clamp(long long nb, long long min, long long max);

#endif
