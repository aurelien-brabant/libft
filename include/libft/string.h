/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 13:41:21 by abrabant          #+#    #+#             */
/*   Updated: 2021/03/25 21:20:42 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_H
#define STRING_H
#include <stddef.h>
#include "libft/internal/string_int.h"

/* abstraction */
typedef void *t_string;

/*
** Create a new t_string object, using a null terminated C-string for
** initialization. The size of the t_string object will be strlen(cstring).
*/

t_string		ft_string_new_cstr(const char *cstring);

/*
** Create a new t_string object of size n and fill this string with the
** character c.
*/

t_string		ft_string_new_fill(size_t n, const char c);

/*
** Output a string on a given file descriptor. Returns the number of characters
** written, or -1 if an error occured. The return value is the one returned by
** the write syscall, see write(3) for more informations.
*/

int				ft_string_output(t_string str, int fd);

/*
** Convert the string represented by str into a C null terminated version
** of it. This string is allocated by malloc, and therefore needs to be freed
** if required.
*/

char			*ft_string_tocstring(t_string str);

/*
** Append the content of str2 to str. The content of str2 is leaved unchanged,
** while a copy of str2 is added as the end of str.
** No additional dynamic memory allocation is done, and only str1 is modified.
*/

void			ft_string_append(t_string str, t_string str2);

/*
** Append a string terminated by a null byte, also called C string, to the
** str t_string object. No new t_string object is created, so nothing is
** returned.
*/

void			ft_string_append_cstr(t_string str, const char *cstr);

/*
** Get the address of the char at index i of str.
*/

unsigned char	*ft_string_at(t_string str, size_t i);

/*
** Get the number of characters in the string
*/

size_t			ft_string_length(t_string str);

/*
** Get the length of a string. Returns the same value than ft_string_length.
*/

size_t			ft_string_size(t_string str);

/*
** Return the allocated storage (in bytes) for the str
*/

size_t			ft_string_capacity(t_string str);

/*
** Destroy a t_string object, freeing memory allocated for it.
*/

t_string		ft_string_destroy();

#endif
