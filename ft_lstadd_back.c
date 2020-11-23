/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 19:54:22 by abrabant          #+#    #+#             */
/*   Updated: 2020/09/30 18:52:05 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Add new list element to the end of the list. If list has at least one element
** ft_lstlast will be use to retrieve the last element and append the new one
** easily. However, if head is empty the new element will simply becomes the
** first one of the list.
**
** @param	head	=> the address of the first element of the list.
** @param	new		=> the new list item.
*/

void	ft_lstadd_back(t_list **head, t_list *new)
{
	t_list *last_node;

	if (!head)
		return ;
	if (*head)
	{
		last_node = ft_lstlast(*head);
		last_node->next = new;
	}
	else
		*head = new;
}
