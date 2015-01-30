/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 19:55:18 by jealonso          #+#    #+#             */
/*   Updated: 2014/11/06 19:56:11 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int			i;
	const char	*ptr;

	i = 0;
	ptr = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			ptr = (s + i);
		i++;
	}
	if (s[i] == '\0' && s[i] != (char)c)
		return ((char*)ptr);
	else if (s[i] == '\0' && s[i] == (char)c)
	{
		ptr = (s + i);
		return ((char*)ptr);
	}
	return (NULL);
}
