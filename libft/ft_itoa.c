/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 18:27:09 by jealonso          #+#    #+#             */
/*   Updated: 2015/01/04 15:54:42 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	num_digits(long n)
{
	size_t	digits;

	digits = 0;
	if (n == 0)
		return (1);
	else
	{
		while (n)
		{
			n /= 10;
			digits++;
		}
		return (digits);
	}
}

char			*ft_itoa(int n)
{
	size_t	neg_flag;
	size_t	digits;
	char	*result;
	long	n_long;

	n_long = (long)n;
	neg_flag = 0;
	if (n < 0)
	{
		neg_flag = 1;
		n_long *= -1;
	}
	digits = num_digits(n_long);
	result = (char *)ft_memalloc(digits + neg_flag + 1);
	if (result)
	{
		if (neg_flag)
			*result = '-';
		while (digits--)
		{
			*(result + digits + neg_flag) = (n_long % 10) + '0';
			n_long /= 10;
		}
	}
	return (result);
}
