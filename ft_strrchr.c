/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 20:10:05 by mmonahan          #+#    #+#             */
/*   Updated: 2019/01/06 18:39:58 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t			tmp;
	unsigned char	ch;

	tmp = ft_strlen(s);
	ch = (unsigned char)c;
	s += tmp;
	while (*s != c)
	{
		if (!tmp)
			return (NULL);
		s--;
		tmp--;
	}
	return ((char*)s);
}
