/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 17:45:54 by mmonahan          #+#    #+#             */
/*   Updated: 2019/01/14 20:34:24 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	char	*t_str;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str = ft_memalloc(sizeof(char) * (s1_len + s1_len) + 1);
	if (!str)
		return (NULL);
	t_str = str;
	while (s1_len)
	{
		*str++ = *s1++;
		s1_len--;
	}
	while (s2_len)
	{
		*str++ = *s2++;
		s2_len--;
	}
	*str = '\0';
	return (t_str);
}
