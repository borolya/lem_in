#include <stdio.h>
#include "libft.h"
#include "lemin.h"

#include "minlib.h"

void write_map(t_farm *farm)
{
	int win_h;
	int win_w;
	void *mlx_ptr;
	void *mlx_win;
	void *img;
	char *img_data;

	int bits_per_pixel;
	int size_line;
	int endian;


	int i;
	int j;
	t_room *room;
	int ind;

	mlx_ptr = mlx_init();
	win_h = 500;
	win_w = 500;
	mlx_win = mlx_new_window(mlx_ptr, win_w, win_h, "HEX");
	img = mlx_new_image (mlx_ptr, win_w, win_h);
	img_data = mlx_get_data_addr(img, &bits_per_pixel, &size_line, &endian);
	i = 0;
	while (i < farm->count_rooms)
	{
		j = i;
		room = farm->array_rooms[i];
		draw_room(room);
		while (room->links_array[j] != -1)
		{
			ind = room->links_array[j];
			draw_line(room->x, room->y, farm->array_room[ind]->x, 
								farm->array_room[ind]->y, win_w, win_h, img_data);
			i++;
		}
		
		draw_line()
		i++;
	}
	mlx_put_image_to_window(mlx_ptr, mlx_win, img, 0, 0);
	mlx_loop(mlx_ptr);
}



int main(int argc, char **argv)
{
	int i;
	char *str;
	t_farm farm;

	read_data(0, farm);
	write_map(farm);
	//do_instructions(0, farm);
	return (0);
}