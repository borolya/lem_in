/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   olya_new_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 12:33:17 by crenly-b          #+#    #+#             */
/*   Updated: 2019/10/08 13:17:44 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		exist_link(t_room *room, int nbr)
{
	int i;

	i = 0;
	while (room->link[i] != -1)
	{
		if (room->link[i] == nbr)
			return (1);
		i++;
	}
	return (0);
}

int		search_num_path(t_room *room, int path_numb, t_farm *farm)
{
	int		i;
	t_room	*link;

	i = 0;
	while (room->link[i] != -1)
	{
		link = farm->arr[room->link[i]];
		if (link->paint_mark == path_numb)
			return (link->pos);
		i++;
	}
	return (-1);
}

void	intersection(t_farm *farm, char *queue, t_path path, int k)
{
	int		i;
	t_room	*room;

	i = -1;
	while (++i < path.size - 1)
	{
		if (path.bfs[i + 1] > farm->cnt)
			path.bfs[i + 1] -= farm->cnt;
		room = farm->arr[path.bfs[i]];
		if (room->pos == path.bfs[i + 1])
			room = farm->arr[path.bfs[++i]];
		if (exist_link(farm->arr[path.bfs[i + 1]],
			path.bfs[i]) && room->paint_mark != -1)
		{
			queue[room->paint_mark] = 1;
			delete_link(farm->arr[path.bfs[i + 1]], path.bfs[i]);
		}
		else
		{
			add_link(room, path.bfs[i + 1]);
			if (farm->arr[path.bfs[i]]->pos != 1 &&
				farm->arr[path.bfs[i]]->paint_mark != -1)
				farm->arr[path.bfs[i]]->paint_mark = k;
		}
	}
}

t_path	painting_path(t_farm *farm, t_path *good, t_farm *split, int i)
{
	t_room	*room;
	int		new_path[100000];
	t_path	new;
	int		new_size;

	room = farm->arr[0];
	new_size = 1;
	room = farm->arr[good[i].bfs[1]];
	room->paint_mark = i;
	split->arr[good[i].bfs[1]]->paint_mark = i;
	new_path[0] = 0;
	new_path[new_size++] = room->pos;
	while (room->pos != 1 && new_size < 100)
	{
		room = farm->arr[search_path(room)];
		if (room->pos != 1)
		{
			room->paint_mark = i;
			split->arr[good[i].bfs[1]]->paint_mark = i;
		}
		new_path[new_size++] = room->pos;
	}
	ft_fill_path(&new, new_path, new_size);
	return (new);
}

void	add_path(t_path *good, t_farm *farm, int k, t_farm *split)
{
	t_path	path;
	char	queue[100000];
	int		i;

	path = good[k];
	ft_memset(queue, 0, k);
	queue[k] = 1;
	intersection(farm, queue, path, k);
	i = 0;
	while (i < k + 1)
	{
		if (queue[i] == 1)
			good[i] = painting_path(farm, good, split, i);
		i++;
	}
}
