/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   align_l.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/24 19:06:50 by jealonso          #+#    #+#             */
/*   Updated: 2015/03/26 15:08:12 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_search_link(nlink_t link, t_max *save)
{
	if (ft_strlen(ft_itoa(link)) < ft_strlen(ft_itoa(save->slink)))
		ft_putspace(ft_strlen(ft_itoa(save->slink)) -
				ft_strlen(ft_itoa(link)));
	ft_putstr(ft_itoa(link));
	ft_putchar(' ');
}

void	ft_search_user(uid_t uid, t_max *save)
{
	struct passwd	*f;

	f = getpwuid(uid);
	if (ft_strlen(f->pw_name) < save->suser)
	{
		ft_putstr(f->pw_name);
		ft_putspace(ft_strlen(ft_itoa(save->suser)) - ft_strlen(f->pw_name));
	}
	else
		ft_putstr(f->pw_name);
	ft_putstr("  ");
}

void	ft_search_groups(gid_t gid, t_max *save)
{
	struct group	*f;

	f = getgrgid(gid);
	if (ft_strlen(f->gr_name) < save->sgroup)
		ft_putspace(ft_strlen(ft_itoa(save->sgroup)) - ft_strlen(f->gr_name));
	ft_putstr(f->gr_name);
	ft_putstr("  ");
}

void	ft_search_size(off_t size, t_max *save)
{
	if (ft_cmp_char(size) < save->ssize)
		ft_putspace((save->ssize) - ft_cmp_char(size));
	ft_putstr(ft_itoa(size));
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
