/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comp_tri.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/24 19:07:16 by jealonso          #+#    #+#             */
/*   Updated: 2015/02/25 20:20:29 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_sort_cl(t_cl **begin, t_cl *new, int (*ft_comp)(t_cl *, t_cl *))
{
	t_cl	*tmp;

	tmp = *begin;
	if (!tmp || ft_comp(tmp, new) > 0)
	{
		new->next = tmp;
		*begin = new;
		return ;
	}
	while (tmp->next)
	{
		if (ft_comp(tmp->next, new) > 0)
		{
			new->next = tmp->next;
			tmp->next = new;
			return ;
		}
		tmp = tmp->next;
	}
	tmp->next = new;
}

int		ft_comp_name(t_cl *file1, t_cl *file2)
{
	return (ft_strcmp(file1->d_name, file2->d_name));
}

int		ft_rcomp_name(t_cl *file1, t_cl *file2)
{
	return (-ft_strcmp(file1->d_name, file2->d_name));
}

int		ft_comp_time(t_cl *file1, t_cl *file2)
{
	if (file1->file->st_mtimespec.tv_sec == file2->file->st_mtimespec.tv_sec)
		return (ft_strcmp(file1->d_name, file2->d_name));
	return ((file1->file->st_mtimespec.tv_sec) >
	(file2->file->st_mtimespec.tv_sec) ? -1 : 1);
}

int		ft_rcomp_time(t_cl *file1, t_cl *file2)
{
	return (-ft_comp_time(file1, file2));
}
