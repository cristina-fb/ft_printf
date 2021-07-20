/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 15:47:06 by crisfern          #+#    #+#             */
/*   Updated: 2021/07/12 16:20:28 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	n_digits(unsigned int n)
{
	int	digits;

	digits = 1;
	while (n > 15)
	{
		digits++;
		n /= 16;
	}
	return (digits);
}

char	*ft_itoh(unsigned int n)
{
	char	*str;
	int		digits;
	int		i;

	i = 0;
	digits = n_digits(n);
	str = malloc(digits + 1);
	if (str)
	{
		str[digits] = 0;
		while (n > 15)
		{
			if ((n % 16) > 9)
				str[--digits] = 'a' - 10 + (n % 16);
			else
				str[--digits] = '0' + (n % 16);
			n /= 16;
		}
		if ((n % 16) > 9)
			str[--digits] = 'a' - 10 + (n % 16);
		else
			str[--digits] = '0' + (n % 16);
	}
	return (str);
}
