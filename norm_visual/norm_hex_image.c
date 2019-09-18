#include "visu.h"
#include "lemin.h"

void transformation_map(t_farm *farm, int *k) 
{
	int delta_farm;
	int delta_img;
	int kx;
	int ky;

	delta_farm = farm->max_crd.x - farm->min_crd.x;
	delta_img = HEX_W - SQ_SIZE;
	kx =  (HEX_W - SQ_SIZE) / (farm->max_crd.x - farm->min_crd.x);
	ky =  (HEX_H - SQ_SIZE) / (farm->max_crd.y - farm->min_crd.y);
	*k = kx < ky ? kx : ky;
/*
	max_delta_farm = farm->max_crd.x - farm->min_crd.x > farm->max_crd.y - farm->min_crd.y ?
					farm->max_crd.x - farm->min_crd.x : farm->max_crd.y - farm->min_crd.y;
	max_delta_img = HEX_H > HEX_W  ? HEX_H : HEX_W;
	max_delta_img -= SQ_SIZE;
	*k = max_delta_img / max_delta_farm;
	*/
}

void transformation_room(t_room *room, int move_x, int move_y, int k)
{
	room->crd.x = (room->crd.x + move_x) * k + SQ_SIZE / 2;
	room->crd.y = (move_y - room->crd.y) * k + SQ_SIZE / 2;
	if (k == 0)
		return;
}

void draw_line(t_point p1, t_point p2, int *img_data)
{
	t_point delta;
	t_point error;
	t_point sign_d;

	delta.x = abs(p2.x - p1.x);
	delta.y = abs(p2.y - p1.y);
	sign_d.x = p1.x < p2.x ? 1 : -1;
	sign_d.y = p1.y < p2.y ? 1 : -1;
	error.x = delta.x - delta.y;
	if (p2.y >= 0 && p2.y < HEX_H && p2.x >= 0 && p2.x < HEX_W )
		img_data[p2.y * HEX_H + p2.x] = 100000;
	while (p1.x != p2.x || p1.y != p2.y)
	{
		if (p1.y >= 0 && p1.y < HEX_H && p1.x >= 0 && p1.x < HEX_W)
			img_data[p1.y * HEX_H + p1.x] = 100000;
		if ((error.y = error.x * 2) > -delta.y)
		{
			error.x -= delta.y;
			p1.x += sign_d.x;
		}
		if (error.y < delta.x)
		{
			error.x += delta.x;
			p1.y += sign_d.y;
		}
	}
}

void draw_room(t_img *hex, t_room *room)
{
	int i;
	int j;
	int color;
	//add name 

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
#include <stdio.h>
void hex_img(t_img *hex, t_farm *farm)
{
	int     i;
	int     j;
	int     k;
	t_room	room;
	int		ind;

	//write_farm(farm);
	if (hex == NULL)
		return ;
	
	transformation_map(farm, &k);
	printf("k = %d\n", k);
	i = 0;
	while (i < farm->count_rooms)
	{
		transformation_room(farm->array_rooms[i], -farm->min_crd.x , farm->max_crd.y, k);
		printf("crd x = %d, y = %d\n", farm->array_rooms[i]->crd.x, farm->array_rooms[i]->crd.y);
		draw_room(hex, farm->array_rooms[i]);
		i++;
	}
	i = 0;
	while (i < farm->count_rooms)
	{	
		j = 0;
		room = *(farm->array_rooms[i]);
		ind = room.links_array[0];
		while (ind != -1 && j < farm->count_rooms)
		{
			if (ind > i)
				draw_line(room.crd, farm->array_rooms[ind]->crd, hex->data);
			ind = room.links_array[j];
			j++;
		}
		i++;
	}
}