/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 22:09:27 by abrabant          #+#    #+#             */
/*   Updated: 2020/09/30 15:37:07 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Loop over lst and apply f on every element's content,
** creating a new list with the modified content.
**
** @param lst	=> The original list we'll map over.
** @param f		=> The function applied on each element's content.
** @param del	=> Used in the call of ft_lstclear in case an allocation error
** 				is encountered. The subject tells to return NULL if there's an
**				allocation error, but it's even wiser to destroy the newly
**				created list if one allocation problem occured, as we'll not
**				return it anyway (it would be leak). However, the original list
**				will never be affected.
**
** @return the new list, or NULL if allocation error occured.
*/

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_head;
	t_list	*new_current;

	if (!lst || !f || !(new_head = ft_lstnew(f(lst->content))))
		return (NULL);
	new_current = new_head;
	lst = lst->next;
	while (lst)
	{
		if (!(new_current->next = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&new_head, del);
			break ;
		}
		lst = lst->next;
		new_current = new_current->next;
	}
	return (new_head);
}
