#include "lemin.h"
#include "visu.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


void initialisation(t_visu *visu)
{
	visu->mlx_ptr = mlx_init();
	visu->win_ptr = mlx_new_window(visu->mlx_ptr, WIN_W, WIN_H, "HEX");
	
}

void fill_points(t_link *link)//add ft_abs to lib
{
	link->p->x = link->room1->crd.x;
	link->p->y = link->room1->crd.y;
	link->delta->x = link->room1->crd.x - link->room2->crd.x / STEPS;
	link->delta->y = link->room1->crd.y - link->room2->crd.y / STEPS;
}

char *handle_str(char *str, t_farm *farm, t_link *link)
{
	int numb;
	int i;
	int len;
	char *tmp;

	if (str[0] != 'L')
		ft_error("bad_moved");//free all
	str++;
	numb = ft_atoi(str);
	link->room1 = farm->array_rooms[farm->array_aunts[numb]];
	str = ft_strchr(str, '-');
	str++;
	tmp = ft_strchr(str, ' ');
	if (tmp != NULL)
		len = str - tmp;
	else
		len = ft_strlen(str);
	i = 0;
	while (!ft_strnequ(str, farm->array_rooms[i++]->name, len))
	if (i < farm->count_rooms)
		link->room2 = farm->array_rooms[i];
	else
		ft_error("aunt go to nowhere");
	fill_points(link);
	if (tmp != NULL)
		tmp++;
	return (tmp);
}

int step_init(int keycode, t_visu *visu)
{
	t_link link;
	char *save;
	char *str;
	t_list *list;

	if (keycode == 53)
	{
		//free_all;
		exit(1);
	}
	else
	{
		if (get_next_line(0, &str))
		{
			save = str;
			while (str == handle_str(str, visu->farm, &link))
			{
				if (!(list = ft_lstnew(&link, sizeof(t_link))))
					exit(-1);
				ft_lstadd(&(visu->links), list);
			}
			free(save);
			//change count aunt in room
			visu->step = STEPS;
		}
		else 
			visu->step = 0;
	}
    return (0);
}

void draw_aunt(t_link *link, t_visu *visu)
{
	mlx_put_image_to_window(visu->mlx_ptr, visu->win_ptr, visu->aunt.ptr, link->p->x, link->p->y);
	link->p->x += link->delta->x;
	link->p->y = link->delta->y;
	if (visu->step == 0)
	{
		free(link);
		link = NULL;
	}
}

void draw_hex(t_visu *visu)
{
	//add list of rooms and aunt
	mlx_put_image_to_window(visu->mlx_ptr, visu->win_ptr, visu->hex.ptr, 50, 50);
}

void ft_lstfree(t_list **alst)
{
	t_list *lst;
	t_list *next;

	if (alst)
		return;
	lst = (*alst);
	while (lst)
	{
		free((t_link*)(lst->content));
		next = lst->next;
		free(lst);
		lst = next;
	}
	*alst = NULL;
}

int dinamic(t_visu *visu)
{
	t_list *link;

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
			ft_lstfree(&(visu->links));
	}
    return (0);
}

void imag_initialisation(t_img *hex, t_img *aunt, t_visu *visu)
{
	int i;

	hex->h = IMG_W;
	hex->w = IMG_H;
	hex->ptr = mlx_new_image (visu->mlx_ptr, IMG_W, IMG_H);
	hex->data = (int*)mlx_get_data_addr(hex->ptr, &hex->bits_per_pixel, &hex->h, &hex->endian);
	hex_img(hex, visu->farm);
	aunt->h = 5;
	aunt->w = 5;
	aunt->ptr = mlx_new_image(visu->mlx_ptr, aunt->w, aunt->h);
	aunt->data = (int*)mlx_get_data_addr(aunt->ptr, &aunt->bits_per_pixel, &aunt->h, &aunt->endian);
	i = 0;
	while (i < 25)
	{
		aunt->data[i] = 100;
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
	read_data(fd, &farm);//add aunts_to room struct//read to \n
	initialisation(&visu);
	imag_initialisation(&hex, &aunt, &visu);
    visu.aunt = aunt;
	visu.hex = hex;
	mlx_key_hook(visu.win_ptr, &step_init, &visu);
	mlx_loop_hook(visu.win_ptr, &dinamic, &visu);
	mlx_loop(visu.mlx_ptr);
}