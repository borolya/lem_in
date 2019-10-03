/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharmund <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 21:10:31 by bharmund          #+#    #+#             */
/*   Updated: 2019/10/02 21:10:32 by bharmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "visu.h"

void	ft_lstfree(t_list **alst)
{
	t_list	*list;
	t_list	*next;
	t_room	*room;

	list = *alst;
	next = list->next;
	while (list != NULL)
	{
		room = list->content;
		free(room->name);
		free(room->links_array);
		free(room);
		ft_memdel((void**)(&list));
		list = next;
		if (list != NULL)
			next = list->next;
	}
}

void	ft_lstcontentfree(t_list **alst)
{
	t_list *lst;
	t_list *next;

	if (!alst)
		return ;
	lst = (*alst);
	while (lst != NULL)
	{
		free((t_link*)(lst->content));
		next = lst->next;
		free(lst);
		lst = next;
	}
	*alst = NULL;
}

void	free_farm(t_farm *farm)
{
	ft_lstfree(&(farm->room_list));
	free(farm->array_aunts);
	free(farm->array_rooms);
}

void	free_visu(t_visu *visu)
{
	mlx_destroy_image(visu->mlx_ptr, visu->aunt.ptr);
	mlx_destroy_image(visu->mlx_ptr, visu->hex.ptr);
	mlx_destroy_window(visu->mlx_ptr, visu->win_ptr);
	free_farm(visu->farm);
	exit(1);
}
