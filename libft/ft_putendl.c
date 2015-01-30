/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 15:52:33 by jealonso          #+#    #+#             */
/*   Updated: 2014/11/10 11:35:32 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl(char const *s)
{
	int	cmp;

	cmp = 0;
	if (!s)
		return ;
	while (s[cmp] != '\0')
	{
		ft_putchar(s[cmp]);
		cmp++;
	}
	ft_putchar('\n');
}
