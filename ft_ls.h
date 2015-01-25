/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/18 11:10:53 by jealonso          #+#    #+#             */
/*   Updated: 2015/01/25 15:07:24 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <pwd.h>
# include "libft/includes/libft.h"
# include <uuid/uuid.h>
# include <grp.h>
# include <time.h>
# include "ft_ls.h"
# include <unistd.h>

# define LS_A 1
# define LS_REC 2
# define LS_REV 4
# define LS_L 8
# define LS_T 16

typedef struct		s_max
{
	unsigned int	sblock;
	unsigned int	slink;
	unsigned int	suser;
	unsigned int	sgroup;
	unsigned int	ssize;
}					t_max;

typedef struct		s_cl
{
	struct s_cl		*next;
	char			*d_name;
	struct stat		*file;
}					t_cl;

t_cl				*ft_create_elem(struct stat *file, char *d_name);
void				ft_sort_cl(t_cl **begin, t_cl *new,
		int (*ft_comp)(t_cl *, t_cl *), t_max *save);
int					ft_comp_name(t_cl *file1, t_cl *file2);
int					ft_rcomp_name(t_cl *file1, t_cl *file2);
int					ft_comp_time(t_cl *file1, t_cl *file2);
int					ft_rcomp_time(t_cl *file1, t_cl *file2);
int					ft_get_op(int argc, char **argv, int *start);
void				ft_del_chain(t_cl **chain);
void				ft_aff_list(int option, t_cl *chain, t_max *save);
void				ft_sort_list(int option, t_cl *new, t_cl **chain,
		t_max *save);
void				ft_aff(char *d_name, int option, t_max *save);
void				ft_printl(t_cl *chain, t_max *save);
void				ft_print(t_cl *chain);
void				ft_check(t_cl *chain, t_max *save);
void				ft_search_date(struct timespec *time, int i);
void				ft_search_size(off_t size, t_max *save);
void				ft_search_groups(gid_t gid, t_max *save);
void				ft_search_user(uid_t uid, t_max *save);
void				ft_search_link(nlink_t link, t_max *save);
void				ft_blocks(blkcnt_t block, int flag, t_max *save);
void				ft_putspace(int nb);
void				ft_search_right(mode_t mode);
void				ft_wright(int mask);
void				ft_optionr(t_cl *chain, t_max *save, int option);
void				ft_save_val(t_cl *chain, t_max *save);

#endif
