/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_variable2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 13:38:42 by crisfern          #+#    #+#             */
/*   Updated: 2021/07/26 13:38:44 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	get_string_argument(va_list args, t_flags var)
{
	char	*str;

	str = va_arg(args, char *);
	if (!str)
		var.val = ft_strdup("(null)");
	else
		var.val = ft_strdup(str);
	return (var);
}

t_flags	get_char_argument(va_list args, t_flags var)
{
	int	c;

	c = va_arg(args, int);
	if (c == 0)
		var.n_null++;
	var.val = ft_calloc(2, 1);
	var.val[0] = c;
	return (var);
}

char	*write_sign(t_flags var)
{
	char	*aux;

	if (var.f_plus && (var.type == 'd' || var.type == 'i'))
	{
		if (var.sign)
			aux = ft_strjoin("-", var.val);
		else
			aux = ft_strjoin("+", var.val);
		if (aux)
		{
			free(var.val);
			return (aux);
		}
	}
	return (var.val);
}
