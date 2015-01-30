/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 15:47:50 by jealonso          #+#    #+#             */
/*   Updated: 2014/11/06 19:48:31 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	char	*copy;
	char	*p1;
	size_t	i;

	copy = (char *)malloc(sizeof(char *) * len);
	p1 = (char *)dest;
	i = 0;
	while (i <= len)
	{
		copy[i] = ((char *)src)[i];
		i++;
	}
	while (len--)
		p1[len] = copy[len];
	return (dest);
}
