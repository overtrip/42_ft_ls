/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mask.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/24 19:08:04 by jealonso          #+#    #+#             */
/*   Updated: 2015/03/31 18:37:28 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static const t_flags    g_sf[] =
{
	{S_IFMT, S_IFBLK, 'b'}, {S_IFMT, S_IFCHR, 'c'}, {S_IFMT, S_IFLNK, 'l'},
	{S_IFMT, S_IFDIR, 'd'}, {S_IFMT, S_IFSOCK, 's'}, {S_IFMT, S_IFIFO, 'p'},
	{S_IFMT, S_IFREG, '-'}, {S_IRUSR, S_IRUSR, 'r'}, {S_IRUSR, 0, '-'},
	{S_IWUSR, S_IWUSR, 'w'}, {S_IWUSR, 0, '-'},
	{S_ISUID | S_IXUSR, S_ISUID | S_IXUSR, 's'},
	{S_ISUID | S_IXUSR, S_ISUID, 'S'},
	{S_IXUSR | S_ISUID, S_IXUSR, 'x'}, {S_IXUSR | S_ISUID, 0, '-'},
	{S_IRGRP, S_IRGRP, 'r'}, {S_IRGRP, 0, '-'}, {S_IWGRP, S_IWGRP, 'w'},
	{S_IWGRP, 0, '-'}, {S_ISGID | S_IXGRP, S_ISGID | S_IXGRP, 's'},
	{S_ISGID | S_IXGRP, S_ISGID, 'S'}, {S_IXGRP | S_ISGID, S_IXGRP, 'x'},
	{S_IXGRP | S_ISGID, 0, '-'}, {S_IROTH, S_IROTH, 'r'}, {S_IROTH, 0, '-'},
	{S_IWOTH, S_IWOTH, 'w'}, {S_IWOTH, 0, '-'},
	{S_ISVTX | S_IXOTH, S_ISVTX | S_IXOTH, 't'},
	{S_ISVTX | S_IXOTH, S_ISVTX, 'T'}, {S_IXOTH | S_ISVTX, S_IXOTH, 'x'},
	{S_IXOTH | S_ISVTX, 0, '-'}, {0, 0, 0}
};

/*void			ft_error(char *content, char *error)
{
	ft_putstr_fd("ls: ", 2);
	ft_putstr_fd(content, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(error, 2);
}*/
void					ft_search_right(mode_t modes, char *path)
{
	int	i;
	size_t	ext;

	i = 0;
	while (g_sf[i].c != 0)
	{
		if ((modes & g_sf[i].mask) == g_sf[i].ret)
			ft_putchar(g_sf[i].c);
		i++;
	}
	ext = listxattr(path, NULL, 0, XATTR_NOFOLLOW);
	if (ext	> 0)
		ft_putchar('@');
	else
		ft_putchar(' ');
	ft_putchar(' ');
}

void					ft_putspace(int nb)
{
	while (nb--)
		ft_putchar(' ');
}

void					ft_init(t_max *save)
{
	save->sblock = 0;
	save->slink = 0;
	save->suser = 0;
	save->sgroup = 0;
	save->ssize = 0;
}

int						ft_bfile(mode_t mode)
{
	if ((mode & (S_ISUID | S_IXUSR)) == (S_ISUID | S_IXUSR))
	{
		ft_putstr(BOLD_RED);
		return (1);
	}
	if (((mode & (S_ISGID | S_IXGRP)) == (S_ISGID | S_IXGRP)) ||
			((mode & (S_ISVTX | S_IXOTH)) == (S_ISVTX | S_IXOTH)))
	{
		ft_putstr(BOLD_CYAN);
		return (2);
	}
	return (0);
}

int						ft_cfile(mode_t mode)
{

	if ((((mode & (S_IXUSR | S_ISUID)) == S_IXUSR) ||
			((mode & (S_IXGRP | S_ISGID)) == S_IXGRP) ||
			((mode & (S_IXOTH | S_ISVTX)) == S_IXOTH)) && (ft_bfile(mode) == 0))
		return (1);
	return (0);
}

void					ft_color_repertories(t_cl *chain)
{
	(ft_cfile(chain->file->st_mode) == 1) ?
		ft_putstr(RED) : ft_putstr(RESET);
	if (ft_bfile(chain->file->st_mode) > 0)
		(ft_bfile(chain->file->st_mode) == 1) ?
			ft_putstr(BOLD_RED) : ft_putstr(BOLD_CYAN);
	ft_putstr(chain->d_name);
}

void					ft_color(t_cl *chain)
{
	if ((chain->file->st_mode & S_IFMT) == S_IFDIR)
	{
		ft_putstr(BLUE);
		ft_putstr(chain->d_name);
	}
	else if ((chain->file->st_mode & S_IFMT) == S_IFREG)
		ft_color_repertories(chain);
	else if ((chain->file->st_mode & S_IFMT) == S_IFLNK)
	{
		ft_putstr(PURPLE);
		ft_putstr(chain->d_name);
	}
	else if ((chain->file->st_mode & S_IFMT) == S_IFIFO)
	{
		ft_putstr(YELLOW);
		ft_putstr(chain->d_name);
	}
	else
		ft_putstr(chain->d_name);
	ft_putstr(RESET);
}
