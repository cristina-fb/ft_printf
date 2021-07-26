/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 13:38:11 by crisfern          #+#    #+#             */
/*   Updated: 2021/07/26 13:38:13 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_type(char c)
{
	return ((c == 'c') || (c == 's') || (c == 'p') || (c == 'd') || (c == 'i')
		|| (c == 'u') || (c == 'x') || (c == 'X') || (c == '%'));
}

const char	*find_type(const char *fmt)
{
	if (fmt)
	{
		while (*fmt)
		{
			if (is_type(*fmt))
				break ;
			fmt++;
		}
	}
	return (fmt);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	int		len;
	char	*pos;

	len = 0;
	if (fmt)
	{
		va_start(args, fmt);
		while (*fmt)
		{
			pos = ft_strchr(fmt, '%');
			if (pos)
				len = arg_len(fmt, pos, args, len);
			else
			{
				len += ft_strlen(fmt);
				write(1, fmt, ft_strlen(fmt));
				break ;
			}
			fmt = find_type(pos + 1) + 1;
		}
		va_end(args);
	}
	return (len);
}
