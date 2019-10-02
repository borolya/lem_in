/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_initial.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharmund <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 20:40:52 by bharmund          #+#    #+#             */
/*   Updated: 2019/10/02 20:40:56 by bharmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	init_room(t_room *room, int *i, t_farm *farm)
{
	int j;

	if (!(room->links_array = ft_memalloc(sizeof(int) * farm->count_rooms)))
		exit(-1);
	j = -1;
	while (++j < farm->count_rooms)
		room->links_array[j] = -1;
	if (room->start == 1)
	{
		farm->array_rooms[0] = room;
		room->ind = 0;
	}
	else if (room->finish == 1)
	{
		farm->array_rooms[1] = room;
		room->ind = 1;
	}
	else
	{
		farm->array_rooms[*i] = room;
		room->ind = *i;
		(*i)++;
	}
}

void	initial_farm_array_rooms(t_farm *farm)
{
	t_room		*room;
	t_list		*list;
	int			i;

	if (!(farm->array_rooms =
			ft_memalloc(sizeof(t_room*) * farm->count_rooms)))
		exit(-1);
	i = 2;
	list = farm->room_list;
	while (list != NULL)
	{
		room = list->content;
		init_room(room, &i, farm);
		list = list->next;
	}
	if (!(farm->array_aunts = malloc(sizeof(int) * farm->count_aunts)))
		exit(-1);
	i = -1;
	while (++i < farm->count_aunts)
		farm->array_aunts[i] = 0;
}
