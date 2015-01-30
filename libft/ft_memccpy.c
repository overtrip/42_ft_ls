/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 17:02:05 by jealonso          #+#    #+#             */
/*   Updated: 2014/11/05 16:07:48 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	unsigned char		*s1ptr;
	const unsigned char	*s2ptr;

	s1ptr = (unsigned char *)s1;
	s2ptr = (const unsigned char *)s2;
	while (n--)
	{
		*s1ptr = *s2ptr;
		s1ptr++;
		if (*s2ptr == (unsigned char)c)
			return (s1ptr);
		s2ptr++;
	}
	return (NULL);
}
