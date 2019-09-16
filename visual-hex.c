#include <stdio.h>
#include "libft.h"
#include "lemin.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "mlx.h"





void draw_room(int *img_data, t_room *room)
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
	
	i = 0;
	while (i < IMG_W)
	{
		j = 0;
		while (j < IMG_H)
		{
			img_data[IMG_W * j + i] = 99;
			j++;
		}
		i++;
	}
	if (farm == NULL)
		exit(-1);
	transformation_map(farm, &coef);
	printf("coefficent = %d\n", coef);
	i = 0;
	while (i < farm->count_rooms)
	{
		room = farm->array_rooms[i];
		if (room == NULL)
			break;
		transformation_room(room, -farm->min_x , farm->max_y, coef);
		i++;
	}
	

	mlx_put_image_to_window(mlx_ptr, mlx_win, img, 50, 50);
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
	write_map(&farm);
	//do_instructions(0, farm);
	return (0);
}