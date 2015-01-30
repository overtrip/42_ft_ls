/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 20:02:25 by jealonso          #+#    #+#             */
/*   Updated: 2014/11/10 11:55:39 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strcpy(char *dest, char *src)
{
	int cmp;

	cmp = 0;
	while (src[cmp] != '\0')
	{
		dest[cmp] = src[cmp];
		cmp++;
	}
	dest[cmp] = '\0';
	return (dest);
}
