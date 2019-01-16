/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 19:53:25 by mmonahan          #+#    #+#             */
/*   Updated: 2019/01/05 16:07:11 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_charcount(char const *s, char c)
{
	size_t count;

	count = 0;
	if (!s || !c)
		return (count);
	while (*s != c && *s != '\0')
	{
		count++;
		s++;
	}
	return (count);
}
