/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 19:58:37 by jealonso          #+#    #+#             */
/*   Updated: 2014/11/07 16:25:43 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(char *str, char *to_find)
{
	int	cmp_tf;
	int cmp_str;

	cmp_tf = 0;
	cmp_str = 0;
	if (to_find[cmp_tf] == '\0')
		return (str);
	while (str[cmp_str])
	{
		while (str[cmp_str] == to_find[cmp_tf])
		{
			if (to_find[cmp_tf + 1] == '\0')
				return (&str[(cmp_str - cmp_tf)]);
			cmp_tf++;
			cmp_str++;
		}
		cmp_str = cmp_str - cmp_tf + 1;
		cmp_tf = 0;
	}
	return (NULL);
}
