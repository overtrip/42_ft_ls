/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extention_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/24 19:04:07 by jealonso          #+#    #+#             */
/*   Updated: 2015/01/25 20:02:02 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

unsigned int		ft_cmp_char(unsigned long nb)
{
	unsigned int i = 1;

	while (nb / 10)
	{
		i++;
		nb /= 10;
	}
	return (i);
}

void	ft_save_val(t_cl *chain, t_max *save, int option)
{
	struct passwd	*f;
	struct group	*g;
	struct stat		*a;

	f = getpwuid(chain->file->st_uid);
	g = getgrgid(chain->file->st_gid);

	while (chain)
	{
		a = chain->file;
		if (a->st_nlink > save->slink)
			save->slink = a->st_nlink;
		if (ft_strlen(f->pw_name) > save->suser)
			save->suser = ft_strlen(f->pw_name);
		if (ft_strlen(g->gr_name) > save->sgroup)
			save->sgroup = ft_strlen(g->gr_name);
		if (ft_cmp_char(a->st_size) > save->ssize)
			save->ssize = ft_cmp_char(a->st_size);
		if (option & LS_A)
			save->sblock += a->st_blocks;
		else if (chain->d_name[0] != '.')
			save->sblock += a->st_blocks;
		chain = chain->next;
	}
}
