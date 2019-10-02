#include "lemin.h"
#include "visu.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void initialisation(t_visu *visu)
{
	visu->mlx_ptr = mlx_init();
	visu->win_ptr = mlx_new_window(visu->mlx_ptr, WIN_W, WIN_H, "HEX");
	visu->links = NULL;
}

void fill_points(t_link *link)
{
	link->p.x = (double)link->room1->crd.x;
	link->p.y = (double)link->room1->crd.y;
	link->delta.x = (double)(link->room2->crd.x - link->room1->crd.x) / STEPS;
	link->delta.y = (double)(link->room2->crd.y - link->room1->crd.y) / STEPS;
}

char *handle_str(char *str, t_farm *farm, t_link *link)
{
	int numb;
	int i;
	int len;
	char *tmp;

	if (str[0] != 'L')
		ft_error("bad_moved");
	str++;
	numb = ft_atoi(str) - 1;
	link->numb = numb;
	if (numb >= farm->count_aunts)
		ft_error("bad_aunt_numb\n");
	tmp = NULL;
	link->room1 = farm->array_rooms[farm->array_aunts[numb]];
	str = ft_strchr(str, '-');
	str++;
	tmp = ft_strchr(str, ' ');
	if (tmp != NULL)
		len = tmp - str;
	else
		len = ft_strlen(str);
	i = 0;
	while (!ft_strnequ(str, farm->array_rooms[i]->name, len))
		i++;
	if (i < farm->count_rooms)
		link->room2 = farm->array_rooms[i];
	else
		ft_error("aunt go to nowhere");
	fill_points(link);
	if (tmp != '\0')
		tmp++;
	return (tmp);
}

int step_init(int keycode, t_visu *visu)
{
	t_link link;
	char *save;
	char *str;
	t_list *list;
	t_link *plink;

	if (keycode == 53)
	{
		free_visu(visu);
		exit(1);
	}
	else if (keycode == 49 && visu->step < 0)
	{
		if (get_next_line(visu->fd, &str))
		{
			save = str;
			while (save != NULL)
			{
				save = handle_str(save, visu->farm, &link);
				if (!(list = ft_lstnew(&link, sizeof(t_link))))
					exit(-1);
				ft_lstadd(&(visu->links), list);
			}
			free(str);
			list = visu->links;
			while (list != NULL)
			{
				plink = list->content;
				list = list->next;
			}
			visu->step = STEPS;
		}
		else 
			visu->step = 0;
	}
	return (0);
}

void draw_aunt(t_link *link, t_visu *visu)
{
	mlx_put_image_to_window(visu->mlx_ptr, visu->win_ptr, visu->aunt.ptr, link->p.x - SQ_SIZE / 2, link->p.y - SQ_SIZE / 2);
	link->p.x += link->delta.x;
	link->p.y += link->delta.y;
}

void draw_hex(t_visu *visu)
{
	int i;
	t_room *room;
	char *str;
	
	mlx_put_image_to_window(visu->mlx_ptr, visu->win_ptr, visu->hex.ptr, 0, 0);
	i = 0;
	while (i < visu->farm->count_rooms)
	{
		room = visu->farm->array_rooms[i];
		str = ft_itoa(room->aunts);
		mlx_string_put(visu->mlx_ptr, visu->win_ptr, room->crd.x - SQ_SIZE / 2, room->crd.y + SQ_SIZE, 100000,
											str);
		free(str);
		i++;
	}
	
}

int dinamic(t_visu *visu)
{
	t_list	*link;
	t_link	*content;

	mlx_clear_window(visu->mlx_ptr, visu->win_ptr);
	draw_hex(visu);
	if (visu->step >= 0)
	{
		link = visu->links;
		mlx_clear_window(visu->mlx_ptr, visu->win_ptr);
		draw_hex(visu);
		while (link != NULL)
		{
			draw_aunt(link->content, visu);
			link = link->next;
		}
		visu->step--;
		if (visu->step < 0)
		{
			link = visu->links;
			while (link != NULL)
			{	
				content = link->content;
				content->room1->aunts--;
				content->room2->aunts++;
				visu->farm->array_aunts[content->numb] = content->room2->ind;
				link = link->next;
			}
			ft_lstcontentfree(&(visu->links));
			visu->links = NULL;
		}
	}
	return (0);
}

void imag_initialisation(t_img *hex, t_img *aunt, t_visu *visu)
{
	int i;

	hex->h = HEX_W;
	hex->w = HEX_H;
	hex->ptr = mlx_new_image(visu->mlx_ptr, HEX_W, HEX_H);
	hex->data = (int*)mlx_get_data_addr(hex->ptr, &hex->bits_per_pixel, &hex->h, &hex->endian);
	hex_img(hex, visu->farm);
	aunt->h = SQ_SIZE;
	aunt->w = SQ_SIZE;
	aunt->ptr = mlx_new_image(visu->mlx_ptr, aunt->w, aunt->h);
	aunt->data = (int*)mlx_get_data_addr(aunt->ptr, &aunt->bits_per_pixel, &aunt->h, &aunt->endian);
	i = 0;
	while (i < SQ_SIZE * SQ_SIZE)
	{
		aunt->data[i] = 10000000;
		i++;
	}
}

int main(int argc, char **argv)
{
	t_farm farm;
	t_visu visu;
	t_img	aunt;
	t_img	hex;
	int fd;

	if (argc == 1)
		fd = 0;
	else
		fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		exit(-1);
	read_data(fd, &farm);//add aunts_to room struct//read to \n
	initialisation(&visu);
	visu.farm = &farm;
	visu.fd = fd;
	visu.step = -1;
	imag_initialisation(&hex, &aunt, &visu);
	visu.aunt = aunt;
	visu.hex = hex;
	mlx_key_hook(visu.win_ptr, &step_init, &visu);
	mlx_loop_hook(visu.mlx_ptr, &dinamic, &visu);
 	mlx_loop(visu.mlx_ptr);
	free_visu(&visu);
	free_farm(&farm);
	return (0);
}