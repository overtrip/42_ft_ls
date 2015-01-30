/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 12:04:37 by jealonso          #+#    #+#             */
/*   Updated: 2014/11/09 19:44:08 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *final;

	if (!(s1 && s2))
		return (NULL);
	if ((final = (ft_strnew((ft_strlen(s1)) + (ft_strlen(s2))))))
	{
		ft_strcpy(final, (char *)s1);
		ft_strcat(final, (char *)s2);
		return (final);
	}
	return (NULL);
}
