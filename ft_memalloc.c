/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 05:14:06 by mmonahan          #+#    #+#             */
/*   Updated: 2019/01/08 18:23:50 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char *tmp;

	tmp = (unsigned char*)malloc(sizeof(unsigned char) * size);
	if (!tmp)
		return (NULL);
	ft_memset(tmp, 0, size);
	return (tmp);
}
