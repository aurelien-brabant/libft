/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intconv.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 14:31:21 by abrabant          #+#    #+#             */
/*   Updated: 2020/11/22 13:34:37 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTCONV_H
# define INTCONV_H
# include "./types.h"

char	*ft_itoa(int n);
char	*ft_lltob(long long n, unsigned char base);
char	*ft_ulltob(unsigned long long n, unsigned char base);

#endif
