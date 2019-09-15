#include <stdio.h>
//#include "libft.h"
#include "lemin.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "mlx.h"


int ft_fab(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

typedef struct s_visu
{
	void *mlx_ptr;
	void *mlx_win;
	void *img;
	int *img_data;
	int flag;
	t_point *point;
}   t_visu;

t_point visual_line(t_point p1, t_point p2,  void *mlx_ptr, void *mlx_win)//essey case from p1 to p2
{
	int *img_data;
	void *img;
	int steps;
	t_point p;
	t_point delta;
	t_point delta_step;

	int bits_per_pixel;
	int size_line;
	int endian;
	int i;

	delta.x = ft_fab(p1.x - p2.x);
	delta.y = ft_fab(p1.y - p2.y);
	steps = 200;
	img = mlx_new_image (mlx_ptr, 5, 5);
	img_data = (int*)mlx_get_data_addr(img, &bits_per_pixel, &size_line, &endian);
	i = 0;
	while (i < 25)
	{
		img_data[i] = 1000;
		i++; 
	}
	p = p1;
	if (delta.x > delta.y)// == if delta x != 0
	{
		delta_step.x = delta.x / steps;
		delta_step.y = delta.y / steps;
		printf("p.x = %d, p.y = %d\n", p.x, p.y);
		mlx_put_image_to_window(mlx_ptr, mlx_win, img, p.x, p.y);
		while (p2.x - p.x > delta_step.x + 3 || p2.y - p.y > delta_step.y + 3)
		{
			p.x = p.x + delta_step.x;
			p.y = p.y + delta_step.y;
			printf("p.x = %d, p.y = %d\n", p.x, p.y);
			mlx_put_image_to_window(mlx_ptr, mlx_win, img, p.x, p.y);
		}
	}
	return (p);
}

int ft_draw(t_visu *visu)
{
	t_point *point;
	int i;
	point = visu->point;

	i = 0;
	while (i < 49)
	{
		visu->img_data[i] = 1000;
		i++;
	}
	
	if (point->x < 500 && point->y < 500)
	{
		mlx_clear_window(visu->mlx_ptr, visu->mlx_win);
		mlx_put_image_to_window(visu->mlx_ptr, visu->mlx_win, visu->img, point->x, point->y);
		point->x += 5;
		point->y += 5;
		
	}
	return (1);
}

int main()
{
	void *mlx_ptr;
	void *mlx_win;
	t_point p1;
	t_point p2;
	mlx_ptr = mlx_init();
	mlx_win = mlx_new_window(mlx_ptr, 1000, 1000, "test_line");
	t_visu visu;
		int bits_per_pixel;
	int size_line;
	int endian;
	int i;
	int *img_data;
	visu.mlx_ptr = mlx_ptr;
	visu.mlx_win = mlx_win;
	visu.flag = 1;

	visu.img = mlx_new_image (mlx_ptr, 7, 7);
	visu.img_data = (int*)mlx_get_data_addr(visu.img, &bits_per_pixel, &size_line, &endian);
	p1.x = 10;
	p1.y = 10;
	p2.x = 400;
	p2.y = 10;
	visu.point = &p1;
		//visual_line(p1, p2, mlx_ptr, mlx_win);
	mlx_loop_hook(mlx_ptr, &ft_draw, &visu);
	mlx_loop(mlx_ptr);
}