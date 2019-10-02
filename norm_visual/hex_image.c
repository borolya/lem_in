/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_hex_image.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharmund <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 21:33:07 by bharmund          #+#    #+#             */
/*   Updated: 2019/10/02 21:33:08 by bharmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"
#include "lemin.h"

void	transformation_map(t_farm *farm, int *k)
{
	int delta_farm;
	int delta_img;
	int kx;
	int ky;

	delta_farm = farm->max_crd.x - farm->min_crd.x;
	delta_img = HEX_W - SQ_SIZE;
	kx = (HEX_W - SQ_SIZE) / (farm->max_crd.x - farm->min_crd.x);
	ky = (HEX_H - SQ_SIZE) / (farm->max_crd.y - farm->min_crd.y);
	*k = kx < ky ? kx : ky;
}

void	trns_room(t_room *room, int move_x, int move_y, int k)
{
	room->crd.x = (room->crd.x + move_x) * k + SQ_SIZE / 2;
	room->crd.y = (move_y - room->crd.y) * k + SQ_SIZE / 2;
	if (k == 0)
		return ;
}

void	draw_room(t_img *hex, t_room *room)
{
	int i;
	int j;
	int color;

	i = room->crd.y - SQ_SIZE / 2;
	while (i < room->crd.y + SQ_SIZE / 2)
	{
		j = room->crd.x - SQ_SIZE / 2;
		while (j < room->crd.x + SQ_SIZE / 2)
		{
			if (room->start)
				color = 122200;
			else if (room->finish)
				color = 150000000;
			else
				color = 1000;
			hex->data[i * hex->w + j] = color;
			j++;
		}
		i++;
	}
}

void	hex_img(t_img *hex, t_farm *farm)
{
	int		i;
	int		j;
	t_room	room;
	int		ind;

	transformation_map(farm, &j);
	i = -1;
	while (++i < farm->count_rooms)
	{
		trns_room(farm->array_rooms[i], -farm->min_crd.x, farm->max_crd.y, j);
		draw_room(hex, farm->array_rooms[i]);
	}
	i = -1;
	while (++i < farm->count_rooms)
	{
		j = -1;
		room = *(farm->array_rooms[i]);
		ind = room.links_array[0];
		while (ind != -1 && ++j < farm->count_rooms)
		{
			if (ind > i)
				draw_line(room.crd, farm->array_rooms[ind]->crd, hex->data);
			ind = room.links_array[j];
		}
	}
}
