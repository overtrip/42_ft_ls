/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extention_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/09 17:47:38 by jealonso          #+#    #+#             */
/*   Updated: 2015/06/09 18:24:18 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_print_link(t_cl *chain)
{
	char	buf[512];
	int		ret;

	if ((chain->file->st_mode & S_IFMT) == S_IFLNK)
	{
		ret = readlink(chain->path, buf, 511);
		buf[ret] = '\0';
		ft_putstr(" -> ");
		ft_putstr(buf);
	}
}

void	ft_search_t(unsigned int nb_maj, unsigned int nb_min, t_max *save)
{
	if (ft_cmp_char(nb_maj) < ft_cmp_char(save->major))
		ft_putspace(ft_cmp_char(save->major) - ft_cmp_char(nb_maj));
	ft_putnbr(nb_maj);
	ft_putstr(", ");
	if (ft_cmp_char(nb_min) < ft_cmp_char(save->minor))
		ft_putspace(ft_cmp_char(save->minor) - ft_cmp_char(nb_min));
	ft_putnbr(nb_min);
	ft_putchar(' ');
}

void	*ft_init_index(t_val *index)
{
	index->i = 1;
	index->j = 0;
	index->k = 1;
	return (index);
}
