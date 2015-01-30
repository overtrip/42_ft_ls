/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 14:58:40 by jealonso          #+#    #+#             */
/*   Updated: 2014/11/09 19:36:32 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_strclr(char *s)
{
	int	cmp;

	cmp = 0;
	if (!s)
		return ;
	while (s[cmp] != '\0')
	{
		s[cmp] = '\0';
		cmp++;
	}
}