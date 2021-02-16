/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_destroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 23:21:05 by abrabant          #+#    #+#             */
/*   Updated: 2021/02/16 21:47:53 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/internal/vector_int.h"
#include "libft/vector.h"

void	ft_vec_destroy(t_vector vector, void (*cleanup)())
{
	if (cleanup)
		ft_vec_foreach(vector, cleanup, NULL);
	free(((t_vector_int *)vector)->items);
	free(vector);
}
