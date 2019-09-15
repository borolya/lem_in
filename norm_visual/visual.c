#include "lemin.h"
#include "visu.h"


void initialization(t_visu *visu, t_img aunt, t_img hex)
{
	visu->mlx_ptr = mlx_init();
	visu->win_ptr = mlx_new_window(visu->mlx_ptr, WIN_W, WIN_H, "HEX");
	visu->aunt = aunt;
	visu->hex = hex;
}

void fill_points(t_link *link)//add ft_abs to lib
{
	link->p->x = link->room1->x;
	link->p->y = link->room1->y;
	link->delta->x = link->room1->x - link->room2->x / STEPS;
	link->delta->y = link->room1->y - link->room2->y / STEPS;
}

char *handle_str(char *str, t_farm *farm, t_link *link)
{
	int numb;
	int i;
	int len;
	char *tmp;

	if (str[0] != "L")
		ft_error("bad_moved");//free all
	str++;
	numb = ft_atoi(str + i);
	link->room1 = farm->array_rooms[farm->aunt[numb]];
	str = ft_strchr(str, "-");
	str++;
	tmp = ft_strchr(str, " ");
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
		free_all;
		exit(1);
	}
	else
	{
		if (get_next_line(0, &str))
		{
			save = str;
			while (str = handle_str(str, visu->farm, &link))
			{
				if (!(list = ft_lstnew(&link, sizeof(t_link))))
					exit(-1);
				ft_lstadd(&(visu->links), list);
			}
			free(save);
			visu->action = 1;
		}
		else
		{
			
		}
	}
}

void draw_aunt(t_link *link, t_visu *visu)
{
	if (link->step > STEPS)
	{
		free(link);
		link == NULL;
		return ;
	}
	mlx_put_image_to_window(visu->mlx_ptr, visu->win_ptr, visu->aunt, link->p->x, link->p->y);
	link->p->x += link->delta->x;
	link->p->y = link->delta->y;
	
}

int dinamic(t_visu *visu)
{
	t_list *link;

	draw_hex(visu);
	if (visu->action == 1)
	{
		link = visu->links;
		mlx_clear_window(visu->mlx_ptr, visu->win_ptr);
		draw_hex(visu);
		while (link != NULL)
		{
			change_coord_aunt(link->content);
			link = link->next;
		}
		visu->action = 0;
	}
}

void hex_img(t_img *hex, t_visu *visu)
{

}

void imag_initialization(t_img *hex, t_img *aunt, t_visu *visu)
{
	int i;

	hex->h = IMG_W;
	hex->w = IMG_H;
	hex->ptr = mlx_new_image (visu->mlx_ptr, IMG_W, IMG_H);
	hex->data = (int*)mlx_get_data_addr(hex->ptr, &hex->bits_per_pixel, &hex->h, &hex->endian);
	hex_img(hex, visu);
	aunt->h = 5;
	aunt->w = 5;
	aunt->ptr = mlx_new_image (visu->mlx_ptr, aunt->w, aunt->h);
	aunt->data = (int*)mlx_get_data_addr(aunt->ptr, &aunt->bits_per_pixel, &aunt->h, &aunt->endian);
	i = 0;
	while (i < 25)
	{
		aunt->data[i] = 100;
		i++;
	}
}
int main()
{
	t_farm farm;
	t_visu visu;
	t_img	aunt;
	t_img	hex;

	read_data(0, &farm);//add aunts_to room struct//read to \n
	initialisation(&visu, aunt, hex);
	imag_initialization(&hex, &aunt, &visu);
	mlx_key_hook(visu.win_ptr, &step_init, &visu);
	mlx_loop_hook(visu.win_ptr, &dinamic, &visu);
	mlx_loop(visu.mlx_ptr);
}