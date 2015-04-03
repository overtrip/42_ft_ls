/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/05 15:36:07 by jealonso          #+#    #+#             */
/*   Updated: 2015/04/03 17:05:15 by jealonso         ###   ########.fr       */
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
/*void	ft_bad_permission(mode_t mode, char *name)
{
	char *message;

	if ((mode & (S_IRUSR | S_IXUSR)) == (S_IRUSR | S_IXUSR))
	{
		ft_putchar('\n');
		ft_putstr(name);
		ft_putchar(':');
		ft_putstr("\nft_ls: ");
		message = ft_strjoin(name, ": Permission denied\n\n");
		ft_putstr(message);
	}
}*/
