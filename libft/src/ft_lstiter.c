/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 15:34:13 by crenly-b          #+#    #+#             */
/*   Updated: 2019/08/30 15:34:19 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	if (!lst || !f)
		return ;
	while (lst->next != NULL)
	{
		(*f)(lst);
		lst = lst->next;
	}
	if (lst != NULL)
		(*f)(lst);
}
