/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 16:21:57 by mmonahan          #+#    #+#             */
/*   Updated: 2019/01/15 20:53:31 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	size_t	count;
	char	*str;

	count = n < 0 ? ft_intcount(n) + 1 : ft_intcount(n);
	str = ft_memalloc(sizeof(char) * count + 1);
	if (!str)
		return (NULL);
	str[count--] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		if (n == -2147483648)
		{
			n = 214748364;
			str[count--] = '8';
			//return ("-2147483648");
		}
		else
			n *= -1;
	}
	if (n == 0)
		str = "0";
	while (n)
	{
		str[count] = n % 10 + '0';
		if (count)
			count--;
		n /= 10;
	}
	return (str);

	// size_t	count;
	// char	*str;
	//
	// count = n < 0 ? ft_intcount(n) + 1 : ft_intcount(n);
	// str = ft_memalloc(sizeof(char) * count + 1);
	// if (!str)
	// 	return (NULL);
	// if (n == 0)
	// 	return (str = "0");
	// else if (n == -2147483648)
	// 	return (str = "-2147483648");
	// else if (n < 0)
	// {
	// 	str[0] = '-';
	// 	n *= -1;
	// }
	// count--;
	// while (n)
	// {
	// 	str[count] = n % 10 + '0';
	// 	if (count)
	// 		count--;
	// 	n /= 10;
	// }
	// return (str);
}
