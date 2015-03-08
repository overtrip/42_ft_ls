/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/05 15:36:07 by jealonso          #+#    #+#             */
/*   Updated: 2015/03/08 15:33:02 by jealonso         ###   ########.fr       */
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
