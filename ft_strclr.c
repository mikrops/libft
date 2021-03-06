/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 04:48:49 by mmonahan          #+#    #+#             */
/*   Updated: 2018/12/19 20:10:40 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strclr(char *s)
{
	char	*tmp;

	if (s == NULL)
		return ;
	tmp = s + ft_strlen(s);
	while (tmp >= s)
	{
		*tmp = '\0';
		tmp--;
	}
}
