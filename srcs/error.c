/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/05 15:36:07 by jealonso          #+#    #+#             */
/*   Updated: 2015/06/10 18:26:04 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_error(char *name)
{
	char	*str;

	str = ft_strjoin("ft_ls: ", name);
	perror(str);
	free(str);
}

void	ft_bad_permission(char *name)
{
	ft_putstr_fd("ft_ls: ", 2);
	ft_putstr_fd(name, 2);
	ft_putendl_fd(": Permission denied", 2);
}

void	ft_badoption(void)
{
	ft_putstr_fd("ft_ls: illegal option ", 2);
	ft_putendl_fd("\nusage: ls [-GRalrt] [file ...]", 2);
}
