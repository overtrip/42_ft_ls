/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/18 11:10:53 by jealonso          #+#    #+#             */
/*   Updated: 2015/06/10 18:41:36 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/xattr.h>
# include <pwd.h>
# include "libft.h"
# include <uuid/uuid.h>
# include <grp.h>
# include <time.h>
# include <stdio.h>
# include "ft_ls.h"
# include <unistd.h>

# define LS_A 1
# define LS_REC 2
# define LS_REV 4
# define LS_L 8
# define LS_T 16
# define FIRST_ARG 32
# define ARGS 64
# define ARG 128
# define LS_G 256

# define BLACK				"\033[22;30m"
# define RED				"\033[22;31m"
# define GREEN				"\033[22;32m"
# define BROWN				"\033[22;33m"
# define BLUE				"\033[22;34m"
# define PURPLE				"\033[22;35m"
# define CYAN				"\033[22;36m"
# define LIGHT_GRAY			"\033[22;37m"
# define BOLD_BLACK 		"\e[22;40m"
# define BOLD_GREEN			"\e[22;42m"
# define BOLD_BROWN			"\e[22;43m"
# define BOLD_BLUE			"\e[22;44m"
# define BOLD_PURPLE		"\e[22;45m"
# define BOLD_CYAN			"\e[22;46m"
# define BOLD_LIGHT GRAY	"\e[22;47m"
# define BOLD_RED			"\e[22;41m"

# define YELLOW				"\033[02;33m"
# define DARK_GREY			"\033[01;30m"
# define BOLD_GRENN			"\e[22;42m"
# define BOLD_YELLOW		"\e[02;43m"
# define RESET				"\033[0m"

typedef struct		s_max
{
	unsigned int	sblock;
	unsigned int	slink;
	unsigned int	suser;
	unsigned int	sgroup;
	unsigned int	ssize;
	int				minor;
	int				major;
}					t_max;

typedef struct		s_cl
{
	struct s_cl		*next;
	char			*d_name;
	struct stat		*file;
	char			*path;

}					t_cl;

typedef struct		s_val
{
	int				i;
	int				j;
	int				k;
}					t_val;

typedef struct		s_flags
{
	int				mask;
	int				ret;
	char			c;
}					t_flags;

t_cl				*ft_create_elem(struct stat *file, char *d_nam, char *path);
void				ft_sort_cl(t_cl **begin, t_cl *new,
		int (*ft_comp)(t_cl *, t_cl *));
int					ft_comp_name(t_cl *file1, t_cl *file2);
int					ft_rcomp_name(t_cl *file1, t_cl *file2);
int					ft_comp_time(t_cl *file1, t_cl *file2);
int					ft_rcomp_time(t_cl *file1, t_cl *file2);
int					ft_get_op(char **argv, int *start);
void				ft_del_chain(t_cl **chain);
void				ft_aff_list(int option, t_cl *chain,
		t_max *save, char *path);
void				ft_sort_list(int option, t_cl *new, t_cl **chain);
void				ft_aff_folder(char *d_name, int *option, t_max *save);
void				ft_aff_file(int argc, char **argv, int start, int *option);
void				ft_printl(t_cl *chain, t_max *save, int option);
void				ft_print(t_cl *chain, int option);
void				ft_check(t_cl *chain, t_max *save, int option);
void				ft_aff_list_files(int option, t_cl *chain, t_max *save);
void				ft_search_date(struct timespec *time, int i);
void				ft_search_size(off_t size, t_max *save);
void				ft_search_groups(t_cl *chain, t_max *save);
void				ft_search_user(t_cl *chain, t_max *save);
void				ft_search_link(nlink_t link, t_max *save);
void				ft_putspace(int nb);
void				ft_search_right(mode_t mode, ssize_t nb);
void				ft_wright(int mask);
void				ft_optionr(t_cl *chain, t_max *save,
		int *option, char *path);
void				ft_save_val(t_cl *chain, t_max *save, int option);
unsigned int		ft_cmp_char(unsigned long nb);
void				ft_init(t_max *save);
char				*ft_joinpath(char *d_name, char *path);
int					ft_printable(int option, t_cl *chain);
void				ft_sort_param(int nb, char **tab,
		int (*c)(char const *, char const *));
int					ft_ascii_cmp_rev(char const *str1, char const *str2);
int					ft_ascii_cmp(char const *str1, char const *str2);
void				ft_error(char *name);
int					ft_putexit(char *str, char *tabc);
void				ft_free_chain(t_cl *chain);
void				ft_bad_permission(char *name);
void				ft_color(t_cl *chain);
int					ft_bfile(mode_t mode);
void				ft_color_repertories(t_cl *chain);
void				ft_color_directories(t_cl *chain);
void				ft_opt_ls_rec(t_cl *chain, t_max *save, int *option,
		char *d_name);
void				ft_sort_param_hub(int argc, char ***argv, int option,
		int start);
void				ft_badoption();
void				ft_search_t(unsigned int nb_maj, unsigned int nb_min
		, t_max *save);
void				ft_print_link(t_cl *chain);
void				*ft_init_index(t_val *index);
#endif
