/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   align_l.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/24 19:06:50 by jealonso          #+#    #+#             */
/*   Updated: 2015/06/10 18:01:47 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_search_link(nlink_t link, t_max *save)
{
	if (ft_strlen(ft_itoa(link)) < ft_strlen(ft_itoa(save->slink)))
		ft_putspace(ft_strlen(ft_itoa(save->slink)) -
				ft_strlen(ft_itoa(link)));
	ft_putnbr(link);
	ft_putchar(' ');
}

void	ft_search_user(t_cl *chain, t_max *save)
{
	struct passwd	*f;
	uid_t			uid;

	uid = chain->file->st_uid;
	f = getpwuid(uid);
	if (f)
	{
		ft_putstr(f->pw_name);
		ft_putspace(save->suser - ft_strlen(f->pw_name));
	}
	else
	{
		ft_putnbr(uid);
		ft_putspace(save->suser - ft_cmp_char(uid));
	}
	ft_putstr("  ");
}

void	ft_search_groups(gid_t gid, t_max *save)
{
	struct group	*f;

	f = getgrgid(gid);
	ft_putstr(f->gr_name);
	if (ft_strlen(f->gr_name) < save->sgroup)
		ft_putspace(save->sgroup - ft_strlen(f->gr_name));
	ft_putstr("  ");
}

void	ft_search_size(off_t size, t_max *save)
{
	if (ft_cmp_char(size) < save->ssize)
		ft_putspace((save->ssize) - ft_cmp_char(size));
	ft_putnbr_long(size);
	ft_putchar(' ');
}

void	ft_search_date(struct timespec *time, int i)
{
	char	*f;

	i = 4;
	f = ctime(&(time->tv_sec));
	while (i < 16)
	{
		ft_putchar(f[i]);
		i++;
	}
	ft_putchar(' ');
}
