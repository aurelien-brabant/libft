/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_destroy.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 15:47:19 by abrabant          #+#    #+#             */
/*   Updated: 2021/03/25 15:49:11 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft/internal/string_int.h"

void	ft_string_destroy(t_string_int *str)
{
	free(str->chrs);
	free(str);
}
