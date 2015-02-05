/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 18:50:23 by jealonso          #+#    #+#             */
/*   Updated: 2015/02/05 16:26:31 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_strcmp(char const *s1, char const *s2)
{
	int	i;
	unsigned char *s1ptr;
	unsigned char *s2ptr;

	s1ptr = (unsigned char *)s1;
	s2ptr = (unsigned char *)s2;
	i = 0;
	while (s1ptr[i] == s2ptr[i] && (s1ptr[i] != '\0' || s2ptr[i] != '\0'))
		i++;
	return (s1ptr[i] - s2ptr[i]);
}
