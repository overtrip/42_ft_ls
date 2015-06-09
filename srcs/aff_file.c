/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/03 17:17:17 by jealonso          #+#    #+#             */
/*   Updated: 2015/06/08 18:34:35 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			ft_aff_folder2(t_cl *chain, char *name, int *option, t_max save)
{
	ft_aff_list(*option, chain, &save, name);
	*option &= ~(FIRST_ARG);
	ft_opt_ls_rec(chain, &save, option, name);
}

void			ft_aff_folder(char *d_name, int *opt, t_max *save)
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
				ft_error(reading->d_name);
			if (lstat(ft_joinpath(reading->d_name, d_name), info) == -1)
				return ;
			ft_sort_list(*opt, ft_create_elem(info, reading->d_name,
						ft_joinpath(reading->d_name, d_name)), &chain);
		}
		ft_aff_folder2(chain, d_name, opt, *save);
		closedir(tmp);
	}
	else
		ft_bad_permission(d_name);
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
			ft_error(argv[start++]);
			continue ;
		}
		if ((info->st_mode & S_IFMT) != S_IFDIR)
		{
			ft_sort_list(*option, ft_create_elem(info, argv[start]
						, ft_strdup(argv[start])), &chain);
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
