/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_int.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 16:02:50 by abrabant          #+#    #+#             */
/*   Updated: 2021/03/26 21:07:19 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_INT_H
# define STACK_INT_H

# include "libft/array.h"

typedef struct s_stack_int
{
	int		top;
	t_array	data;
}	t_stack_int;

#endif
