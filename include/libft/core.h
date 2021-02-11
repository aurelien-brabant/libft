/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 14:30:22 by abrabant          #+#    #+#             */
/*   Updated: 2021/02/11 00:09:49 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_H
# define CORE_H
# include "./types.h"

void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_realloc(void *ptr, size_t osize, size_t nsize);
void	ft_bsort(void *addr, size_t len, size_t size
			, int (*cmp)(void *, void *));

#endif
