/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/02 14:44:51 by jealonso          #+#    #+#             */
/*   Updated: 2015/04/03 17:04:47 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int						ft_cfile(mode_t mode)
{
	if ((((mode & (S_IXUSR | S_ISUID)) == S_IXUSR) ||
			((mode & (S_IXGRP | S_ISGID)) == S_IXGRP) ||
			((mode & (S_IXOTH | S_ISVTX)) == S_IXOTH)) && (ft_bfile(mode) == 0))
		return (1);
	return (0);
}

int						ft_brep(mode_t mode)
{
	if (((mode & (S_ISVTX | S_IXOTH)) ==
				(S_ISVTX | S_IXOTH) && (mode & S_IWOTH) == S_IWOTH))
		return (1);
	if ((mode & S_IWOTH) == S_IWOTH)
		return (2);
	return (0);
}

int						ft_crepertories(mode_t mode)
{
	if ((mode & S_IWOTH) == S_IWOTH)
		return (1);
	return (0);
}

void					ft_color_directories(t_cl *chain)
{
	(ft_crepertories(chain->file->st_mode) == 1) ?
		ft_putstr(RESET) : ft_putstr(BLUE);
	if (ft_brep(chain->file->st_mode) > 0)
		(ft_brep(chain->file->st_mode) == 1) ?
			ft_putstr(BOLD_GREEN) : ft_putstr(BOLD_YELLOW);
}

void					ft_color_repertories(t_cl *chain)
{
	(ft_cfile(chain->file->st_mode) == 1) ?
		ft_putstr(RED) : ft_putstr(RESET);
	if (ft_bfile(chain->file->st_mode) > 0)
		(ft_bfile(chain->file->st_mode) == 1) ?
			ft_putstr(BOLD_RED) : ft_putstr(BOLD_CYAN);
}
