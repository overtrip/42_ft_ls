/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 15:52:33 by jealonso          #+#    #+#             */
/*   Updated: 2014/11/10 11:57:45 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char const *s, int fd)
{
	int	cmp;

	cmp = 0;
	if (!s)
		return ;
	while (s[cmp] != '\0')
	{
		ft_putchar_fd(s[cmp], fd);
		cmp++;
	}
	ft_putchar_fd('\n', fd);
}
