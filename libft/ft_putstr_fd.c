/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 16:06:49 by jealonso          #+#    #+#             */
/*   Updated: 2014/11/09 17:17:59 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char const *s, int fd)
{
	int	cmp;

	cmp = 0;
	while (s[cmp] != '\0')
	{
		ft_putchar_fd(s[cmp], fd);
		cmp++;
	}
}
