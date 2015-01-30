/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 19:54:39 by jealonso          #+#    #+#             */
/*   Updated: 2014/11/06 21:37:15 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	char		*p;
	size_t		i;

	p = dst;
	i = 0;
	while (i < n && dst && src && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	while (i < n && dst && src)
	{
		dst[i] = '\0';
		i++;
	}
	return (p);
}
