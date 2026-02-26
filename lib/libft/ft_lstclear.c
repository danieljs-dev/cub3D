/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajesus- <dajesus-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:52:41 by dajesus-          #+#    #+#             */
/*   Updated: 2024/10/28 14:36:54 by dajesus-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list		*tmp_lst;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		tmp_lst = *lst;
		*lst = (*lst)->next;
		ft_lstdelone(tmp_lst, del);
	}
	*lst = NULL;
}
