/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 20:44:18 by mmonahan          #+#    #+#             */
/*   Updated: 2019/01/14 18:42:41 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_lstaddend(t_list **alst, t_list *new)
{
	printf("START - ft_lstaddend\n");
	size_t len;
	printf("size_t len;\n");
	if (!alst || !new)
		return ;
	len = ft_lstlen(*alst);
	printf("len = %zu;\n", len);
	while (len)
	{
		printf("while (len[%zu])\n", len);
		*alst = (*alst)->next;
		printf("*alst = (*alst)->next;\n");
		len--;
		printf("len--;[%zu]\n", len);
	}
	(*alst)->next = new;
	printf("(*alst)->next = new;\n");
}
