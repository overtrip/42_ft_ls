/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/05 15:36:07 by jealonso          #+#    #+#             */
/*   Updated: 2015/04/08 15:54:39 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_write_msg(char c)
{
	write(2, &c, 4);
	write(1, "\n", 1);
}

void	ft_error(char *name)
{
	char	*str;

	str = ft_strjoin("ft_ls: ", name);
	perror(str);
	free(str);
}

void	ft_bad_permission(char *name)
{
	ft_putstr("\nls: ");
	ft_putstr(name);
	ft_putendl(": Permission denied");
}

void	ft_badoption(void)
{
	ft_putstr("ls: illegal option ");
	ft_putendl("\nusage: ls [-GRalrt] [file ...]");
}
