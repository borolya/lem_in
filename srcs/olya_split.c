/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   olya_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 12:35:56 by crenly-b          #+#    #+#             */
/*   Updated: 2019/10/08 12:37:19 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	change_link(t_room *room, int change, int new)
{
	int	i;
	int	*link;

	link = room->link;
	i = 0;
	while (link[i] != -1)
	{
		if (link[i] == change)
		{
			link[i] = new;
			return ;
		}
		i++;
	}
}

void	delete_link(t_room *room, int del_link)
{
	int	i;
	int	*link;
	int	flag;

	i = 0;
	flag = 0;
	link = room->link;
	while (link[i] != -1)
	{
		if (link[i] == del_link || flag)
		{
			flag = 1;
			link[i] = link[i + 1];
		}
		i++;
	}
}

int		no_duplicate(int room_pos, t_farm *farm)
{
	int *link;

	if (room_pos > farm->cnt)
		return (0);
	link = farm->arr[room_pos + farm->cnt]->link;
	if (link[0] == -1)
		return (1);
	return (0);
}

void	split_room(t_room *next, t_room *pr, t_room *room, t_farm *farm)
{
	int		j;
	t_room	*outing;

	j = 0;
	while (room->link[j] != -1)
	{
		if (room->link[j] == pr->pos)
		{
			delete_link(room, room->link[j]);
			add_link(pr, room->pos);
		}
		else if (room->link[j] == next->pos)
		{
			delete_link(next, room->pos);
			change_link(room, next->pos, room->pos + farm->cnt);
			add_link(farm->arr[room->pos + farm->cnt], next->pos);
		}
		else
		{
			outing = farm->arr[room->link[j++]];
			change_link(outing, room->pos, room->pos + farm->cnt);
			if (outing->paint_mark != -1)
				change_link(room, outing->pos, outing->pos + farm->cnt);
		}
	}
}

void	split_rev(t_path *path, t_farm *farm)
{
	int		i;
	t_room	*next;
	t_room	*room;
	t_room	*pr;

	i = path->size - 2;
	while (i > 0)
	{
		room = farm->arr[path->bfs[i]];
		pr = farm->arr[path->bfs[i + 1]];
		next = farm->arr[path->bfs[i - 1]];
		split_room(next, pr, room, farm);
		i--;
	}
}
