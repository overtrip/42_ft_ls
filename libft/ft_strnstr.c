/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 18:24:40 by jealonso          #+#    #+#             */
/*   Updated: 2014/11/06 19:43:41 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	cmp_tf;
	size_t	cmp_str;

	cmp_tf = 0;
	cmp_str = 0;
	if (s2[cmp_tf] == '\0')
		return ((char *)s1);
	while (s1[cmp_str] && cmp_str < n)
	{
		while ((s1[cmp_str] == s2[cmp_tf]) && cmp_str < n)
		{
			if (s2[cmp_tf + 1] == '\0')
				return ((char *)&(s1[(cmp_str - cmp_tf)]));
			cmp_tf++;
			cmp_str++;
		}
		cmp_str = cmp_str - cmp_tf + 1;
		cmp_tf = 0;
	}
	return (NULL);
}
