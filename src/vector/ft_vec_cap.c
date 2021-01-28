/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_cap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 19:51:08 by abrabant          #+#    #+#             */
/*   Updated: 2021/01/28 19:52:50 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/vector.h" 
#include "libft/internal/vector_int.h"

size_t 	ft_vec_cap(t_vector vector)
{
	return (((t_vector_int *)vector)->cap);
}
