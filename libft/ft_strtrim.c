/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 14:59:01 by jealonso          #+#    #+#             */
/*   Updated: 2014/11/09 20:09:35 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*newmem;
	char	*tmp;
	char	*pend;
	size_t	i;

	if (!s)
		return (NULL);
	tmp = ft_strnew(ft_strlen(s) + 1);
	pend = (char *)s + (ft_strlen(s) - 1);
	i = 0;
	while (*s == ' ' || *s == '\n' || *s == '\t')
		s++;
	while (*pend == ' ' || *pend == '\n' || *pend == '\t')
		pend--;
	while (s <= pend)
	{
		tmp[i] = *s;
		i++;
		s++;
	}
	tmp[i] = '\0';
	newmem = ft_strnew(ft_strlen(tmp));
	ft_strcpy(newmem, tmp);
	ft_strdel(&tmp);
	return (newmem);
}
