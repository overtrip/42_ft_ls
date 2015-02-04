/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 17:36:17 by jealonso          #+#    #+#             */
/*   Updated: 2015/02/04 19:37:57 by jealonso         ###   ########.fr       */
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

static void		ft_print_total(t_max *save)
{
	ft_putstr("total ");
	ft_putnbr(save->sblock);
	ft_putchar('\n');
}

void	ft_aff_list(int option, t_cl *chain, t_max *save, char *path)
{
	char	*file;

	file = ft_strrchr(path, '/') ? ft_strrchr(path, '/') + 1 : path;
	if (ft_strequ(path, ".") || (*file != '.' || option & LS_A))
	{
		if (!(option & FIRST_ARG) && (option & ARGS))
			ft_putchar('\n');
		if (option & ARGS)
		{
			ft_putstr(path);
			ft_putendl(":");
		}
		if (option & LS_L)
		{
			ft_save_val(chain, save, option);
			if (ft_printable(option, chain))
				ft_print_total(save);
		}
		while (chain)
		{
			if (option & LS_A || chain->d_name[0] != '.')
			{
				if (option & LS_L)
					ft_printl(chain, save);
				else
					ft_print(chain);
			}
			chain = chain->next;
		}
	}
}

void	ft_aff_list_files(int option, t_cl *chain, t_max *save)
{
	if (chain && option & LS_L)
		ft_save_val(chain, save, option);
	while (chain)
	{
		if (option & LS_A || chain->d_name[0] != '.')
		{
			if (option & LS_L)
				ft_printl(chain, save);
			else
				ft_print(chain);
		}
		chain = chain->next;
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

void	ft_aff_folder(char *d_name, int *option, t_max *save)
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
			ft_sort_list(*option, ft_create_elem(info, reading->d_name), &chain);
		}
		ft_aff_list(*option, chain, save, d_name);
		*option &= ~(FIRST_ARG);
		if (*option & LS_REC)
		{
			t_cl *current = chain;
			while (current)
			{
				ft_optionr(current, save, option, d_name);
				current = current->next;
			}
		}
		closedir(tmp);
	}
}

void	ft_aff_file(int argc, char **argv, int start, int *option)
{
	t_max		save;
	struct stat	*info;
	t_cl		*chain;

	chain = NULL;
	ft_init(&save);
	while (start < argc)
	{
		if (!(info = (struct stat*)malloc(sizeof(struct stat))))
			return ;
		if (lstat(argv[start], info) == -1)
			return ;
		if ((info->st_mode & S_IFMT) != S_IFDIR)
		{
			ft_sort_list(*option, ft_create_elem(info, argv[start]), &chain);
			*option &= ~(FIRST_ARG);
		}
		++start;
	}
	ft_aff_list_files(*option, chain, &save);
	//
	// TODO: free chain elems
	//
}

int		main(int argc, char **argv)
{
	int		res_opt;
	int		start;
	t_max	save;

	start = 1;
	if ((res_opt = ft_get_op(argc, argv, &start)) == -1)
		return (-1);
	res_opt |= FIRST_ARG;
	ft_sort_param(argc - 1, &argv[1]);
	if (start == argc)
		ft_aff_folder(".", &res_opt, &save);
	else
		ft_aff_file(argc, argv, start, &res_opt);
	while (start < argc)
	{
		res_opt |= ARGS;
		ft_aff_folder(argv[start++], &res_opt, &save);
	}
	return (0);
}
