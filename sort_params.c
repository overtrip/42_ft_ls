/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_params.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/02 15:35:02 by jealonso          #+#    #+#             */
/*   Updated: 2015/02/05 16:51:07 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <string.h>

int		ft_ascii_cmp_rev(char const *str1, char const *str2)
{
	return (strcmp(str1, str2) < 0);
}

int		ft_ascii_cmp(char const *str1, char const *str2)
{
	return (strcmp(str1, str2) > 0);
}

void	ft_sort_param(int nb, char **tab, int (*c)(char const *, char const *))
{
	char	*tmp;
	int		i;

	i = 0;
	while (i < nb - 1)
	{
		if (c(tab[i], tab[i + 1]))
		{
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp;
			i = 0;
		}
		else
			i++;
	}
}
