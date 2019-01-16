/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 18:19:14 by mmonahan          #+#    #+#             */
/*   Updated: 2019/01/16 20:18:26 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_wordcount(char const *s, char c)
{
	size_t	count;

	count = 0;
	if (!s || !c)
		return (count);
	while (*s)
	{
		if (*s != c && (*(s + 1) == c || *(s + 1) == '\0'))
		{
			count++;
			s++;
		}
		else
			s++;
	}
	return (count);
}
