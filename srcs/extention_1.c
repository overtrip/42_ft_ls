/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extention_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/24 19:07:37 by jealonso          #+#    #+#             */
/*   Updated: 2015/04/02 15:47:27 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_cl	*ft_create_elem(struct stat *file, char *d_name)
{
	t_cl	*new;

	if (!(new = (t_cl *)malloc(sizeof(t_cl))))
		return (NULL);
	new->file = file;
	new->path = NULL;
	new->d_name = ft_strdup(d_name);
	new->next = NULL;
	return (new);
}

void	ft_print(t_cl *chain)
{
	if (chain)
	{
		if (LS_G)
		{
			ft_color(chain);
			ft_putchar('\n');
		}
		else
			ft_putendl(chain->d_name);
	}
}

void	ft_printl(t_cl *chain, t_max *save, int option)
{
	ft_check(chain, save, option);
	ft_putchar('\n');
}

void	ft_check(t_cl *chain, t_max *save, int option)
{
	char	*path;
	char	buf[512];
	int		ret;

	path = (chain->path != NULL) ? chain->path : chain->d_name;
	ft_search_right(chain->file->st_mode, path);
	ft_search_link(chain->file->st_nlink, save);
	ft_search_user(chain->file->st_uid, save);
	ft_search_groups(chain->file->st_gid, save);
	ft_search_size(chain->file->st_size, save);
	ft_search_date(&(chain->file->st_mtimespec), 0);
	if (option & LS_G)
		ft_color(chain);
	else
		ft_putstr(chain->d_name);
	if ((chain->file->st_mode & S_IFMT) == S_IFLNK)
	{
		ret = readlink(ft_strjoin("/", path), buf, 511);
		buf[ret] = '\0';
		ft_putstr(" -> ");
		ft_putstr(buf);
	}
}

void	ft_optionr(t_cl *chain, t_max *save, int *option, char *d_name)
{
	if ((chain->file->st_mode & S_IFMT) == S_IFDIR)
	{
		if (!ft_strequ(chain->d_name, ".") && !ft_strequ(chain->d_name, ".."))
		{
			chain->path = ft_joinpath(chain->d_name, d_name);
			ft_putchar('\n');
			ft_putstr(chain->path);
			ft_putstr(":\n");
			ft_aff_folder(chain->path, option, save);
		}
	}
}
