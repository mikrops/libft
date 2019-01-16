/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 01:03:25 by mmonahan          #+#    #+#             */
/*   Updated: 2019/01/15 17:10:29 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*tmp;
	char	*ts;

	if (!s)
		return (NULL);
	s = s + start;
	tmp = ft_memalloc(sizeof(char) * len + 1);
	if (!tmp)
		return (NULL);
	ts = tmp;
	while (len)
	{
		*tmp++ = *s++;
		len--;
	}
	return (ts);
}
