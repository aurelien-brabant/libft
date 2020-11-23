/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 16:29:00 by abrabant          #+#    #+#             */
/*   Updated: 2020/09/30 18:59:46 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Create a new list element, given element's content item. To enable generic
** support, content is a void pointer, but the user MUST ALWAYS be aware of the
** type and dereference the content accordingly.
**
** @param	content	=> the address of the item to be stored.
**
** @return	the newly allocated element, NULL if malloc failed.
*/

t_list	*ft_lstnew(void const *content)
{
	t_list *new;

	if (!(new = (t_list *)malloc(sizeof(*new))))
		return (NULL);
	new->content = (void *)content;
	new->next = NULL;
	return (new);
}
