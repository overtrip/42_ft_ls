/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extention_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/24 19:04:07 by jealonso          #+#    #+#             */
/*   Updated: 2015/01/25 14:59:27 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
/*
int		ft_si(char *a, char *b)
{
	return ((ft_strlen(ft_atoi(a))) > (ft_strlen(ft_atoi(b))) ? a : b);
}*/

void	ft_save_val(t_cl *chain, t_max *save)
{
	struct passwd	*f;
	struct group	*g;
	struct stat		*a;

	a = chain->file;
	f = getpwuid(a->st_uid);
	g = getgrgid(a->st_gid);
	while (chain)
	{
		if (a->st_nlink > save->slink)
			save->slink = a->st_nlink;
		if (ft_strlen(f->pw_name) > save->suser)
			save->suser = ft_strlen(f->pw_name);
		if (ft_strlen(g->gr_name) > save->sgroup)
			save->sgroup = ft_strlen(g->gr_name);
		if (a->st_size > save->ssize)
			save->ssize = a->st_size;
		chain = chain->next;
	}
}
