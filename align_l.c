/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   align_l.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/24 19:06:50 by jealonso          #+#    #+#             */
/*   Updated: 2015/01/25 15:04:06 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdio.h>

void	ft_search_link(nlink_t link,  t_max *save)
{
/*	if (flag == 0)
	{
		if (ft_strlen(ft_itoa(link)) > ft_strlen(ft_itoa(save->slink)))
			save->slink = link;
			ft_putnbr(save->slink);
			ft_putchar('\n');
	}
	else if (flag == 1)
	{*/
		if (ft_strlen(ft_itoa(link)) < ft_strlen(ft_itoa(save->slink)))
			ft_putspace(ft_strlen(ft_itoa(save->slink)) -
					ft_strlen(ft_itoa(link)));
		ft_putstr(ft_itoa(link));
		ft_putchar(' ');
	//}
}

void	ft_search_user(uid_t uid,  t_max *save)
{
	struct passwd	*f;

	f = getpwuid(uid);
/*	if (flag == 0)
	{
		if (ft_strlen(f->pw_name) > save->suser)
			save->suser = ft_strlen(f->pw_name);
	}
	else if (flag == 1)
	{*/
		if (ft_strlen(f->pw_name) < save->suser)
			ft_putspace(ft_strlen(ft_itoa(save->suser)) -
					ft_strlen(f->pw_name));
		ft_putstr(f->pw_name);
		ft_putstr("  ");
//	}
}

void	ft_search_groups(gid_t gid,  t_max *save)
{
	struct group	*f;

	f = getgrgid(gid);
/*	if (flag == 0)
	{
		if (ft_strlen(f->gr_name) > save->sgroup)
			save->sgroup = ft_strlen(f->gr_name);
	}
	else if (flag == 1)
	{*/
		if (ft_strlen(f->gr_name) < save->sgroup)
			ft_putspace(ft_strlen(ft_itoa(save->sgroup)) -
					ft_strlen(f->gr_name));
		ft_putstr(f->gr_name);
		ft_putstr("  ");
//	}
}

void	ft_search_size(off_t size,  t_max *save)
{
/*	if (flag == 0)
	{
		if (ft_strlen(ft_itoa(size)) > (save->ssize))
			save->ssize = size;
	}
	else if (flag == 1)
	{*/
		if (ft_strlen(ft_itoa(size)) < ft_strlen(ft_itoa(save->ssize)))
			ft_putspace(ft_strlen(ft_itoa(save->ssize)) -
					ft_strlen(ft_itoa(size)));
		ft_putstr(ft_itoa(size));
		ft_putchar(' ');
//	}
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
