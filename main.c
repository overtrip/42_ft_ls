/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 17:36:17 by jealonso          #+#    #+#             */
/*   Updated: 2015/01/28 17:45:44 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_get_op(int argc, char **argv, int *start)
{
	const int		tab[5] = {LS_A, LS_REC, LS_REV, LS_L, LS_T};
	const char		tabc[6] = {'a', 'R', 'r', 'l', 't', '\0'};
	int				i;
	int				j;
	int				k;
	int				ret;

	argc = argc;
	ret = 0;
	i = 1;
	while (argv[i] && argv[i][0] == '-')
	{
		if (!argv[i++][1])
			continue ;
		i--;
		if (argv[i][1] == '-' && argv[i][2])
			return (-1);
		if (argv[i][1] == '-' && !argv[i][2])
		{
			i++;
			break ;
		}
		j = 0;
		while (argv[i][++j])
		{
			k = -1;
			while (tabc[++k])
			{
				if (tabc[k] == argv[i][j])
				{
					ret |= tab[k];
					break ;
				}
			}
			if (k == 5)
				return (-1);
		}
		i++;
	}
	*start = i;
	return (ret);
}

void	ft_aff_list(int option, t_cl *chain, t_max *save, char *path)
{
	if (option & LS_L)
	{
		ft_save_val(chain, save, option);
		ft_putstr("total ");
		ft_putnbr(save->sblock);
		ft_putchar('\n');
	}
	if (ft_strequ(path, ".") || ((path = ft_strrchr(path, '/')) && path[1] != '.' ))
	{
		while (chain)
		{
			if (option & LS_A || (*chain).d_name[0] != '.')
			{
				if (option & LS_L)
					ft_printl(chain, save);
				else
					ft_print(chain);
			}
			chain = chain->next;
		}
		if (option & LS_REC)
			ft_putchar('\n');
	}
}

void	ft_sort_list(int option, t_cl *new, t_cl **chain)
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

void	ft_aff(char *d_name, int option, t_max *save)
{
	DIR				*tmp;
	struct dirent	*reading;
	struct stat		*info;
	t_cl			*chain;

	chain = NULL;
	ft_init(save);
	if ((tmp = opendir(d_name)))
	{
		while ((reading = readdir(tmp)))
		{
			if (!(info = (struct stat *)malloc(sizeof(struct stat))))
				return ;
			if (lstat(ft_joinpath(reading->d_name,d_name), info) == -1)
				return ;
			ft_sort_list(option, ft_create_elem(info, reading->d_name), &chain);
		}
		ft_aff_list(option, chain, save, d_name);
		if (option & LS_REC)
		{
			t_cl *current = chain->next;
			while (current)
			{
				ft_optionr(current, save, option, d_name);
				current = current->next;
			}
		}
		closedir(tmp);
	}
}

int		main(int argc, char **argv)
{
	int		res_opt;
	int		start;
	t_max	save;

	start = 1;
	if ((res_opt = ft_get_op(argc, argv, &start)) == -1)
		return (-1);
	if (start == argc)
		ft_aff(".", res_opt, &save);
	while (start < argc)
		ft_aff(argv[start++], res_opt, &save);
	return (0);
}
