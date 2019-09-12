#include <stdio.h>
#include "libft.h"
#include "lemin.h"

#include "minlib.h"

void transformation_map(t_farm farm, int *k) 
{
	int max_delta_farm;
	int max_delta_img;

	max_delta_farm = farm->max_x - farm->min_x > farm->max_y - farm->min_y ?
					farm->max_x - farm->min_x : farm->max_y - farm->min_y;
	max_delta_img = IMG_H > IMG_W  ? IMG_H : IMG_W;
	max_delta_img -= SQ_SIZE;
	*k = max_delta_img / max_delta_farm;
}

void transformation_room(t_room *room, int move_x, int move_y, int k)
{
	room->x = (room->x + move_x) * k;
	room->y = - (room->y - move_y) * k;
}

void draw_room(char *img_data, t_room *room)
{
	int i;
	int j;

	i = -3;
	while (i < 3)
	{
		j  = -3;
		while (j < 3)
		{
			img_data[i + room->x + (j + room->y) * IMG_W] = 1000;
			j++;
		}
		i++;
	}
}

void draw_line(t_point p1, t_point p2, int *img_data)
{
	t_point delta;
	t_point error;
	t_point sign_delta;

	delta->x = abs(p2->x - p1->x);
	delta->y = abs(p2->y - p1->y);
	sign_d.x = p1.x < p2.x ? 1 : -1;
	sign_d.y = p1.y < p2.y ? 1 : -1;
	error.x = delta.x - delta.y;
	if (p2.y >= 0 && p2.y < IMG_H && p2.x >= 0 && p2.x < IMG_W )
		img_data[p2.y * IMG_H + p2.x] = 10000;
	while (p1.x != p2.x || p1.y != p2.y)
	{
		if (p1.y >= 0 && p1.y < IMG_H && p1.x >= 0 && p1.x < IMG_W)
			img_data[p1.y * IMG_H + p1.x] = 10000;
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

void write_map(t_farm *farm)
{
	int win_h;
	int win_w;
	void *mlx_ptr;
	void *mlx_win;
	void *img;
	int *img_data;

	int bits_per_pixel;
	int size_line;
	int endian;

	int i;
	int j;
	t_room *room;
	int ind;

	int coef;
	t_point point1;
	t_point point2;

	mlx_ptr = mlx_init();
	win_h = 500;
	win_w = 500;
	mlx_win = mlx_new_window(mlx_ptr, win_w, win_h, "HEX");
	img = mlx_new_image (mlx_ptr, IMG_W, IMG_H);
	img_data = (int*)mlx_get_data_addr(img, &bits_per_pixel, &size_line, &endian);
	
	transformation_map(farm, &coef);
	i = 0;
	while (i < farm->count_rooms)
	{
		j = 0;
		ind = room->links_array[0];
		room = farm->array_rooms[i];
		transformation_room(room, -farm->min_x + SQ_SIZE / 2, - farm->min_y - SQ_SIZE / 2, coef);
		draw_room(room);
		while (ind != -1 && j < farm->count_rooms)
		{
			ind = room->links_array[j];
			point1.x = room->x;
			point1.y = room->y;
			point2.x = farm->array_room[ind]->x;
			point2.y = farm->array_room[ind]->y;
			draw_line(point1, point2, img_data);
			j++;
		}
		//draw_line();
		i++;
	}
	mlx_put_image_to_window(mlx_ptr, mlx_win, img, 0, 0);
	mlx_loop(mlx_ptr);
}

int main(int argc, char **argv)
{
	t_farm farm;
	int fd;

	if (argc == 1)
		fd = 0;
	else
		fd = open(argv[1], O_RDONLY);
	read_data(fd, &farm);
	write_map(farm);
	//do_instructions(0, farm);
	return (0);
}