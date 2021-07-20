/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 11:49:08 by crisfern          #+#    #+#             */
/*   Updated: 2021/07/05 09:41:39 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*ptr;

	if (s1 && s2)
	{
		len = ft_strlen(s1) + ft_strlen(s2);
		ptr = ft_calloc(len + 1, 1);
		if (ptr)
		{
			while (*s1)
				*ptr++ = *s1++;
			while (*s2)
				*ptr++ = *s2++;
			*ptr = 0;
			return (ptr - len);
		}
	}
	return (0);
}
