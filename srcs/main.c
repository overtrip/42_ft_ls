/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 17:36:17 by jealonso          #+#    #+#             */
/*   Updated: 2015/03/11 19:11:43 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			*ft_init_index(t_val *index)
{
	index->i = 1;
	index->j = 1;
	index->k = 1;
	return (index);
}

int				ft_get_op(char **argv, int *start)
{
	const int		tab[5] = {LS_A, LS_REC, LS_REV, LS_L, LS_T};
	const char		tabc[6] = {'a', 'R', 'r', 'l', 't', '\0'};
	t_val			index;
	int				ret;

	ft_init_index(&index);
	ret = 0;
	while (argv[index.i] && argv[index.i][0] == '-')
	{
		if (!argv[index.i++][1])
			continue ;
		index.i--;
		if (argv[index.i][1] == '-' && argv[index.i][2])
			return (-1);
		if (argv[index.i][1] == '-' && !argv[index.i][2])
		{
			index.i++;
			break ;
		}
		index.j = 0;
		while (argv[index.i][++index.j])
		{
			index.k = -1;
			while (tabc[++index.k])
			{
				if (tabc[index.k] == argv[index.i][index.j])
				{
					ret |= tab[index.k];
					break ;
				}
			}
			if (index.k == 5)
				return (-1);
		}
		index.i++;
	}
	*start = index.i;
	return (ret);
}

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
				ft_printl(chain, save);
			else
				ft_print(chain);
		}
		chain = chain->next;
	}
}

void			ft_aff_list(int option, t_cl *chain, t_max *save, char *path)
{
	char	*file;

	file = ft_strrchr(path, '/') ? ft_strrchr(path, '/') + 1 : path;
	if (ft_strequ(path, ".")
			|| (ft_strequ(path, "..") && (option & ARG))
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
				ft_printl(chain, save);
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

void			ft_opt_ls_rec(t_cl *chain, t_max *save,
		int *option, char *d_name)
{
	t_cl	*current;

	if (*(option) & LS_REC)
	{
		current = chain;
		while (current)
		{
			ft_optionr(current, save, option, d_name);
			current = current->next;
		}
	}
}

void			ft_aff_folder2(t_cl *chain, char *name, int *option, t_max save)
{
	ft_aff_list(*option, chain, &save, name);
	*option &= ~(FIRST_ARG);
	ft_opt_ls_rec(chain, &save, option, name);
}

void			ft_aff_folder(char *d_name, int *option, t_max *save)
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
			if (lstat(ft_joinpath(reading->d_name, d_name), info) == -1)
			{
				ft_error(reading->d_name);
				return ;
			}
			ft_sort_list(*option,
					ft_create_elem(info, reading->d_name), &chain);
		}
		ft_aff_folder2(chain, d_name, option, *save);
		closedir(tmp);
	}
}

void			ft_free_chain(t_cl *chain)
{
	t_cl	*save;

	save = chain;
	while (save)
	{
		save = chain->next;
		free(chain->d_name);
		free(chain->file);
		free(chain->path);
		free(chain);
		chain = save;
	}
}

void			ft_aff_file(int argc, char **argv, int start, int *option)
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
		{
			ft_error(argv[start]);
			return ;
		}
		if ((info->st_mode & S_IFMT) != S_IFDIR)
		{
			ft_sort_list(*option, ft_create_elem(info, argv[start]), &chain);
			*option &= ~(FIRST_ARG);
		}
		++start;
	}
	ft_aff_list_files(*option, chain, &save);
	ft_free_chain(chain);
}

void			ft_sort_param_hub(int argc, char ***argv, int option, int start)
{
	int	(*cmp)(char const *, char const *);

	cmp = (option & LS_REV) ? &ft_ascii_cmp_rev : &ft_ascii_cmp;
	ft_sort_param(argc - start, &argv[0][start], cmp);
}

int				main(int argc, char **argv)
{
	int		res_opt;
	int		start;
	t_max	save;

	start = 1;
	if ((res_opt = ft_get_op(argv, &start)) == -1)
		return (-1);
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
		ft_aff_folder(argv[start++], &res_opt, &save);
	}
	return (0);
}
