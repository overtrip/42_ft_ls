/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 17:08:12 by jealonso          #+#    #+#             */
/*   Updated: 2014/11/09 19:38:39 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	char	*save;

	if (!(s && f))
		return (NULL);
	if ((str = ft_strnew(ft_strlen(s))) && f)
	{
		save = str;
		while (*s)
		{
			*str = f(*s);
			s++;
			str++;
		}
		return (save);
	}
	return (NULL);
}
