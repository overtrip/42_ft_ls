/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extention_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/24 19:07:37 by jealonso          #+#    #+#             */
/*   Updated: 2015/01/25 15:07:12 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_ls.h"

t_cl	*ft_create_elem(struct stat *file, char *d_name)
{
	t_cl	*new;

	if (!(new = (t_cl *)malloc(sizeof(t_cl))))
		return (NULL);
	new->file = file;
	new->d_name = d_name;
	new->next = NULL;
	return (new);
}

void	ft_print(t_cl *chain)
{
	if (chain)
		ft_putendl(chain->d_name);
}

void	ft_printl(t_cl *chain, t_max *save)
{
	ft_check(chain, save);
	ft_putchar('\n');
}

void	ft_check(t_cl *chain, t_max *save)
{
	ft_search_right(chain->file->st_mode);
	ft_search_link(chain->file->st_nlink, save);
	ft_search_user(chain->file->st_uid, save);
	ft_search_groups(chain->file->st_gid, save);
	ft_search_size(chain->file->st_size, save);
	ft_blocks(chain->file->st_blocks, 1, save);
	ft_search_date(&(chain->file->st_mtimespec), 0);
	ft_putstr(chain->d_name);
}

void	ft_optionr(t_cl *chain, t_max *save, int option)
{
	while ((chain = chain->next))
		if ((chain->file->st_mode & S_IFMT) == S_IFDIR)
		{
			ft_aff(chain->d_name, option, save);
			ft_putendl(chain->d_name);
		}
}
