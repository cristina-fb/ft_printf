/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 18:45:16 by crisfern          #+#    #+#             */
/*   Updated: 2021/07/14 11:01:52 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	get_digits(long n)
{
	int				digits;
	unsigned long	num;

	digits = 1;
	if (n < 0)
	{
		digits++;
		num = n * (-1);
	}
	else
		num = n;
	while (num > 9)
	{
		num /= 10;
		digits++;
	}
	return (digits);
}

char	*ft_itoa(long n)
{
	unsigned long	num;
	unsigned int	dig;
	char			*str;

	dig = get_digits(n) + 1;
	str = ft_calloc(dig, 1);
	num = (unsigned long) n;
	if (n < 0)
		num *= -1;
	if (str)
	{
		str[dig - 1] = '\0';
		while (--dig > 0)
		{
			if ((n < 0) && (dig == 1))
				str[0] = '-';
			else
			{
				str[dig - 1] = '0' + num % 10;
				num /= 10;
			}
		}
	}
	return (str);
}