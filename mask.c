/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mask.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/24 19:08:04 by jealonso          #+#    #+#             */
/*   Updated: 2015/01/25 20:02:04 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_wright(int mask)
{
	if (mask == 0)
		ft_putstr("---");
	else if (mask == 1)
		ft_putstr("--x");
	else if (mask == 2)
		ft_putstr("-w-");
	else if (mask == 3)
		ft_putstr("-wx");
	else if (mask == 4)
		ft_putstr("r--");
	else if (mask == 5)
		ft_putstr("r-x");
	else if (mask == 6)
		ft_putstr("rw-");
	else if (mask == 7)
		ft_putstr("rwx");
}

void	ft_search_right(mode_t mode)
{
	int	mask;

	if ((mode & S_IFMT) == S_IFIFO)
		ft_putchar('p');
	else if ((mode & S_IFMT) == S_IFCHR)
		ft_putchar('c');
	else if ((mode & S_IFMT) == S_IFDIR)
		ft_putchar('d');
	else if ((mode & S_IFMT) == S_IFBLK)
		ft_putchar('b');
	else if ((mode & S_IFMT) == S_IFREG)
		ft_putchar('-');
	else if ((mode & S_IFMT) == S_IFLNK)
		ft_putchar('l');
	else if ((mode & S_IFMT) == S_IFSOCK)
		ft_putchar('s');
	mask = ((mode & S_IRWXU) / 64);
	ft_wright(mask);
	mask = ((mode & S_IRWXG) / 8);
	ft_wright(mask);
	mask = (mode & S_IRWXO);
	ft_wright(mask);
	ft_putstr("  ");
}

void	ft_putspace(int nb)
{
	while (nb--)
		ft_putchar(' ');
}

void	ft_init(t_max *save)
{
	save->sblock = 0;
	save->slink = 0;
	save->suser = 0;
	save->sgroup = 0;
	save->ssize = 0;
}
