/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 11:11:48 by jealonso          #+#    #+#             */
/*   Updated: 2014/11/09 19:39:03 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	char	*save;
	int		i;

	i = 0;
	if (!(s && f))
		return (NULL);
	if ((str = ft_strnew(ft_strlen(s))) && f)
	{
		save = str;
		while (*s)
		{
			*str = f(i, *s);
			s++;
			str++;
			i++;
		}
		return (save);
	}
	return (NULL);
}
