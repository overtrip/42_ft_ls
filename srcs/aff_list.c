/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/03 17:06:28 by jealonso          #+#    #+#             */
/*   Updated: 2015/04/03 17:15:07 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ft_print_total(t_max *save)
{
	ft_putstr("total ");
	ft_putnbr(save->sblock);
	ft_putchar('\n');
}

void			ft_aff_list2(t_cl *chain, int option, t_max *save)
{
	while (chain)
	{
		if (option & LS_A || chain->d_name[0] != '.')
		{
			if (option & LS_L)
				ft_printl(chain, save, option);
			else
				ft_print(chain);
		}
		chain = chain->next;
	}
}

void			ft_aff_list(int option, t_cl *chain, t_max *save, char *path)
{
	char	*file;

	file = ft_strrchr(path, '/') ? ft_strrchr(path, '/') + 0 : path;
	if (ft_strequ(path, ".") || (ft_strequ(path, "..") && (option & ARG))
			|| (*file != '.' || option & LS_A))
	{
		if (option & ARGS)
		{
			if (!(option & FIRST_ARG))
				ft_putchar('\n');
			ft_putstr(path);
			ft_putendl(":");
		}
		if (option & LS_L)
		{
			chain->maxmin = 0;
			ft_save_val(chain, save, option);
			if (ft_printable(option, chain))
				ft_print_total(save);
		}
		ft_aff_list2(chain, option, save);
	}
}

void			ft_aff_list_files(int option, t_cl *chain, t_max *save)
{
	if (chain && option & LS_L)
		ft_save_val(chain, save, option);
	while (chain)
	{
		if (option & LS_A || chain->d_name[0] != '.')
		{
			if (option & LS_L)
				ft_printl(chain, save, option);
			else
				ft_print(chain);
		}
		chain = chain->next;
	}
}

void			ft_sort_list(int option, t_cl *new, t_cl **chain)
{
	if (option & LS_T)
	{
		if (option & LS_REV)
			ft_sort_cl(chain, new, &ft_rcomp_time);
		else
			ft_sort_cl(chain, new, &ft_comp_time);
	}
	else if (option & LS_REV)
		ft_sort_cl(chain, new, &ft_rcomp_name);
	else
		ft_sort_cl(chain, new, &ft_comp_name);
}
