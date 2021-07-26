/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_variable1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 13:38:33 by crisfern          #+#    #+#             */
/*   Updated: 2021/07/26 13:38:35 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	get_pointer_argument(va_list args, t_flags var)
{
	long	c;

	c = va_arg(args, long);
	var.val = ft_litoh(c);
	var.f_sharp = 1;
	return (var);
}

t_flags	get_int_argument(va_list args, t_flags var)
{
	long int	c;

	c = (long int)va_arg(args, int);
	if (c < 0)
	{
		var.f_plus = 1;
		var.sign = 1;
		c *= -1;
	}
	var.val = ft_itoa(c);
	return (var);
}

t_flags	get_unsigned_argument(va_list args, t_flags var)
{
	unsigned int	c;

	c = va_arg(args, unsigned int);
	var.val = ft_itoa(c);
	return (var);
}

t_flags	get_hex_argument(va_list args, t_flags var)
{
	unsigned int	c;
	int				i;

	i = 0;
	c = va_arg(args, unsigned int);
	if (!c && var.f_sharp)
		var.f_sharp = 0;
	var.val = ft_itoh(c);
	if (var.type == 'X')
	{
		while (var.val[i])
		{
			var.val[i] = ft_toupper(var.val[i]);
			i++;
		}
	}
	return (var);
}
