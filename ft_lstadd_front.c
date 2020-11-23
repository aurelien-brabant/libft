/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 19:31:39 by abrabant          #+#    #+#             */
/*   Updated: 2020/09/30 19:28:11 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Add a new element to the beginning of the list.
**
** @param	head	=> the address of the first element of the list.
** @param	new		=> the item to add at the beginning.
*/

void	ft_lstadd_front(t_list **head, t_list *new)
{
	t_list	*tmp;

	tmp = *head;
	*head = new;
	new->next = tmp;
}
