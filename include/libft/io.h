/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 14:33:15 by abrabant          #+#    #+#             */
/*   Updated: 2020/12/12 17:19:43 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IO_H
# define IO_H
# include "./types.h"
# include <stdarg.h>

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
int		ft_gnl(int fd, char **line);

/*
** printf family, including "v" variants.
*/

int		ft_printf(const char *fmt,
							...) __attribute__((format(printf,1,2)));

int		ft_sprintf(char *str, const char *fmt,
							...) __attribute__((format(printf,2,3)));

int		ft_snprintf(char *str, size_t len, const char *fmt,
							...) __attribute__((format(printf,3,4)));

int		ft_dprintf(int fd, const char *fmt,
							...) __attribute__((format(printf,2,3)));

int		ft_vprintf(const char *fmt, va_list ap);

int		ft_vsprintf(char *str, const char *fmt, va_list ap);

int		ft_vsnprintf(char *str, size_t len, const char *fmt, va_list ap);

int		ft_vdprintf(int fd, const char *fmt, va_list ap);

#endif
