/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 20:25:08 by abrabant          #+#    #+#             */
/*   Updated: 2020/09/30 19:21:59 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Delete a list element. Delete the content using the del function, then frees
** the memory allocated for the list element.
** WARNING: Even if element is considered as deleted, the element before the
** deleted one (if there's one) still have a pointer to the deleted one. As lst
** is passed by value, the pointer could not be set to NULL globally. User must
** be aware of this drawback and reorganize the list accordingly, otherwise
** segfaults will likely occur.
**
** @param	lst	=> the list element to delete.
** @param	del	=> a pointer to delete function used to delete element's
** content.
*/

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst && del)
	{
		del(lst->content);
		free(lst);
	}
}
