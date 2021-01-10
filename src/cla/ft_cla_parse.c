/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cla_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 21:34:03 by abrabant          #+#    #+#             */
/*   Updated: 2021/01/10 15:49:15 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft/cla.h"
#include "libft/string.h"
#include "libft/strconv.h"
#include "libft/internal/cla_int.h"

static void parse_bools(t_cla *cla)
{
	int		i;
	int		j;
	char	*opt;

	opt = NULL;
	i = 0;
	while (cla->bools[i].key != NULL)
	{
		opt = ft_strjoin("--", cla->bools[i].key);
		*(cla->bools[i].ptr) = cla->bools[i].dflt;
		j = 0;
		while (j < cla->ac)
			if (ft_strcmp(opt, cla->av[j++]) == 0)
				*(cla->bools[i].ptr) = true; 
		++i;
	}
	free(opt);
}

static void parse_strs(t_cla *cla)
{
	int		i;
	int		j;
	char	*tmp;
	char	*opt;

	opt = NULL;
	i = 0;
	while (cla->strs[i].key != NULL)
	{
		tmp = ft_strjoin("--", cla->strs[i].key);
		opt = ft_strjoin(tmp, "=");
		free(tmp);
		*(cla->strs[i].ptr) = (char *)cla->strs[i].dflt;
		j = 0;
		while (j < cla->ac)
			if (ft_strhsprfx(cla->av[j++], opt))
				*(cla->strs[i].ptr) = ft_strchr(cla->av[j - 1], '=') + 1; 
		++i;
	}
	free(opt);
}

static void parse_ints(t_cla *cla)
{
	int		i;
	int		j;
	char	*tmp;
	char	*opt;

	i = 0;
	opt = NULL;
	while (cla->ints[i].key != NULL)
	{
		tmp = ft_strjoin("--", cla->ints[i].key);
		opt = ft_strjoin(tmp, "=");
		free(tmp);
		*(cla->ints[i].ptr) = cla->ints[i].dflt;
		j = 0;
		while (j < cla->ac)
			if (ft_strhsprfx(cla->av[j++], opt)) 
				*(cla->ints[i].ptr) = 
					ft_atoi(ft_strchr(cla->av[j - 1], '=') + 1);
		++i;
	}
	free(opt);
}

static void	parse_pos(t_cla *cla)
{
	int	i;
	int	j;
	int	index;

	i = 0;
	while (cla->pos[i].index != -1)
	{
		index = cla->pos[i].index;
		*cla->pos[i].ptr = (char *)cla->pos[i].dflt;
		j = 0;
		while (j < cla->ac)
		{
			if (!ft_strhsprfx(cla->av[j], "--"))
				if (index-- == 0)
					break ;
			++j;
		}
		if (index == -1 && j < cla->ac)
			*cla->pos[i].ptr = cla->av[j];
		++i;
	}
}

void	ft_cla_parse(void *cla)
{
	t_cla	*cla_ptr;

	cla_ptr = (t_cla *) cla;
	parse_bools(cla);
	parse_strs(cla);
	parse_ints(cla);
	parse_pos(cla);
	free(cla_ptr);
}
