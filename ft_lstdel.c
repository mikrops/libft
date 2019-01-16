/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 18:15:24 by mmonahan          #+#    #+#             */
/*   Updated: 2019/01/14 20:21:27 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *next;

	if (!alst || !del)
		return ;
	next = *alst;
	while (next)
	{
		del(next->content, next->content_size);
		next = next->next;
		(*alst)->next = NULL;
		ft_memdel((void**)alst);
		*alst = next;
	}
}
