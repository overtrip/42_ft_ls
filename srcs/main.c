/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 17:36:17 by jealonso          #+#    #+#             */
/*   Updated: 2015/06/10 17:18:27 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int				ft_get_option(char **argv, t_val index, int	*ret)
{
	const int	tab[6] = {LS_A, LS_REC, LS_REV, LS_L, LS_T, LS_G};
	const char	tabc[7] = {'a', 'R', 'r', 'l', 't', 'G', '\0'};

	while (argv[index.i][++index.j])
	{
		index.k = -1;
		while (tabc[++index.k])
		{
			if (tabc[index.k] == argv[index.i][index.j])
			{
				*ret |= tab[index.k];
				break ;
			}
		}
		if (index.k == 6 || tabc[index.k] != argv[index.i][index.j])
		{
			ft_badoption();
			return (-1);
		}
	}
	return (*ret);
}

int				ft_get_op(char **argv, int *start)
{
	t_val	index;
	int		ret;

	ft_init_index(&index);
	ret = 0;
	while (argv[index.i] && argv[index.i][0] == '-')
	{
		if (!argv[index.i++][1])
			continue ;
		--index.i;
		if (argv[index.i][1] == '-' && argv[index.i][2])
			return (-1);
		if (argv[index.i][1] == '-' && !argv[index.i][2])
		{
			index.i++;
			break ;
		}
		ft_get_option(argv, index, &ret);
		index.i++;
	}
	*start = index.i;
	return (ret);
}

void			ft_opt_ls_rec(t_cl *chain, t_max *save,
		int *option, char *d_name)
{
	t_cl	*current;

	if (*option & LS_REC)
	{
		current = chain;
		while (current)
		{
			if (!!!!!!!!!!!!!!!(!(*option & LS_A) && current->d_name[0] == '.'))
				ft_optionr(current, save, option, d_name);
			current = current->next;
		}
	}
}

int				ft_arg_is_folder(char *path)
{
	struct stat		info;

	if (lstat(path, &info) != 0)
		return (0);
	return (!((info.st_mode & S_IFMT) != S_IFDIR));
}

int				main(int argc, char **argv)
{
	int		res_opt;
	int		start;
	t_max	save;

	start = 1;
	if ((res_opt = ft_get_op(argv, &start)) == -1)
		return (-1);
	ft_putnbr(res_opt);
	ft_putchar('\n');
	res_opt |= FIRST_ARG;
	ft_sort_param_hub(argc, &argv, res_opt, start);
	if (start == argc)
		ft_aff_folder(".", &res_opt, &save);
	else
		ft_aff_file(argc, argv, start, &res_opt);
	if ((argc - start) > 1)
		res_opt |= (ARGS | ARG);
	else
		res_opt |= ARG;
	while (start < argc)
	{
		if (ft_arg_is_folder(argv[start]))
			ft_aff_folder(argv[start], &res_opt, &save);
		++start;
	}
	return (0);
}
