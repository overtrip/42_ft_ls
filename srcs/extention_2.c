/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extention_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/24 19:04:07 by jealonso          #+#    #+#             */
/*   Updated: 2015/06/10 17:27:12 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

unsigned int		ft_cmp_char(unsigned long nb)
{
	unsigned int	i;

	i = 1;
	while (nb / 10 && ++i)
		nb /= 10;
	return (i);
}

void				ft_save_val2(struct stat a, t_max *save,
									struct passwd *f, struct group *g)
{
	if (a.st_nlink > save->slink)
		save->slink = a.st_nlink;
	if (f && (ft_strlen(f->pw_name) > save->suser))
		save->suser = ft_strlen(f->pw_name);
	else if (ft_cmp_char(a.st_uid) > save->suser)
		save->suser = 10;
	if (g && ft_strlen(g->gr_name) > save->sgroup)
		save->sgroup = ft_strlen(g->gr_name);
	else if (ft_cmp_char(a.st_gid) > save->sgroup)
		save->sgroup = 10;
	if (ft_cmp_char(a.st_size) > save->ssize)
		save->ssize = ft_cmp_char(a.st_size);
	if (major(a.st_rdev) > save->major)
		save->major = major(a.st_rdev);
	if (minor(a.st_rdev) > save->minor)
		save->minor = minor(a.st_rdev);
}

void				ft_save_val(t_cl *chain, t_max *save, int option)
{
	struct passwd	*f;
	struct group	*g;
	struct stat		*a;

	while (chain)
	{
		f = getpwuid(chain->file->st_uid);
		g = getgrgid(chain->file->st_gid);
		if ((option & LS_A) || (!(option & LS_A) && chain->d_name[0] != '.'))
		{
			a = chain->file;
			ft_save_val2(*a, save, f, g);
			if (option & LS_A)
				save->sblock += a->st_blocks;
			else if (chain->d_name[0] != '.')
				save->sblock += a->st_blocks;
		}
		chain = chain->next;
	}
}

char				*ft_joinpath(char *d_name, char *path)
{
	if (ft_strequ(d_name, path))
		return (d_name);
	if (!(path[ft_strlen(path) - 1] == '/'))
		path = ft_strjoin(path, "/");
	return (ft_strjoin(path, d_name));
}

int					ft_printable(int option, t_cl *chain)
{
	if (!(option & LS_A))
	{
		while (chain)
		{
			if (chain->d_name[0] != '.')
				return (1);
			chain = chain->next;
		}
		return (0);
	}
	return (1);
}
