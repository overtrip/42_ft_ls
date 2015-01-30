/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 18:29:58 by jealonso          #+#    #+#             */
/*   Updated: 2014/11/09 14:49:34 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_issep(char c, char sep)
{
	return (c == sep);
}

static int	ft_num_substr(char const *str, char c)
{
	int		i;
	int		num_str;

	i = 0;
	num_str = 0;
	while (str[i])
	{
		if (!ft_issep(str[i], c) && (i == 0 || ft_issep(str[i - 1], c)))
			num_str++;
		i++;
	}
	return (num_str);
}

static void	ft_put_words(char const *s, char **tab, char c)
{
	int			i;
	int			j;
	const char	*begin;
	const char	*end;

	i = 0;
	j = 0;
	begin = NULL;
	end = NULL;
	while (s[i])
	{
		if (!ft_issep(s[i], c) && !begin)
			begin = &s[i];
		if ((ft_issep(s[i + 1], c) || s[i + 1] == '\0') && begin)
			end = &s[i];
		if (begin && end)
		{
			tab[j++] = ft_strsub(begin, 0, end - begin + 1);
			begin = NULL;
			end = NULL;
		}
		i++;
	}
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		num_str;

	if (!s || !c)
		return (NULL);
	num_str = ft_num_substr(s, c);
	if (!(tab = (char **)malloc(sizeof(char *) * (num_str + 1))))
		return (NULL);
	ft_put_words(s, tab, c);
	tab[num_str] = NULL;
	return (tab);
}
