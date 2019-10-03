/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_visual.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharmund <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 19:47:32 by bharmund          #+#    #+#             */
/*   Updated: 2019/10/03 19:47:34 by bharmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "visu.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void	initialisation(t_visu *visu)
{
	visu->mlx_ptr = mlx_init();
	visu->win_ptr = mlx_new_window(visu->mlx_ptr, WIN_W, WIN_H, "HEX");
	visu->links = NULL;
}

void	imag_initialisation(t_img *hex, t_img *aunt, t_visu *visu)
{
	int i;

	hex->h = HEX_W;
	hex->w = HEX_H;
	hex->ptr = mlx_new_image(visu->mlx_ptr, HEX_W, HEX_H);
	hex->data = (int*)mlx_get_data_addr(hex->ptr, &hex->bits_per_pixel,
													&hex->h, &hex->endian);
	hex_img(hex, visu->farm);
	aunt->h = SQ_SIZE;
	aunt->w = SQ_SIZE;
	aunt->ptr = mlx_new_image(visu->mlx_ptr, aunt->w, aunt->h);
	aunt->data = (int*)mlx_get_data_addr(aunt->ptr, &aunt->bits_per_pixel,
													&aunt->h, &aunt->endian);
	i = 0;
	while (i < SQ_SIZE * SQ_SIZE)
	{
		aunt->data[i] = 10000000;
		i++;
	}
}

int		main(int argc, char **argv)
{
	t_farm	farm;
	t_visu	visu;
	int		fd;

	if (argc == 1)
		fd = 0;
	else
		fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		exit(-1);
	read_data(fd, &farm);
	initialisation(&visu);
	visu.farm = &farm;
	visu.fd = fd;
	visu.step = -1;
	imag_initialisation(&(visu.hex), &(visu.aunt), &visu);
	mlx_key_hook(visu.win_ptr, &step_init, &visu);
	mlx_loop_hook(visu.mlx_ptr, &dinamic, &visu);
	mlx_loop(visu.mlx_ptr);
	return (0);
}
