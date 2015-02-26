/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/05 15:36:07 by jealonso          #+#    #+#             */
/*   Updated: 2015/02/11 11:44:27 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_write_msg(char c)
{
	write(2, &c, 4);
	write(1, "\n", 1);

}
/*
int		ft_putexit(char *c, char *tabc)
{
	int i;

	i = 0;
	while()
}*/

void		ft_error(char *name)
{
	char *str;

	str = ft_strjoin("ft_ls: ", name);
	perror(str);
	free(str);
}
